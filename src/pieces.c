#include "pieces.h"

struct Pieces initializeDeckPieces(struct Pieces pieces){
    pieces = (struct Pieces){
        .deck_grenade_general = {
            "    --    ",
            "   /  \\    ",
            "   \\ /     ",
            "    | |.   ",
            "  __   ___ ",
            "  |______| "
        },

        .deck_arkeyan_bomber = {
            "  __      ",
            " _/o \\_   ",
            "|      |  ",
            "|      |=-",
            " \\____/   ",
            "   ||     " 
        },

        .deck_root_runner = {
            "          ",
            "          ",
            " /\\ /\\ /\\ ",
            "|  |  |  |",
            "/  |  |  \\",
            "----------"
        },

        .deck_crystal_golem = {
            "          ",
            "/\\/\\/\\/\\",
            "\\ \\  / /",
            "  \\  /   ",
            "     \\/   ",
            "          "   
        },

        .deck_blaze_brewer = {
            "⠀⠀⢱⣿⣆⠀⠀⠀⠀⠀⠀",
            "⠀⢠⣿⣿⣿⣷⣧⠀⠀⠀⠀",
            "⢀⣾⣿⣿⣿⣿⣿⣷⡀⠀⠀",
            "⣰⣿⣿⣿⡿⢸⣿⣿⣿⣆⠀",
            "⠸⣿⣿⣿⠁⠀⠹⣿⣿⣿⡄",
            "⠀⠙⠛⠿⠀⠀⠀⠉⠛⠋⠀"
        },

        .deck_conquertron = {
            "         ",
            "   ⣿⣿⣿⣿   ",
            "  ⣾⣿⣿⣿⣿   ",
            "  ⣿⣿⣿⣿⡟   ",
            "  ⠻⣿⣿⠟    ",
            "   ⣿⣿⡇    "
        },

        .deck_dragonet = {
            "     /\\ ",
            "    /  \\",  
            "   /----",
            "  /     /",
            " /   /\\  ",
            " \\/     "
        },

        .deck_d_riveter = {
            "   ----   ",
            "  |    |  ",
            "  ------  ",
            "    | |   ",
            "    | |   ",
            "    | |   "
        }
    };

    return pieces;
}

struct Pieces initializeBoardPieces(struct Pieces pieces){
pieces = (struct Pieces){
        .board_grenade_general = {
        "              .",
        "            \'/",
        "          -=>*<=-",
        "         .-'/.\\",
        "        /    '",
        "    _.|_|._",
        "  .'       '.",
        " /           \\",
        "|         #   |",
        " \\           /",
        "  '.       .'",
        "    `'---'`"
        },

        .board_arkeyan_bomber = {
        "       *|*",
        "   _/>  #  <\\_",
        " /~  ;_/|\\_;  ~\\",
        "(       #       )",
        " \\_  ;~\\|/~;  _/",
        "   ~\\>  #  </~",
        "        #",
        "        #",
        "        #",
        "        #",
        "       /,\\",
        "       \\`/ ",
        },

        .board_root_runner = {
            "          ",
            "          ",
            " /\\ /\\ /\\ ",
            "|  |  |  |",
            "/  |  |  \\",
            "----------",
            "          ",
            "          ",
            " /\\ /\\ /\\ ",
            "|  |  |  |",
            "/  |  |  \\",
            "----------"
        },

        .board_crystal_golem = {
            "          ",
            "/\\/\\/\\/\\",
            "\\ \\  / /",
            "  \\  /   ",
            "     \\/   ",
            "          ",
            "          ",
            "/\\/\\/\\/\\",
            "\\ \\  / /",
            "  \\  /   ",
            "     \\/   ",
            "          "     
        },

        .board_blaze_brewer = {
            "⠀⠀⢱⣿⣆⠀⠀⠀⠀⠀⠀",
            "⠀⢠⣿⣿⣿⣷⣧⠀⠀⠀⠀",
            "⢀⣾⣿⣿⣿⣿⣿⣷⡀⠀⠀",
            "⣰⣿⣿⣿⡿⢸⣿⣿⣿⣆⠀",
            "⠸⣿⣿⣿⠁⠀⠹⣿⣿⣿⡄",
            "⠀⠙⠛⠿⠀⠀⠀⠉⠛⠋⠀",
            "⠀⠀⢱⣿⣆⠀⠀⠀⠀⠀⠀",
            "⠀⢠⣿⣿⣿⣷⣧⠀⠀⠀⠀",
            "⢀⣾⣿⣿⣿⣿⣿⣷⡀⠀⠀",
            "⣰⣿⣿⣿⡿⢸⣿⣿⣿⣆⠀",
            "⠸⣿⣿⣿⠁⠀⠹⣿⣿⣿⡄",
            "⠀⠙⠛⠿⠀⠀⠀⠉⠛⠋⠀"
        },

        .board_conquertron = {
            "         ",
            "   ⣿⣿⣿⣿   ",
            "  ⣾⣿⣿⣿⣿   ",
            "  ⣿⣿⣿⣿⡟   ",
            "  ⠻⣿⣿⠟    ",
            "   ⣿⣿⡇    ",
            "         ",
            "   ⣿⣿⣿⣿   ",
            "  ⣾⣿⣿⣿⣿   ",
            "  ⣿⣿⣿⣿⡟   ",
            "  ⠻⣿⣿⠟    ",
            "   ⣿⣿⡇    "
        },

        .board_dragonet = {
            "     /\\ ",
            "    /  \\",  
            "   /----",
            "  /     /",
            " /   /\\  ",
            " \\/     ",
            "     /\\ ",
            "    /  \\",  
            "   /----",
            "  /     /",
            " /   /\\  ",
            " \\/     "
        },

        .board_d_riveter = {
            "   ----   ",
            "  |    |  ",
            "  ------  ",
            "    | |   ",
            "    | |   ",
            "    | |   ",
            "   ----   ",
            "  |    |  ",
            "  ------  ",
            "    | |   ",
            "    | |   ",
            "    | |   "
        }
    };

    char GRENADE_GENERAL_A = 0;
    char GRENADE_GENERAL_B = 2;
    char GRENADE_GENERAL_C = 0;
    char GRENADE_GENERAL_D = 2;

    char ARKEYAN_BOMBER_A = 2;
    char ARKEYAN_BOMBER_B = 2;
    char ARKEYAN_BOMBER_C = 2;
    char ARKEYAN_BOMBER_D = 0;

    char ROOT_RUNNER_A = 1;
    char ROOT_RUNNER_B = 2;
    char ROOT_RUNNER_C = 3;
    char ROOT_RUNNER_D = 2;

    char CRYSTAL_GOLEM_A = 3;
    char CRYSTAL_GOLEM_B = 3;
    char CRYSTAL_GOLEM_C = 0;
    char CRYSTAL_GOLEM_D = 0;

    char BLAZE_BREWER_A = 2;
    char BLAZE_BREWER_B = 0;
    char BLAZE_BREWER_C = 0;
    char BLAZE_BREWER_D = 2;

    char CONQUERTRON_A = 4;
    char CONQUERTRON_B = 4;
    char CONQUERTRON_C = 4;
    char CONQUERTRON_D = 4;

    char DRAGONET_A = 1;
    char DRAGONET_B = 2;
    char DRAGONET_C = 1;
    char DRAGONET_D = 2;

    char D_RIVETER_A = 2;
    char D_RIVETER_B = 0;
    char D_RIVETER_C = 2;
    char D_RIVETER_D = 0;

    return pieces;
}

void initializeNames(struct Pieces pieces){
    for (int i=0; i<9; i++){
        pieces.pieceAssignment[i] = 0;
    }
}