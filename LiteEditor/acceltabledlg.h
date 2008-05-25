//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah                            
// file name            : acceltabledlg.h              
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
 #ifndef __acceltabledlg__
#define __acceltabledlg__

/**
@file
Subclass of AccelTableBaseDlg, which is generated by wxFormBuilder.
*/

#include "acceltablebasedlg.h"

/** Implementing AccelTableBaseDlg */
class AccelTableDlg : public AccelTableBaseDlg
{
	long m_selectedItem;
	
protected:
	// Handlers for AccelTableBaseDlg events.
	void OnItemActivated( wxListEvent& event );
	void OnItemSelected( wxListEvent& event );
	void OnItemDeselected( wxListEvent& event );
	void OnColClicked(wxListEvent &event);
	void PopulateTable();
	void OnButtonOk(wxCommandEvent &e);
public:
	/** Constructor */
	AccelTableDlg( wxWindow* parent );
};

#endif // __acceltabledlg__
