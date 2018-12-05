#ifndef bishop_h
#define bishop_h

#include "piece.h"
#include "types.h"

Piece * make_new_bishop(Color, int, int);
boolean check_valid_move_bishop(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

typedef struct Bishop{
	Piece piece;
	Position pos;
}Bishop;

#endif /* end def bishop_h */