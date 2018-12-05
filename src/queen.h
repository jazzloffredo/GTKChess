#ifndef queen_h
#define queen_h

#include "piece.h"
#include "types.h"

Piece * make_new_queen(Color, int, int);
boolean check_valid_move_queen(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

typedef struct Queen{
	Piece piece;
	Position pos;
}Queen;

#endif /* end def queen_h */