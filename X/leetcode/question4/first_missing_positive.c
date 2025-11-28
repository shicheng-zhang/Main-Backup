/*
 *  Leetcode Question 41. First Missing Positive. Hard Difficulty
 *
 *  This is a solution to Leetcode Question 41, First Missing Positive,
 *  which has a hard difficulty. The aim is to find the lowest positive 
 *  number not included within the array n [*], where n can have negative
 *  and positive values. It uses a tracking array and distinguishing algorithm
 *  to find the lowest number not present in the array, and then prints it out
 *  in the final step.
 *
 *  Please reference this program should you use it in your own programs.
 *
 *  Copyright 2025. Shicheng Z. 18/01/25 
 * */
#include <stdio.h>
#include <stdlib.h>
void main_algorithm () {
    int size_arr = 0;
    printf ("Enter the size of the array:");
    scanf ("%d", &size_arr);
    int array [size_arr];
    for (int x = 0; x < size_arr; x++) {
        printf ("Enter attribute:");
        scanf ("%d", &array [x]);
    } int largest = array [0];
    for (int y = 1; y < size_arr; y++) {
        if (largest < array [y]) {
            largest = array [y];
        } else {
            ;
        }
    } int finis = 0;
    if (largest < 0) {
        printf ("1\n");
        exit (0);
    } else {
        int pos_array [largest - 1][2];
        for (int z = 0; z < largest - 1; z++) {
            pos_array [z][0] = z + 1;
            pos_array [z][1] = 0;
        } for (int a = 0; a < size_arr; a++) {
            if (array [a] > 0) {
                pos_array [array [a] - 1][1] = 1;
            } else {
                ;
            }
        } for (int b = 0; b < largest - 1; b++) {
            if (pos_array [b][1] == 0) {
                printf ("%d\n", pos_array [b][0]);
                finis = 1;
                exit (0);
            } else {
                ;
            }
        } if (finis == 0) {
            printf ("%d\n", largest + 1);
        }
    }
} int main () {
    main_algorithm ();
    return 0;
}
