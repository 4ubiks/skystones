// C libraries
#include "stdio.h"
#include "ncurses.h"

// Custom files
#include "player.h"
#include "stone.h"
#include "skyprint.h"

int main(){
    initscr();
    noecho();
    cbreak();

    keypad(stdscr, TRUE);
    curs_set(1); // cursor appearance: 0 invisible, 1 normal, 2strong
    printBoard();

    if (has_colors() == FALSE){
        endwin();
        printf("bad terminal\n");
        return 1;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    attron(COLOR_PAIR(1));

    int y, x;
    getmaxyx(stdscr, y, x);
    y = y*0.5;
    x = (x*0.5) -6;
    mvwprintw(stdscr, y, x, "Game board");
    mvwprintw(stdscr, 2, 2, "Skystones-C");

    struct Player p1;

    printPlayerDeck(p1);

    while (true){
        int ch = getch();
        switch(ch) {
            case KEY_UP:    y--; break;
            case KEY_DOWN:  y++; break;
            case KEY_LEFT:  x--; break;
            case KEY_RIGHT: x++; break;
        }

        wmove(stdscr, y, x);
    }

    refresh();

    attroff(COLOR_PAIR(1));

    getch();

    endwin();


    return 0;
}