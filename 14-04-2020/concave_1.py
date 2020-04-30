#input vertices are defined here
inputs = [[22, 6], [20, 11], [18, 6], [16, 5], [15, 8], [20, 13], [18, 15],\
[15, 13], [13, 8], [9, 13], [3, 9], [6, 2], [6, 5], [11, 6], [16, 1]]

#calculate positive terms
positive_terms = 0;
for i in range(0, len(inputs)):
    if i == len(inputs)-1:
        temp = inputs[i][0]*inputs[0][1]
    else:
        temp = inputs[i][0]*inputs[i+1][1]
    positive_terms += temp
    
#calculate negative terms
negative_terms = 0;
for i in range(0, len(inputs)):
    if i == len(inputs)-1:
        temp = inputs[i][1]*inputs[0][0]
    else:
        temp = inputs[i][1]*inputs[i+1][0]
    negative_terms += temp

area = (positive_terms - negative_terms)/2
print("Area of Polygon : ", area)

#Referenced from https://en.wikipedia.org/wiki/Shoelace_formula