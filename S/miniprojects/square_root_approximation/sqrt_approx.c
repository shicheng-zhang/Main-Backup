/*
 * A program to implement
 * */
#include <stdio.h>
float absolute (float input);
float absolute (float input) {
    if (input < 0) {
        input = (float) (input * -1);
        return input;
    } else {
        return input;
    }
} void main_algorithm () {
    float margin_of_error = 0.0;
    printf ("Enter an acceptable margin of error:");
    scanf ("%f", &margin_of_error);
    float number = 0.0;
    printf ("Enter the number to be computed:");
    scanf ("%f", &number);
    float pseudo_number = (float) (number / 2);
    float concurrent_result = 0.0;
    float concurrent_result2 = 0.0;
    while (1) {
        concurrent_result = (float) ((0.5) * (pseudo_number + (number / pseudo_number)));
        concurrent_result2 = (float) (concurrent_result * concurrent_result);
        if (absolute ((float) (number - concurrent_result2)) <= (float) margin_of_error) {
            break;
        } else {
            pseudo_number = (float) concurrent_result;
            concurrent_result = 0.0;
            concurrent_result2 = 0.0;
        }
    } printf ("The approximated result of sqrt (%f) = +-%f\n", number, concurrent_result);
} int main () {
    main_algorithm ();
    return 0;
}
