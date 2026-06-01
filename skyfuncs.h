// Functions throughout the game
char setPiece(struct Board*, int pieceNumber, int turn);

int calculateCellNumber(int x, int y);

char gameIsOver(struct Board*);

int toggleTurn(int turn);

void selectPlayerColor(int turn, int tmp_x, int tmp_y, WINDOW* newPieceWindow, struct Board board);