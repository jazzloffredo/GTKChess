#ifndef types_h
#define types_h

typedef enum {BLACK, WHITE} Color;
typedef enum {BFALSE, BTRUE} boolean;
typedef enum{FIRST, WAITING, LAST, FINISH} GameState;

typedef struct Position{
	int x;
	int y;
}Position;

#endif