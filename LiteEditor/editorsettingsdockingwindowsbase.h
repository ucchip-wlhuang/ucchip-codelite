///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  3 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __EDITORSETTINGSDOCKINGWINDOWSBASE_H__
#define __EDITORSETTINGSDOCKINGWINDOWSBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/radiobox.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class EditorSettingsDockingWindowsBase
///////////////////////////////////////////////////////////////////////////////
class EditorSettingsDockingWindowsBase : public wxPanel 
{
	private:
	
	protected:
		wxCheckBox* m_checkBoxHideOutputPaneOnClick;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfBuild;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfErrors;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfSearch;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfReplace;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfReferences;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfOutput;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfDebug;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfTrace;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfTasks;
		wxCheckBox* m_checkBoxHideOutputPaneNotIfCscope;
		wxCheckBox* m_checkBoxDontFoldSearchResults;
		wxCheckBox* m_checkBoxFindBarAtBottom;
		wxCheckBox* m_checkBoxShowDebugOnRun;
		wxRadioBox* m_radioBoxHint;
		wxRadioBox* m_radioBoxTabControlStyle;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnHideOutputPaneNotIfDebugUI( wxUpdateUIEvent& event ) { event.Skip(); }
		
	
	public:
		
		EditorSettingsDockingWindowsBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~EditorSettingsDockingWindowsBase();
	
};

#endif //__EDITORSETTINGSDOCKINGWINDOWSBASE_H__
