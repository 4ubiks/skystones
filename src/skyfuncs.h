// Functions throughout the game
char setPiece(struct Board*, int pieceNumber, int turn);

int calculateCellNumber(int x, int y);

char gameIsOver(struct Board*);

int toggleTurn(int turn);

void selectPlayerColor(int tmp_x, int tmp_y, WINDOW* newPieceWindow1, WINDOW* newPieceWindow, struct Board board, int piece_count, const char* piecePlayed);

int playerScore(struct Board board);

void pickDeckSkystone(WINDOW* currentPieceWindow, int deckWall, struct Pieces deckPieces, int deckPiece);

char* setDeckPieceName(int selectedPiece);