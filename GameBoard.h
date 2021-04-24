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
