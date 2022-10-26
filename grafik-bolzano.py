import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-5, 5, 100) 

y = (1 - (0.6 * x)) / x

# mengatur axis di pusat
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('zero')

ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')

ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

plt.plot(x, y, 'r')

# show the plot
plt.show()
