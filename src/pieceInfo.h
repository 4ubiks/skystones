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

struct PieceInfo initializeDeckPieces(struct PieceInfo);

struct PieceInfo initializeBoardPieces(struct PieceInfo);

struct PieceInfo initializeSpikes(struct PieceInfo);

#endif