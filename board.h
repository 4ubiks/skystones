#ifndef BOARD_H
#define BOARD_H

// Framework for the board itself
struct Board {
    int piecesPlayed;

    // These points are the board themselves, whether or not the piece is played. '0' is empty, '1' is played. 
    char point00;
    char point01;
    char point02;

    char point10;
    char point11;
    char point12;
    
    char point20;
    char point21;
    char point22;
};

#endif