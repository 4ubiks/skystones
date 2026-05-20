// C libraries
#include "stdio.h"
#include "ncurses.h"

// Custom files
#include "constants.h"
#include "player.h"
#include "stone.h"
#include "skyprint.h"
#include "skyinit.h"

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
    p1 = initializePlayer(p1);

    WINDOW *gridSelection = newwin(15, 25, 8, 52);
    box(gridSelection, 0, 0);

    wattron(gridSelection, A_REVERSE);

    refresh();

    wrefresh(gridSelection);

    printPlayerDeck(p1);

    y=8;
    x=52;

    while (true){
        int ch = getch();
        switch(ch) {
            case KEY_UP:    y-=20; break;
            case KEY_DOWN:  y+=20; break;
            case KEY_LEFT:  x-=50; break;
            case KEY_RIGHT: x+=50; break;
        }

        werase(gridSelection);
        wrefresh(gridSelection);

        gridSelection = newwin(15, 25, y, x);
        box(gridSelection, 0, 0);
        wmove(gridSelection, y, x);

        refresh();
        wrefresh(gridSelection);
    }

    refresh();

    attroff(COLOR_PAIR(1));

    getch();

    endwin();


    return 0;
}