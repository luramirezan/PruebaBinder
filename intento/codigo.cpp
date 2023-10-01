#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>

float function(float t, float y,float v);

float euler(float t, float y,float v,float H, int d);

float leapfrog(float t, float y,float v,float H, int d);

int main() {
//Valores iniciales
  float v_0=0;
  float x_0=0.1;
  float t_0=0;
  float t_f=10;
  float H=t_f-t_0;//A donde se quiere llegar
//Los pasos que se quieren hacer:
  float d=1000;
  
//Euler ED segundo orden
  double x_e= euler(t_0, x_0,v_0, H, d);
  std::cout << "Euler: "<< x_e << " "<<"\n";
// Algoritmo Leap-Frog
  double x_l= leapfrog(t_0, x_0,v_0, H, d);
  std::cout << "leapfrog: "<< x_l << " "<<"\n";


}

float function(float t, float y,float v){
  float k=50;
  float m=0.2;
  float d2y= -k*y/m;
  return d2y;
}

//Metodo de euler con ecuacion de segundo orden
float euler(float t, float y,float v,float H, int d){
// Escritura
  std::ofstream fout;
  fout.precision(16); fout.setf(std::ios::scientific);
  fout.open("data_euler.txt");
  float h= H/d;
  for (int i = 0; i < d; i++) {
    fout  << t << "\t" << y << "\t" << v << "\n";
    v = v + (h * function(t, y, v));
    y = y + (h * v);
    t = t + h;
  }
  fout.close();
  return y;
}
//Algoritmo Leap-Frog
float leapfrog(float t, float y,float v,float H, int d){
// Escritura
  std::ofstream fout;
  fout.precision(16); fout.setf(std::ios::scientific);
  fout.open("data_leapfrog.txt");
  float h= H/d;
  for (int i = 0; i < d; i++) {
    fout  << t << "\t" << y << "\t" << v << "\n";
    v = v + (0.5*h * function(t, y, v));
    y = y + (h * v);
    v= v + (0.5*h * function(t, y, v));
    t = t + h;      
  }
  fout.close();
  return y;
}
