// c includes
#include "ncurses.h"

// custom includes
#include "board.h"
#include "player.h"
#include "skyfuncs.h"
#include "skyinit.h"

char setPiece(struct Board *board, int pieceNumber, int turn){

    if (pieceStatus(*board, pieceNumber) != '1'){
        board->boardPieceIsPresent[pieceNumber] = '1';
        if (turn > 0){
            board->boardPiecePlayer[pieceNumber] = '1';
        }
        else
            board->boardPiecePlayer[pieceNumber] = '2';
        board->piecesPlayed++;       
    }
    else {
        mvwprintw(stdscr, 40, 15, "Piece already exists here.");
    }

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
        mvwprintw(stdscr, 50, 15, "Player 1");
    }
    else{
        mvwprintw(stdscr, 50, 15, "Player 2");
    }

    return turn;
}

void selectPlayerColor(int tmp_x, int tmp_y, WINDOW* newPieceWindow1, WINDOW* newPieceWindow2, struct Board board, int piece_count){
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
}

int playerScore(struct Board board){
    int tmpScore=0;
    for (int piece=0; piece<9; piece++){
        if (board.boardPiecePlayer[piece] == '1'){
            tmpScore++;
        }
    }

    return tmpScore;
}