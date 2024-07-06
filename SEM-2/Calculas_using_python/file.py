import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

y=1

t = np.linspace(0,5)

def returns_dydt(y, t):
    dydt = -y * t + 13
    return dydt

y = odeint(returns_dydt, y, t)

plt.plot(t,y)
plt.show()