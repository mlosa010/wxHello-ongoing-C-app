/***************************************************************
 * Name:      testing_2Main.h
 * Purpose:   Defines Application Frame
 * Author:    manny ()
 * Created:   2017-05-26
 * Copyright: manny ()
 * License:
 **************************************************************/

#ifndef TESTING_2MAIN_H
#define TESTING_2MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "testing_2App.h"

class testing_2Frame: public wxFrame
{
    public:
        testing_2Frame(wxFrame *frame, const wxString& title);
        ~testing_2Frame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,
            idMenuOpen,
            idMenuSave,
            ID_TextBox
        };

        wxTextCtrl*textControl;
        wxFileDialog*openDialog;
        wxFileDialog* saveDialog;


        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnOpen(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // TESTING_2MAIN_H
