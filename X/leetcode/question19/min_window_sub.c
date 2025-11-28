#include <stdio.h>
#include <stdlib.h>
void main_algorithm () {
    int size_string = 0;
    printf ("Enter the size of the main string:");
    scanf ("%d", &size_string);
    char string_main [size_string];
    printf ("Enter the main string:");
    scanf (" %s", string_main);
    int size_sub_string = 0;
    printf ("Enter the size of the substring:");
    scanf ("%d", &size_sub_string);
    char substring [size_sub_string];
    printf ("Enter the substring:");
    scanf (" %s", substring);
    if (size_sub_string > size_string) {printf ("None Possible.\n"); exit (0);}
    else if (size_sub_string == size_string) {
        int numerical [2][size_string];
        for (int x = 0; x < size_string; x++) {
            numerical [0][x] = (int) (string_main [x]);
        } for (int x1 = 0; x1 < size_string; x1++) {
            for (int x2 = 0; x2 < size_string; x2++) {
                if (numerical [0][x2] > numerical [0][x1]) {
                    int temp = 0;
                    temp = numerical [0][x2];
                    numerical [0][x2] = numerical [0][x1];
                    numerical [0][x1] = temp;   
                }
            }
        } for (int y = 0; y < size_string; y++) {
            numerical [1][y] = (int) (substring [y]);
        } for (int y1 = 0; y1 < size_string; y1++) {
            for (int y2 = 0; y2 < size_string; y2++) {
                if (numerical [1][y2] > numerical [1][y1]) {
                    int temp = 0;
                    temp = numerical [1][y2];
                    numerical [1][y2] = numerical [1][y1];
                    numerical [1][y1] = temp;
                }
            }
        } int ext_cde = 0;
        for (int z = 0; z < size_string; z++) {
            if (numerical [0][z] != numerical [1][z]) {ext_cde = 1; break;}
        } if (ext_cde == 0) {printf ("%s\n", string_main); exit (0);} 
        else {printf ("None Possible.\n"); exit (0);}
    }
} int main () {
    main_algorithm ();
    return 0;
}
