// C libraries
#include "stdio.h"
#include "ncurses.h"

// Custom files
#include "constants.h"
#include "pieces.h"
#include "player.h"
#include "board.h"
#include "stone.h"
#include "skyprint.h"
#include "skyinit.h"
#include "skyfuncs.h"

int main(){
    initscr();
    noecho();
    cbreak();

    keypad(stdscr, TRUE);
    curs_set(1); // cursor appearance: 0 invisible, 1 normal, 2strong
    printBlankBoard();

    if (has_colors() == FALSE){
        endwin();
        printf("bad terminal\n");
        return 1;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    attron(COLOR_PAIR(1));

    int y, x;
    int grid_x, grid_y = 0;
    getmaxyx(stdscr, y, x);
    y = y*0.5;
    x = (x*0.5) -6;
    mvwprintw(stdscr, 2, 2, "Skystones-C");

    struct Player p1;
    p1 = initializePlayer1(p1, PLAYER_ONE);

    struct Player p2;
    p2 = initializePlayer2(p2, PLAYER_TWO);

    struct Board boardPieces;
    boardPieces = initializeBoard(boardPieces);

    struct Pieces deckPieces;
    deckPieces = initializeDeckPieces(deckPieces);

    // GRID selection initalization
    WINDOW *gridSelection = newwin(13, 21, 9, 54);
    box(gridSelection, 0, 0);

    wattron(gridSelection, A_REVERSE);

    WINDOW *deckSelection = newwin(10, 18, 9, 11);
    box(deckSelection, 0, 0);
    wrefresh(deckSelection);

    wattron(deckSelection, A_REVERSE);

    refresh();

    wrefresh(deckSelection);
    wrefresh(gridSelection);

    // print the first player's deck
    printPlayerDeck(p1, deckPieces);

    y=8;
    x=52;

    grid_x = 0;
    grid_y = 0;

    int deck_y = 9;
    int piece_number = 0;
    int deck_piece_played=0;
    char piecePlayed = OPEN;
    char* piecePlayedString = "DEFAULT";

    // when `turn` is positive, player 1's turn. otherwise, p2's turn.
    int turn = 1;

    while (true){

        int pressedKey = getch();
        while (pressedKey != ' '){
            pressedKey = getch();
            switch(pressedKey){
                case 'w':
                    deck_y-=11;
                    if (deck_y < 9){
                        deck_y = 9;
                        break;
                    }
                    deck_piece_played -=1;
                    break;
                case 's':
                    deck_y+=11;
                    if (deck_y > 53){
                        deck_y = 53;
                        break;
                    }
                    deck_piece_played +=1;
                    break;
            }

            // refresh to erase old selection
            werase(deckSelection);
            wrefresh(deckSelection);

            // highlights user selection of DECK
            deckSelection = newwin(10, 18, deck_y, 11);
            box(deckSelection, 0, 0);
            wmove(deckSelection, deck_y, 11);

            if (turn > 0){
                printPlayerDeck(p1, deckPieces);
            }
            else{
                printPlayerDeck(p2, deckPieces);
            }

            wrefresh(deckSelection);

            
        }

        if (turn > 0){
            piecePlayedString = setDeckPieceName(p1.stones[deck_piece_played]);
            p1.stones[deck_piece_played] = PIECE_PLAYED;
        }
        else {
            piecePlayedString = setDeckPieceName(p2.stones[deck_piece_played]);
            p2.stones[deck_piece_played] = PIECE_PLAYED;
        }

        while (pressedKey != 10){
            pressedKey = getch();
            
            switch(pressedKey) {
                case KEY_UP:    y-=20; grid_y--; break;
                case KEY_DOWN:  y+=20; grid_y++; break;
                case KEY_LEFT:  x-=50; grid_x--; break;
                case KEY_RIGHT: x+=50; grid_x++; break;

            }

            if (grid_y == 3){
                grid_y = 2;
                y-=20;
            }
            else if (grid_y == -1){
                grid_y = 0;
                y+=20;
            }

            if (grid_x == 3){
                grid_x = 2;
                x-=50;
            }
            else if (grid_x == -1){
                grid_x = 0;
                x+=50;
            }

            werase(gridSelection);
            wrefresh(gridSelection);

            // highlights user selection of GRID
            gridSelection = newwin(13, 21, y+1, x+2);
            box(gridSelection, 0, 0);
            wmove(gridSelection, y, x);
            
            // second refresh to draw new selection
            wrefresh(gridSelection);

            // piecePlayed needs to go here and print out what was played, and where. 

        }

        if (gameIsOver(&boardPieces)){
            timeout(-1);
            erase();
            mvwprintw(stdscr, 28, 102, "game over");
        }

            mvwprintw(stdscr, 5, 5, "Player 1 points: %d", p1.points);

        if (turn < 0){
            p1.points = playerScore(boardPieces);
        }

        piece_number = calculateCellNumber(grid_x, grid_y);
        setPiece(&boardPieces, piece_number, turn);

        printBoardPieces(boardPieces, turn, piecePlayedString, &deckPieces);
        turn = toggleTurn(turn);
        
    }

    refresh();

    attroff(COLOR_PAIR(1));

    getch();

    endwin();


    return 0;
}