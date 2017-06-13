/***************************************************************
 * Name:      testing_2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    manny ()
 * Created:   2017-05-26
 * Copyright: manny ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "testing_2Main.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(testing_2Frame, wxFrame)
    EVT_CLOSE(testing_2Frame::OnClose)
    EVT_MENU(idMenuQuit, testing_2Frame::OnQuit)
    EVT_MENU(idMenuOpen, testing_2Frame::OnOpen)
    EVT_MENU(idMenuAbout, testing_2Frame::OnAbout)
    EVT_MENU(idMenuSave, testing_2Frame::OnSave)

END_EVENT_TABLE()

testing_2Frame::testing_2Frame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuOpen, _("&Open\tAlt-F4"),_("Quit the application"));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    fileMenu->Append(idMenuOpen, _("&Open\tAlt-F5"), _("Open a file"));
    fileMenu->Append(idMenuSave,_("Open\tAlt-F6"), _("save a file"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello its "+ wxDateTime::Now().Format("%c using"+wxbuildinfo(short_f))),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

 textControl = new wxTextCtrl(this, ID_TextBox,
 wxT(""), wxDefaultPosition, wxDefaultSize,
 wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);

/* above we just have the construction of a wxTextCtrl object, belonging to the text control class*/
}


testing_2Frame::~testing_2Frame()
{
}

void testing_2Frame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void testing_2Frame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void testing_2Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
void testing_2Frame::OnOpen(wxCommandEvent &event)
{
    wxFileDialog *openDialog = new wxFileDialog(this, wxT("choose a file"),wxT(""),wxT(""),
wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Header Files (*.h)|*.h"),
wxFD_OPEN );

int response = openDialog->ShowModal(); //get response from the dialog
    if(response == wxID_OK)
        { //if response ok, then load contents into textControl
        this->textControl->LoadFile(openDialog->GetPath());
        }


}
void testing_2Frame::OnSave(wxCommandEvent &event)
{
    wxFileDialog *saveDialog = new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""),
wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Header Files (*.h)|*.h"),
wxFD_SAVE );

int response = saveDialog->ShowModal(); //get response from the dialog

if(response == wxID_OK)
 { //if response ok, then load contents into textControl
 this->textControl->SaveFile(saveDialog->GetPath());
 }


}

