/**
 * @file Game.h
 *
 * @author Jack Sleeman
 *
 * The actual Minesweeper Game.
 *
 * Class representing a game of minesweeper in which
 * the user can play.
 */

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

/// Width between items.
const int ItemSpacing = 32;

/// Path for all images
const wxString FilePath = L"data/";

/// Wide image filename
const std::wstring WhiteImage = L"blank.png";

/**
 * A game of minesweeper in which users will play.
 */
class Game {
private:
    /// All items in our game.
    int mItems[10][10];

    /// The white item image
    std::unique_ptr<wxImage> mWhiteImage;

    /// The bitmap we can display for white item
    std::unique_ptr<wxBitmap> mWhiteBitmap;

public:
    Game();

    void Create();
    void OnDraw(wxDC *dc);
};

#endif //MINESWEEPER_GAME_H
