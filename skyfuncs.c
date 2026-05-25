// c includes
#include "ncurses.h"

// custom includes
#include "board.h"
#include "skyfuncs.h"

char setPiece(struct Board *board, int pieceNumber){
    //board.piece
    mvwprintw(stdscr, 20, 14, "setting piece number %d to 1", pieceNumber);
    board->boardPieceIsPresent[pieceNumber] = '1';

    return '1';
}