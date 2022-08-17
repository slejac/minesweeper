/**
 * @file GameView.h
 *
 * @author Jack Sleeman
 *
 * A view within the window of the game.
 */

#ifndef MINESWEEPER_GAMEVIEW_H
#define MINESWEEPER_GAMEVIEW_H

#include <wx/wx.h>
#include "Game.h"

/**
 * A view representing our game itself.
 */
class GameView : public wxWindow {
private:
    /// Game we are using
    Game mGame;

    void OnPaint(wxPaintEvent& event);

    void OnGenerateGame(wxCommandEvent& event);

public:
    void Initialize(wxFrame* parent);
};

#endif //MINESWEEPER_GAMEVIEW_H
