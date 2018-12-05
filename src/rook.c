#include <stdlib.h>

#include "rook.h"
#include "types.h"
#include "piece.h"

// generates a new Piece object that is a Rook.
Piece * make_new_rook(Color c, int xPos, int yPos){
	Rook * r = malloc(sizeof(Rook));
	
	r -> pos.x = xPos;
	r -> pos.y = yPos;
	r -> piece.team = c;
	r -> piece.rank = 'r';
	r -> piece.check_move = check_valid_move_rook;
	r -> piece.imageLocation = (c == BLACK ? "chess_pieces/rook_black.png" : "chess_pieces/rook_white.png");
	
	return (Piece *)r;
}

// given a board, current selected piece, current position and new position
// checks if the rook has made a valid move
boolean check_valid_move_rook(Piece pieces[8][8], Piece * self, Position curPos, Position newPos){
	Rook * r = (Rook *) self;
	
	int curY, curX;
	
	// generate valid move array
	boolean possible_moves[8][8];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			possible_moves[i][j] = BFALSE;
		}
	}
	
	//check up
	curY = curPos.y - 1;
	while(curY >= 0){
		if(pieces[curPos.x][curY].team == self->team) break;
		else if(pieces[curPos.x][curY].team != self->team){
			possible_moves[curPos.x][curY] = BTRUE;
			break;
		}
		else{
			possible_moves[curPos.x][curY] = BTRUE;
			curY--;
		}
	}
	
	
	//check down
	curY = curPos.y + 1;
	while(curY <= 7){
		if(pieces[curPos.x][curY].team == self->team) break;
		else if(pieces[curPos.x][curY].team != self->team){
			possible_moves[curPos.x][curY] = BTRUE;
			break;
		}
		else{
			possible_moves[curPos.x][curY] = BTRUE;
			curY++;
		}
	}
	
	
	//check right
	curX = curPos.x + 1;
	while(curX <= 7){
		if(pieces[curX][curPos.y].team == self->team) break;
		else if(pieces[curX][curPos.y].team != self->team){
			possible_moves[curX][curPos.y] = BTRUE;
			break;
		}
		else{
			possible_moves[curX][curPos.y] = BTRUE;
			curX++;
		}
	}
	
	//check left
	curX = curPos.x - 1;
	while(curX >= 0){
		if(pieces[curX][curPos.y].team == self->team) break;
		else if(pieces[curX][curPos.y].team != self->team){
			possible_moves[curX][curPos.y] = BTRUE;
			break;
		}
		else{
			possible_moves[curX][curPos.y] = BTRUE;
			curX--;
		}
	}
	
	if(possible_moves[newPos.x][newPos.y] == BTRUE) return BTRUE;
	else return BFALSE;
	
}
