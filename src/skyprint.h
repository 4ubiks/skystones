void printBlankBoard();

void printBoardPieces(struct Board board, char* piecePlayed, struct PieceInfo *boardPieceCharacteristics, int pieceNumber, struct PieceSpikes pieceSpikes[]);

void printPieceCoordinates(int grid_x, int grid_y);

void printPlayerDeck(struct Player player, struct PieceInfo pieceSpikeInfo, int deckPieceNumber);

void erasePieces();