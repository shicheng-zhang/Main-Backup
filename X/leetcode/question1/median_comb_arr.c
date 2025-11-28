/*
 * Leetcode Question 4: Median of Two Sorted Arrays.
 * Difficulty: Hard
 * Started: 29/12/24
 * Completed: 29/12/24
 * Total Completion Time: <1D
 *
 * This is a program made to sovle Question 4 of the Leetcode problem set: 
 * Median of two sorted arrays. It defines two arrays, combines them, and
 * then sorts the combined array to find the median of the new array, which
 * would be out output.
 *
 * Example from Leetcode:
 *     arr1 = [1, 3]
 *     arr2 = [2]
 *     Combined array = [1, 2, 3]
 *     Median of combined array = 2
 * 
 * Please give appropiate credit to this program if you wish to implement it 
 * in your programs.
 *
 * Copyright 2024, Shicheng Z.
 * */
#include <stdio.h>
void main_algorithm () {
    int size_arr1 = 0, size_arr2 = 0;
    printf ("Enter the size of the first array:");
    scanf ("%d", &size_arr1);
    printf ("Enter the size of yje second array:");
    scanf ("%d", &size_arr2);
    float array1 [size_arr1], array2 [size_arr2];
    float array_final [size_arr1 + size_arr2];
    for (int x = 0; x < size_arr1; x++) {
        printf ("Enter the %dth attribute of array1:", x);
        scanf ("%f", &array1 [x]);
    } for (int y = 0; y < size_arr2; y++) {
        printf ("Enter the %dth attribute of array2:", y);
        scanf ("%f", &array2 [y]);
    } int secondary_count = 0;
    for (int z = 0; z < size_arr1 + size_arr2; z++) {
        if (z < size_arr1) {
            array_final [z] = array1 [z];
        } else {
            array_final [z] = array2 [secondary_count];
            secondary_count++;
        } printf ("%f, %d\n", array_final [z], z);
    } for (int a = 0; a < size_arr1 + size_arr2; a++) {
        for (int b = 0; b < size_arr1 + size_arr2; b++) {
            float temp = 0;
            if (array_final [a] < array_final [b]) {
                temp = array_final [a];
                array_final [a] = array_final [b];
                array_final [b] = temp;
            } else {
                ;
            }
        }
    } float median = 0;
    if ((size_arr1 + size_arr2) % 2 == 1) {
        median = array_final [(size_arr1 + size_arr2 - 1) / 2];
    } else {
        median = (array_final [((size_arr1 + size_arr2) / 2 - 1)] + array_final [(size_arr1 + size_arr2) / 2]) / 2;
    } printf ("The median of these combined arrays is = %.2f\n", median);
} int main () {
    main_algorithm ();
    return 0;
}
