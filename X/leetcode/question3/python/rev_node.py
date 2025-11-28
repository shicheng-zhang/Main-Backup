size_node = (int) (input ("Enter the size of the nodes:"))
size_array = (int) (input ("Enter the size of the array:"))
array = []
input_counter = 0
for x in range (size_array):
    array += [1]
    array [x] = (int) (input ("Enter attribute:"))
    input_counter += 1
print (array)
amt_nodes = size_array // size_node
print (amt_nodes, size_node)
array_nodes = [[0] * size_node for a in range (amt_nodes)]
array_counter = 0
for y in range (amt_nodes):
    for z in range (size_node):
        array_nodes [y][z] = array [array_counter]
        array_counter += 1
if size_node % 2 != 0:
    untracked = (size_node - 1) // 2
    for b in range (amt_nodes):
        for c in range (untracked):
            array_nodes [b][c], array_nodes [b][size_node - (1 + c)] = array_nodes [b][size_node - (1 + c)], array_nodes [b][c]
else:
    untracked2 = size_node // 2
    for d in range (amt_nodes):
        for e in range (untracked2):
            array_nodes [d][e], array_nodes [d][size_node - (1 + e)] = array_nodes [d][size_node - (1 + e)], array_nodes [d][e]
array_counter2 = 0
for f in range (amt_nodes):
    for g in range (size_node):
        array [array_counter2] = array_nodes [f][g]
        array_counter2 += 1
print (array)

