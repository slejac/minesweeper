/**
 * @file Game.cpp
 * @author sleja
 */

#include "pch.h"
#include "Game.h"

/**
 * Game Board Constructor
 */
Game::Game()
{
    mWhiteImage = std::make_unique<wxImage>(FilePath + WhiteImage, wxBITMAP_TYPE_ANY);
    mWhiteBitmap = std::make_unique<wxBitmap>(*mWhiteImage);
}

void Game::Create()
{
    // Replace functionality with randomized system
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mItems[i][j] = 0;
        }
    }
}

void Game::OnDraw(wxDC *dc)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mItems[i][j] == 0)
            {
                double wid = mWhiteBitmap->GetWidth();
                double hit = mWhiteBitmap->GetHeight();
                dc->DrawBitmap(*mWhiteBitmap, i * ItemSpacing,
                        j * ItemSpacing);
            }
        }
    }
}
