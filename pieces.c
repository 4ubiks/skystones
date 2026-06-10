#include "pieces.h"

struct Pieces initializeDeckPieces(struct Pieces pieces){
    pieces.deck_grenade_general[6] = (char *[6]){
        "    --    ",
        "   /  \\    ",
        "   \\ /     ",
        "    | |.   ",
        "  __   ___ ",
        "  |______| "
    };

    pieces.deck_arkeyan_bomber[6] = (char *[6]){
        "  __      ",
        " _/o \\_   ",
        "|      |  ",
        "|      |=-",
        " \\____/   ",
        "   ||     " 
    };

    pieces.deck_root_runner[6] = (char *[6]){
        "          ",
        "          ",
        " /\\ /\\ /\\ ",
        "|  |  |  |",
        "/  |  |  \\",
        "----------"
    };

    pieces.deck_crystal_golem[6] = (char *[6]){
        "          ",
        "/\\/\\/\\/\\",
        "\\ \\  / /",
        "  \\  /   ",
        "     \\/   ",
        "          "   
    };

    pieces.deck_blaze_brewer[6] = (char *[6]){
        "⠀⠀⢱⣿⣆⠀⠀⠀⠀⠀⠀",
        "⠀⢠⣿⣿⣿⣷⣧⠀⠀⠀⠀",
        "⢀⣾⣿⣿⣿⣿⣿⣷⡀⠀⠀",
        "⣰⣿⣿⣿⡿⢸⣿⣿⣿⣆⠀",
        "⠸⣿⣿⣿⠁⠀⠹⣿⣿⣿⡄",
        "⠀⠙⠛⠿⠀⠀⠀⠉⠛⠋⠀"
    };

    pieces.deck_conquertron[6] = (char *[6]){
        "         ",
        "   ⣿⣿⣿⣿   ",
        "  ⣾⣿⣿⣿⣿   ",
        "  ⣿⣿⣿⣿⡟   ",
        "  ⠻⣿⣿⠟    ",
        "   ⣿⣿⡇    "
    };

    pieces.deck_dragonet[6] = (char *[6]){
        "     /\\ ",
        "    /  \\",  
        "   /----",
        "  /     /",
        " /   /\\  ",
        " \\/     "
    };

    pieces.deck_d_riveter[6] = (char *[6]){
        "   ----   ",
        "  |    |  ",
        "  ------  ",
        "    | |   ",
        "    | |   ",
        "    | |   "
    };
}

struct Pieces initializeBoardPieces(struct Pieces pieces){
    
}