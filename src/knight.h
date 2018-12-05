#ifndef knight_h
#define knight_h

#include "piece.h"
#include "types.h"

Piece * make_new_knight(Color, int, int);
boolean check_valid_move_knight(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

typedef struct Knight{
	Piece piece;
	Position pos;
}Knight;

#endif /* end def knight_h */