// a struct for pieces that are used in the game

#ifndef PIECES_H
#define PIECES_H

struct Pieces {
    char deck_grenade_general[6][12];

    char deck_arkeyan_bomber[6][12];

    char deck_root_runner[6][12];

    char deck_crystal_golem[6][12];

    char deck_blaze_brewer[6][12];

    char deck_conquertron[6][12];

    char deck_dragonet[6][12];

    char deck_d_riveter[6][12];

    char board_grenade_general[12][21];

    char board_arkeyan_bomber[12][21];

    char board_root_runner[12][21];

    char board_crystal_golem[12][21];

    char board_blaze_brewer[12][21];

    char board_conquertron[12][21];

    char board_dragonet[12][21];

    char board_d_riveter[12][21];
};

struct Pieces initializeDeckPieces(struct Pieces);

struct Pieces initializeBoardPieces(struct Pieces);

#endif