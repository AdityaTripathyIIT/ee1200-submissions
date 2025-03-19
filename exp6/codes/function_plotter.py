import matplotlib.pyplot as plt 
import numpy as np 
import csv
import math
x = list()
y = list()
i = 0
with open("../data/highpass-2.csv", "r") as file:
    for line in csv.reader(file):
        if (i == 0):
            i = 1
            continue
        x.append(math.log10(2*math.pi*float(line[2])))
        y.append(20 * np.log10(float(line[1])/float(line[0])))
def func_1(x):
    R = 22*1e3
    C=220*1e-9
    f= 10 * 1/(2 * np.pi * R * C)
    Q = 0.5
    a = np.power(10, x)
    return 20 * np.log10((a**2)/np.sqrt(((2 * np.pi * f)**2 - (a**2))**2 + (2*np.pi*f*a/Q)**2))
plt.plot(x, y)
t = np.linspace(0, 10, 10000)
plt.plot(t,func_1(t))
plt.show()
