#include <stdio.h>
int find_next_prime (int seed);
int find_next_prime (int seed) {
    if ((seed == 0) || (seed == 2) || (seed == 1)) {
        return seed;
    } int start = seed + 1;
    int iscomposite = 0;
    while (1) {
        for (int x = 2; x < start; x++) {
            if (start % x == 0) {
                iscomposite = 1;
            } else {
                ;
            }
        } if (iscomposite == 0) {
            break;
        } start++;
        iscomposite = 0;
    } return start;
} void main_algorithm () {
    int min = 0, max = 0;
    printf ("Enter the minimum value possible:");
    scanf ("%d", &min);
    printf ("Enter the maximum value possible:");
    scanf ("%d", &max);
    int lt_p1 = -1, lt_p2 = -1, difference = 0;
    int prime_1 = find_next_prime (min), prime_2 = find_next_prime (prime_1);
    if (prime_2 >= max) {
        goto manual_override;
    } lt_p1 = prime_1, lt_p2 = prime_2, difference = prime_2 - prime_1;
    while (1) {
        if ((prime_2 - prime_1) < difference) {
            lt_p1 = prime_1;
            lt_p2 = prime_2;
            difference = prime_2 - prime_1;
        } else {
            ;
        } int temp = 0;
        if (find_next_prime (prime_2) >= max) {
            break;
        } else {
            temp = prime_2;
            prime_1 = temp;
            prime_2 = find_next_prime (prime_1);
        }
    } manual_override: 
    printf ("[%d, %d]\n", lt_p1, lt_p2);
} int main () {
    main_algorithm ();
    return 0;
}
