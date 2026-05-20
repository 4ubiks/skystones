// c libraries
#include "stdio.h"
#include "ncurses.h"

// custom files
#include "player.h"
#include "skyprint.h"


void printBoard(){

    int gridWidth = COLS - 10;
    int gridHeight = LINES - 5;

    WINDOW *gridBorder = newwin(gridHeight, gridWidth, 0, 0);
    box(gridBorder, 0, 0);


    // upper  Vborders
    for (int i=0; i<20; i++){
        mvwprintw(gridBorder, 5+i, 85, "||");
        mvwprintw(gridBorder, 5+i, 140, "||");
    }

    // first Hrow
    for (int row1=0; row1<140; row1++){
        mvwprintw(gridBorder, 25, 45+row1, "=");
    }

    // middle Vborders
    for (int k=0; k<20; k++){
        mvwprintw(gridBorder, 26+k, 85, "||");
        mvwprintw(gridBorder, 26+k, 140, "||");
    }

    // bottom Vborders
    for (int j=0; j<20; j++){
        mvwprintw(gridBorder, 45+j, 85, "||");
        mvwprintw(gridBorder, 45+j, 140, "||");
    }

    // second Hrow
    for (int row1=0; row1<140; row1++){
        mvwprintw(gridBorder, 45, 45+row1, "=");
    }


    refresh();

    wrefresh(gridBorder);


}

void printPlayerDeck(struct Player player){
    mvwprintw(stdscr, 5, 10, "Player 1's Deck:");
    mvwprintw(stdscr, 6, 10, "[]");
    mvwprintw(stdscr, 6, 13, "[]");
    mvwprintw(stdscr, 6, 16, "[]");
    mvwprintw(stdscr, 6, 19, "[]");
    mvwprintw(stdscr, 6, 22, "[]");

    mvwprintw(stdscr, 8, 15, "Player points: %d", player.points);
}