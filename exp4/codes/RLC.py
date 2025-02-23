import matplotlib.pyplot as plt 
import numpy as np 

R = 27.5
L = 2.2*1e-3
C = 560*1e-12
V_0 = 5

t = np.linspace(0, 50*1e-6, 1000)

w_n = 1/(np.sqrt(L*C))
w_d = np.sqrt(w_n ** 2 - (R/(2*L)) ** 2)

V_c = -np.exp(-R*t/(2*L))*(-V_0 * np.cos(w_d * t) - ((R * V_0)/(2*L*w_d)) * np.sin(w_d * t))

plt.plot(t, V_c)
plt.show()
