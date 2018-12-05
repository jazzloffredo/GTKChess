//
//  knight.h 
//  CIS 308 Final Project 
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

#ifndef knight_h
#define knight_h

// Include user-defined header files.
#include "piece.h"
#include "types.h"

// 'Constructor' function to create a new Piece pointer
Piece * make_new_knight(Color, int, int);

// Used to 'override' generic Piece check_valid method
boolean check_valid_move_knight(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

// Knight Struct
typedef struct Knight{
	Piece piece;
	Position pos;
}Knight;

#endif /* end def knight_h */