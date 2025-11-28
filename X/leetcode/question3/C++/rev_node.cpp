#include <iostream>
using namespace std;
void main_algorithm () {
    int size_arr = 0, size_node = 0;
    cout << "Enter the size of the array:";
    cin >> size_arr;
    cout << "Enter the size of the node:";
    cin >> size_node;
    int array [size_arr];
    int amt_nodes = (size_arr - (size_arr % size_node)) / size_node;
    int arr_nodes [amt_nodes][size_node];
    for (int x = 0; x < size_arr; x++) {
        cout << "Enter attribute:";
        cin >> array [x];
    } int main_arr_counter = 0;
    for (int y = 0; y < amt_nodes; y++) {
        for (int z = 0; z < size_node; z++) {
            arr_nodes [y][z] = array [main_arr_counter];
            main_arr_counter++;
        }
    } if (size_node % 2 == 1) {
        int stop_count = (size_node - 1) / 2;
        for (int a = 0; a < amt_nodes; a++) {
            for (int b = 0; b < stop_count; b++) {
                int temp = 0;
                temp = arr_nodes [a][b];
                arr_nodes [a][b] = arr_nodes [a][(stop_count * 2) - b];
                arr_nodes [a][(stop_count * 2) - b] = temp;
            }
        }
    } else {
        int stop_count2 = size_node / 2;
        for (int c = 0; c < amt_nodes; c++) {
            for (int d = 0; d < stop_count2; d++) {
                int temp2 = 0;
                temp2 = arr_nodes [c][d];
                arr_nodes [c][d] = arr_nodes [c][((stop_count2 * 2) - 1) - d];
                arr_nodes [c][((stop_count2 * 2) - 1) - d] = temp2;
            }
        }
    } int main_arr_counter2 = 0; 
    for (int e = 0; e < amt_nodes; e++) {
        for (int f = 0; f < size_node; f++) {
            array [main_arr_counter2] = arr_nodes [e][f];
            main_arr_counter2++;
        }
    } cout << "["; 
    for (int g = 0; g < size_arr; g++) {
        cout << array [g] << " ";
    } cout << "]\n";
} int main () {
    main_algorithm ();
    return 0;
}
