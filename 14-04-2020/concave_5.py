#input vertices are defined here
inputs = [[22, 6], [20, 11], [18, 6], [16, 5], [15, 8], [20, 13], [18, 15],\
[15, 13], [13, 8], [9, 13], [3, 9], [6, 2], [6, 5], [11, 6], [16, 1]]
x_p = []
y_p = []
x = 0
y = 1
px = input("Enter point x: ")
py = input("Enter point y: ")
crossing = 0
ranges = range(0, len(inputs))
size = len(inputs)

for i in ranges:
    if inputs[i][x] < inputs[(i+1)%size][x]:
        x1 = inputs[i][x]
        x2 = inputs[(i+1)%size][x]
    else:
        x1 = inputs[(i+1)%size][x]
        x2 = inputs[i][x]
    
    if px > x1 and px <= x2 and (py < inputs[i][y] or py <= inputs[(i+1)%size]):
        eps = 0.000001
        dx = inputs[(i+1)%size][x] - inputs[i][x];
        dy = inputs[(i+1)%size][y] - inputs[i][y];
        
        if abs(dx) < eps:
            k = 10000000
        else:
            k = dy/dx

        m = inputs[i][y] - k * inputs[i][x]
        
        y2 = k * px + m
        if py <= y2:
            crossing += 1
print("The point crossing "+str(crossing)+" lines\n")
if crossing%2 == 1:
    print("Point is inside the polygon")
else:
    print("Point is outside the polygon")

# Referenced from https://sidvind.com/wiki/Point-in-polygon:_Jordan_Curve_Theorem