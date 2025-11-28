/*
 * Leetcode Question 25: Reverse Nodes in k-Group.
 * Difficulty: Hard
 * Started: 02/01/25 (DD/MM/YY)
 * Completed: 02/01/25 (DD/YY/MM)
 *
 * This is a solution to Leetcode Question 25: Reverse Nodes in k-Group.
 * It finds defined nodes of a specific size within a array, reverses the 
 * values of the individual nodes, and reaffixes them to the original array.
 *
 * This solves the problem and returns the original array with all the
 * possible nodes reversed in value order.
 *
 * Please reference this program should you wish to incorporate any code into 
 * your own programs.
 *
 * Copyright 2025, Shicheng Z
 *
 * */
#include <stdio.h>
void main_algorithm () {
    int size_array = 0;
    printf ("Enter the size of the array:");
    scanf ("%d", &size_array);
    int array [size_array];
    //Inputs
    for (int x = 0; x < size_array; x++) {
        printf ("Enter attribute [%d] of the array:", x);
        scanf ("%d", &array [x]);
    } int node_size = 0;
    printf ("Enter the size of the individual nodes:");
    scanf ("%d", &node_size);
    //Node size generation
    int amt_nodes = (size_array - (size_array % node_size)) / node_size;
    int node_array [amt_nodes][node_size];
    int count_og_node = 0;
    int count_node_arr1 = 0, count_node_arr2 = 0;
    //Node Formation
    while (1) {
        if (count_node_arr1 == amt_nodes) {
            break;
        } else {
            if (count_node_arr2 == node_size) {
                count_node_arr2 = 0;
                count_node_arr1++;
            } else {
                node_array [count_node_arr1][count_node_arr2] = array [count_og_node];
                count_og_node++;
                count_node_arr2++;
            }
        }
    } /*Node reversal*/ if (node_size % 2 == 1) {
        int skip_node_arr = (node_size - 1) / 2;
        int banned_list [skip_node_arr][2];
        int banned_list_count = 0;
        int clear_check = 1;
        for (int j = 0; j < skip_node_arr; j++) {
            banned_list [j][0] = -1;
            banned_list [j][1] = -1;
        } for (int y = 0; y < amt_nodes; y++) {
            for (int z = 0; z < node_size; z++) {
                for (int a = 0; a < node_size; a++) {
                    if (((z == skip_node_arr) || (a == skip_node_arr)) || ((z == skip_node_arr) && (a == skip_node_arr))) {
                        continue;
                    } else {
                        if ((a + z) == (node_size - 1)) {
                            for (int b = 0; b < skip_node_arr; b++) {
                                if ((banned_list [b][0] == a) && (banned_list [b][1] == z)) {
                                    clear_check = 0;
                                } else {
                                    if ((banned_list [b][0] == z) && (banned_list [b][1] == a)) {
                                        clear_check = 0;
                                    } else {
                                        ;
                                    }
                                }
                            } if (clear_check == 1) {
                                int temp = 0;
                                temp = node_array [y][z];
                                node_array [y][z] = node_array [y][a];
                                node_array [y][a] = temp;
                                banned_list [banned_list_count][0] = a;
                                banned_list [banned_list_count][1] = z;
                                banned_list_count++;
                            } else {
                                clear_check = 1;
                            }
                        } else {
                            ;
                        }
                    }
                }
            } for (int c = 0; c < skip_node_arr; c++) {
                banned_list [c][0] = -1;
                banned_list [c][1] = -1;
            } banned_list_count = 0;
            clear_check = 1;
        }
    } else {
        int banned_list2 [node_size / 2][2];
        int banned_list_count2 = 0;
        int clear_check2 = 1;
        for (int i = 0; i < node_size / 2; i++) {
            banned_list2 [i][0] = -1;
            banned_list2 [i][1] = -1;
        } for (int d = 0; d < amt_nodes; d++) {
            for (int e = 0; e < node_size; e++) {
                for (int f = 0; f < node_size; f++) {
                    if ((e + f) == (node_size - 1)) {
                        for (int g = 0; g < node_size / 2; g++) {
                            if ((banned_list2 [g][0] == e) && (banned_list2 [g][1] == f)) {
                                clear_check2 = 0;
                            } else {
                                if ((banned_list2 [g][0] == f) && (banned_list2 [g][1] == e)) {
                                    clear_check2 = 0;
                                } else {
                                    ;
                                }
                            }
                        } if (clear_check2 == 1) {
                            int temp2 = 0;
                            temp2 = node_array [d][e];
                            node_array [d][e] = node_array [d][f];
                            node_array [d][f] = temp2;
                            banned_list2 [banned_list_count2][0] = e;
                            banned_list2 [banned_list_count2][1] = f;
                            banned_list_count2++;
                        }
                    } else {
                        ;
                    }
                }
            } for (int h = 0; h < node_size / 2; h++) {
                banned_list2 [h][0] = -1;
                banned_list2 [h][1] = -1;
            } banned_list_count2 = 0;
            clear_check2 = 1;
        }
    } /*Re-Incooporation*/ 
    int count_node_1 = 0, count_node_2 = 0;
    int count_og_array = 0;
    while (1) {
        if (count_node_1 == amt_nodes) {
            break;
        } else {
            if (count_node_2 == node_size) {
                count_node_2 = 0;
                count_node_1++;
            } else {
                array [count_og_array] = node_array [count_node_1][count_node_2];
                count_og_array++;
                count_node_2++;
            }
        }
    } /*Computation Complete*/
    /*Print-Out*/
    printf ("[");
    for (int k = 0; k < size_array; k++) {
        printf ("%d ", array [k]);
    } printf ("]\n");
} int main () {
    main_algorithm ();
    return 0;
}
