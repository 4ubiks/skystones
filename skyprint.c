#include "skyprint.h"
#include "stdio.h"
#include "ncurses.h"


void printBoard(){
    printf("         |          |         \n");
    printf("         |          |         \n");
    printf("         |          |         \n");
    printf("---------|----------|---------\n");
    printf("         |          |         \n");
    printf("         |          |         \n");
    printf("         |          |         \n");
    printf("---------|----------|---------\n");
    printf("         |          |         \n");
    printf("         |          |         \n");
    printf("         |          |         \n");

}

void printPlayerDeck(){
    mvwprintw(stdscr, 5, 10, "Player 1's Deck:");
    mvwprintw(stdscr, 6, 10, "[]");
    mvwprintw(stdscr, 6, 13, "[]");
    mvwprintw(stdscr, 6, 16, "[]");
    mvwprintw(stdscr, 6, 19, "[]");
    mvwprintw(stdscr, 6, 22, "[]");
}