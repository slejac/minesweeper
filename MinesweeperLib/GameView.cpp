/**
 * @file GameView.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "GameView.h"
#include "ids.h"

/**
 * Initializes GameView class.
 *
 * @param parent The parent window.
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
    Bind(wxEVT_RIGHT_DOWN, &GameView::OnRightDown, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnGenerateGame, this, IDM_GENERATE);

    mGame.NewGame();
    Refresh();
}

/**
 * Paints the window and it's contents.
 *
 * @param event Paint event.
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();
    mGame.OnDraw(&dc);
}

/**
 * Event handler for Generate Game
 *
 * @param event Menu->Generate Game
 */
void GameView::OnGenerateGame(wxCommandEvent& event)
{
    mGame.NewGame();
    Refresh();
}

/**
 * Handle the left mouse button down event.
 *
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
    if (!mGame.GetGameStatus())
    {
        mGame.HitTest(event.GetX(), event.GetY());
        Refresh();
    }
}

/**
 * Handle the right mouse button down event.
 *
 * @param event
 */
void GameView::OnRightDown(wxMouseEvent& event)
{
    if (!mGame.GetGameStatus())
    {
        mGame.Flag(event.GetX(), event.GetY());
        Refresh();
    }
}