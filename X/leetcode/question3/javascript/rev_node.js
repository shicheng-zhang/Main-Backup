var size_array = 0;
var size_node = 0;
size_array = parseInt (prompt ("Enter the size of the array:"));
size_node = parseInt (prompt ("Enter the size of the node:"));
var array = new Array (size_array);
var amt_nodes = Math.floor ((size_array - (size_array % size_node)) / size_node);
var array_nodes = new Array (amt_nodes).fill ().map (() => new Array (size_node));
for (var x = 0; x < size_array; x++) {
    array [x] = parseInt (prompt ("Enter attribute:"));
} var main_arr_count = 0;
for (var y = 0; y < amt_nodes; y++) {
    for (var z = 0; z < size_node; z++) {
        array_nodes [y][z] = array [main_arr_count];
        main_arr_count++;
    }
} if (size_node % 2 == 1) {
    var stop_point = Math.floor ((size_node - 1) / 2);
    for (var a = 0; a < amt_nodes; a++) {
        for (var b = 0; b < stop_point; b++) {
            var temp = 0;
            temp = array_nodes [a][b];
            array_nodes [a][b] = array_nodes [a][(size_node - 1) - b];
            array_nodes [a][(size_node - 1) - b] = temp;
        }
    }
} else {
    var stop_point2 = Math.floor (size_node / 2);
    for (var c = 0; c < amt_nodes; c++) {
        for (var d = 0; d < stop_point2; d++) {
            var temp2 = 0;
            temp2 = array_nodes [c][d];
            array_nodes [c][d] = array_nodes [c][(size_node - 1) - d];
            array_nodes [c][(size_node - 1) - d] = temp2;
        }
    }
} var main_arr_count2 = 0;
for (var e = 0; e < amt_nodes; e++) {
    for (var f = 0; f < size_node; f++) {
        array [main_arr_count2] = array_nodes [e][f];
        main_arr_count2++;
    }
} console.log ("[");
for (var g = 0; g < size_array; g++) {
    console.log (array [g], " ");
} console.log ("]");

