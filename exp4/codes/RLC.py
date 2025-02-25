import matplotlib.pyplot as plt 
import numpy as np 

R = 24.0
L = 2.2*1e-3
C = 560*1e-12
V_0 = 5

t = np.linspace(0, 500*1e-6, 10000)

w_n = 1/(np.sqrt(L*C))
w_d = np.sqrt(w_n ** 2 - (R/(2*L)) ** 2)

V_c = -np.exp(-R*t/(2*L))*(-V_0 * np.cos(w_d * t) - ((R * V_0)/(2*L*w_d)) * np.sin(w_d * t))
for x in t:
    if (np.abs(-np.exp(-R*x/(2*L))*(-V_0 * np.cos(w_d * x) - ((R * V_0)/(2*L*w_d)) * np.sin(w_d * x))-3.6) < 1e-2):
        print(x)

plt.plot(t, V_c)
plt.plot(t, (t/t)*3.6)
plt.scatter([(6.2775)*1e-6, (6.2775+2.96)*1e-6,(6.2775+5.92)*1e-6,(6.2775+8.88)*1e-6, + (6.2775+11.92)*1e-6,(6.2775+17.84)*1e-6], [3.6,3.2,3.0,2.8,2.6,2.2])
plt.show()
