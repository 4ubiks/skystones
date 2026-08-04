// a struct for pieces that are used in the game

#ifndef PIECES_H
#define PIECES_H

struct PieceInfo {
    
    // piece array 
    int pieceAssignment[9];

    // name array
    char *pieces[9];

    // Number of spikes in each respective direction of the piece
    // A: UP
    // B: RIGHT
    // C: DOWN
    // D: LEFT
    // |-----------|
    // |           |
    // |     A     |
    // |   D   B   |
    // |     C     |
    // |           |
    // |___________|
    int GRENADE_GENERAL_A;
    int GRENADE_GENERAL_B;
    int GRENADE_GENERAL_C;
    int GRENADE_GENERAL_D;

    int ARKEYAN_BOMBER_A;
    int ARKEYAN_BOMBER_B;
    int ARKEYAN_BOMBER_C;
    int ARKEYAN_BOMBER_D;

    int ROOT_RUNNER_A;
    int ROOT_RUNNER_B;
    int ROOT_RUNNER_C;
    int ROOT_RUNNER_D;

    int CRYSTAL_GOLEM_A;
    int CRYSTAL_GOLEM_B;
    int CRYSTAL_GOLEM_C;
    int CRYSTAL_GOLEM_D;

    int BLAZE_BREWER_A;
    int BLAZE_BREWER_B;
    int BLAZE_BREWER_C;
    int BLAZE_BREWER_D;

    int CONQUERTRON_A;
    int CONQUERTRON_B;
    int CONQUERTRON_C;
    int CONQUERTRON_D;

    int DRAGONET_A;
    int DRAGONET_B;
    int DRAGONET_C;
    int DRAGONET_D;

    int D_RIVETER_A;
    int D_RIVETER_B;
    int D_RIVETER_C;
    int D_RIVETER_D;

};

struct PieceInfo initializeSpikes(struct PieceInfo);

#endif