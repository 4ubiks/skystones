// Functions throughout the game
char setPiece(struct Board*, int pieceNumber, int turn);

int calculateCellNumber(int x, int y);

char gameIsOver(struct Board*);

int toggleTurn(int turn);

void selectPlayerColor(WINDOW* newPieceWindow1, struct Board board, int piece_count, const char* piecePlayed);

int playerScore(struct Board board);

void pickDeckSkystone(WINDOW* currentPieceWindow, int deckWall, int deckPiece);

char* setDeckPieceName(int selectedPiece);

void assignPieceNames(struct PieceInfo *boardPieces, int thePieceNumberPlayed, char* pieceName);

void selectPieceNumbers(WINDOW* pieceWindow, struct PieceInfo *pieces, char* piecePlayed, int spikes[]);

void checkPiece(int pieceNum, struct PieceSpikes pieceSpikes[], struct Board *boardPieces);

bool checkPieceExists(int piecePlayed);

bool checkOppositePlayer(int playedPlayer, int targetPlayer);

int comparePieces(int pieceNumPlayed, int pieceNumAdj, int playedSpike, int adjacentSpike, struct Board *boardPieces);