#ifndef rook_h
#define rook_h

#include "piece.h"
#include "types.h"

Piece * make_new_rook(Color, int, int);
boolean check_valid_move_rook(Piece pieces[8][8], Piece * self, Position curPos, Position newPos);

typedef struct Rook{
	Piece piece;
	Position pos;
}Rook;

#endif /* end def rook_h */