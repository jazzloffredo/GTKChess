//
//  rook.h
//  CIS 308 Final Project
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

#ifndef rook_h
#define rook_h

// Include user-defined header files.
#include "piece.h"
#include "types.h"

// 'Constructor' function to create a new Piece pointer
Piece * make_new_rook(Color, int, int);

// Used to 'override' generic Piece check_valid method
boolean check_valid_move_rook(Piece pieces[8][8], Piece * self, Position curPos, Position newPos);

// Rook Struct
typedef struct Rook{
	Piece piece;
	Position pos;
}Rook;

#endif /* end def rook_h */
