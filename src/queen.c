#include <stdlib.h>

#include "queen.h"
#include "types.h"
#include "piece.h"

// generates a new Piece object that is a Queen.
Piece * make_new_queen(Color c, int xPos, int yPos){
	Queen * q = malloc(sizeof(Queen));
	
	q -> pos.x = xPos;
	q -> pos.y = yPos;
	q -> piece.team = c;
	q -> piece.rank = 'q';
	q -> piece.check_move = check_valid_move_queen;
	q -> piece.imageLocation = (c == BLACK ? "chess_pieces/queen_black.png" : "chess_pieces/queen_white.png");
	
	return (Piece *)q;
}

// given a board, current selected piece, current position and new position
// checks if the queen has made a valid move
boolean check_valid_move_queen(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos){

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
		if(pieces[curPos.x][curY] -> team == self->team) break;
		else if(pieces[curPos.x][curY] -> team != self->team){
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
		if(pieces[curPos.x][curY] -> team == self->team) break;
		else if(pieces[curPos.x][curY] -> team != self->team){
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
		if(pieces[curX][curPos.y] -> team == self->team) break;
		else if(pieces[curX][curPos.y] -> team != self->team){
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
		if(pieces[curX][curPos.y] -> team == self->team) break;
		else if(pieces[curX][curPos.y] -> team != self->team){
			possible_moves[curX][curPos.y] = BTRUE;
			break;
		}
		else{
			possible_moves[curX][curPos.y] = BTRUE;
			curX--;
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