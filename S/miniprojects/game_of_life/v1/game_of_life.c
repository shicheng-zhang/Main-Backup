/*
 * This is a program which runs the Conway's Game of Life using C code. Please note that
 * this is C99 and beyond only as it uses explicited function and parameter declarations
 * which were not present in ANSI C (C89). 
 *
 * The sleeper function provides functionality to the user to sleep for a defined number of milliseconds.
 *
 * The printout function prints out the game grid. Live cells, represented by 1 in the code, prints out
 * as #, while the dead or uninitialised cells, represented by 0 in the code, prints out as just a space.
 *
 * The life_machine function checks if a cell should continue living or dead, die, or be resurrected based
 * on the amount of neighbours it possesses and its current life state.
 *
 * The find_neighbours function finds the neighbours of a cell, runs it through life_machine, and affixes the 
 * future result of the computation to the secondary grid, otherwise interpreted as the next generation of 
 * the game grid.
 *
 * The reaffixtion function superimposes the secondary grid back up onto the main game grid, which is then printed
 * out for the next generation, and so forth.
 *
 * The algorithm is cross-leveled, meaning that the main algorithm, the find_neighbours function, can be either
 * hardcoded, such as using a distinct method to determine if the cell is affixed to the wall or not, thereby
 * needing another formula, such as for instance grid [y][x] = grid [y - 1][x] + grid [y - 1][x - 1] ... and so
 * forth, or one can use a algorithm such as the one I utilised, which is a softcoded, variable dependency algorithm.
 *
 * Please refer to this program on my GitHub if you wish to utilise it in your own programs.
 *
 * Copyright 2025, 04/10/25, Shicheng Z
 *
 * */
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sleeper (int milliseconds) {
    struct timespec req = {0};
    req.tv_sec = milliseconds / 1000;
    req.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep (&req, NULL);
} int printout (int x_size, int y_size, int grid [y_size][x_size], int generation);
int printout (int x_size, int y_size, int grid [y_size][x_size], int generation) {
    printf ("    ");
    for (int x = 0; x < x_size; x++) {printf ("%d   ", x % 10);} 
    printf (" x\n    ");
    for (int x3 = 0; x3 < x_size; x3++) {printf ("-   ");}
    printf ("\n"); 
    for (int y = 0; y < y_size; y++) {
        printf ("%d |", y % 10);
        for (int x1 = 0; x1 < x_size; x1++) {
            if (grid [y][x1] == 0) {printf ("   |");} 
            else {printf (" # |");}
        } printf ("\n    ");
        for (int x2 = 0; x2 < x_size; x2++) {printf ("-   ");}
        printf ("\n");
    } printf ("y\n\nGeneration: %d\n", generation);
    return 0;
} int life_machine (int neighbours, int life_state);
int life_machine (int neighbours, int life_state) {
    if (life_state == 0) {
        if (neighbours == 3) {life_state = 1;} 
        else {;}
    } else {
        if ((neighbours == 2) || (neighbours == 3)) {;}
        else {life_state = 0;}
    } return life_state;
} int find_neighbours (int size_x, int size_y, int main_grid [size_y][size_x], int sub_grid [size_y][size_x]); 
int find_neighbours (int size_x, int size_y, int main_grid [size_y][size_x], int sub_grid [size_y][size_x]) {
    int neighbour_vector [3] = {-1, 0, 1};
    int actual_neighbours = 0;
    int current_y = 0, current_x = 0;
    for (int y4 = 0; y4 < size_y; y4++) {
        for (int x4 = 0; x4 < size_x; x4++) {
            for (int cy = 0; cy < 3; cy++) {
                for (int cx = 0; cx < 3; cx++) {
                    current_y = y4 + neighbour_vector [cy];
                    current_x = x4 + neighbour_vector [cx];
                    if ((cx == 1) && (cy == 1)) {continue;}
                    else {
                        if ((current_x > -1) && (current_x < size_x)) {
                            if ((current_y > -1) && (current_y < size_y)) {
                                if (main_grid [current_y][current_x] == 1) {actual_neighbours++;}
                                else {;}
                            } else {continue;}
                        } else {continue;}
                    }
                }
            } sub_grid [y4][x4] = life_machine (actual_neighbours, main_grid [y4][x4]);
            actual_neighbours = 0;
        }  
    } return 0;
} int reaffixtion (int size_x, int size_y, int main_grid [size_y][size_x], int sub_grid [size_y][size_x]);
int reaffixtion (int size_x, int size_y, int main_grid [size_y][size_x], int sub_grid [size_y][size_x]) {
    for (int y5 = 0; y5 < size_y; y5++) {
        for (int x5 = 0; x5 < size_x; x5++) {main_grid [y5][x5] = sub_grid [y5][x5];}
    } return 0;
} void main_algorithm () {
    //Game mode is always set to automatically generate
    int size_x = 0, size_y = 0;
    x_len_reinput:
    printf ("Enter the x size of the grid:");
    scanf ("%d", &size_x);
    if ((size_x < 2) || (size_x > 99)) {
        printf ("Size is too big or small (0 < x < 99).\n");
        goto x_len_reinput;
    } 
    y_len_reinput: 
    printf ("Enter the y size of the grid:");
    scanf ("%d", &size_y);
    if ((size_y < 2) || (size_y > 99)) {
        printf ("Size is too big or small (0 < y < 99).\n");
        goto y_len_reinput;
    } system ("clear"); 
    int main_grid [size_y][size_x];
    int sub_grid [size_y][size_x];
    for (int a = 0; a < size_y; a++) {
        for (int b = 0; b < size_x; b++) {
            main_grid [a][b] = 0; //Both uninitialised
            sub_grid [a][b] = 0;  
        }
    } int num_seeds = 0;
    printout (size_x, size_y, main_grid, 0);
    printf ("Enter how many seed coordinates that you would like to enter:");
    scanf ("%d", &num_seeds);
    int seeds [num_seeds][2]; //0 is x, 1 is y (index values)
    system ("clear");
    printout (size_x, size_y, main_grid, 0);
    for (int z = 0; z < num_seeds; z++) {
        printout (size_x, size_y, main_grid, 0);   
        seed_x_reinput:
        printf ("Enter the x coordinate of the %dth seed:", z);
        scanf ("%d", &seeds [z][0]);
        if ((seeds [z][0] < 0) || (seeds [z][0] > size_x - 1)) {
            printf ("Seed X value out of bounds (0 < x < size_x).\n");
            goto seed_x_reinput;  
        } 
        seed_y_reinput:
        printf ("Enter the y coordinate of the %dth seed:", z);
        scanf ("%d", &seeds [z][1]);
        if ((seeds [z][1] < 0) || (seeds [z][1] > size_y - 1)) {
            printf ("Seed Y value out of bounds (0 < x < size_y).\n");
            goto seed_y_reinput;  
        } if (main_grid [seeds [z][1]][seeds [z][0]] == 0) {
            main_grid [seeds [z][1]][seeds [z][0]] = 1;
            sub_grid [seeds [z][1]][seeds [z][0]] = 1;
        } else {
            system ("clear");
            printout (size_x, size_y, main_grid, 0);
            printf ("Grid already seeded. Input Another.\n");
            goto seed_x_reinput; 
        }system ("clear");
    } printout (size_x, size_y, main_grid, 0);
    int max_generation = 0;
    generation_input:
    printf ("How many generations do you want the game to run?");
    scanf ("%d", &max_generation);
    if (max_generation < 1) {
        printf ("You cannot run for less than 1 generation.");
        goto generation_input;
    } int ms_delay_time = 0;
    delay_reinput:
    printf ("Enter the time of the delay you wish to impose is ms:");
    scanf ("%d", &ms_delay_time);
    if (ms_delay_time < 75) {
        int continuation = 0;
        re_input_delay:
        printf ("Having a delay time under 75 ms is not recommended. If you wish to continue, enter 1, if not, enter 0:");
        scanf ("%d", &continuation);
        if (continuation == 0) {goto delay_reinput;} 
        else if (continuation == 1) {;} 
        else {
            printf ("Invalid Choice.\n");
            goto re_input_delay;
        }
    } system ("clear"); 
    for (int loop = 0; loop < max_generation; loop++) {
        find_neighbours (size_x, size_y, main_grid, sub_grid);
        reaffixtion (size_x, size_y, main_grid, sub_grid);
        printout (size_x, size_y, main_grid, loop);
        sleeper (ms_delay_time);
        system ("clear");
    }
} int main () {
    main_algorithm ();
    return 0;
}
