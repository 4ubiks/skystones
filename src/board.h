#ifndef BOARD_H
#define BOARD_H

// Framework for the board itself
struct Board {
    int piecesPlayed;

    // These points are the board themselves, whether or not a piece exists at that point. 
    char boardPieceIsPresent[9];
    char boardPiecePlayer[9];

    // holds the name of each piece played at each spot on the 3x3 grid
    char boardPiecesPlayed[9];
};

#endif