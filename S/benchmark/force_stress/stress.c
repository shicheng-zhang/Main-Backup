#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main_algorithm () {
    int count = 10000;
    int num1 = 2, num2 = num1;
    while (1) {
        if (num1 > count) {exit(0);} num2++;
        int check = 0;
        for (int x = 2; x < num2; x++) {
            if (num2 % x == 0) {check = 1;}
        } if (check == 1) {continue;} 
        else {
            int sum = num1 + num2;
            while ((sum >= 0) && (sum >= 10)) {sum = (sum / 2) + (sum % 2);}
        } num1 = num2;
    }
} int main () {
    main_algorithm ();
    execlp ("neofetch", "neofetch", NULL);
    return 0;
}
