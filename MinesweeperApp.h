/**
 * @file MinesweeperApp.h
 *
 * @author Jack Sleeman
 *
 * The main application class of our program.
 *
 * Initializes program, allowing creation of game window.
 */

#ifndef _MINESWEEPERAPP_H
#define _MINESWEEPERAPP_H

/**
 * Main application class
 */
class MinesweeperApp : public wxApp {
public:
    bool OnInit() override;
};

#endif //_MINESWEEPERAPP_H
