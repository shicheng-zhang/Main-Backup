/*
 * Leetcode 2138: Divide a String Into Groups of Size k
 *
 * This is a solution to Leetcode problem 2138, which asks for the 
 * division of a string into groups of a specified size, filling 
 * extraneous characters with a specified filler character defined by the user.
 * It uses current_sub_cnt to track the iteration of the substring count and 
 * then prints out each segment of the string accordingly until all characters
 * are depleted, at which poitn should there be any extraneous spots to fill, 
 * filler characters are printed to fill the gap.
 *
 * Example: string = "abcdefghi", size_sub = 3, fill = 'x'
 * Output:
 * abc
 * def
 * ghi
 *
 * Please reference this program should you use it in your own code.
 *
 * Copyright 2025, Shicheng Z, 24/06/25
 *
 * */
#include <stdio.h>
void main_algorithm () {
    int size_string = 0, size_sub = 0;
    printf ("Enter the size of the string:");
    scanf ("%d", &size_string);
    char string [size_string];
    char fill;
    printf ("Enter the string:");
    scanf ("%s", string);
    printf ("Enter the filler character:");
    scanf (" %c", &fill);
    printf ("Enter the size of the substring:");
    scanf ("%d", &size_sub);
    int current_index = 0;
    int current_sub_cnt = 0;
    while (1) {
        int target = (current_sub_cnt + 1) * size_sub - 1;
        if (target >= size_string - 1) {
            int gap = target - size_string + 1;
            for (int y = current_index; y < size_string; y++) {printf ("%c", string [y]);}
            for (int z = 0; z < gap; z++) {printf ("%c", fill);}
            printf ("\n");
            break;
        } else {
            for (int x = current_index; x <= target; x++) {printf ("%c", string [x]);}
            printf ("\n");
        } current_index = (current_sub_cnt + 1) * size_sub;
        current_sub_cnt++;
    }
} int main () {
    main_algorithm ();
    return 0;
}

