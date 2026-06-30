// c includes
#include "ncurses.h"

// custom includes
#include "board.h"
#include "constants.h"
#include "pieces.h"
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

void selectPlayerColor(int tmp_x, int tmp_y, WINDOW* newPieceWindow1, WINDOW* newPieceWindow2, struct Board board, int piece_count, const char* piecePlayed){
    if (board.boardPiecePlayer[piece_count] == '1') {
        wbkgd(newPieceWindow1, COLOR_PAIR(2));
        wborder(newPieceWindow1, '<', '>', 206, 206, '+', '+', '+', '+');
        mvwprintw(newPieceWindow1, 5, 5, piecePlayed);
    }
    else {
        wbkgd(newPieceWindow2, COLOR_PAIR(3));
        wborder(newPieceWindow2, '<', '>', 206, 206, '+', '+', '+', '+');
        mvwprintw(newPieceWindow2, 5, 5, piecePlayed);
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

void pickDeckSkystone(WINDOW* currentPieceWindow, int deckWall, struct Pieces pieces, int deckPiece){
    switch (deckPiece){
        case GRENADE_GENERAL:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "GRENADE");
            // for (int pieceRow=0; pieceRow<6; pieceRow++){
            //     mvwprintw(currentPieceWindow, deckWall+pieceRow+1, 2, pieces.deck_grenade_general[pieceRow]);
            // }
            break;

        case ARKEYAN_BOMBER:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "ARKEYAN");
            // for (int pieceRow=0; pieceRow<6; pieceRow++){
            //     mvwprintw(currentPieceWindow, deckWall+pieceRow+1, 2, pieces.deck_arkeyan_bomber[pieceRow]);
            // }
            break;

        case ROOT_RUNNER:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "ROOT");
            // for (int pieceRow=0; pieceRow<6; pieceRow++){
            //     mvwprintw(currentPieceWindow, deckWall+pieceRow+1, 2, pieces.deck_root_runner[pieceRow]);
            // }
            break;

        case CRYSTAL_GOLEM:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "CRYSTAL");
            // for (int pieceRow=0; pieceRow<6; pieceRow++){
            //     mvwprintw(currentPieceWindow, deckWall+pieceRow+1, 2, pieces.deck_crystal_golem[pieceRow]);
            // }
            break;

        case BLAZE_BREWER:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "BLAZE");
            // for (int pieceRow=0; pieceRow<6; pieceRow++){
            //     mvwprintw(currentPieceWindow, deckWall+pieceRow+1, 2, pieces.deck_blaze_brewer[pieceRow]);
            // }
            break;

        case CONQUERTRON:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "CONQUERTRON");
            // for (int pieceRow=0; pieceRow<6; pieceRow++){
            //     mvwprintw(currentPieceWindow, deckWall+pieceRow+1, 2, pieces.deck_conquertron[pieceRow]);
            // }
            break;

        case DRAGONET:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "DRAGONET");
            // for (int pieceRow=0; pieceRow<6; pieceRow++){
            //     mvwprintw(currentPieceWindow, deckWall+pieceRow+1, 2, pieces.deck_dragonet[pieceRow]);
            // }
            break;

        case D_RIVETER:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "D-RIVET");
            // for (int pieceRow=0; pieceRow<6; pieceRow++){
            //     mvwprintw(currentPieceWindow, deckWall+pieceRow+1, 2, pieces.deck_d_riveter[pieceRow]);
            // }
            break;
        
            case PIECE_PLAYED:
                break;


    }
}

char* setDeckPieceName(int selectedPiece){
    switch (selectedPiece){
        case GRENADE_GENERAL:
            return "Grenade General";

        case ARKEYAN_BOMBER:
            return "Arkeyan Bomber";

        case ROOT_RUNNER:
            return "Root Runner";

        case CRYSTAL_GOLEM:
            return "Crystal Golem";

        case BLAZE_BREWER:
            return "Blaze Brewer";

        case CONQUERTRON:
            return "Conquertron";

        case DRAGONET:
            return "Dragonet";

        case D_RIVETER:
            return "D-Riveter";
        
        case PIECE_PLAYED:
            return 0x0;
    }

    return 0;
}