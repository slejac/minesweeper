/**
 * @file Mainframe.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Mainframe.h"
#include "ids.h"
#include "GameView.h"

/**
 * Initialize the MainFrame window.
 *
 * @return
 */
void Mainframe::Initialize()
{
    Create(nullptr, wxID_ANY, L"Minesweeper",wxDefaultPosition,  wxSize(332, 375 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    auto gameView = new GameView();
    gameView->Initialize(this);

    sizer->Add(gameView, 1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar( );

    // Add menu selection item
    auto menu = new wxMenu();

    // Append menu bar item
    menuBar->Append(menu, L"&Menu");

    menu->Append(IDM_GENERATE, L"&Generate Game",
            "Generate a New Minesweeper Game");

    SetMenuBar( menuBar );
}