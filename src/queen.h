//
//  queen.h
//  CIS 308 Final Project
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

#ifndef queen_h
#define queen_h

// Include user-defined header files
#include "piece.h"
#include "types.h"

// 'Constructor' function to create a new Piece pointer
Piece * make_new_queen(Color, int, int);

// Used to 'override' generic Piece check_valid method
boolean check_valid_move_queen(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

// Queen Struct
typedef struct Queen{
	Piece piece;
	Position pos;
}Queen;

#endif /* end def queen_h */
