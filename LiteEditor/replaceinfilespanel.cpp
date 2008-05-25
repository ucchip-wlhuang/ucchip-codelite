//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : replaceinfilespanel.cpp              
//                                                                          
// -------------------------------------------------------------------------
// A                                                                        
//              _____           _      _     _ _                            
//             /  __ \         | |    | |   (_) |                           
//             | /  \/ ___   __| | ___| |    _| |_ ___                      
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )                     
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/                     
//              \____/\___/ \__,_|\___\_____/_|\__\___|                     
//                                                                          
//                                                  F i l e                 
//                                                                          
//    This program is free software; you can redistribute it and/or modify  
//    it under the terms of the GNU General Public License as published by  
//    the Free Software Foundation; either version 2 of the License, or     
//    (at your option) any later version.                                   
//                                                                          
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 #include "replaceinfilespanel.h"
#include "wx/progdlg.h"
#include "cl_editor.h"
#include "manager.h"

ReplaceInFilesPanel::ReplaceInFilesPanel( wxWindow* parent )
		:
		ReplaceInFilesBasePanel( parent )
{

}

void ReplaceInFilesPanel::OnItemSelected( wxCommandEvent& event )
{
	int selection;
	selection = m_listBox1->GetSelection();
	if (selection == wxNOT_FOUND) {
		return;
	}

	long lineNumber = -1;
	long matchLen = wxNOT_FOUND;
	long col = wxNOT_FOUND;
	wxString fileName;
	wxString pattern;

	ParseEntry(selection, lineNumber, col, matchLen, fileName, pattern);

	// open the file in the editor
	if (ManagerST::Get()->OpenFile(fileName, wxEmptyString, lineNumber - 1 )) {
		LEditor *editor = ManagerST::Get()->GetActiveEditor();
		if (editor) {
			if (col >= 0 && matchLen >= 0) {
				int offset = editor->PositionFromLine(lineNumber-1);
				editor->SetSelection(offset + col, offset + col + matchLen);
			}
		}
	}
	m_listBox1->SetFocus();
}

void ReplaceInFilesPanel::OnItemDClicked( wxCommandEvent& event )
{
	OnItemSelected(event);
	DoReplaceSelection();
	m_listBox1->SetFocus();

	int sel = m_listBox1->GetSelection();
	if (sel != wxNOT_FOUND) {
		int nextItem(wxNOT_FOUND);
		if ((size_t)sel < m_listBox1->GetCount()-1 && m_listBox1->GetCount() > 1) {
			nextItem = sel;
		} else if ((size_t)sel == m_listBox1->GetCount()-1 && m_listBox1->GetCount() > 1) {
			nextItem = sel - 1;
		}

		if (nextItem != wxNOT_FOUND) {
			long line;
			long matchLen;
			long col;
			wxString fileName;
			wxString pattern;

			ParseEntry(sel, line, col, matchLen, fileName, pattern);
			AdjustItems((unsigned int)sel, m_textCtrlReplaceWith->GetValue().Length()-matchLen, fileName, line);
		}

		m_listBox1->Delete((unsigned int)sel);
		m_listBox1->Select((unsigned int)nextItem);

		//select next item
		OnItemSelected(event);
	}
}

void ReplaceInFilesPanel::OnReplaceAll( wxCommandEvent& event )
{
	//parse all entries in the list, collect the file names and perform a massive replace
	size_t count = m_listBox1->GetCount();

	wxString warnMessage;
	warnMessage << wxT("Are you sure you want to replace all ") << count << wxT(" occurrences of ") << m_findWhat << wxT(" ?");
	if (wxMessageBox(warnMessage, wxT("CodeLite"), wxYES_NO|wxCANCEL|wxICON_WARNING) != wxYES) {
		return;
	}

	// Create a progress dialog
	wxProgressDialog prgDlg(wxT("Performing replace all..."), wxT("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"), (int)count, NULL, wxPD_APP_MODAL | wxPD_SMOOTH|wxPD_AUTO_HIDE);
	prgDlg.GetSizer()->Fit( &prgDlg );
	prgDlg.Layout();
	prgDlg.Centre();

	wxString msg;
	prgDlg.Update(0, wxT("Replacing..."));
	for (size_t i=0; i< m_listBox1->GetCount(); i++) {

		long cur_line;
		long matchLen;
		long col;
		wxString file_name;
		wxString pattern;

		ParseEntry(i, cur_line, col, matchLen, file_name, pattern);
		
		//open this file
		if ( ManagerST::Get()->OpenFile(file_name, wxEmptyString) ) {
			//do the actual replacement here
			LEditor *editor = ManagerST::Get()->GetActiveEditor();
			if ( editor ) {
				//select the target string
				if (col >= 0 && matchLen >= 0) {
					int offset = editor->PositionFromLine(cur_line-1);
					editor->SetSelection(offset + col, offset + col + matchLen);
				}
				//replace the selection
				if (editor->GetSelectedText().IsEmpty() == false) {
					editor->ReplaceSelection(m_textCtrlReplaceWith->GetValue());
					AdjustItems((unsigned int)i, m_textCtrlReplaceWith->GetValue().Length()-matchLen, file_name, cur_line);
				}
			}
		}

		// update the progress bar
		msg.Clear();
		msg << wxT("Replacing in file: ") << file_name;
		prgDlg.Update(i, msg);
	}

	wxString statusMessage;
	statusMessage << m_listBox1->GetCount() << wxT(" replacements have been made");
	wxMessageBox(statusMessage, wxT("CodeLite"), wxICON_INFORMATION|wxOK);
	Clear();
}

void ReplaceInFilesPanel::OnReplaceAllUI( wxUpdateUIEvent& event )
{
	event.Enable(m_listBox1->IsEmpty() == false);
}

void ReplaceInFilesPanel::AddResults(SearchResultList *res)
{
	SearchResultList::iterator iter = res->begin();

	m_listBox1->Freeze();

	wxString msg;
	wxArrayString arr;
	for (; iter != res->end(); iter++) {
		SearchResult r = (*iter);
		msg = r.GetMessage();
		msg = msg.Trim().Trim(false);
		arr.Add( msg );
		m_findWhat = r.GetFindWhat();
	}

	m_listBox1->Append(arr);
	m_listBox1->Thaw();
	delete res;
	m_listBox1->SetFocus();
}

void ReplaceInFilesPanel::Clear()
{
	m_findWhat.Clear();
	m_listBox1->Clear();
}

void ReplaceInFilesPanel::DoReplaceSelection()
{
	LEditor *editor = ManagerST::Get()->GetActiveEditor();
	if (editor) {
		if (editor->GetSelectedText().IsEmpty() == false) {
			editor->ReplaceSelection(m_textCtrlReplaceWith->GetValue());
		}
	}
}

void ReplaceInFilesPanel::OnClearResults(wxCommandEvent &e)
{
	wxUnusedVar(e);
	Clear();
}

void ReplaceInFilesPanel::OnClearResultsUI( wxUpdateUIEvent& event )
{
	event.Enable(m_listBox1->IsEmpty() == false);
}

void ReplaceInFilesPanel::ParseEntry(int index, long &line, long &col, long &matchLen, wxString &fileName, wxString &pattern)
{
	wxString lineText = m_listBox1->GetString((unsigned int)index);

	// each line has the format of
	// file(line, col, len): text
	fileName = lineText.BeforeFirst(wxT('('));
	wxString strLineNumber = lineText.AfterFirst(wxT('('));
	wxString strLen = strLineNumber.AfterFirst(wxT(',')).AfterFirst(wxT(',')).BeforeFirst(wxT(')'));
	wxString strCol = strLineNumber.AfterFirst(wxT(',')).BeforeFirst(wxT(','));

	pattern = lineText.AfterFirst(wxT('('));
	pattern = pattern.AfterFirst(wxT(' '));

	strLineNumber = strLineNumber.BeforeFirst(wxT(','));
	strLineNumber = strLineNumber.Trim();
	strLineNumber.ToLong(&line);

	strLen = strLen.Trim().Trim(false);
	strLen.ToLong( &matchLen );

	strCol = strCol.Trim().Trim(false);
	strCol.ToLong( &col );
}

void ReplaceInFilesPanel::AdjustItems(unsigned int from, int diff, const wxString &fileName, long line)
{
	for (unsigned int i=from; i< m_listBox1->GetCount(); i++) {
		long cur_line;
		long matchLen;
		long col;
		wxString file_name;
		wxString pattern;

		ParseEntry(i, cur_line, col, matchLen, file_name, pattern);
		if (file_name == fileName && line == cur_line) {
			//adjust this item
			wxString msg;
			msg << file_name
			<< wxT("(")
			<< line
			<< wxT(",")
			<< col + diff
			<< wxT(",")
			<< matchLen
			<< wxT("): ")
			<< pattern;
			m_listBox1->SetString(i, msg);
		} else {
			break;
		}
	}
}
