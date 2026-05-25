// c includes

// custom includes
#include "board.h"
#include "skyfuncs.h"

char setPiece(struct Board *board, int pieceNumber){
    //board.piece
   board->boardPieceIsPresent[pieceNumber] = '1';

    return '1';
}