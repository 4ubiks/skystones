// c includes
#include "ncurses.h"
#include "string.h"

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

void selectPlayerColor(WINDOW* newPieceWindow1, struct Board board, int piece_count, const char* piecePlayed){
    if (board.boardPiecePlayer[piece_count] == '1') {
        wbkgd(newPieceWindow1, COLOR_PAIR(2));
    }   
    else {
        wbkgd(newPieceWindow1, COLOR_PAIR(3));
    }
    
    wborder(newPieceWindow1, '<', '>', 206, 206, '+', '+', '+', '+');
    mvwprintw(newPieceWindow1, 5, 5, piecePlayed);
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

void pickDeckSkystone(WINDOW* currentPieceWindow, int deckWall, int deckPiece){
    switch (deckPiece){
        case GRENADE_GENERAL:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "GRENADE");
            break;

        case ARKEYAN_BOMBER:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "ARKEYAN");
            break;

        case ROOT_RUNNER:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "ROOT");
            break;

        case CRYSTAL_GOLEM:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "CRYSTAL");
            break;

        case BLAZE_BREWER:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "BLAZE");
            break;

        case CONQUERTRON:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "CONQUERTRON");
            break;

        case DRAGONET:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "DRAGONET");
            break;

        case D_RIVETER:
            mvwprintw(currentPieceWindow, deckWall+2, 2, "D-RIVET");
            break;
        
            case PIECE_PLAYED:
                break;


    }
}

char* setDeckPieceName(int selectedPiece){
    switch (selectedPiece){
        case GRENADE_GENERAL:
            return "Grenade General\0";

        case ARKEYAN_BOMBER:
            return "Arkeyan Bomber\0";

        case ROOT_RUNNER:
            return "Root Runner\0";

        case CRYSTAL_GOLEM:
            return "Crystal Golem\0";

        case BLAZE_BREWER:
            return "Blaze Brewer\0";

        case CONQUERTRON:
            return "Conquertron\0";

        case DRAGONET:
            return "Dragonet\0";

        case D_RIVETER:
            return "D-Riveter\0";
        
        case PIECE_PLAYED:
            return 0x0;
    }

    return 0;
}

void assignPieceNames(struct Pieces *boardPieces, int thePieceNumberPlayed, char* pieceName){
    if (boardPieces->pieceAssignment[thePieceNumberPlayed] != 1){
        boardPieces->pieces[thePieceNumberPlayed] = pieceName;
        boardPieces->pieceAssignment[thePieceNumberPlayed] = 1;
    }
}

void selectPieceNumbers(WINDOW* pieceWindow, struct Pieces *pieces, char* piecePlayed){
    if (strcmp(piecePlayed, "Grenade General") == 0){
        mvwprintw(pieceWindow, 7, 8, "%s", pieces->GRENADE_GENERAL_A);
        mvwprintw(pieceWindow, 8, 10, "%s", pieces->GRENADE_GENERAL_B);
        mvwprintw(pieceWindow, 9, 8, "%s", pieces->GRENADE_GENERAL_C);
        mvwprintw(pieceWindow, 8, 6, "%s", pieces->GRENADE_GENERAL_D);
    }
    else if (strcmp(piecePlayed, "Arkeyan Bomber") == 0){
        mvwprintw(pieceWindow, 7, 8, "%s", pieces->ARKEYAN_BOMBER_A);
        mvwprintw(pieceWindow, 8, 10, "%s", pieces->ARKEYAN_BOMBER_B);
        mvwprintw(pieceWindow, 9, 8, "%s", pieces->ARKEYAN_BOMBER_C);
        mvwprintw(pieceWindow, 8, 6, "%s", pieces->ARKEYAN_BOMBER_D);
    }
    else if (strcmp(piecePlayed, "Root Runner") == 0){
        mvwprintw(pieceWindow, 7, 8, "%s", pieces->ROOT_RUNNER_A);
        mvwprintw(pieceWindow, 8, 10, "%s", pieces->ROOT_RUNNER_B);
        mvwprintw(pieceWindow, 9, 8, "%s", pieces->ROOT_RUNNER_C);
        mvwprintw(pieceWindow, 8, 6, "%s", pieces->ROOT_RUNNER_D);
    }
    else if (strcmp(piecePlayed, "Crystal Golem") == 0){
        mvwprintw(pieceWindow, 7, 8, "%s", pieces->CRYSTAL_GOLEM_A);
        mvwprintw(pieceWindow, 8, 10, "%s", pieces->CRYSTAL_GOLEM_B);
        mvwprintw(pieceWindow, 9, 8, "%s", pieces->CRYSTAL_GOLEM_C);
        mvwprintw(pieceWindow, 8, 6, "%s", pieces->CRYSTAL_GOLEM_D);
    }
    else if (strcmp(piecePlayed, "Blaze Brewer") == 0){
        mvwprintw(pieceWindow, 7, 8, "%s", pieces->BLAZE_BREWER_A);
        mvwprintw(pieceWindow, 8, 10, "%s", pieces->BLAZE_BREWER_B);
        mvwprintw(pieceWindow, 9, 8, "%s", pieces->BLAZE_BREWER_C);
        mvwprintw(pieceWindow, 8, 6, "%s", pieces->BLAZE_BREWER_D);
    }
    else if (strcmp(piecePlayed, "Conquertron") == 0){
        mvwprintw(pieceWindow, 7, 8, "%s", pieces->CONQUERTRON_A);
        mvwprintw(pieceWindow, 8, 10, "%s", pieces->CONQUERTRON_B);
        mvwprintw(pieceWindow, 9, 8, "%s", pieces->CONQUERTRON_C);
        mvwprintw(pieceWindow, 8, 6, "%s", pieces->CONQUERTRON_D);
    }
    else if (strcmp(piecePlayed, "Dragonet") == 0){
        mvwprintw(pieceWindow, 7, 8, "%s", pieces->DRAGONET_A);
        mvwprintw(pieceWindow, 8, 10, "%s", pieces->DRAGONET_B);
        mvwprintw(pieceWindow, 9, 8, "%s", pieces->DRAGONET_C);
        mvwprintw(pieceWindow, 8, 6, "%s", pieces->DRAGONET_D);
    }
    else if (strcmp(piecePlayed, "D-Riveter") == 0){
        mvwprintw(pieceWindow, 7, 8, "%s", pieces->D_RIVETER_A);
        mvwprintw(pieceWindow, 8, 10, "%s", pieces->D_RIVETER_B);
        mvwprintw(pieceWindow, 9, 8, "%s", pieces->D_RIVETER_C);
        mvwprintw(pieceWindow, 8, 6, "%s", pieces->D_RIVETER_D);
    }
    else {
        mvwprintw(pieceWindow, 7, 8, "0");
        mvwprintw(pieceWindow, 8, 10, "0");
        mvwprintw(pieceWindow, 8, 6, "0");
        mvwprintw(pieceWindow, 9, 8, "0");
    }

    refresh();
    wrefresh(pieceWindow);
}