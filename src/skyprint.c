// c libraries
#include "stdio.h"
#include "ncurses.h"

// custom files
#include "player.h"
#include "constants.h"
#include "pieces.h"
#include "board.h"
#include "skyprint.h"
#include "skyfuncs.h"


void printBlankBoard(){

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

// prints all entries where a piece exists
void printFullBoard(struct Board board, int turn){
    int tmp_x = 52;
    int tmp_y = 8;

    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);


    int piece_count = 0;
    for (int piece_row=0; piece_row<3; piece_row++){
        for (int piece_col=0; piece_col<3; piece_col++){
            WINDOW* newPieceWindow1 = newwin(15, 25, tmp_y, tmp_x);
            WINDOW* newPieceWindow2 = newwin(15, 25, tmp_y, tmp_x);

            if (board.boardPieceIsPresent[piece_count] == '1'){
                selectPlayerColor(tmp_x, tmp_y, newPieceWindow1, newPieceWindow2, board, piece_count);
            }
            piece_count++;
            tmp_x+=50;
        }
        tmp_x = 52;
        tmp_y+=20;
    }
}

void printPieceCoordinates(int grid_x, int grid_y){
    mvwprintw(stdscr, 10, 10, "(%d, ", grid_x);
    mvwprintw(stdscr, 10, 14, "%d)", grid_y);  
}

void printPlayerDeck(struct Player player, struct Pieces deckPieces){

    WINDOW* playerDeckBorder = newwin(56, 20, 8, 10);
    wborder(playerDeckBorder, '|', '|', '-', '-', '-', '-', '-', '-');
    for (int deckWall=0; deckWall < 55; deckWall+=11){
        mvwprintw(playerDeckBorder, deckWall, 0, "--------------------");
        for (int y_graphic=0; y_graphic<6; y_graphic++){
            mvwprintw(playerDeckBorder, deckWall+y_graphic+1, 2, (char *)deckPieces.deck_arkeyan_bomber[y_graphic]);
        }
    }

    refresh();
    wrefresh(playerDeckBorder);
}

void enterPiece(int x, int y){

    // signify that piece X, Y has been taken. 
    WINDOW *enterPiece = newwin(15, 25, x, y);
    box(enterPiece, 0, 0);
    wborder(enterPiece, '<', '>', 206, 206, '+', '+', '+', '+');

    refresh();
    wrefresh(enterPiece);
}