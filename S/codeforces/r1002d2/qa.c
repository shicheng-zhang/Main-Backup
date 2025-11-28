#include <stdio.h>
#include <stdlib.h>
int main () {
    int size_arr = 0, iteration = 0;
    scanf ("%d", &iteration);
    scanf ("%d", &size_arr);
    int array [2][size_arr];
    int arrc [size_arr];
    int largest1 = 0, largest2 = 0;
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < size_arr; y++) {
            scanf ("%d", &array [x][y]);
            if (x == 0) {
                if (array [x][y] > largest1) {
                    largest1 = array [x][y];
                }
            } else {
                if (array [x][y] > largest2) {
                    largest2 = array [x][y];
                }
            }
        } printf ("\n");
    } int new_array [2][size_arr];
    for (int xx = 0; xx < size_arr; xx++) {
        new_array [0][xx] = array [0][xx];
        new_array [1][xx] = array [1][xx];  
    } int preset_val [largest1 + largest2];
    for (int c = 0; c < largest1 + largest2; c++) {
        preset_val [c] = 0;     
    } for (int z = 0; z < iteration; z++) {
        if (z == 0) {
            if (size_arr % 2 == 0) {
                //even
                //swap mid2
                int swap1 = size_arr / 2 - 1;
                int swap2 = swap1 + 1;
                int temp = 0;
                temp = new_array [0][swap1];
                new_array [0][swap1] = new_array [0][swap2];
                new_array [0][swap2] = temp;
            } else {
                //odd
                //swap 2 right beside mid
                int mid = (size_arr - 1) / 2;
                int swap1 = mid - 1;
                int swap2 = mid + 1;
                int temp = 0;
                temp = new_array [0][swap1];
                new_array [0][swap1] = new_array [0][swap2];
                new_array [0][swap2] = temp;
            } //swap complete
            for (int f = 0; f < size_arr; f++) {
                arrc [f] = new_array [0][f] + new_array [1][f];
                printf ("%d %d %d\n", arrc [f], new_array [0][f], new_array [1][f]);
                preset_val [arrc [f] - 1]++;
            } int count_distinct = 0;
            for (int g = 0; g < largest1 + largest2; g++) {
                if (preset_val [g] != 0) {
                    count_distinct++;
                } preset_val [g] = 0;
            } if (count_distinct >= 3) {
                printf ("YES\n");
                exit (0);
            }
        } else {
            int head = array [0][0];
            for (int a = 0; a < size_arr - 1; a++) {
                array [0][a] = array [0][a + 1];
            } array [0][size_arr - 1] = head;
            //Rotation complete
            for (int b = 0; b < size_arr; b++) {
                arrc [b] = array [0][b] + array [1][b];
                printf ("{%d, ", arrc [b]);
                preset_val [arrc [b] - 1]++;
                printf ("%d, %d}\n", preset_val [arrc [b] - 1], b);
            } int count_distinct = 0; 
            for (int d = 0; d < largest1 + largest2; d++) {
                if (count_distinct == 3) {
                    break;
                } else {
                    if (preset_val [d] != 0) {
                        count_distinct++;
                    }
                } 
            } if (count_distinct >= 3) {
                printf ("YES\n");
                exit (0);
            } for (int e = 0; e < largest1 + largest2; e++) {
                preset_val [e] = 0;
            }
        } printf ("\n");
    } printf ("NO\n"); 
    return 0;
}
