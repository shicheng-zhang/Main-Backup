/*
 * Leetcode Question 23. Merge K Sorted Kists
 *
 * This is a solution to Leetcode Question 23: Merge k sorted lists. 
 * It uses a 2D array to store multiple lists, then stores it in one giant list,
 * compensates for mini-list length discrepancy using a nullification mechanism, 
 * and then sorts the list.
 *
 * Example:
 *  [[1, 4, 5], [1, 3, 4], [2, 6]]
 *  Becomes:
 *  [1, 1, 2, 3, 4, 4, 5, 6]
 *
 * Please reference this program if you wish to use the algorithm in your own programs.
 * Copyright 2024, Shicheng Z
 **/
#include <stdio.h>
#include <stdlib.h>
void main_algorithm () {
    int arr_count = 0;
    printf ("Enter the amount of arrays:");
    scanf ("%d", &arr_count);
    int max_arr_size = 0;
    printf ("Enter the maximum size a individual array can be:");
    scanf ("%d", &max_arr_size);
    int default_non_inclusive = 0;
    printf ("Enter any number that will not be included within this list as placeholder:");
    scanf ("%d", &default_non_inclusive);
    if ((arr_count == 0) || (max_arr_size == 0)) {
        printf ("[]\n");
        exit (0);
    } else {
        ;
    } int array [arr_count][max_arr_size];
    for (int x = 0; x < arr_count; x++) {
        printf ("\nArray %d:\n", x + 1);
        for (int y = 0; y < max_arr_size; y++) {
            printf ("Attribute [%d] (Enter the placeholder if there is not a value there, it will be nullified.)", y);
            scanf ("%d", &array [x][y]);
        }
    } int recountable_arr_reset_1 = 0;
    int recountable_arr_reset_2 = 0;
    int recountable_arr_reset_middle = 0;
    int array_middle [arr_count * max_arr_size];
    for (int c = 0; c < arr_count * max_arr_size; c++) {
        array_middle [c] = default_non_inclusive;  
    } printf ("%d, %d, %d\n", arr_count, max_arr_size, arr_count * max_arr_size);
    while (1) {
        if (recountable_arr_reset_1 == arr_count) {
            break;
        } else {
            if (recountable_arr_reset_2 == max_arr_size) {
                recountable_arr_reset_2 = 0;
                recountable_arr_reset_1++;
            } else {
                if (array [recountable_arr_reset_1][recountable_arr_reset_2] != default_non_inclusive) {
                    array_middle [recountable_arr_reset_middle] = array [recountable_arr_reset_1][recountable_arr_reset_2];
                    recountable_arr_reset_middle++;
                    recountable_arr_reset_2++;
                } else {
                    recountable_arr_reset_2++;
                }
            }
        }
    } int array_final [recountable_arr_reset_middle];
    for (int d = 0; d < recountable_arr_reset_middle; d++) {
        array_final [d] = array_middle [d];
    }for (int z = 0; z < arr_count * max_arr_size - 1; z++) {
        for (int a = 0; a < arr_count * max_arr_size - 1; a++) {
            int temporary = 0;
            if (array_final [a] > array_final [z]) {
                temporary = array_final [a];
                array_final [a] = array_final [z];
                array_final [z] = temporary;
            } else {
                ;
            }
        }
    } printf ("["); 
    for (int b = 0; b < arr_count * max_arr_size - 1; b++) {
        if (array_final [b] != default_non_inclusive) {
            printf ("%d", array_final [b]);
        };
        if (b < arr_count * max_arr_size - 2) {
            printf (", ");
        }
    } printf ("]\n");
} int main () {
    main_algorithm ();
    return 0;
} 
