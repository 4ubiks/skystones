# SkyStones
An homage to my favorite childhood game, Skylanders: Giants. In this game, there exists a minigame called skystones. There are two players, and each player has a collection of five 'stones'. Each stone is a square object where every side has a number of spikes, 1 through 4. The game is played on a 3x3 grid. The first player places a stone. Then, the second player places a stone, and if the number of spikes on the edge of player 2's stone is larger than the number of spikes on the adjacent edge of player 1's stone, player 2 'steals' player 1's stone. At the end of the game, the player with the most stones wins. 

Using `ncurses` to render the graphics

Use 'A/D' keys to select your next stone to play, and press 'Space' to select the piece to play. 
Use the arrow keys to select where you want to play your next stone, and press 'Enter' when you're ready to place the stone. 

## Structure
This is the include breakdown, just to help avoid include loops
```
main.c
--> stdio.h
--> ncurses.h
--> constants.h
--> pieceInfo.h
--> pieceSpikes.h
--> player.h
--> board.h
--> stone.h
--> skyprint.h  
--> skyinit.h
--> skyfuncs.h

pieceInfo.c
--> pieceInfo.h

skyfuncs.c
--> ncurses.h
--> string.h
--> board.h
--> constants.h
--> pieceInfo.h
--> pieceSpikes.h
--> player.h
--> skyfuncs.h
--> skyinit.h

skyinit.c
--> constants.h
--> player.h
--> board.h
--> skyinit.h

skyprint.c
--> stdio.h
--> string.h
--> ncurses.h
--> player.h
--> constants.h
--> pieceInfo.h
--> pieceSpikes.h
--> board.h
--> skyprint.h
--> skyfuncs.h

```
