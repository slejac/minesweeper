/**
 * @file Game.cpp
 *
 * @author Jack Sleeman
 */

#include "pch.h"
#include "Game.h"
#include <ctime>

/**
 * Game Board Constructor.
 */
Game::Game()
{
    mWhiteImage = std::make_unique<wxImage>(FilePath + WhiteImage, wxBITMAP_TYPE_ANY);
    mWhiteBitmap = std::make_unique<wxBitmap>(*mWhiteImage);
    mYellowImage = std::make_unique<wxImage>(FilePath + YellowImage, wxBITMAP_TYPE_ANY);
    mYellowBitmap = std::make_unique<wxBitmap>(*mYellowImage);
    mGreenImage = std::make_unique<wxImage>(FilePath + GreenImage, wxBITMAP_TYPE_ANY);
    mGreenBitmap = std::make_unique<wxBitmap>(*mGreenImage);
    mRedImage = std::make_unique<wxImage>(FilePath + RedImage, wxBITMAP_TYPE_ANY);
    mRedBitmap = std::make_unique<wxBitmap>(*mRedImage);
    mBlueImage = std::make_unique<wxImage>(FilePath + BlueImage, wxBITMAP_TYPE_ANY);
    mBlueBitmap = std::make_unique<wxBitmap>(*mBlueImage);
}

/**
 * Generates new game, mines will not set until first click.
 */
void Game::NewGame()
{
    mClearGame = true;
    mGameOver = false;
}

/**
 * Mine setting function for the game, generates new game board.
 */
void Game::SetMines()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mItems[i][j] = 10;
        }
    }
    for (int total = 0; total < 10; total++)
    {
        int randomX = rand()%10;
        int randomY = rand()%10;
        mItems[randomX][randomY] = 11;
    }
}

/**
 * Draw function.
 *
 * @param dc Context we are drawing on.
 */
void Game::OnDraw(wxDC *dc)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mItems[i][j] == 10 || mClearGame|| mItems[i][j] == 11)
            {
                dc->DrawBitmap(*mWhiteBitmap, i * ItemSpacing,
                        j * ItemSpacing);
            }
            else if (mItems[i][j] == 20 || mItems[i][j] == 21)
            {
                dc->DrawBitmap(*mYellowBitmap, i*ItemSpacing,
                        j * ItemSpacing);
            }
            else if (mItems[i][j] == 31)
            {
                dc->DrawBitmap(*mRedBitmap, i * ItemSpacing,
                        j * ItemSpacing);
            }
            else if (mItems[i][j] == 41)
            {
                dc->DrawBitmap(*mBlueBitmap, i * ItemSpacing,
                        j * ItemSpacing);
            }
            else
            {
                dc->DrawBitmap(*mGreenBitmap, i * ItemSpacing,
                        j * ItemSpacing);
                wxFont font(10,
                        wxFONTFAMILY_SWISS,
                        wxFONTSTYLE_NORMAL,
                        wxFONTWEIGHT_NORMAL);
                dc->SetTextForeground(wxColour(0, 0, 0));
                dc->SetFont(font);
                std::wstring minesNearby = std::to_wstring(mItems[i][j]);
                dc->DrawText(minesNearby, i * ItemSpacing, j * ItemSpacing);
            }
        }
    }
}

/**
 * Function handling a click on the board
 *
 * @param x X location of the click.
 *
 * @param y Y location of the click.
 */
void Game::HitTest(int x, int y)
{
    int i = (x / ItemSpacing);
    int j = (y / ItemSpacing);
    if (mClearGame == true)
    {
        SetMines();
        while (mItems[i][j] == 11)
        {
            SetMines();
        }
        mClearGame = false;
    }
    Click(i, j);
}

/**
 * Flagging a square on our board.
 *
 * @param x X location of the click.
 *
 * @param y Y location of the click.
 */
void Game::Flag(int x, int y)
{
    int i = (x / ItemSpacing);
    int j = (y / ItemSpacing);
    if (mItems[i][j] == 11)
    {
        mItems[i][j] = 21;
    }
    else
    {
        mItems[i][j] = 20;
    }
}

/**
 * Handles click onto a square.
 *
 * @param i Row we are clicking
 *
 * @param j Column we are clicking.
 */
void Game::Click(int i, int j)
{
    int totalLocalMines = 0;
    if (mItems[i][j] == 11 || mItems[i][j] == 21)
    {
        mGameOver = true;
        Fail();
    }
    else if (i >= 0 && i < 10 && j >= 0 && j < 10)
    {
        if (mItems[i-1][j-1] == 11 || mItems[i-1][j-1] == 21)
        {
            if (i-1 >= 0 && j-1 >= 0)
            {
                totalLocalMines++;
            }
        }
        if (mItems[i-1][j] == 11 || mItems[i-1][j] == 21)
        {
            if (i-1 >= 0)
            {
                totalLocalMines++;
            }
        }
        if (mItems[i-1][j+1] == 11 || mItems[i-1][j+1] == 21)
        {
            if (i-1 >= 0 && j+1 < 10)
            {
                totalLocalMines++;
            }
        }
        if (mItems[i][j-1] == 11 || mItems[i][j-1] == 21)
        {
            if (j-1 >= 0)
            {
                totalLocalMines++;
            }
        }
        if (mItems[i][j+1] == 11 || mItems[i][j+1] == 21)
        {
            if (j+1 < 10)
            {
                totalLocalMines++;
            }
        }
        if (mItems[i+1][j-1] == 11 || mItems[i+1][j-1] == 21)
        {
            if (i+1 < 10 && j-1 >= 0)
            {
                totalLocalMines++;
            }
        }
        if (mItems[i+1][j] == 11 || mItems[i+1][j] == 21)
        {
            if (i+1 < 10)
            {
                totalLocalMines++;
            }
        }
        if (mItems[i+1][j+1] == 11 || mItems[i+1][j+1] == 21)
        {
            if (i+1 < 10 && j+1 < 10)
            {
                totalLocalMines++;
            }
        }
        mItems[i][j] = totalLocalMines;
        if (totalLocalMines == 0)
        {
            Chain(i, j);
        }
    }
    if (!mGameOver)
    {
        bool isWin = true;
        for (int i = 0; i<10; i++)
        {
            if (!isWin)
            {
                break;
            }
            for (int j = 0; j<10; j++)
            {
                if (mItems[i][j] == 10 || mItems[i][j] == 20)
                {
                    isWin = false;
                    break;
                }
            }
        }
        if (isWin)
        {
            Win();
        }
    }
}

/**
 * Handling a player lose scenario.
 */
void Game::Fail()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mItems[i][j] != 11 && mItems[i][j] != 21)
            {
                Click(i, j);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mItems[i][j] == 11 || mItems[i][j] == 21)
            {
                mItems[i][j] = 31;
            }
        }
    }
}

/**
 * Function to handle when game has been won.
 */
void Game::Win()
{
    mGameOver = true;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mItems[i][j] == 11 || mItems[i][j] == 21)
            {
                mItems[i][j] = 41;
            }
        }
    }
}

/**
 * Chaining mechanism for a block of empty squares
 *
 * @param i The row in which we are searching for nearby chaining.
 *
 * @param j The column in which we are searching for nearby chaining.
 */
void Game::Chain(int i, int j)
{
    if (mItems[i-1][j-1] == 10)
    {
        Click(i-1, j-1);
    }
    if (mItems[i-1][j] == 10)
    {
        Click(i-1, j);
    }
    if (mItems[i-1][j+1] == 10)
    {
        Click(i-1, j+1);
    }
    if (mItems[i][j-1] == 10)
    {
        Click(i, j-1);
    }
    if (mItems[i][j+1] == 10)
    {
        Click(i, j+1);
    }
    if (mItems[i+1][j-1] == 10)
    {
        Click(i+1, j-1);
    }
    if (mItems[i+1][j] == 10)
    {
        Click(i+1, j);
    }
    if (mItems[i+1][j+1] == 10)
    {
        Click(i+1, j+1);
    }
}
