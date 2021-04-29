#include "GameBoard.h"

GameBoard::GameBoard(void) {
}
GameBoard::~GameBoard(void) {

}
bool GameBoard::validateMoveRules(string move, int currentPlayer) {
	bool valid;
	convertMovetoPositions(move);
	Piece* selectedPiece = board[selectedPieceCoor.y][selectedPieceCoor.x].piece;
	Piece* targetPosition = board[targetPositionCoor.y][targetPositionCoor.x].piece;

	if (selectedPiece == nullptr) {
		cout << "There's no piece at the specified location." << endl;
		return false;
	}
	else if (selectedPiece->player != currentPlayer) {
		cout << "This is not your piece" << endl;
		return false;
	}
	if (targetPosition != nullptr && targetPosition->player == currentPlayer && selectedPiece->player == currentPlayer) {
		cout << "You already have a piece there." << endl;
		return false;
	}

	availablePositions(1);
	availablePositions(2);
	valid = isValidMove(selectedPiece);
	selectedPiece->movesMade += 1;
	if (valid) {
		movePiece();

	}
	clearPositions(1);
	clearPositions(2);
	availablePositions(1);
	availablePositions(2);

	return valid;
}
void GameBoard::movePiece() {
	board[targetPositionCoor.y][targetPositionCoor.x] = board[selectedPieceCoor.y][selectedPieceCoor.x].piece;
	board[selectedPieceCoor.y][selectedPieceCoor.x] = nullptr;
	cout << "Move successful" << endl;
	//Sleep(450);
}
void GameBoard::availablePositions(int targetPlayer) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Piece* currentPiece = board[y][x].piece;
			// looping trhough all pieces
			if (currentPiece != nullptr && currentPiece->player == targetPlayer) {
				
				// looping trhough all possible movements of a piece
				int length = currentPiece->movements.size();
				for (int i = 0; i < length; i++) {
					if (currentPiece->direction && !currentPiece->pawn) {

						// find all available positions in a direction
						positions movement = { currentPiece->movements[i].x, currentPiece->movements[i].y };
						positions currentPos = { x, y };
						// up
						if (movement.y < 0 && movement.x == 0) {
							// loop for step movement
							int iy = (currentPos.y - 1);
							int ix = currentPos.x;
							while (iy >= 0)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy--;
							}
						}else if (movement.y > 0 && movement.x == 0) {
						// down
							// loop for step movement
							int iy = (currentPos.y + 1);
							int ix = currentPos.x;
							while (iy < 8)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy++;
							}
						}else if (movement.y == 0 && movement.x > 0) {
						//right
							// loop for step movement
							int iy = currentPos.y;
							int ix = (currentPos.x + 1);
							while (ix < 8)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								ix++;
							}
						} else if (movement.y == 0 && movement.x < 0) {
						//left
							// loop for step movement
							int iy = currentPos.y;
							int ix = (currentPos.x - 1);
							while (ix >= 0)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								ix--;
							}
						} else if (movement.y < 0 && movement.x > 0) {
						// up & right
							// loop for step movement
							int iy = (currentPos.y - 1);
							int ix = (currentPos.x + 1);
							while (iy >= 0 && iy < 8 && ix < 8)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy--;
								ix++;
							}
						} else if (movement.y < 0 && movement.x < 0) {
						// up & left
							// loop for step movement
							int iy = (currentPos.y - 1);
							int ix = (currentPos.x - 1);
							while (iy >= 0 && iy < 8 && ix >= 0)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy--;
								ix--;
							}
						} else if (movement.y > 0 && movement.x > 0) {
						// down & right
							// loop for step movement
							int iy = (currentPos.y + 1);
							int ix = (currentPos.x + 1);
							while (iy < 8 && ix < 8)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy++;
								ix++;
							}
						} else if (movement.y > 0 && movement.x < 0){
						// down & left
							// loop for step movement
							int iy = (currentPos.y + 1);
							int ix = (currentPos.x - 1);
							while (iy < 8 && ix >= 0)
							{	
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy++;
								ix--;
							}
						}
					}
					else if (!currentPiece->direction && !currentPiece->pawn) {
						// find available pos around a piece (for N, K)
						positions movement = { currentPiece->movements[i].x, currentPiece->movements[i].y };
						positions currentPos = { x, y };
						int ix = (currentPos.x + movement.x);
						int iy = (currentPos.y + movement.y);
						if (ix >= 0 && iy >= 0 && ix < 8 && iy < 8) {
							if (board[iy][ix].piece == nullptr || board[iy][ix].piece->player != currentPiece->player) {
								currentPiece->availablePositions.push_back({ ix, iy });
							}
						};
					}
					else if (currentPiece->pawn && currentPiece->player == 1) {
					// white pawn logic
					Piece* pawn = board[y][x].piece;
						positions movement = { pawn->movements[i].x, pawn->movements[i].y };
						positions currentPos = { x, y };

						// down
						if (movement.y > 0 && movement.x == 0) {
							// loop for step movement
							int iy = (currentPos.y + movement.y);
							int ix = currentPos.x;
							if (board[iy][ix].piece == nullptr) {
								pawn->availablePositions.push_back({ ix, iy });
								if (pawn->movesMade == 0) {
									iy = iy + 1;
									if (board[iy][ix].piece == nullptr) {
										pawn->availablePositions.push_back({ ix, iy });
									}
								}
							}
						}
						// down & left
						// looping trhough pawntakes 
						int lengthpw = currentPiece->pawnTakes.size();
						for (int i = 0; i < lengthpw; i++) {
							if (currentPiece->pawnTakes[i].y > 0 && currentPiece->pawnTakes[i].x < 0) {
								int iy = (currentPos.y + 1);
								int ix = (currentPos.x - 1);
								if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {

									if (board[iy][ix].piece != nullptr) {
										if (board[iy][ix].piece->player != currentPiece->player) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}
						// down & right
						for (int i = 0; i < lengthpw; i++) {
							if (currentPiece->pawnTakes[i].y > 0 && currentPiece->pawnTakes[i].x > 0) {
								int iy = (currentPos.y + 1);
								int ix = (currentPos.x + 1);
								if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
									if (board[iy][ix].piece != nullptr) {
										if (board[iy][ix].piece->player != currentPiece->player) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}

					}
					else if (currentPiece->pawn && currentPiece->player == 2) {
						// black pawn logic
						positions movement = { currentPiece->movements[i].x, currentPiece->movements[i].y };
						positions currentPos = { x, y };
						
						// up
						if (movement.y < 0 && movement.x == 0) {
							// loop for step movement
							int iy = (currentPos.y - 1);
							int ix = currentPos.x;
							if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
									if (currentPiece->movesMade == 0 && iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
										iy = iy - 1;
										if (board[iy][ix].piece == nullptr) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}
						// up & left
						// looping trhough pawntakes 
						int lengthpw = currentPiece->pawnTakes.size();
						for (int i = 0; i < lengthpw; i++) {
							if (currentPiece->pawnTakes[i].y < 0 && currentPiece->pawnTakes[i].x < 0) {
								int iy = (currentPos.y - 1);
								int ix = (currentPos.x - 1);
								if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
									if (board[iy][ix].piece != nullptr) {
										if (board[iy][ix].piece->player != currentPiece->player) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}
						// up & right
						for (int i = 0; i < lengthpw; i++) {
							if (currentPiece->pawnTakes[i].y < 0 && currentPiece->pawnTakes[i].x > 0) {
								int iy = (currentPos.y - 1);
								int ix = (currentPos.x + 1);
								if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
									if (board[iy][ix].piece != nullptr) {
										if (board[iy][ix].piece->player != currentPiece->player) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
