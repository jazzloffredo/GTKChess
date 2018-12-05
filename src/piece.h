//
//  piece.h
//  CIS 308 Final Project
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

#ifndef piece_h
#define piece_h

// Include user-defined header files.
#include "types.h"

// Prototype Piece struct
typedef struct Piece Piece;

// Prototype check_valid_move function pointer
typedef boolean (* check_valid_move)(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos);

// Piece Struct
struct Piece{
	Color team;
	char rank;
	check_valid_move check_move;
	char* imageLocation;
};

#endif /* end def piece_h */
