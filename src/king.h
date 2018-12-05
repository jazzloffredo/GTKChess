#ifndef king_h
#define king_h

#include "piece.h"
#include "types.h"

Piece * make_new_king(Color, int, int);
boolean check_valid_move_king(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

typedef struct King{
	Piece piece;
	Position pos;
	int alive;
}King;

#endif /* end def king_h */