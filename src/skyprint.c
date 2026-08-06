// c libraries
#include "stdio.h"
#include "string.h"
#include "ncurses.h"

// custom files
#include "player.h"
#include "constants.h"
#include "pieceInfo.h"
#include "pieceSpikes.h"
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
void printBoardPieces(struct Board board, char* piecePlayed, struct PieceInfo *boardPieceCharacteristics, int pieceNumber, struct PieceSpikes pieceSpikes[]){
    int tmp_x = 52;
    int tmp_y = 8;

    // Player 1
    init_pair(2, COLOR_RED, COLOR_BLACK);

    // Player 2
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

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
                    selectPieceNumbers(pieceBoardArray[piece_count], boardPieceCharacteristics, piecesPlayed[piece_count], pieceSpikes[piece_count].spikes);
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

    // print spikes
    for (int structPieceCounter=0; structPieceCounter<9; structPieceCounter++){
        if (board.boardPieceIsPresent[structPieceCounter] == '1'){
            mvwprintw(pieceBoardArray[structPieceCounter], 7, 8, "%d", pieceSpikes[structPieceCounter].spikes[0]); 
            mvwprintw(pieceBoardArray[structPieceCounter], 8, 10, "%d", pieceSpikes[structPieceCounter].spikes[1]);
            mvwprintw(pieceBoardArray[structPieceCounter], 9, 8, "%d", pieceSpikes[structPieceCounter].spikes[2]);
            mvwprintw(pieceBoardArray[structPieceCounter], 8, 6, "%d", pieceSpikes[structPieceCounter].spikes[3]);

            refresh();
            wrefresh(pieceBoardArray[structPieceCounter]);
        }
    
    }

}

void printPlayerDeck(struct Player player, struct PieceInfo pieceSpikeInfo, int deckPieceNumber, int turn) {

    WINDOW* playerDeckBorder[5];

    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);

    int y_increment=11;
    for (int j=0; j<5; j++){
        y_increment = 11;
        y_increment *= j;
        playerDeckBorder[j] = newwin(10, 20, (8 + y_increment), 10);

        box(playerDeckBorder[j], 0, 0);

        if (j == deckPieceNumber){
            if (turn > 0){
                wbkgd(playerDeckBorder[j], COLOR_PAIR(5));
            }
            else{
                wbkgd(playerDeckBorder[j], COLOR_PAIR(6));
            }
        }
        
        pickDeckSkystone(playerDeckBorder[j], 1, player.stones[j], pieceSpikeInfo);

        refresh();
        wrefresh(playerDeckBorder[j]);

    }

}

void erasePieces(){
    int tmp_x=8;
    int tmp_y=52;

    WINDOW* pieceArray[9];

    int piece_count=0;

    for (int piece_row=0; piece_row<3; piece_row++){
        for (int piece_col=0; piece_col<3; piece_col++){
            pieceArray[piece_count] = newwin(15, 25, tmp_y, tmp_x);

            werase(pieceArray[piece_count]);
            wrefresh(pieceArray[piece_count]);
            piece_count++;
        }
    }
}

void printGridPieceOnSelection(int pieceSelection, WINDOW* gridSelectionWindow, struct PieceInfo pieceSpikes){
    // giant switch to print current data onto existing selection

    mvwprintw(gridSelectionWindow, 2, 2, "grid: %d", pieceSelection);

    switch (pieceSelection){
        case GRENADE_GENERAL:
            mvwprintw(gridSelectionWindow, 2, 2, "Grenade Gen");
            mvwprintw(gridSelectionWindow, 3, 4, pieceSpikes.GRENADE_GENERAL_A);
            mvwprintw(gridSelectionWindow, 4, 5, pieceSpikes.GRENADE_GENERAL_B);
            mvwprintw(gridSelectionWindow, 5, 4, pieceSpikes.GRENADE_GENERAL_C);
            mvwprintw(gridSelectionWindow, 4, 3, pieceSpikes.GRENADE_GENERAL_D);
            break;
        
        case ARKEYAN_BOMBER:
            mvwprintw(gridSelectionWindow, 2, 2, "Arkeyan Bomb");
            break;

        case ROOT_RUNNER:
            mvwprintw(gridSelectionWindow, 2, 2, "Root Runner");
            break;

        case CRYSTAL_GOLEM:
            mvwprintw(gridSelectionWindow, 2, 2, "Crystal Golem");
            break;

        case BLAZE_BREWER:
            mvwprintw(gridSelectionWindow, 2, 2, "Blaze Brewer");
            break;

        case CONQUERTRON:
            mvwprintw(gridSelectionWindow, 2, 2, "Conquertron");
            break;

        case DRAGONET:
            mvwprintw(gridSelectionWindow, 2, 2, "Dragonet");
            break;

        case D_RIVETER:
            mvwprintw(gridSelectionWindow, 2, 2, "D-Riveter");
            break;

        case PIECE_PLAYED:
            break;
    }

}