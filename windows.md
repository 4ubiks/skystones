# All Windows in Game
`ncurses` uses windows, and this is just documentation to say how many window variables there are, and their hierarchal order. 


```
stdscr // the border, title, etc
│
├──> gridBorder // the actual 3x3 grid, basically the tic-tac-toe board
│   ├──> enterPiece // a temp window created whenever the user presses enter. becomes part of gridBorder. 
│
├──> gridSelection // when the user navigates the board, the box showing them their current selection
```