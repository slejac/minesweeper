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

/// Width between items placements
const int ItemSpacing = 32;

/// Width of items
const int ItemWidth = 30;

/// Path for all images
const wxString FilePath = L"data/";

/// White image filename
const std::wstring WhiteImage = L"blank.png";

/// Yellow image filename
const std::wstring YellowImage = L"yellow.png";

/// Green image filename
const std::wstring GreenImage = L"green.png";

/// Red image filename
const std::wstring RedImage = L"red.png";

/// Red image filename
const std::wstring BlueImage = L"blue.png";

/**
 * A game of minesweeper in which users will play.
 */
class Game {
private:
    /// All items in our game.
    int mItems[10][10];

    /// Whether or not the game has begun.
    bool mClearGame = true;

    /// Whether or not the game has been failed.
    bool mGameOver = false;

    /// The white item image
    std::unique_ptr<wxImage> mWhiteImage;

    /// The bitmap we can display for white item
    std::unique_ptr<wxBitmap> mWhiteBitmap;

    /// The yellow item image
    std::unique_ptr<wxImage> mYellowImage;

    /// The bitmap we can display for yellow item
    std::unique_ptr<wxBitmap> mYellowBitmap;

    /// The green item image
    std::unique_ptr<wxImage> mGreenImage;

    /// The bitmap we can display for green item
    std::unique_ptr<wxBitmap> mGreenBitmap;

    /// The red item image
    std::unique_ptr<wxImage> mRedImage;

    /// The bitmap we can display for red item
    std::unique_ptr<wxBitmap> mRedBitmap;

    /// The blue item image
    std::unique_ptr<wxImage> mBlueImage;

    /// The bitmap we can display for blue item
    std::unique_ptr<wxBitmap> mBlueBitmap;

    void SetMines();
    void Click(int i, int j);
    void Fail();
    void Win();
    void Chain(int i, int j);

public:
    Game();

    void NewGame();
    void OnDraw(wxDC *dc);
    void HitTest(int x, int y);
    void Flag(int x, int y);

    /**
     * Getter for the status of the game.
     *
     * @return Whether or not the game has failed.
     */
    bool GetGameStatus() const { return mGameOver; }
};

#endif //MINESWEEPER_GAME_H
