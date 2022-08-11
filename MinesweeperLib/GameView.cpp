/**
 * @file GameView.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "GameView.h"

void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}
