#input vertices are defined here
inputs = [[22, 6], [20, 11], [18, 6], [16, 5], [15, 8], [20, 13], [18, 15],\
[15, 13], [13, 8], [9, 13], [3, 9], [6, 2], [6, 5], [11, 6], [16, 1]]

x = 0 
y = 1
concave_vertex = []
ranges = reversed(range(0, len(inputs)))

for i in ranges:
    if i == 0:
        magnitude = ((inputs[i][x]-inputs[len(inputs)-1][x])*(inputs[i+1][y]-inputs[i][y])) - \
                     ((inputs[i+1][x] - inputs[i][x])*(inputs[i][y]-inputs[len(inputs)-1][y]))
    elif i == len(inputs)-1:
        magnitude = ((inputs[i][x]-inputs[i-1][x])*(inputs[0][y]-inputs[i][y])) - \
                     ((inputs[0][x] - inputs[i][x])*(inputs[i][y]-inputs[i-1][y]))
    else:
        magnitude = ((inputs[i][x]-inputs[i-1][x])*(inputs[i+1][y]-inputs[i][y])) - \
                     ((inputs[i+1][x] - inputs[i][x])*(inputs[i][y]-inputs[i-1][y]))
    if magnitude < 0:
        concave_vertex.append([inputs[i][x], inputs[i][y]])
print(concave_vertex[::-1])