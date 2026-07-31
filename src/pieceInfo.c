#include "pieceInfo.h"

struct PieceInfo initializeSpikes(struct PieceInfo piece_info){
    piece_info.GRENADE_GENERAL_A = "0\0";
    piece_info.GRENADE_GENERAL_B = "2\0";
    piece_info.GRENADE_GENERAL_C = "0\0";
    piece_info.GRENADE_GENERAL_D = "2\0";

    piece_info.ARKEYAN_BOMBER_A = "2\0";
    piece_info.ARKEYAN_BOMBER_B = "2\0";
    piece_info.ARKEYAN_BOMBER_C = "2\0";
    piece_info.ARKEYAN_BOMBER_D = "0\0";

    piece_info.ROOT_RUNNER_A = "1\0";
    piece_info.ROOT_RUNNER_B = "2\0";
    piece_info.ROOT_RUNNER_C = "3\0";
    piece_info.ROOT_RUNNER_D = "2\0";

    piece_info.CRYSTAL_GOLEM_A = "3\0";
    piece_info.CRYSTAL_GOLEM_B = "3\0";
    piece_info.CRYSTAL_GOLEM_C = "0\0";
    piece_info.CRYSTAL_GOLEM_D = "0\0";

    piece_info.BLAZE_BREWER_A = "2\0";
    piece_info.BLAZE_BREWER_B = "0\0";
    piece_info.BLAZE_BREWER_C = "0\0";
    piece_info.BLAZE_BREWER_D = "2\0";

    piece_info.CONQUERTRON_A = "4\0";
    piece_info.CONQUERTRON_B = "4\0";
    piece_info.CONQUERTRON_C = "4\0";
    piece_info.CONQUERTRON_D = "4\0";

    piece_info.DRAGONET_A = "1\0";
    piece_info.DRAGONET_B = "2\0";
    piece_info.DRAGONET_C = "1\0";
    piece_info.DRAGONET_D = "2\0";

    piece_info.D_RIVETER_A = "2\0";
    piece_info.D_RIVETER_B = "0\0";
    piece_info.D_RIVETER_C = "2\0";
    piece_info.D_RIVETER_D = "0\0";

    return piece_info;
}

void initializeNames(struct PieceInfo piece_info){
    for (int i=0; i<9; i++){
        piece_info.pieceAssignment[i] = 0;
    }
}