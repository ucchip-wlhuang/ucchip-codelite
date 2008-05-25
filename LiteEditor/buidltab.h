//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : buidltab.h              
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
 #ifndef __buidltab__
#define __buidltab__

#include "wx/string.h"
#include "map"
#include "outputtabwindow.h"
#include "compiler.h"

struct LineInfo {
	wxString project;
	wxString configuration;
};

class BuildTab : public OutputTabWindow {
	std::map<int, LineInfo> m_lineInfo;
	// holds the index of the last line in the build window
	// that was reached, using F4 (last build error)
	int m_nextBuildError_lastLine;
	bool m_skipWarnings;
	
protected:
	bool OnBuildWindowDClick(const wxString &line, int lineClicked);
	void OnNextBuildError(wxCommandEvent &event);
	void OnMouseDClick(wxScintillaEvent &event);
	void OnHotspotClicked(wxScintillaEvent &event);
	void OnCompilerColours(wxCommandEvent &e);
	void Initialize();
	
	wxString ProjectFromLine(int line);
	
public:
	BuildTab(wxWindow *parent, wxWindowID id, const wxString &name);
	~BuildTab();

	virtual void AppendText(const wxString &text);
	virtual void Clear();
	
	void OnBuildEnded();
	void ReloadSettings();
	CompilerPtr GetCompilerByLine(int lineClicked);
	int LineFromPosition(int pos);
	
	static int ColourGccLine(int startLine, const char *line, size_t &fileNameStart, size_t &fileNameLen);
	
	DECLARE_EVENT_TABLE()
};
#endif // __buidltab__

