/**
 * @file GameView.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "GameView.h"
#include "ids.h"
#include "Game.h"

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

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnGenerateGame, this, IDM_GENERATE);
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

void GameView::OnGenerateGame(wxCommandEvent& event)
{
    mGame.Create();
}
