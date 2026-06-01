// c includes
#include "ncurses.h"

// custom includes
#include "board.h"
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

void selectPlayerColor(int turn, int tmp_x, int tmp_y, WINDOW* newPieceWindow, struct Board board){
    if (turn > 0){
        init_pair(2, COLOR_RED, COLOR_BLACK);
        wbkgd(newPieceWindow, COLOR_PAIR(2));
    }
    else{
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
        wbkgd(newPieceWindow, COLOR_PAIR(3));
    }


    mvwin(newPieceWindow, tmp_y, tmp_x);
    wborder(newPieceWindow, '<', '>', 206, 206, '+', '+', '+', '+');

    refresh();
    wrefresh(newPieceWindow);
}