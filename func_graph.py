import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 300); 
y = (pow(x,3)-(3*x)+1) #declare the function that will be used

fig = plt.figure() #graphic canvas
ax = fig.add_subplot(1, 1, 1) 

ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('center')
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')

plt.plot(x, y, 'y')
plt.show()
