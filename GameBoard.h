#ifndef _GAMEBOARD_H
#define _GAMEBOARD_H
#include "Piece.h"
#include "Check.h"
#include <iostream>
#include <sstream>
#include<vector>

using namespace std;
	class GameBoard {
	public:
		GameBoard(void);
		~GameBoard(void);
		struct positions {
			int x;
			int y;
		};

	
Check board[8][8];
		void Display();
		void clearBoard();
		void testAvailablePositions(int curPlayer);
		int isCheck();
		bool isCheckMate(int);
		bool validateMoveRules(string, int);
		void convertMovetoPositions(string);
		void clearPositions(int);
	
private:
		void movePiece();
		void availablePositions(int);
		bool isValidMove(Piece*);
		void pieceAtPosition();
	
	};

public:
	Square* getSquare(int x, int y) {
		return &square[x][y];
	}
	void setSquare(Square * s, int x, int y){
		square[x][y]=*s;
	}
	bool doMove();

	void setBoard();
	bool playGame();
};
