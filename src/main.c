//
//  main.c 
//  CIS 308 Final Project 
//
//  Created by Jazz Loffredo and Zayin Brunson
//  Copyright © 2018 Jazz Loffredo and Zayin Brunson. All rights reserved.
//


#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "piece.h"
#include "types.h"

void fill_grid_with_buttons(GtkWidget *grid);

void init_grid_images(GtkWidget *grid);

void init_internal_board(Piece* pieces[8][8]);

void update_internal_board(Position oldPos, Position newPos); 

void redraw_external_board(GtkWidget *grid, Position oldPos, Position newPos, char * image);

void button_clicked(GtkWidget *widget, gpointer data);

Position find_button_in_grid(GtkGrid *grid, GtkWidget *widget);

GameState gState = FIRST;

Color turn = WHITE;

Piece* pieces[8][8];
GtkWidget       *window;

King * wkk;
King * bkk;

char win1[] = "Player Two Wins!";
char win2[] = "Player One Wins!";

int main(int argc, char *argv[]){
    GtkBuilder      *builder; 
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/chess_interface.glade", NULL);
    
    GtkWidget *grid = GTK_WIDGET(gtk_builder_get_object(builder, "chess_grid"));
    fill_grid_with_buttons(grid);    
    init_grid_images(grid);
	
	init_internal_board(pieces);
	
	
	FILE *f = fopen("file500.txt", "a");
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(pieces[i][j] != NULL){
				fprintf(f, "%c-", pieces[i][j]->rank);
			}
		}
		fprintf(f,"\n");
	}
	fclose(f);
	
	
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
 
    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
	
 
    return 0;
}
 
// called when window is closed
void on_window_main_destroy(){
    gtk_main_quit();
}

// fill each grid container with a button
void fill_grid_with_buttons(GtkWidget *grid){
    GtkWidget *button;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            button = gtk_button_new_with_label(NULL);
            gtk_grid_attach(GTK_GRID(grid), button, i, j, 1, 1);
			g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_clicked), grid);
            gtk_widget_show(button);
        }
    }
}

// set each button to show the appropriate piece image
void init_grid_images(GtkWidget *grid){
	//init rooks
	for(int i = 0, j = 0; i < 2; i++, j+=7){
		GtkWidget *w = gtk_image_new_from_file("chess_pieces/rook_white.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 7);
		gtk_button_set_image(GTK_BUTTON(b), w);
	}
	for(int i = 0, j = 0; i < 2; i++, j+=7){
		GtkWidget *bl = gtk_image_new_from_file("chess_pieces/rook_black.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 0);
		gtk_button_set_image(GTK_BUTTON(b), bl);
	}
	//init knights
	for(int i = 0, j = 1; i < 2; i++, j+=5){
		GtkWidget *w = gtk_image_new_from_file("chess_pieces/knight_white.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 7);
		gtk_button_set_image(GTK_BUTTON(b), w);
	}
	for(int i = 0, j = 1; i < 2; i++, j+=5){
		GtkWidget *bl = gtk_image_new_from_file("chess_pieces/knight_black.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 0);
		gtk_button_set_image(GTK_BUTTON(b), bl);
	}
	//init bishops
	for(int i = 0, j = 2; i < 2; i++, j+=3){
		GtkWidget *w = gtk_image_new_from_file("chess_pieces/bishop_white.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 7);
		gtk_button_set_image(GTK_BUTTON(b), w);
	}
	for(int i = 0, j = 2; i < 2; i++, j+=3){
		GtkWidget *bl = gtk_image_new_from_file("chess_pieces/bishop_black.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 0);
		gtk_button_set_image(GTK_BUTTON(b), bl);
	}
	//init kings and queens
	for(int i = 0, j = 4; i < 2; i++){
		GtkWidget *w = gtk_image_new_from_file("chess_pieces/king_white.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 7);
		gtk_button_set_image(GTK_BUTTON(b), w);
	}
	for(int i = 0, j = 4; i < 2; i++){
		GtkWidget *bl = gtk_image_new_from_file("chess_pieces/king_black.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 0);
		gtk_button_set_image(GTK_BUTTON(b), bl);
	}	
	for(int i = 0, j = 3; i < 2; i++){
		GtkWidget *w = gtk_image_new_from_file("chess_pieces/queen_white.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 7);
		gtk_button_set_image(GTK_BUTTON(b), w);
	}
	for(int i = 0, j = 3; i < 2; i++){
		GtkWidget *bl = gtk_image_new_from_file("chess_pieces/queen_black.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), j, 0);
		gtk_button_set_image(GTK_BUTTON(b), bl);
	}
    //init pawns
    for(int i = 0; i < 8; i++){
		GtkWidget *wp = gtk_image_new_from_file("chess_pieces/pawn_white.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), i, 6);
		gtk_button_set_image(GTK_BUTTON(b), wp);
    }
    for(int i = 0; i < 8; i++){
		GtkWidget *bp = gtk_image_new_from_file("chess_pieces/pawn_black.png");
		GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), i, 1);
		gtk_button_set_image(GTK_BUTTON(b), bp);
	}

}

// setup the internal board with correct pieces
void init_internal_board(Piece* pieces[8][8]){
	
	Piece * p = NULL;
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			pieces[i][j] = p;
		}
	}
	
    Piece * br = make_new_rook(BLACK, 0, 0);
    pieces[0][0] = br;

    Piece * bn = make_new_knight(BLACK, 1, 0);
	pieces[1][0] = bn;
	
	Piece * bb = make_new_bishop(BLACK, 2, 0);
	pieces[2][0] = bb;
	
	Piece * bq = make_new_queen(BLACK, 3, 0);
	pieces[3][0] = bq;
	
	Piece * bk = make_new_king(BLACK, 4, 0);
	pieces[4][0] = bk;
	bkk = (King *)bk;
	
	Piece * bb2 = make_new_bishop(BLACK, 5, 0);
	pieces[5][0] = bb2;
	
	Piece * bn2 = make_new_knight(BLACK, 6, 0);
	pieces[6][0] = bn2;
	
	Piece * br2 = make_new_rook(BLACK, 7, 0);
	pieces[7][0] = br2;
	
	
	for(int i = 0; i < 8; i++){
		Piece * pawn = make_new_pawn(BLACK, i, 1);
		pieces[i][1] = pawn;
	}
	
	for(int i = 0; i < 8; i++){
		Piece * pawn = make_new_pawn(WHITE, i, 6);
		pieces[i][6] = pawn;
	}
	
	
	Piece * wr = make_new_rook(WHITE, 0, 7);
    pieces[0][7] = wr;

    Piece * wn = make_new_knight(WHITE, 1, 7);
	pieces[1][7] = wn;
	
	Piece * wb = make_new_bishop(WHITE, 2, 7);
	pieces[2][7] = wb;
	
	Piece * wq = make_new_queen(WHITE, 3, 7);
	pieces[3][7] = wq;
	
	Piece * wk = make_new_king(WHITE, 4, 7);
	pieces[4][7] = wk;
	wkk = (King *)wk;
	
	Piece * wb2 = make_new_bishop(WHITE, 5, 7);
	pieces[5][7] = wb2;
	
	Piece * wn2 = make_new_knight(WHITE, 6, 7);
	pieces[6][7] = wn2;
	
	Piece * wr2 = make_new_rook(WHITE, 7, 7);
	pieces[7][7] = wr2;
	
	
	
	/*Piece * br = make_new_rook(BLACK, 0, 0);
    pieces[0][0] = br;

    Piece * bn = make_new_knight(BLACK, 0, 1);
	pieces[0][1] = bn;
	
	Piece * bb = make_new_bishop(BLACK, 0, 2);
	pieces[0][2] = bb;
	
	Piece * bq = make_new_queen(BLACK, 0, 3);
	pieces[0][3] = bq;
	
	Piece * bk = make_new_king(BLACK, 0, 4);
	pieces[0][4] = bk;

	Piece * bb2 = make_new_bishop(BLACK, 0, 5);
	pieces[0][5] = bb2;
	
	Piece * bn2 = make_new_knight(BLACK, 0, 6);
	pieces[0][6] = bn2;
	
	Piece * br2 = make_new_rook(BLACK, 0, 7);
	pieces[0][7] = br2;
	
	
	for(int i = 0; i < 8; i++){
		Piece * pawn = make_new_pawn(BLACK, 1, i);
		pieces[1][i] = pawn;
	}
	
	for(int i = 0; i < 8; i++){
		Piece * pawn = make_new_pawn(WHITE, 6, i);
		pieces[6][i] = pawn;
	}
	
	
	Piece * wr = make_new_rook(WHITE, 7, 0);
    pieces[7][0] = wr;

    Piece * wn = make_new_knight(WHITE, 7, 1);
	pieces[7][1] = wn;
	
	Piece * wb = make_new_bishop(WHITE, 7, 2);
	pieces[7][2] = wb;
	
	Piece * wq = make_new_queen(WHITE, 7, 3);
	pieces[7][3] = wq;
	
	Piece * wk = make_new_king(WHITE, 7, 4);
	pieces[7][4] = wk;
	
	Piece * wb2 = make_new_bishop(WHITE, 7, 5);
	pieces[7][5] = wb2;
	
	Piece * wn2 = make_new_knight(WHITE, 7, 6);
	pieces[7][6] = wn2;
	
	Piece * wr2 = make_new_rook(WHITE, 7, 7);
	pieces[7][7] = wr2;
	*/
	
}

void button_clicked(GtkWidget *widget, gpointer data){
	GtkWidget *grid = data;
	
	GtkWidget *dialog;
	GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
	
	
	static Position firstPos;
	static Position secondPos;
	
	FILE *f = fopen("file.txt", "a");
	switch(gState){
		case FIRST:
			firstPos = find_button_in_grid(GTK_GRID(grid), widget);
			if(pieces[firstPos.x][firstPos.y] != NULL && pieces[firstPos.x][firstPos.y] -> team == turn){
				gState = WAITING;
			}
			break;
		case WAITING:
			secondPos = find_button_in_grid(GTK_GRID(grid), widget);
			fprintf(f,"1st: %d, %d -> %c\n", firstPos.x, firstPos.y, pieces[firstPos.x][firstPos.y]->rank);
			fprintf(f,"2nd: %d, %d\n", secondPos.x, secondPos.y);
	
			
			/*if(pieces[firstPos.x][firstPos.y] -> check_move(pieces, pieces[firstPos.x][firstPos.y], firstPos, secondPos) == BTRUE){
				fprintf(f,"WEREIN");
				//update_internal_board(firstPos, secondPos);
				//redraw_external_board(grid, firstPos, secondPos, pieces[firstPos.x][firstPos.y]->imageLocation);
				//turn = turn == WHITE ? BLACK : WHITE;
			}*/
			
			fclose(f);
			redraw_external_board(grid, firstPos, secondPos, pieces[firstPos.x][firstPos.y]->imageLocation);
			update_internal_board(firstPos, secondPos);
			turn = turn == WHITE ? BLACK : WHITE;
			gState = FIRST;
			break;
		case LAST:
			if(turn == WHITE){
			dialog = gtk_message_dialog_new (window,
										 flags,
										 GTK_MESSAGE_ERROR,
										 GTK_BUTTONS_CLOSE,
										 "%s",win1);
			gtk_dialog_run (GTK_DIALOG (dialog));
			gtk_widget_destroy (dialog);
			}
			else{
			dialog = gtk_message_dialog_new (window,
										 flags,
										 GTK_MESSAGE_ERROR,
										 GTK_BUTTONS_CLOSE,
										 "%s",win2);
			gtk_dialog_run (GTK_DIALOG (dialog));
			gtk_widget_destroy (dialog);
			}
			gState = FINISH;
	}
	if((bkk->alive == 0 || wkk->alive == 0) && gState != FINISH){
		gState = LAST;
		button_clicked(widget, data);
	}
}

// returns x,y position of button clicked in grid
Position find_button_in_grid(GtkGrid *grid, GtkWidget *widget){
	Position retPos;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(gtk_grid_get_child_at(grid, i, j) == widget){
				retPos.x = i;
				retPos.y = j;
				return retPos;
			}
		}
	}
	
	
	retPos.x = -1;
	retPos.y = -1;
	return retPos;
	
}

// updates internal board to match user behavior
void update_internal_board(Position oldPos, Position newPos){
	pieces[newPos.x][newPos.y] = pieces[oldPos.x][oldPos.y];	
	pieces[oldPos.x][oldPos.y] = NULL;
}

void redraw_external_board(GtkWidget *grid, Position oldPos, Position newPos, char * image){
		if((King *)pieces[newPos.x][newPos.y] == bkk){
			bkk->alive = 0;
		}
		if((King *)pieces[newPos.x][newPos.y] == wkk){
			wkk->alive = 0;
		}
		FILE *f = fopen("file.txt", "a");	
		fprintf(f,"1st: %d, %d CHANGE\n", oldPos.x, oldPos.y);
		fprintf(f,"2nd: %d, %d CHANGE\n", newPos.x, newPos.y);
		fprintf(f,"%s\n",image);
		fclose(f);
		GtkWidget *oldButton = gtk_grid_get_child_at(GTK_GRID(grid), oldPos.x, oldPos.y);
		GtkWidget *newButton = gtk_grid_get_child_at(GTK_GRID(grid), newPos.x, newPos.y);
		GtkWidget *oldImage = gtk_image_new_from_file(image);
		//GtkWidget *b = gtk_grid_get_child_at(GTK_GRID(grid), oldPos.x, oldPos.y);
		//GtkWidget *oldImage = gtk_button_get_image(GTK_BUTTON(b));
		gtk_button_set_image(GTK_BUTTON(oldButton), NULL);
		//gtk_button_set_image(GTK_BUTTON(newButton), oldImage);
		gtk_button_set_image(GTK_BUTTON(newButton), oldImage);
}
