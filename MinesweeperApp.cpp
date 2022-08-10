/**
 * @file MinesweeperApp.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "MinesweeperApp.h"
#include "Mainframe.h"

/**
 * Initialize the application
 *
 * @return
 */
bool MinesweeperApp::OnInit()
{
    if (!wxApp::OnInit())
    {
        return false;
    }

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new Mainframe();
    frame->Initialize();
    frame->Show(true);

    return true;
}