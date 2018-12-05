//
//  king.c 
//  CIS 308 Final Project 
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

// Include pre-defined header files.
#include <stdlib.h>

// Include user-defined header files.
#include "king.h"
#include "types.h"
#include "piece.h"

// generates a new Piece pointer that is a King.
Piece * make_new_king(Color c, int xPos, int yPos){
	King * k = malloc(sizeof(King));
	
	k -> pos.x = xPos;
	k -> pos.y = yPos;
	k -> alive = 1;
	k -> piece.team = c;
	k -> piece.rank = 'k';
	k -> piece.check_move = check_valid_move_king;
	k -> piece.imageLocation = (c == BLACK ? "chess_pieces/king_black.png" : "chess_pieces/king_white.png");
	
	return (Piece *)k;
}

// given a board, current selected piece, current position and new position
// checks if the king has made a valid move
boolean check_valid_move_king(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos){
	
	// generate valid move array
	boolean possible_moves[8][8];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			possible_moves[i][j] = BFALSE;
		}
	}
	
	//check up
	if((curPos.y > 0 && !(pieces[curPos.x][curPos.y - 1])) || (curPos.y > 0 && (pieces[curPos.x][curPos.y - 1] -> team != self->team)))
		possible_moves[curPos.x][curPos.y - 1] = BTRUE;
		
	//check right
	if((curPos.x < 7 && !(pieces[curPos.x + 1][curPos.y])) || (curPos.x < 7 && (pieces[curPos.x + 1][curPos.y] -> team != self->team)))
		possible_moves[curPos.x + 1][curPos.y] = BTRUE;
	
	//check left
	if((curPos.x > 0 && !(pieces[curPos.x - 1][curPos.y])) || (curPos.x > 0 && (pieces[curPos.x + 1][curPos.y] -> team != self->team)))
		possible_moves[curPos.x - 1][curPos.y] = BTRUE;
	
	//check down
	if((curPos.y < 7 && !(pieces[curPos.x][curPos.y + 1])) || (curPos.y < 7 && (pieces[curPos.x][curPos.y + 1] -> team != self->team)))
		possible_moves[curPos.x][curPos.y + 1] = BTRUE;
	
	//check up right
	if((curPos.y > 0 && curPos.x < 7 && !(pieces[curPos.x + 1][curPos.y - 1])) || (curPos.y > 0 && curPos.x < 7 && (pieces[curPos.x + 1][curPos.y - 1] -> team != self->team)))
		possible_moves[curPos.x + 1][curPos.y - 1] = BTRUE;
	
	//check up left
	if((curPos.y > 0 && curPos.x > 0 && !(pieces[curPos.x - 1][curPos.y - 1])) || (curPos.y > 0 && curPos.x > 0 && (pieces[curPos.x - 1][curPos.y - 1] -> team != self->team)))
		possible_moves[curPos.x - 1][curPos.y - 1] = BTRUE;
		
	// check down right
	if((curPos.y < 7 && curPos.x < 7 && !(pieces[curPos.x + 1][curPos.y + 1])) || (curPos.y < 7 && curPos.x < 7 && (pieces[curPos.x + 1][curPos.y + 1] -> team != self->team)))
		possible_moves[curPos.x + 1][curPos.y + 1] = BTRUE;
	
	// check down left
	if((curPos.y < 7 && curPos.x > 0 && !(pieces[curPos.x - 1][curPos.y + 1])) || (curPos.y < 7 && curPos.x > 0 && (pieces[curPos.x - 1][curPos.y + 1] -> team != self->team)))
		possible_moves[curPos.x - 1][curPos.y + 1] = BTRUE;
	
	
	if(possible_moves[newPos.x][newPos.y] == BTRUE) return BTRUE;
	else return BFALSE;
}