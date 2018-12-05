//
//  types.h
//  CIS 308 Final Project
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

#ifndef types_h
#define types_h

// Typedef enumerators
typedef enum {BLACK, WHITE} Color;
typedef enum {BFALSE, BTRUE} boolean;
typedef enum{FIRST, WAITING, LAST, FINISH} GameState;

// Position Struct - Vector with (x,y)
typedef struct Position{
	int x;
	int y;
}Position;

#endif
