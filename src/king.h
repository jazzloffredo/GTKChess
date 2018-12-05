//
//  king.h 
//  CIS 308 Final Project 
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

#ifndef king_h
#define king_h

// Include user-defined header files.
#include "piece.h"
#include "types.h"

// 'Constructor' function to create a new Piece pointer
Piece * make_new_king(Color, int, int);

// Used to 'override' generic Piece check_valid method
boolean check_valid_move_king(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

// King Struct
typedef struct King{
	Piece piece;
	Position pos;
	int alive;
}King;

#endif /* end def king_h */