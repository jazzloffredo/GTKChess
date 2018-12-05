#ifndef pawn_h
#define pawn_h

#include "piece.h"
#include "types.h"

Piece * make_new_pawn(Color, int, int);

boolean check_valid_move_pawn(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

typedef struct Pawn{
	Piece piece;
	Position pos;
	boolean moved;
}Pawn;

#endif /* end def pawn_h */
