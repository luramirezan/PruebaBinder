import numpy as np
import matplotlib.pyplot as plt
t_e,x_e,v_e = np.loadtxt("data_euler.txt", unpack=True ) 
t_l,x_l,v_l = np.loadtxt("data_leapfrog.txt", unpack=True ) 
fig, ax = plt.subplots() 
plt.plot(t_e , x_e,  label="Posicion")
plt.plot(t_e , v_e , label= "velocidad")
ax.set_xlabel(f" t [s] ") # titulo eje x
ax.set_ylabel(f" Posición x [m] y velocidad [m/s]") # titulo eje y
ax.set_title(f" Euler Usando 1000 pasos")  # titulo general
plt.grid() #cuadricula
ax.legend(); # añade leyenda con los nombres puestos
fig.savefig("Figura_euler.pdf", bbox_inches='tight') # lo guarda 
#Algoritmo Leap-Frog
#fig, ax = plt.subplots() 
#plt.plot(t_l , x_l,  label="posicion")
#plt.plot(t_l , v_l , label= "velocidad")
#ax.set_xlabel(f" t [s] ") # titulo eje x
#ax.set_ylabel(f" Posición x [m] y velocidad [m/s] ") # titulo eje y
#ax.set_title(f" leap frog usando 1000 pasos")  # titulo general
#plt.grid() #cuadricula
#ax.legend(); # añade leyenda con los nombres puestos
#fig.savefig("Figura_LeapFrog.pdf", bbox_inches='tight') # lo guarda 