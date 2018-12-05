//
//  bishop.h 
//  CIS 308 Final Project 
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

#ifndef bishop_h
#define bishop_h

// Inlclude user-defined header files.
#include "piece.h"
#include "types.h"

// 'Constructor' function to create a new Piece pointer
Piece * make_new_bishop(Color, int, int);

// Used to 'override' generic Piece check_valid method
boolean check_valid_move_bishop(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

// Bishop Struct
typedef struct Bishop{
	Piece piece;
	Position pos;
}Bishop;

#endif /* end def bishop_h */