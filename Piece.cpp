#include "Piece.h"

Piece::Piece(void) {};
Piece::~Piece(void) {};
Piece::Piece(string nm, int pl, int iny, int inx, int mm) {
	name = nm;
	player = pl;
	defaultPosition.x = inx;
	defaultPosition.y = iny;
	movesMade = mm;
