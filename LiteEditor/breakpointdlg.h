//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : breakpointdlg.h              
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
 #ifndef __breakpointdlg__
#define __breakpointdlg__

/**
@file
Subclass of BreakpointDlgBase, which is generated by wxFormBuilder.
@todo Add your event handlers directly to this file.
*/

#include "breakpoint_dlg_base.h"

/** Implementing BreakpointDlgBase */
class BreakpointDlg : public BreakpointTab
{
	long m_selectedItem;
protected:
	void OnDelete(wxCommandEvent &e);
	void OnDeleteAll(wxCommandEvent &e);
	void OnItemActivated(wxListEvent &e);
	void OnItemSelected(wxListEvent &e);
	void OnItemDeselected(wxListEvent &e);
	
public:
	/** Constructor */
	BreakpointDlg( wxWindow* parent );
	void Initialize();
};

#endif // __breakpointdlg__
