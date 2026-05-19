#include "constants.h"
#include "skyinit.h"
#include "player.h"

struct Player initializePlayer(struct Player player){
    player.stone_1 = ARKEYAN_BOMBER;
    player.stone_2 = D_RIVETER;
    player.stone_3 = BLAZE_BREWER;
    player.stone_4 = CONQUERTRON;
    player.stone_5 = GRENADE_GENERAL;

    player.points = 0;

    return player;
}