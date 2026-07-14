// c libraries
#include "stdio.h"
#include "string.h"
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
void printBoardPieces(struct Board board, int turn, char* piecePlayed, struct Pieces *boardPieceCharacteristics){
    int tmp_x = 52;
    int tmp_y = 8;

    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    /*
    I need nine piece windows. This will be an irritating overhaul, but it'll simplify everything a lot once it's completed. 

    Action is called nine times. Each function call increments the x, y coordinates to create each WINDOW* object in a different location. 
    
    I am *not* looping this. It's nine calls, I can justify hard-coding it here, because I need to ensure each piece window does not
    call the same pointer that points to the same character array.
    */

    WINDOW* pieceBoardArray[9];

    int piece_count = 0;

    int x=0;
    int y=0;

    // piece spike numbers
    int piece_a = 0;
    int piece_b = 0;
    int piece_c = 0;
    int piece_d = 0;

    for (int piece_row=0; piece_row<3; piece_row++){
        for (int piece_col=0; piece_col<3; piece_col++){
            pieceBoardArray[piece_count] = newwin(15, 25, tmp_y, tmp_x);

            if (board.boardPieceIsPresent[piece_count] == '1'){
                assignPieceNames(boardPieceCharacteristics, (piece_row*3)+piece_col, piecePlayed);
                selectPlayerColor(tmp_x, tmp_y, pieceBoardArray[piece_count], board, piece_count, boardPieceCharacteristics->pieces[piece_count]);
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

// prints individual piece information (name, graphic, spikes)
void printBoardPieceContent(struct Board board){
    
}

void printPieceCoordinates(int grid_x, int grid_y){
    mvwprintw(stdscr, 10, 10, "(%d, ", grid_x);
    mvwprintw(stdscr, 10, 14, "%d)", grid_y);  
}

void printPlayerDeck(struct Player player, struct Pieces deckPieces){

    WINDOW* playerDeckBorder = newwin(56, 20, 8, 10);
    wborder(playerDeckBorder, '|', '|', '-', '-', '-', '-', '-', '-');
    int deckPiece=0;
    for (int deckWall=0; deckWall < 55; deckWall+=11){
        mvwprintw(playerDeckBorder, deckWall, 0, "--------------------");
        pickDeckSkystone(playerDeckBorder, deckWall, deckPieces, player.stones[deckPiece]);
        deckPiece++;
    }

    refresh();
    wrefresh(playerDeckBorder);
}

void printPieceSpikes(WINDOW* spikesToPrint, char* itemToPrint){
    if (strcmp(itemToPrint, "GRENADE") == 0){
        // grenade
    }
    else if (strcmp(itemToPrint, "ARKEYAN") == 0){
        // arkeyan
    }
    else if (strcmp(itemToPrint, "ROOT") == 0){
        // root
    }
    else if (strcmp(itemToPrint, "CRYSTAL") == 0){
        // crystal
    }
    else if (strcmp(itemToPrint, "BLAZE") == 0){
        // blaze brewer
    }
    else if (strcmp(itemToPrint, "CONQUERTRON") == 0){
        // conquertron
    }
    else if (strcmp(itemToPrint, "DRAGONET") == 0){
        // dragonet
    }
    else if (strcmp(itemToPrint, "D-RIVET") == 0){
        // d-rivet
    }
}

void enterPiece(int x, int y){

    // signify that piece X, Y has been taken. 
    WINDOW *enterPiece = newwin(15, 25, x, y);
    box(enterPiece, 0, 0);
    wborder(enterPiece, '<', '>', 206, 206, '+', '+', '+', '+');

    refresh();
    wrefresh(enterPiece);
}