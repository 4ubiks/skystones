// Functions throughout the game
char setPiece(struct Board*, int pieceNumber);

int calculateCellNumber(int x, int y);

char gameIsOver(struct Board*);

int toggleTurn(int turn);

void selectPlayerColor(int turn, WINDOW *stoneWindow);