//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : newworkspacedlg.h              
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
 #ifndef __newworkspacedlg__
#define __newworkspacedlg__

/**
@file
Subclass of NewWorkspaceBase, which is generated by wxFormBuilder.
*/

#include "newworkspacebasedlg.h"

/** Implementing NewWorkspaceBase */
class NewWorkspaceDlg : public NewWorkspaceBase
{
	wxString m_workspacePath;
	
protected:
	// Handlers for NewWorkspaceBase events.
	void OnWorkspacePathUpdated( wxCommandEvent& event );
	void OnWorkspaceDirPicker( wxCommandEvent& event );
	void OnButtonCreate( wxCommandEvent& event );

public:
	/** Constructor */
	NewWorkspaceDlg( wxWindow* parent );
	
	wxString GetFilePath() const {return m_workspacePath;}
};

#endif // __newworkspacedlg__
