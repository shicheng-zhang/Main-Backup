#include <stdio.h>
void main_algorithm () {
    int arr_size = 0;
    printf ("Enter the size of the array:");
    scanf ("%d", &arr_size);
    int array [arr_size];
    for (int x = 0; x < arr_size; x++) {
        printf ("Enter attribute [%d]:", x);
        scanf ("%d", &array [x]);
    } int count_main = 0, count_continue = array [0];
    int set_count = 0; 
    while (1) {
        if (count_continue < 2) {
            set_count++;
            count_continue = array [set_count];
        } else {break;}
    } for (int y = set_count + 1; y < arr_size; y++) {
        if (array [y] == count_continue - 1) {
            if (array [y] == 1) {
                count_main++;
                count_continue = array [y + 1];
                y++;
            } else {count_continue = array [y];}
        } else {count_continue = array [y + 1];}
    } printf ("There are %d contiguous subarrays in the array.\n", count_main);
} int main () {
    main_algorithm ();
    return 0;
}

