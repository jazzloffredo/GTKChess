#ifndef piece_h
#define piece_h

#include "types.h"

typedef struct Piece Piece;

typedef boolean (* check_valid_move)(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

struct Piece{
	Color team;
	char rank;
	check_valid_move check_move;
	char* imageLocation;
};

#endif /* end def piece_h */
