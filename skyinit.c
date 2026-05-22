#include "constants.h"
#include "skyinit.h"
#include "player.h"
#include "board.h"

struct Player initializePlayer(struct Player player){
    player.stone_1 = ARKEYAN_BOMBER;
    player.stone_2 = D_RIVETER;
    player.stone_3 = BLAZE_BREWER;
    player.stone_4 = CONQUERTRON;
    player.stone_5 = GRENADE_GENERAL;

    player.points = 0;

    return player;
}

struct Board initializeBoard(struct Board board){

    board.piecesPlayed = 0;

    board.point00 = '0';
    board.point01 = '0';
    board.point02 = '0';
    board.point10 = '0';
    board.point11 = '0';
    board.point12 = '0';
    board.point20 = '0';
    board.point21 = '0';
    board.point22 = '0';

    return board;
}