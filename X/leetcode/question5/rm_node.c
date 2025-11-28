/*
 * Leetcode Question 19. Remove Nth Node from End of List
 *
 * This is a solution to Leetcode Quesiton 19, Remove Nth Node from End of List.
 * It requires that the nth node from the end of the array be removed from the array.
 * This program utilises a recounting formula to determine the node that is to be removed,
 * and omits that node in the output of the program, tehreby achieving that effect, as
 * C does not have dynamic size allocation for arrays.
 *
 * Please reference this program should you wish to use it in your own programs.
 *
 * Copyright 2025, Shicheng.Z, 22/01/24
 * */
#include <stdio.h>
void main_algorithm () {
    int size_node = 0;
    printf ("Enter the size of the node:");
    scanf ("%d", &size_node);
    int array [size_node];
    for (int x = 0; x < size_node; x++) {
        printf ("Enter array [%d]:", x);
        scanf ("%d", &array [x]);    
    } int remover = 0;
    printf ("Enter the node to be removed:");
    scanf ("%d", &remover);
    int actual_remover = size_node - remover;
    printf ("[");
    for (int y = 0; y < size_node; y++) {
        if (y != actual_remover) {
            printf ("%d ", array [y]);
        } else {
            ;
        }
    } printf ("]\n");
} int main () {
    main_algorithm ();
    return 0;
}
