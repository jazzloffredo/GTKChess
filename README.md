This is a chess application that interfaces with GTK3+ to provide the player(s) with a graphical user interface. The GUI representation of the board is decoupled from an internal representation that updates with each player move. Data validation is contained within each specific knight.c, rook.c, etc. to ensure the pieces are not moved outside their valid bounds. However, we were unable to weave the backend data validation to the front end. In terms of our proposal, we feel that we accomplished a majority of the tasks we set out to complete.

Compilation Instructions:
    "make all" - Generates executable ./chess_app
    "make clean" - Removes all .o files.
