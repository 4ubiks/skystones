// c includes
#include "ncurses.h"

// custom includes
#include "board.h"
#include "skyfuncs.h"

char setPiece(struct Board *board, int pieceNumber){

    if (board->boardPieceIsPresent[pieceNumber] != '1'){
        board->boardPieceIsPresent[pieceNumber] = '1';
        board->piecesPlayed++;       
    }
    else {
        mvwprintw(stdscr, 40, 15, "Piece already exists here.");
    }
    //board.piece
   

    return '1';
}

int calculateCellNumber(int x, int y){
    return (y*3 + x);
}

char gameIsOver(struct Board *board){
    for (int cell=0; cell<9; cell++){
        if (board->piecesPlayed == 9){
            return 1;
        }
    }
    return 0;
}

int toggleTurn(int turn){
    turn *= -1;

    if (turn > 0){
        mvwprintw(stdscr, 50, 15, "player 1's turn");
    }
    else{
        mvwprintw(stdscr, 50, 15, "player 2's turn");
    }
    mvwprintw(stdscr, 52, 16, "%d", turn);

    return turn;
}