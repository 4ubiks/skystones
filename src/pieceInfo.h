// a struct for pieces that are used in the game

#ifndef PIECES_H
#define PIECES_H

struct Pieces {
    char deck_grenade_general[6][12];

    char deck_arkeyan_bomber[6][12];

    char deck_root_runner[6][12];

    char deck_crystal_golem[6][12];

    char deck_blaze_brewer[6][36];

    char deck_conquertron[6][36];

    char deck_dragonet[6][12];

    char deck_d_riveter[6][12];

    char board_grenade_general[12][21];

    char board_arkeyan_bomber[12][21];

    char board_root_runner[12][21];

    char board_crystal_golem[12][21];

    char board_blaze_brewer[12][63];

    char board_conquertron[12][63];

    char board_dragonet[12][21];

    char board_d_riveter[12][21];

    // piece array 
    int pieceAssignment[9];

    // name array
    char *pieces[9];

    // Number of spikes in each respective direction of the piece
    // A: UP
    // B: RIGHT
    // C: DOWN
    // D: LEFT
    char* GRENADE_GENERAL_A;
    char* GRENADE_GENERAL_B;
    char* GRENADE_GENERAL_C;
    char* GRENADE_GENERAL_D;

    char* ARKEYAN_BOMBER_A;
    char* ARKEYAN_BOMBER_B;
    char* ARKEYAN_BOMBER_C;
    char* ARKEYAN_BOMBER_D;

    char* ROOT_RUNNER_A;
    char* ROOT_RUNNER_B;
    char* ROOT_RUNNER_C;
    char* ROOT_RUNNER_D;

    char* CRYSTAL_GOLEM_A;
    char* CRYSTAL_GOLEM_B;
    char* CRYSTAL_GOLEM_C;
    char* CRYSTAL_GOLEM_D;

    char* BLAZE_BREWER_A;
    char* BLAZE_BREWER_B;
    char* BLAZE_BREWER_C;
    char* BLAZE_BREWER_D;

    char* CONQUERTRON_A;
    char* CONQUERTRON_B;
    char* CONQUERTRON_C;
    char* CONQUERTRON_D;

    char* DRAGONET_A;
    char* DRAGONET_B;
    char* DRAGONET_C;
    char* DRAGONET_D;

    char* D_RIVETER_A;
    char* D_RIVETER_B;
    char* D_RIVETER_C;
    char* D_RIVETER_D;

};

struct Pieces initializeDeckPieces(struct Pieces);

struct Pieces initializeBoardPieces(struct Pieces);

struct Pieces initializeSpikes(struct Pieces);

#endif