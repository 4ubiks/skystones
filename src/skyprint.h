void printBlankBoard();

void printBoardPieces(struct Board, int turn, char* piecePlayed, struct Pieces *boardPieceCharacteristics);

void printBoardPieceContent(struct Board board);

void printPieceCoordinates(int grid_x, int grid_y);

void printPlayerDeck(struct Player player, struct Pieces deckPieces);

void enterPiece(int x, int y);
