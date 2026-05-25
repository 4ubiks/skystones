#include "constants.h"
#include "player.h"
#include "board.h"
#include "skyinit.h"

struct Player initializePlayer(struct Player player, int teamNumber){
    player.stone_1 = ARKEYAN_BOMBER;
    player.stone_2 = D_RIVETER;
    player.stone_3 = BLAZE_BREWER;
    player.stone_4 = CONQUERTRON;
    player.stone_5 = GRENADE_GENERAL;

    player.points = 0;

    player.team = teamNumber;

    return player;
}

struct Board initializeBoard(struct Board board){

    board.piecesPlayed = 0;

    for (int i=0; i<9; i++){
        board.boardPieceIsPresent[i] = '0';
    }

    return board;
}

int pieceStatus(struct Board board, int pieceNumber){
    return board.boardPieceIsPresent[pieceNumber];  
}