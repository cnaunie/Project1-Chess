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
	
	
public:
		GameBoard(void);
		~GameBoard(void);
		struct positions {
			int x;
			int y;
		};
	
	
