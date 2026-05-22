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
    int grid_x, grid_y = 0;
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

    grid_x = 0;
    grid_y = 0;

    while (true){
        int pressedKey = getch();

        
        switch(pressedKey) {
            case KEY_UP:    y-=20; grid_y--; break;
            case KEY_DOWN:  y+=20; grid_y++; break;
            case KEY_LEFT:  x-=50; grid_x--; break;
            case KEY_RIGHT: x+=50; grid_x++; break;

            case 10: enterPiece(x, y); break;
        }

        if (grid_y == 3){
            grid_y = 2;
            y-=20;
        }
        else if (grid_y == -1){
            grid_y = 0;
            y+=20;
        }

        if (grid_x == 3){
            grid_x = 2;
            x-=50;
        }
        else if (grid_x == -1){
            grid_x = 0;
            x+=50;
        }

        printPieceCoordinates(grid_x, grid_y);

        werase(gridSelection);
        wrefresh(gridSelection);

        gridSelection = newwin(15, 25, y, x);
        box(gridSelection, 0, 0);
        wmove(gridSelection, y, x);

        //refresh();
        wrefresh(gridSelection);
    }

    refresh();

    attroff(COLOR_PAIR(1));

    getch();

    endwin();


    return 0;
}