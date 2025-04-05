import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import fsolve

def f(x):
    return x**4 - x**2 + 5*x - 10

x_values = np.linspace(-2.5, 1.75, 1000)
y_values = f(x_values)

roots = fsolve(f, [-2.5, -0.5, 0.5, 1.5])


plt.plot(x_values, y_values, label='$x^4 - x^2 + 5x - 10$')

plt.scatter(roots, [0] * len(roots), color='red', label='Корни уравнения')
for root in roots:
    plt.annotate(f'({root:.2f})', (root, 0), textcoords="offset points", xytext=(0,10), ha='center', fontsize=8, color='red')

#наводим красоту
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.grid(color='gray', linestyle='--', linewidth=0.5)
plt.title('График функции и корни уравнения')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()
