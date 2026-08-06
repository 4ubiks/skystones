void printBlankBoard();

void printBoardPieces(struct Board board, char* piecePlayed, struct PieceInfo *boardPieceCharacteristics, int pieceNumber, struct PieceSpikes pieceSpikes[]);

void printPlayerDeck(struct Player player, struct PieceInfo pieceSpikeInfo, int deckPieceNumber, int turn);

void erasePieces();

void printGridPieceOnSelection(int pieceSelection, WINDOW* gridSelectionWindow, struct PieceInfo pieceSpikes);

void printTopSpikes(int numberOfSpikes, int x_spike, int y_spike, WINDOW* piece);

void printRightSpikes(int numberOfSpikes, int x_spike, int y_spike, WINDOW* piece);

void printBottomSpikes(int numberOfSpikes, int x_spike, int y_spike, WINDOW* piece);

void printLeftSpikes(int numberOfSpikes, int x_spike, int y_spike, WINDOW* piece);

