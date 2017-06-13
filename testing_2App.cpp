/***************************************************************
 * Name:      testing_2App.cpp
 * Purpose:   Code for Application Class
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

#include "testing_2App.h"
#include "testing_2Main.h"

IMPLEMENT_APP(testing_2App);

bool testing_2App::OnInit()
{
    testing_2Frame* frame = new testing_2Frame(0L, _("Manny's text Editor"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();

    return true;
}
