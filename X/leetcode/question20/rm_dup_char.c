#include <stdio.h>
void main_algorithm () {
	int arr_size = 0;
	printf ("Enter the array size:");
	scanf ("%d", &arr_size);
	int array [arr_size];
	for (int ent_arr = 0; ent_arr < arr_size; ent_arr++) {
		printf ("Enter attribute %d:", ent_arr);
		scanf ("%d", &array [ent_arr]);
	} for (int lp1 = 0; lp1 < arr_size; lp1++) {
		for (int lp2 = 0; lp2 < arr_size; lp2++) {
			int temp_swp = 0;
			if (array [lp2] > array [lp1]) {
				temp_swp = array [lp2];
				array [lp2] = array [lp1];
				array [lp1] = temp_swp;
			}
		}
	} int new_array [arr_size];
	int n_count = 0;
	int n_val = array [0];
	int na_c = 0;
	for (int filter = 0; filter < arr_size; filter++) {
		if (array [filter] != n_val) {
			n_count = 1;
			n_val = array [filter];
			new_array [na_c] = array [filter];
			na_c++;
		} else {
			n_count++;
			if (n_count > 2) {new_array [na_c] = -1;} 
			else {
				new_array [na_c] = array [filter];
				na_c++;
			}
		}
	} for (int pt_o = 0; pt_o < na_c; pt_o++) {
		if (new_array [pt_o] != -1) {printf ("%d ", new_array [pt_o]);}
	} printf ("\n");
} int main () {
	main_algorithm ();
	return 0;
}

