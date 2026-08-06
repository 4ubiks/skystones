// c includes
#include "ncurses.h"
#include "string.h"

// custom includes
#include "board.h"
#include "constants.h"
#include "pieceInfo.h"
#include "pieceSpikes.h"
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
    if (board->piecesPlayed == 17){
        return '1';
    }
    return '0';
}

int toggleTurn(int turn){
    turn *= -1;

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

void pickDeckSkystone(WINDOW* currentPieceWindow, int deckWall, int deckPiece, struct PieceInfo pieceSpikeInfo){
    switch (deckPiece){
        case GRENADE_GENERAL:
            mvwprintw(currentPieceWindow, deckWall+2, 6, "GRENADE");
            mvwprintw(currentPieceWindow, deckWall+3, 7, "%d\0", pieceSpikeInfo.GRENADE_GENERAL_A);
            mvwprintw(currentPieceWindow, deckWall+4, 8, "%d\0", pieceSpikeInfo.GRENADE_GENERAL_B);
            mvwprintw(currentPieceWindow, deckWall+5, 7, "%d\0", pieceSpikeInfo.GRENADE_GENERAL_C);
            mvwprintw(currentPieceWindow, deckWall+4, 6, "%d\0", pieceSpikeInfo.GRENADE_GENERAL_D);
            break;

        case ARKEYAN_BOMBER:
            mvwprintw(currentPieceWindow, deckWall+2, 6, "ARKEYAN");
            mvwprintw(currentPieceWindow, deckWall+3, 8, "%d\0", pieceSpikeInfo.ARKEYAN_BOMBER_A);
            mvwprintw(currentPieceWindow, deckWall+4, 9, "%d\0", pieceSpikeInfo.ARKEYAN_BOMBER_B);
            mvwprintw(currentPieceWindow, deckWall+5, 8, "%d\0", pieceSpikeInfo.ARKEYAN_BOMBER_C);
            mvwprintw(currentPieceWindow, deckWall+4, 7, "%d\0", pieceSpikeInfo.ARKEYAN_BOMBER_D);
            break;

        case ROOT_RUNNER:
            mvwprintw(currentPieceWindow, deckWall+2, 8, "ROOT");
            mvwprintw(currentPieceWindow, deckWall+3, 8, "%d\0", pieceSpikeInfo.ROOT_RUNNER_A);
            mvwprintw(currentPieceWindow, deckWall+4, 9, "%d\0", pieceSpikeInfo.ROOT_RUNNER_B);
            mvwprintw(currentPieceWindow, deckWall+5, 8,  "%d\0", pieceSpikeInfo.ROOT_RUNNER_C);
            mvwprintw(currentPieceWindow, deckWall+4, 7, "%d\0", pieceSpikeInfo.ROOT_RUNNER_D);
            break;

        case CRYSTAL_GOLEM:
            mvwprintw(currentPieceWindow, deckWall+2, 6, "CRYSTAL");
            mvwprintw(currentPieceWindow, deckWall+3, 8, "%d\0", pieceSpikeInfo.CRYSTAL_GOLEM_A);
            mvwprintw(currentPieceWindow, deckWall+4, 9, "%d\0", pieceSpikeInfo.CRYSTAL_GOLEM_B);
            mvwprintw(currentPieceWindow, deckWall+5, 8, "%d\0", pieceSpikeInfo.CRYSTAL_GOLEM_C);
            mvwprintw(currentPieceWindow, deckWall+4, 7, "%d\0", pieceSpikeInfo.CRYSTAL_GOLEM_D);
            break;

        case BLAZE_BREWER:
            mvwprintw(currentPieceWindow, deckWall+2, 7, "BLAZE");
            mvwprintw(currentPieceWindow, deckWall+3, 8, "%d\0", pieceSpikeInfo.BLAZE_BREWER_A);
            mvwprintw(currentPieceWindow, deckWall+4, 9, "%d\0", pieceSpikeInfo.BLAZE_BREWER_B);
            mvwprintw(currentPieceWindow, deckWall+5, 8, "%d\0", pieceSpikeInfo.BLAZE_BREWER_C);
            mvwprintw(currentPieceWindow, deckWall+4, 7, "%d\0", pieceSpikeInfo.BLAZE_BREWER_D);
            break;

        case CONQUERTRON:
            mvwprintw(currentPieceWindow, deckWall+2, 3, "CONQUERTRON");
            mvwprintw(currentPieceWindow, deckWall+3, 8, "%d\0", pieceSpikeInfo.CONQUERTRON_A);
            mvwprintw(currentPieceWindow, deckWall+4, 9, "%d\0", pieceSpikeInfo.CONQUERTRON_B);
            mvwprintw(currentPieceWindow, deckWall+5, 8, "%d\0", pieceSpikeInfo.CONQUERTRON_C);
            mvwprintw(currentPieceWindow, deckWall+4, 7, "%d\0", pieceSpikeInfo.CONQUERTRON_D);
            break;

        case DRAGONET:
            mvwprintw(currentPieceWindow, deckWall+2, 5, "DRAGONET");
            mvwprintw(currentPieceWindow, deckWall+3, 8, "%d\0", pieceSpikeInfo.DRAGONET_A);
            mvwprintw(currentPieceWindow, deckWall+4, 9, "%d\0", pieceSpikeInfo.DRAGONET_B);
            mvwprintw(currentPieceWindow, deckWall+5, 8, "%d\0", pieceSpikeInfo.DRAGONET_C);
            mvwprintw(currentPieceWindow, deckWall+4, 7, "%d\0", pieceSpikeInfo.DRAGONET_D);
            break;

        case D_RIVETER:
            mvwprintw(currentPieceWindow, deckWall+2, 6, "D-RIVET");
            mvwprintw(currentPieceWindow, deckWall+3, 8, "%d\0", pieceSpikeInfo.D_RIVETER_A);
            mvwprintw(currentPieceWindow, deckWall+4, 9, "%d\0", pieceSpikeInfo.D_RIVETER_B);
            mvwprintw(currentPieceWindow, deckWall+5, 8, "%d\0", pieceSpikeInfo.D_RIVETER_C);
            mvwprintw(currentPieceWindow, deckWall+4, 7, "%d\0", pieceSpikeInfo.D_RIVETER_D);
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

void assignPieceNames(struct PieceInfo *boardPieceInfo, int thePieceNumberPlayed, char* pieceName){
    if (boardPieceInfo->pieceAssignment[thePieceNumberPlayed] != 1){
        boardPieceInfo->pieces[thePieceNumberPlayed] = pieceName;
        boardPieceInfo->pieceAssignment[thePieceNumberPlayed] = 1;
    }
}

void selectPieceNumbers(WINDOW* pieceWindow, struct PieceInfo *pieces, char* piecePlayed, int spikes[]){
    if (strcmp(piecePlayed, "Grenade General") == 0){
        spikes[0] = pieces->GRENADE_GENERAL_A;
        spikes[1] = pieces->GRENADE_GENERAL_B;
        spikes[2] = pieces->GRENADE_GENERAL_C;
        spikes[3] = pieces->GRENADE_GENERAL_D;
    }
    else if (strcmp(piecePlayed, "Arkeyan Bomber") == 0){
        spikes[0] = pieces->ARKEYAN_BOMBER_A;
        spikes[1] = pieces->ARKEYAN_BOMBER_B;
        spikes[2] = pieces->ARKEYAN_BOMBER_C;
        spikes[3] = pieces->ARKEYAN_BOMBER_D;
    }
    else if (strcmp(piecePlayed, "Root Runner") == 0){
        spikes[0] = pieces->ROOT_RUNNER_A;
        spikes[1] = pieces->ROOT_RUNNER_B;
        spikes[2] = pieces->ROOT_RUNNER_C;
        spikes[3] = pieces->ROOT_RUNNER_D;
    }
    else if (strcmp(piecePlayed, "Crystal Golem") == 0){
        spikes[0] = pieces->CRYSTAL_GOLEM_A;
        spikes[1] = pieces->CRYSTAL_GOLEM_B;
        spikes[2] = pieces->CRYSTAL_GOLEM_C;
        spikes[3] = pieces->CRYSTAL_GOLEM_D;
    }
    else if (strcmp(piecePlayed, "Blaze Brewer") == 0){
        spikes[0] = pieces->BLAZE_BREWER_A;
        spikes[1] = pieces->BLAZE_BREWER_B;
        spikes[2] = pieces->BLAZE_BREWER_C;
        spikes[3] = pieces->BLAZE_BREWER_D;
    }
    else if (strcmp(piecePlayed, "Conquertron") == 0){
        spikes[0] = pieces->CONQUERTRON_A;
        spikes[1] = pieces->CONQUERTRON_B;
        spikes[2] = pieces->CONQUERTRON_C;
        spikes[3] = pieces->CONQUERTRON_D;
    }
    else if (strcmp(piecePlayed, "Dragonet") == 0){
        spikes[0] = pieces->DRAGONET_A;
        spikes[1] = pieces->DRAGONET_B;
        spikes[2] = pieces->DRAGONET_C;
        spikes[3] = pieces->DRAGONET_D;
    }
    else if (strcmp(piecePlayed, "D-Riveter") == 0){
        spikes[0] = pieces->D_RIVETER_A;
        spikes[1] = pieces->D_RIVETER_B;
        spikes[2] = pieces->D_RIVETER_C;
        spikes[3] = pieces->D_RIVETER_D;
    }
}

void checkPiece(int pieceNum, struct PieceSpikes pieceSpikes[], struct Board *boardPieces) {
    // checks adjacent pieces and their spike counts...
    // if pieceNum == 1 then 
        // check spikePieceArrays[1].spike[3] and spikePieceArrays[3].[0]
        // that's spike D on piece 2 and spike A on piece 4 respectively. 

    // legit i think the easiest way to do this is brute force because it's overall so minimal. 

    // PLAYER 1: '1'
    // PLAYER 2: '0'

    int currentPlayer = boardPieces->boardPiecePlayer[pieceNum];

    switch (pieceNum){
        case 0:

            // check 
            // pieceSpikes[0].spikes[1]; 
            // pieceSpikes[1].spikes[3];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[1]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[1])){
                // compare
                comparePieces(pieceNum, 1, pieceSpikes[pieceNum].spikes[1], pieceSpikes[1].spikes[3], boardPieces);
            }

            // pieceSpikes[0].spikes[2];
            // pieceSpikes[3].spikes[0];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[3]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[3])){
                // compare
                comparePieces(pieceNum, 3, pieceSpikes[pieceNum].spikes[2], pieceSpikes[3].spikes[0], boardPieces);
            }

            break;
        
        case 1:

        // check 
            // pieceSpikes[1].spikes[3];
            // pieceSpikes[0].spikes[1];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[0]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[0])){
                // compare
                comparePieces(pieceNum, 0, pieceSpikes[pieceNum].spikes[3], pieceSpikes[0].spikes[1], boardPieces);
            }

            // pieceSpikes[1].spikes[2];
            // pieceSpikes[4].spikes[0];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[4]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[4])){
                // compare
                comparePieces(pieceNum, 4, pieceSpikes[pieceNum].spikes[2], pieceSpikes[4].spikes[0], boardPieces);
            }

            // pieceSpikes[1].spikes[1];
            // pieceSpikes[2].spikes[3];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[2]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[2])){
                // compare
                comparePieces(pieceNum, 2, pieceSpikes[pieceNum].spikes[1], pieceSpikes[2].spikes[3], boardPieces);
            }

            break;

        case 2:
            // pieceSpikes[2].spikes[3];
            // pieceSpikes[1].spikes[1];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[1]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[1])){
                comparePieces(pieceNum, 1, pieceSpikes[pieceNum].spikes[3], pieceSpikes[1].spikes[1], boardPieces);
            }

            // pieceSpikes[2].spikes[2];
            // pieceSpikes[5].spikes[0];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[5]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[5])){
                comparePieces(pieceNum, 5, pieceSpikes[pieceNum].spikes[2], pieceSpikes[5].spikes[0], boardPieces);
            }

            break;

        case 3:
            // pieceSpikes[3].spikes[0];
            // pieceSpikes[0].spikes[2];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[0]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[0])){
                comparePieces(pieceNum, 0, pieceSpikes[pieceNum].spikes[0], pieceSpikes[0].spikes[2], boardPieces);
            }

            // pieceSpikes[3].spikes[1];
            // pieceSpikes[4].spikes[3];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[4]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[4])){
                comparePieces(pieceNum, 4, pieceSpikes[pieceNum].spikes[1], pieceSpikes[4].spikes[3], boardPieces);
            }

            // pieceSpikes[3].spikes[2];
            // pieceSpikes[6].spikes[0];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[6]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[6])){
                comparePieces(pieceNum, 6, pieceSpikes[pieceNum].spikes[2], pieceSpikes[6].spikes[0], boardPieces);
            }

            break;

        case 4:
            // pieceSpikes[4].spikes[0];
            // pieceSpikes[1].spikes[2];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[1]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[1])){
                comparePieces(pieceNum, 1, pieceSpikes[pieceNum].spikes[0], pieceSpikes[1].spikes[2], boardPieces);
            }

            // pieceSpikes[4].spikes[1];
            // pieceSpikes[5].spikes[3];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[5]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[5])){
                comparePieces(pieceNum, 5, pieceSpikes[pieceNum].spikes[1], pieceSpikes[5].spikes[3], boardPieces);
            }

            // pieceSpikes[4].spikes[2];
            // pieceSpikes[7].spikes[0];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[7]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[7])){
                comparePieces(pieceNum, 7, pieceSpikes[pieceNum].spikes[2], pieceSpikes[7].spikes[0], boardPieces);
            }

            // pieceSpikes[4].spikes[3];
            // pieceSpikes[3].spikes[1];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[3]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[3])){
                comparePieces(pieceNum, 3, pieceSpikes[pieceNum].spikes[3], pieceSpikes[3].spikes[1], boardPieces);
            }
            break;

        case 5: 
            // pieceSpikes[5].spikes[0];
            // pieceSpikes[2].spikes[2];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[2]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[2])){
                comparePieces(pieceNum, 2, pieceSpikes[pieceNum].spikes[0], pieceSpikes[2].spikes[2], boardPieces);
            }

            // pieceSpikes[5].spikes[2];
            // pieceSpikes[8].spikes[0];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[8]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[8])){
                comparePieces(pieceNum, 8, pieceSpikes[pieceNum].spikes[2], pieceSpikes[8].spikes[0], boardPieces);
            }

            // pieceSpikes[5].spikes[3];
            // pieceSpikes[4].spikes[1];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[4]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[4])){
                comparePieces(pieceNum, 4, pieceSpikes[pieceNum].spikes[3], pieceSpikes[4].spikes[1], boardPieces);
            }
            break;

        case 6:
            // pieceSpikes[6].spikes[0];
            // pieceSpikes[3].spikes[2];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[3]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[3])){
                comparePieces(pieceNum, 3, pieceSpikes[pieceNum].spikes[0], pieceSpikes[3].spikes[2], boardPieces);
            }

            // pieceSpikes[6].spikes[1];
            // pieceSpikes[7].spikes[3];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[7]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[7])){
                comparePieces(pieceNum, 7, pieceSpikes[pieceNum].spikes[1], pieceSpikes[7].spikes[3], boardPieces);
            }
            break;

        case 7:
            // pieceSpikes[7].spikes[0];
            // pieceSpikes[4].spikes[2];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[4]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[4])){
                comparePieces(pieceNum, 4, pieceSpikes[pieceNum].spikes[0], pieceSpikes[4].spikes[2], boardPieces);
            }

            // pieceSpikes[7].spikes[1];
            // pieceSpikes[8].spikes[3];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[8]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[8])){
                comparePieces(pieceNum, 8, pieceSpikes[pieceNum].spikes[1], pieceSpikes[8].spikes[3], boardPieces);
            }

            // pieceSpikes[7].spikes[3];
            // pieceSpikes[6].spikes[1];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[6]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[6])){
                comparePieces(pieceNum, 6, pieceSpikes[pieceNum].spikes[3], pieceSpikes[6].spikes[1], boardPieces);
            }

            break;

        case 8:
            // pieceSpikes[8].spikes[0];
            // pieceSpikes[5].spikes[2];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[5]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[5])){
                comparePieces(pieceNum, 5, pieceSpikes[pieceNum].spikes[0], pieceSpikes[5].spikes[2], boardPieces);
            }

            // pieceSpikes[8].spikes[3];
            // pieceSpikes[7].spikes[1];
            if (checkPieceExists(boardPieces->boardPieceIsPresent[7]) && checkOppositePlayer(currentPlayer, boardPieces->boardPiecePlayer[7])){
                comparePieces(pieceNum, 7, pieceSpikes[pieceNum].spikes[3], pieceSpikes[7].spikes[1], boardPieces);
            }

            break;

        default:
            break;
    }
}

bool checkPieceExists(int piecePlayed){
    if (piecePlayed == '1'){
        return true;
    }

    return false;
}

bool checkOppositePlayer(int playedPlayer, int targetPlayer){
    if (playedPlayer != targetPlayer) {
        return true;
    }

    return false;
}

int comparePieces(int pieceNumPlayed, int pieceNumAdj, int playedSpike, int adjacentSpike, struct Board *boardPieces){
    mvwprintw(stdscr, DEBUG_Y, DEBUG_X, "inside comparePieces");
    mvwprintw(stdscr, DEBUG_Y + 1, DEBUG_X, "playedSpike from piece %d: %d", pieceNumPlayed, playedSpike);
    mvwprintw(stdscr, DEBUG_Y + 2, DEBUG_X, "adjacentSpike from piece %d: %d", pieceNumAdj, adjacentSpike);
    if (playedSpike > adjacentSpike){
        boardPieces->boardPiecePlayer[pieceNumAdj] = boardPieces->boardPiecePlayer[pieceNumPlayed];
        mvwprintw(stdscr, DEBUG_Y+3, DEBUG_X, "changed team bc winning");
    }
    else
        mvwprintw(stdscr, DEBUG_Y + 3, DEBUG_X, "no change happening rn,");

    return 0;
}