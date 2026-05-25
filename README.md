# SkyStones
An homage to my favorite childhood game, Skylanders: Giants. There is a minigame called skystones. There are two teams, and each team has a collection of five 'stones'. Each stone is a square object where every side has a number of spikes, 1 through 4. The game is played on a 3x3 grid. The first player places a stone. The second player places a stone, and if the number of spikes on the edge of player 2's stone is larger than the number of spikes on the adjacent edge of player 1's stone, player 2 'steals' player 1's stone. At the end of the game, the player with the most stones wins. 

Using `ncurses` to render the graphics

Use the arrow keys to select where you want to play your next stone. 
Use 'A/D' keys to select your next stone to play. 

## Structure
This is the include breakdown, just to help avoid include loops
```
main.c
--> constants.h
--> player.h
--> board.h
--> stone.h
--> skyprint.h  
--> skyinit.h
--> skyfuncs.h

skyinit.c
--> skyinit.h
--> constants.h
--> player.h
--> board.h

skyprint.c
--> player.h
--> board.h
--> skyprint.h
--> skyfuncs.h

skyfuncs.c
--> board.h
--> skyfuncs.h
--> skyinit.h


```
