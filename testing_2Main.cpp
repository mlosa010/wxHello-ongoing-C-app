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
    EVT_MENU(idMenuAbout, testing_2Frame::OnAbout)
END_EVENT_TABLE()

testing_2Frame::testing_2Frame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
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
