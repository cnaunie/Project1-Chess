#ifndef _CHECK_H
#define _CHECK_H
#include "Piece.h"

class Check {
public:
	Check(void);
	Piece* piece;
	Check(Piece* piece);
};

#endif
