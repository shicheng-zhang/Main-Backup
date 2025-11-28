#include <stdio.h>
int recursion (int end);
int recursion (int end) {
    int end1 = end;
    while (1) {
        int target = end;
        if (target < end1 * end1) {end1 = recursion (target);} 
    } return 0;
} int main () {
    int limit = 0;
    printf ("Limit:");
    scanf ("%d", &limit);
    recursion (limit);
}
