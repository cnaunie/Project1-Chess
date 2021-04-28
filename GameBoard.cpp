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
