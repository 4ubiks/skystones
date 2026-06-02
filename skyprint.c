// c libraries
#include "stdio.h"
#include "ncurses.h"

// custom files
#include "player.h"
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
            if (board.boardPieceIsPresent[piece_count] == '1'){

                WINDOW* newPieceWindow1 = newwin(15, 25, tmp_y, tmp_x);
                WINDOW* newPieceWindow2 = newwin(15, 25, tmp_y, tmp_x);
                if (board.boardPiecePlayer[piece_count] == '1'){
                    wbkgd(newPieceWindow1, COLOR_PAIR(2));
                    wborder(newPieceWindow1, '<', '>', 206, 206, '+', '+', '+', '+');
                }
                else{
                    wbkgd(newPieceWindow2, COLOR_PAIR(3));
                    wborder(newPieceWindow2, '<', '>', 206, 206, '+', '+', '+', '+');
                }

                refresh();

                if (board.boardPiecePlayer[piece_count] == '1'){
                    wrefresh(newPieceWindow1);
                }
                else{
                    wrefresh(newPieceWindow2);
                }
                //selectPlayerColor(turn, tmp_x, tmp_y, newPieceWindow1, board);
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

void printPlayerDeck(struct Player player){
    mvwprintw(stdscr, 5, 10, "Player 1's Deck:");
    mvwprintw(stdscr, 6, 10, "[]");
    mvwprintw(stdscr, 6, 13, "[]");
    mvwprintw(stdscr, 6, 16, "[]");
    mvwprintw(stdscr, 6, 19, "[]");
    mvwprintw(stdscr, 6, 22, "[]");

    mvwprintw(stdscr, 8, 15, "Player points: %d", player.points);
}

void enterPiece(int x, int y){

    // signify that piece X, Y has been taken. 
    WINDOW *enterPiece = newwin(15, 25, x, y);
    box(enterPiece, 0, 0);
    wborder(enterPiece, '<', '>', 206, 206, '+', '+', '+', '+');
    mvwprintw(enterPiece, 35, 35, "CTRL SHIFT ALT PRESS ENTER");

    refresh();
    wrefresh(enterPiece);
}