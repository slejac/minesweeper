/**
 * @file Mainframe.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Mainframe.h"

/**
 * Initialize the MainFrame window.
 *
 * @return
 */
void Mainframe::Initialize()
{
    Create(nullptr, wxID_ANY, L"Minesweeper",wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    //auto gameView = new GameView();
    //gameView->Initialize(this);
}