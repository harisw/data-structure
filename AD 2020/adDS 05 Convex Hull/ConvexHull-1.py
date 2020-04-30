# Convex hull of a random set of points:

import random
import numpy as np
import matplotlib.pyplot as plt

np.random.seed(4567)

from scipy.spatial import ConvexHull
#points = np.random.rand(30, 2)   # 30 random points in 2-D
points = np.random.randint(100, size=(50,   2))
#                        값범위      갯수, 차원

points[0,0]= 0
points[0,1]= 0
hull = ConvexHull(points)

plt.plot(points[:,0], points[:,1], 'o')
#print(points)

for simplex in hull.simplices:  #convex hull edge의 List
    plt.plot(points[simplex, 0], points[simplex, 1], 'r--', alpha=0.6)
    print( "vertex id = ", simplex )

# We could also have directly used the vertices of the hull, which
# for 2-D are guaranteed to be in counterclockwise order:
# list hull에 있는 점에 대해서 다시 그림을 그림


plt.plot(points[hull.vertices,0],    points[hull.vertices,1], 'r--', lw=1, alpha=0.6)
plt.plot(points[hull.vertices[0],0], points[hull.vertices[0],1], 'ro') # 시작점
plt.show()
