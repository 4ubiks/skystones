// c libraries
#include "stdio.h"
#include "string.h"
#include "ncurses.h"

// custom files
#include "player.h"
#include "constants.h"
#include "pieceInfo.h"
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
void printBoardPieces(struct Board board, char* piecePlayed, struct PieceInfo *boardPieceCharacteristics, int pieceNumber){
    int tmp_x = 52;
    int tmp_y = 8;

    // Player 1
    init_pair(2, COLOR_RED, COLOR_BLACK);

    // Player 2
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    /*
    I need nine piece windows. This will be an irritating overhaul, but it'll simplify everything a lot once it's completed. 

    Action is called nine times. Each function call increments the x, y coordinates to create each WINDOW* object in a different location. 
    
    pieceArray[9]
    -> spikeArray[4]

    for (all pieceArray elemnts){
        for (all spikeArray elements){
            print(spikes)
        }
    }

    */

    WINDOW* pieceBoardArray[9];
    char* piecesPlayed[20] = {"Default\0"};

    int piece_count = 0;

    int x=0;
    int y=0;

    piecesPlayed[pieceNumber] = piecePlayed; 

    for (int piece_row=0; piece_row<3; piece_row++){
        for (int piece_col=0; piece_col<3; piece_col++){
            pieceBoardArray[piece_count] = newwin(15, 25, tmp_y, tmp_x);

            if (board.boardPieceIsPresent[piece_count] == '1'){
                assignPieceNames(boardPieceCharacteristics, (piece_row*3)+piece_col, piecePlayed);
                selectPlayerColor(pieceBoardArray[piece_count], board, piece_count, boardPieceCharacteristics->pieces[piece_count]);

                // ensure piecesPlayed[piece_count] exists, AND if it's been assigned
                if (piecesPlayed[piece_count] != NULL){
                    selectPieceNumbers(pieceBoardArray[piece_count], boardPieceCharacteristics, piecesPlayed[piece_count]);
                }

                refresh();
                wrefresh(pieceBoardArray[piece_count]);
            }

            piece_count++;
            tmp_x+=50;
            x++;
        }
        tmp_x = 52;
        tmp_y+=20;
        y++;
    }
}

void printPieceCoordinates(int grid_x, int grid_y){
    mvwprintw(stdscr, 10, 10, "(%d, ", grid_x);
    mvwprintw(stdscr, 10, 14, "%d)", grid_y);  
}

void printPlayerDeck(struct Player player){

    WINDOW* playerDeckBorder = newwin(56, 20, 8, 10);
    wborder(playerDeckBorder, '|', '|', '-', '-', '-', '-', '-', '-');
    int deckPiece=0;
    for (int deckWall=0; deckWall < 55; deckWall+=11){
        mvwprintw(playerDeckBorder, deckWall, 0, "--------------------");
        pickDeckSkystone(playerDeckBorder, deckWall, player.stones[deckPiece]);
        deckPiece++;
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