#include <stdlib.h>

#include "knight.h"
#include "types.h"
#include "piece.h"

// generates a new Piece object that is a Knight.
Piece * make_new_knight(Color c, int xPos, int yPos){
	Knight * n = malloc(sizeof(Knight));
	
	n -> pos.x = xPos;
	n -> pos.y = yPos;
	n -> piece.team = c;
	n -> piece.rank = 'n';
	n -> piece.check_move = check_valid_move_knight;
	n -> piece.imageLocation = (c == BLACK ? "chess_pieces/knight_black.png" : "chess_pieces/knight_white.png");
	
	return (Piece *)n;
}

// given a board, current selected piece, current position and new position
// checks if the bishop has made a valid move
boolean check_valid_move_knight(Piece* pieces[8][8], Piece * self, Position curPos, Position newPos){
	int xRightOne = curPos.x + 1;
	int xLeftOne = curPos.x - 1;
	int xRightTwo = curPos.x + 2;
	int xLeftTwo = curPos.x - 2;
	
	int yUpOne = curPos.y - 1;
	int yDownOne = curPos.y + 1;
	int yUpTwo = curPos.y - 2;
	int yDownTwo = curPos.y + 2;
	
	// generate valid move array
	boolean possible_moves[8][8];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			possible_moves[i][j] = BFALSE;
		}
	}
	
	// check 2up 1right
	if(yUpTwo >= 0 && xRightOne <= 7 && (pieces[xRightOne][yUpTwo] -> team != self->team || !(pieces[xRightOne][yUpTwo]))){
		possible_moves[xRightOne][yUpTwo] = BTRUE;
	}
	
	// check 2up 1left
	if(yUpTwo >= 0 && xLeftOne >= 0 && (pieces[xLeftOne][yUpTwo] -> team != self->team || !(pieces[xRightOne][yUpTwo]))){
		possible_moves[xLeftOne][yUpTwo] = BTRUE;
	}
	
	// check 2right 1up
	if(xRightTwo <= 7 && yUpOne >= 0 && (pieces[xRightTwo][yUpOne] -> team != self->team || !(pieces[xRightTwo][yUpOne]))){
		possible_moves[xRightTwo][yUpOne] = BTRUE;
	}
	
	// check 2right 1down
	if(xRightTwo <= 7 && yDownOne <= 7 && (pieces[xRightTwo][yDownOne] -> team != self->team || !(pieces[xRightTwo][yDownOne]))){
		possible_moves[xRightTwo][yDownOne] = BTRUE;
	}
	
	// check 2down 1right
	if(yDownTwo <= 7 && xRightOne <= 7 && (pieces[xRightOne][yDownTwo] -> team != self->team || !(pieces[xRightOne][yDownTwo]))){
		possible_moves[xRightOne][yDownTwo] = BTRUE;
	}
	
	// check 2down 1left
	if(yDownTwo <= 7 && xLeftOne >= 0 && (pieces[xLeftOne][yDownTwo] -> team != self->team || !(pieces[xLeftOne][yDownTwo]))){
		possible_moves[xLeftOne][yDownTwo] = BTRUE;
	}
	
	//check 2left 1up
	if(xLeftTwo >= 0 && yUpOne >= 0 && (pieces[xLeftTwo][yUpOne] -> team != self->team || !(pieces[xLeftTwo][yUpOne]))){
		possible_moves[xLeftTwo][yUpOne] = BTRUE;
	}
	
	// check 2left 1down
	if(xLeftTwo >= 0 && yDownOne <= 7 && (pieces[xLeftTwo][yDownOne] -> team != self->team || !(pieces[xLeftTwo][yDownOne]))){
		possible_moves[xLeftTwo][yDownOne] = BTRUE;
	}
	
	if(possible_moves[newPos.x][newPos.y] == BTRUE) return BTRUE;
	else return BFALSE;
	
}