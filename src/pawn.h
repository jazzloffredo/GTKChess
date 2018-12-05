//
//  pawn.h
//  CIS 308 Final Project
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

#ifndef pawn_h
#define pawn_h

#include "piece.h"
#include "types.h"

// 'Constructor' function to create a new Piece pointer
Piece * make_new_pawn(Color, int, int);

// Used to 'override' generic Piece check_valid method
boolean check_valid_move_pawn(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

// Pawn Struct
typedef struct Pawn{
	Piece piece;
	Position pos;
	boolean moved;
}Pawn;

#endif /* end def pawn_h */
