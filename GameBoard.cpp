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
