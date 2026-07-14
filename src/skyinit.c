#include "constants.h"
#include "player.h"
#include "board.h"
#include "skyinit.h"

struct Player initializePlayer1(struct Player player, int teamNumber){

    int stone=0;

    player.stones[0] = ARKEYAN_BOMBER;
    player.stones[1] = D_RIVETER;
    player.stones[2] = BLAZE_BREWER;
    player.stones[3] = CONQUERTRON;
    player.stones[4] = GRENADE_GENERAL;

    player.points = 0;

    player.team = teamNumber;

    return player;
}

struct Player initializePlayer2(struct Player player, int teamNumber){

    int stone=0;

    player.stones[0] = D_RIVETER;
    player.stones[1] = CONQUERTRON;
    player.stones[2] = ROOT_RUNNER;
    player.stones[3] = DRAGONET;
    player.stones[4] = ARKEYAN_BOMBER;

    player.points = 0;

    player.team = teamNumber;

    return player;
}

struct Board initializeBoard(struct Board board){

    board.piecesPlayed = 0;

    for (int i=0; i<9; i++){
        board.boardPieceIsPresent[i] = '0';
        board.boardPiecePlayer[i] = '0';
    }

    return board;
}

int pieceStatus(struct Board board, int pieceNumber){
    return board.boardPieceIsPresent[pieceNumber];  
}