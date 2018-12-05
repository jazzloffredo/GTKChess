//
//  bishop.c 
//  CIS 308 Final Project 
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//

// Include pre-defined header files.
#include <stdlib.h>

// Include user-defined header files.
#include "bishop.h"
#include "types.h"
#include "piece.h"

// generates a new Piece pointer that is a Bishop.
Piece * make_new_bishop(Color c, int xPos, int yPos){
	Bishop * b = malloc(sizeof(Bishop));
	
	b -> pos.x = xPos;
	b -> pos.y = yPos;
	b -> piece.team = c;
	b -> piece.rank = 'b';
	b -> piece.check_move = check_valid_move_bishop;
	b -> piece.imageLocation = (c == BLACK ? "chess_pieces/bishop_black.png" : "chess_pieces/bishop_white.png");
	
	return (Piece *)b;
}

// given a board, current selected piece, current position and new position
// checks if the bishop has made a valid move
boolean check_valid_move_bishop(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos){

	int curY, curX;
	
	// generate valid move array
	boolean possible_moves[8][8];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			possible_moves[i][j] = BFALSE;
		}
	}
	
	//check up right
	curX = curPos.x + 1;
	curY = curPos.y - 1;
	while(curX <= 7 && curY >= 0){
		if(pieces[curX][curY] -> team == self->team) break;
		else if(pieces[curX][curY] -> team != self->team){
			possible_moves[curX][curY] = BTRUE;
			break;
		}
		else{
			possible_moves[curX][curY] = BTRUE;
			curX++;
			curY--;
		}
	}
	
	
	//check down right
	curX = curPos.x + 1;
	curY = curPos.y + 1;
	while(curX <= 7 && curY <= 7){
		if(pieces[curX][curY] -> team == self->team) break;
		else if(pieces[curX][curY] -> team != self->team){
			possible_moves[curX][curY] = BTRUE;
			break;
		}
		else{
			possible_moves[curX][curY] = BTRUE;
			curX++;
			curY++;
		}
	}
	
	
	//check up left
	curX = curPos.x - 1;
	curY = curPos.y - 1;
	while(curX >= 0 && curY >= 0){
		if(pieces[curX][curY] -> team == self->team) break;
		else if(pieces[curX][curY] -> team != self->team){
			possible_moves[curX][curY] = BTRUE;
			break;
		}
		else{
			possible_moves[curX][curY] = BTRUE;
			curX--;
			curY--;
		}
	}
	
	//check down left
	curX = curPos.x - 1;
	curY = curPos.y + 1;
	while(curX >= 0 && curY <= 7){
		if(pieces[curX][curY] -> team == self->team) break;
		else if(pieces[curX][curY] -> team != self->team){
			possible_moves[curX][curY] = BTRUE;
			break;
		}
		else{
			possible_moves[curX][curY] = BTRUE;
			curX--;
			curY++;
		}
	}
	
	if(possible_moves[newPos.x][newPos.y] == BTRUE) return BTRUE;
	else return BFALSE;
	
}