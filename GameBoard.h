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

class Board
{
	Square square[8][8];
	Color turn=WHITE;
	bool moveKing(Square* thisKing, Square* thatSpace);
	bool moveQueen(Square* thisQueen, Square* thatSpace);
	bool moveBishop(Square* thisBishop, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool moveRook(Square* thisRook, Square* thatSpace);
	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool makeMove(int x1, int y1, int x2, int y2);
	void printBoard();
	
	
public:
		GameBoard(void);
		~GameBoard(void);
		struct positions {
			int x;
			int y;
		};
	
	
