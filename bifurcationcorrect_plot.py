import numpy as np
import matplotlib.pyplot as plt
def modulo(A):
    n=len(A)
    A1=np.zeros(n)
    for i in range(n):
        x=A[i]
        if(x>np.pi):
            while(x>np.pi):
                x=x-np.pi
        if(x<np.pi):
            while(x<-np.pi):
                x=x+np.pi
        A1[i]=x
    return A1
def logistic(r, x):
    return r * x * (1 - x)
n = 10000
r = np.linspace(2.8, 4.0, n)
iterations = 1000
last = 100
x = np.ones(10000)/(10000)
for i in range(iterations):
    x = logistic(r, x)
    if i >= (iterations - last):
        plt.plot(r, x, ',k', alpha=.06)
plt.xlim(2.8, 4)
plt.title("Bifurcation diagram")
plt.savefig('bifnuevo.png')