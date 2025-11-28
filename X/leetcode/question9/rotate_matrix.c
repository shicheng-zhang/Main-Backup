#include <stdio.h>
void main_algorithm () {
    int n;
    printf ("Enter the size of n:");
    scanf ("%d", &n);
    int array [n][n], attr_cnt = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf ("Enter attrribute %d:", attr_cnt);
            scanf ("%d", &array [x][y]);
            attr_cnt++;
        }
    } if (n % 2 == 1) {
        //Odd Rotation
        for (int c1 = 0; c1 < n * n; c1++) {
            int oy = c1 / n, ox = c1 - (oy * n), ny, nx, gy = (n - 1) - oy, gx = (n - 1) - ox;
            if ()
        } 
    } else {
        //Even Rotation
        ;
    } for (int x2 = 0; x2 < n; x2++)  {
        for (int y2 = 0; y2 < n; y2++) {printf ("%d ", array [x2][y2]);}
        printf ("\n");
    }
} int main () {
    main_algorithm ();
    return 0;
}
