// a struct for pieces that are used in the game

#ifndef PIECES_H
#define PIECES_H

struct Pieces {
    char deck_grenade_general[6];

    char deck_arkeyan_bomber[6];

    char deck_root_runner[6];

    char deck_crystal_golem[6];

    char deck_blaze_brewer[6];

    char deck_conquertron[6];

    char deck_dragonet[6];

    char deck_d_riveter[6];

    char board_grenade_general[6];

    char board_arkeyan_bomber[6];

    char board_root_runner[6];

    char board_crystal_golem[6];

    char board_blaze_brewer[6];

    char board_conquertron[6];

    char board_dragonet[6];

    char board_d_riveter[6];
};

struct Pieces initializeDeckPieces(struct Pieces);

#endif