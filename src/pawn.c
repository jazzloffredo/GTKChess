//
//  pawn.c
//  CIS 308 Final Project
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

// Include pre-defined header files
#include <stdlib.h>

// Include user-defined header files
#include "pawn.h"
#include "types.h"
#include "piece.h"

// generates a new Piece pointer that is a Pawn.
Piece * make_new_pawn(Color c, int xPos, int yPos){
	Pawn * p = malloc(sizeof(Pawn));
	
	p -> piece.team = c;
	p -> piece.rank = 'p';
	p -> piece.check_move = check_valid_move_pawn;
	p -> pos.x = xPos;
	p -> pos.y = yPos;
	p -> moved = BFALSE;
	p -> piece.imageLocation = (c == BLACK ? "chess_pieces/pawn_black.png" : "chess_pieces/pawn_white.png");
	
	return (Piece *)p;
}

// given a board, current selected piece, current position and new position
// checks if the pawn has made a valid move
boolean check_valid_move_pawn(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos){
	Pawn * p = (Pawn *) self;
	
	// generate valid move array
	boolean possible_moves[8][8];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			possible_moves[i][j] = BFALSE;
		}
	}
	
	if(self->team == WHITE){
		if(!(p->moved)){
			if(curPos.y > 0 && !(pieces[curPos.x][curPos.y - 1]))
				possible_moves[curPos.x][curPos.y - 1] = BTRUE;
			if(curPos.y > 0 && curPos.x < 7 && pieces[curPos.x + 1][curPos.y - 1] -> team == BLACK)
				possible_moves[curPos.x + 1][curPos.y - 1] = BTRUE;
			if(curPos.y > 0 && curPos.x > 0 && pieces[curPos.x - 1][curPos.y - 1] -> team == BLACK)
				possible_moves[curPos.x - 1][curPos.y - 1] = BTRUE;
		}
		else{
			if(!(pieces[curPos.x][curPos.y - 1] && !(pieces[curPos.x][curPos.y - 2])))
			   	possible_moves[curPos.x][curPos.y - 2] = BTRUE;
			if(!(pieces[curPos.x][curPos.y - 1]))
				possible_moves[curPos.x][curPos.y - 1] = BTRUE;
			if(curPos.x < 7 && pieces[curPos.x + 1][curPos.y - 1] -> team == BLACK)
				possible_moves[curPos.x + 1][curPos.y - 1] = BTRUE;
			if(curPos.x > 0 && pieces[curPos.x - 1][curPos.y - 1] -> team == BLACK)
				possible_moves[curPos.x - 1][curPos.y - 1] = BTRUE;
		}
	}
	else{
		if(!(p->moved)){
			if(curPos.y < 7 && !(pieces[curPos.x][curPos.y + 1]))
				possible_moves[curPos.x][curPos.y + 1] = BTRUE;
			if(curPos.y < 7 && curPos.x > 0 && pieces[curPos.x - 1][curPos.y + 1] -> team == WHITE)
				possible_moves[curPos.x - 1][curPos.y + 1] = BTRUE;
			if(curPos.y < 7 && curPos.x < 7 && pieces[curPos.x + 1][curPos.y + 1] -> team == WHITE)
				possible_moves[curPos.x + 1][curPos.y + 1] = BTRUE;
		}
		else{
			if(!(pieces[curPos.x][curPos.y + 1] && !(pieces[curPos.x][curPos.y + 2])))
			   	possible_moves[curPos.x][curPos.y + 2] = BTRUE;
			if(!(pieces[curPos.x][curPos.y + 1]))
				possible_moves[curPos.x][curPos.y - 1] = BTRUE;
			if(curPos.x < 7 && pieces[curPos.x + 1][curPos.y + 1] -> team == WHITE)
				possible_moves[curPos.x + 1][curPos.y + 1] = BTRUE;
			if(curPos.x > 0 && pieces[curPos.x - 1][curPos.y + 1] -> team == WHITE)
				possible_moves[curPos.x - 1][curPos.y + 1] = BTRUE;
		}
	}
			   
	if(possible_moves[newPos.x][newPos.y] == BTRUE) return BTRUE;
	else return BFALSE;
}
