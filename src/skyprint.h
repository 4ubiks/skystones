void printBlankBoard();

void printBoardPieces(struct Board board, char* piecePlayed, struct PieceInfo *boardPieceCharacteristics, int pieceNumber, struct PieceSpikes pieceSpikes[]);

void printPlayerDeck(struct Player player, struct PieceInfo pieceSpikeInfo, int deckPieceNumber, int turn);

void erasePieces();

void printGridPieceOnSelection(int pieceSelection, WINDOW* gridSelectionWindow, struct PieceInfo pieceSpikes);