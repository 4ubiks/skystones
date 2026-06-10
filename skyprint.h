void printBlankBoard();

void printFullBoard(struct Board, int turn);

void printPieceCoordinates(int grid_x, int grid_y);

void printPlayerDeck(struct Player);

void enterPiece(int x, int y);

void printDeckSkystone(char* stoneGraphic[6][12], int x, int y, WINDOW* currentPieceWindow);

void printBoardSkystone(char* stoneGraphic[12][21], int x, int y, WINDOW* currentPieceWindow);