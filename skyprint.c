// c libraries
#include "stdio.h"
#include "ncurses.h"

// custom files
#include "player.h"
#include "skyprint.h"


void printBoard(){
    mvwprintw(stdscr, 10, 15, "         |          |         \n");
    mvwprintw(stdscr, 11, 15, "         |          |         \n");
    mvwprintw(stdscr, 12, 15, "         |          |         \n");
    mvwprintw(stdscr, 13, 15, "---------|----------|---------\n");
    mvwprintw(stdscr, 14, 15, "         |          |         \n");
    mvwprintw(stdscr, 15, 15, "         |          |         \n");
    mvwprintw(stdscr, 16, 15, "         |          |         \n");
    mvwprintw(stdscr, 17, 15, "---------|----------|---------\n");
    mvwprintw(stdscr, 18, 15, "         |          |         \n");
    mvwprintw(stdscr, 19, 15, "         |          |         \n");
    mvwprintw(stdscr, 20, 15, "         |          |         \n");

}

void printPlayerDeck(struct Player player){
    mvwprintw(stdscr, 5, 10, "Player 1's Deck:");
    mvwprintw(stdscr, 6, 10, "[]");
    mvwprintw(stdscr, 6, 13, "[]");
    mvwprintw(stdscr, 6, 16, "[]");
    mvwprintw(stdscr, 6, 19, "[]");
    mvwprintw(stdscr, 6, 22, "[]");

    mvwprintw(stdscr, 8, 15, "Player points: %d", player.points);
}