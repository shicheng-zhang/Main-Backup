#include <stdio.h>
int printout (int grid_size_x, int grid_size_y, int grid [grid_size_y][grid_size_x]);
int printout (int grid_size_x, int grid_size_y, int grid [grid_size_y][grid_size_x]) {
    
} void main_algorithm () {  
    int size_x = -1, size_y = -1;
    printf ("Enter the x and y variable:");
    scanf ("%d %d", &size_x, &size_y);
    int gameboard [size_y][size_x];
    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            gameboard [y][x] = -1; //Define and unintialise
        } 
    } int type_game = -1; //Uninitialised
    reinput_game_type:
    printf ("Enter the type of game that you want:"); //0 for Manual Seed, 1 for AI Seed
    scanf ("%d", &type_game);
    if (type_game == 0) {
        //Manual Seed
        manual
    } else if (type_game == 1) {
        //AI Seed
    } else {
        //Error Input
        goto reinput_game_type;
    }
} int main () {
    main_algorithm ();
    return 0;
}
