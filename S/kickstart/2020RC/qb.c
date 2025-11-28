/*
 * Google Kickstart RA-2020, Question A
 *
 * This is a solution to Questtion A of Round A of the 2020 Google Kickstart.
 * It t demands to find the most amountt of houses that can bee purchased for
 * a set prrice, and it uses a sorting algorithm to sort the possible prices 
 * from least to greatest to achieve o log n.
 *
 * Please Reference this program should you wish to implement it in other programs.
 *
 * Copyright 2025. Shicheng Z. 29/03/25
 * */
#include <stdio.h>
void main_algorithm () {
    int n, p;
    printf ("Enter the number of houses there are:");
    scanf ("%d", &n);
    int houses [n];
    printf ("Enter the money you possess:");
    scanf ("%d", &p);
    for (int count_in_h = 0; count_in_h < n; count_in_h++) {
        printf ("Enter the price tag of house %d:", count_in_h);
        scanf ("%d", &houses [count_in_h]);
    } for (int sort1 = 0; sort1 < n; sort1++) {
        for (int sort2 = 0; sort2 < n; sort2++) {
            if (houses [sort2] > houses [sort1]) {
                int temp;
                temp = houses [sort2];
                houses [sort2] = houses [sort1];
                houses [sort1] = temp;
            }
        }
    } int increment = 0;
    for (int compile = 0; compile < n; compile++) {
        increment += houses [compile];
        if (increment > p) {printf ("You can purchase at max %d houses.\n", compile); break;}
    }
} int main () {
    main_algorithm ();
    return 0;
}
