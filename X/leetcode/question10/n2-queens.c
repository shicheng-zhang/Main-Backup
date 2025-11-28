#include <stdio.h>
int factorial (int input);
int factorial (int input) {
    for (int multiplex = input - 1; multiplex > 1; multiplex--) {input *= multiplex;}
    return input;
} int check_list (int n, int list_found [factorial (n)][n][2], int list_in [n][2]);
int check_list (int n, int list_found [factorial (n)][n][2], int list_in [n][2]) {
    for (int count = 0; count < factorial (n); count++) {
        for (int count2 = 0; count2 < n; count2++) {
            if ((list_found [count][count2][0] == list_in [count2][0])
            && (list_found [count][count2][1] == list_in [count2][0])) {return 0;}
        }
    } return 1;
} void nest_process (int n, int count, int pieces [n][2], int total_maneouver [factorial (n)][n][2], int amount);
void nest_process (int n, int count, int pieces [n][2], int total_maneouver [factorial (n)][n][2], int amount) {
    while (1) {
        amount += check_list (n, total_maneouver, pieces);
        if (count == n * n - count) {
            //Loop End
        } else {
                        
        }
    }
} int absolute (int integer);
int absolute (int integer) {
    if (integer < 0) {integer = integer * -1;}
    return integer;  
} int comparison (int n, int spots [n][2]);
int comparison (int n, int spots [n][2]) {
    int similarity = 0;
    for (int x1 = 0; x1 < n; x1++) {
        if (similarity == 1) {break;}
        for (int x2 = 0; x2 < n; x2++) {
            if (x1 == x2) {continue;}
            else if ((spots [n][0] == -1) && (spots [n][1] == -1)) {continue;}
            else {
                //Vertical
                if (spots [x1][0] == spots [x2][0]) {similarity = 1; break;} //Same Vertical Vector
                else {
                    //Horizontal
                    if (spots [x1][1] == spots [x2][1]) {similarity = 1; break;} //Same Horizontal Vector
                    else {
                        //Diagonal
                        int diff_x = spots [x1][1] - spots [x2][1];
                        int diff_y = spots [x1][0] - spots [x2][0];
                        if (absolute (diff_x) == absolute (diff_y)) {similarity = 1; break;} //Same Diagonal Vector
                    }
                }
            }
        }
    } return similarity;
} void main_algorithm () {
    int n = 0;
    printf ("Enter the size of the board in both dimensions:");
    scanf ("%d", &n);
    int board [n][n], pieces [n][2], amount = 0, configurations [factorial (n)][n][2];
    for (int x = 0; x < n; x++) {
        pieces [n][0] = 0;
        pieces [n][1] = 0;
        for (int y = 0; y < n; y++) {board [y][x] = 0;}
    } //0 is for no queen, 1 is for queen there
    
} int main () {
    main_algorithm ();
    return 0;
}
