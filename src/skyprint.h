void printBlankBoard();

void printBoardPieces(struct Board board, char* piecePlayed, struct PieceInfo *boardPieceCharacteristics, int pieceNumber, struct PieceSpikes *pieceSpikes[9]);

void printPieceCoordinates(int grid_x, int grid_y);

void printPlayerDeck(struct Player player);

void enterPiece(int x, int y);
