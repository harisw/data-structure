# 2019 4월 it works.

import numpy as np
import matplotlib.pyplot as plt

points = np.array([[10, 3], [7, 5], [1, 4], [6, 1], [8,8], [5,5], [11,4], [3,10], [7,2], [4,9],[12,5]])

for i in range( len(points)) :
    ptxt =  str(i) + "(" + str(points[i][0]) + "," + str(points[i][1]) + ")"
    plt.annotate( ptxt, (points[i][0], points[i][1]), fontsize=9, fontweight='bold' )

from scipy.spatial import Delaunay
tri = Delaunay(points)

for p in tri.simplices : 
    print ( p )	# 답안 출력시 vertex 순서는 tri.simplices 에서 구해지는 순서 그대로(반시계방향) 사용한다.

plt.triplot(points[:,0], points[:,1], tri.simplices.copy())
plt.plot(points[:,0], points[:,1], 'o')
plt.show()