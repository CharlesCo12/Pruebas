#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void angulos(double F0,string filename);
double g(double theta0, double omega0);
double f(double theta0, float omega0, double t, double F);

const float w0=1.0;
const float gama=0.2;
const float delta=1.0;
const double h=1;
const double w=0.2;
const int N=1000;
const float pi=4*atan(1);
int main(){
    angulos(2.8,"datos_bif.dat");
    return 0;
}

double g(double theta0, double omega0){
    return omega0;
}
double f(double theta0, float omega0, double t, double F){
    return -(w0*w0*sin(theta0)) - (gama*omega0) + (F*sin(w*t + delta));
}

void angulos(double F0, string filename){  
    ofstream outfile;
    outfile.open(filename);
    double F1=F0;
    double df=1.2/10000;
    while(F1<4)
    {        
        double omega1=1.0;
        double theta1=0.0;    
        for(int i=0;i<N;i++){
            if(i=900){outfile << theta1;}
            omega1=omega1+h*f(theta1,omega1,i*h,F1);
            theta1=theta1+h*g(theta1,omega1);
        }
        outfile<<endl;
        F1=F1+df;
    }
    outfile.close();
}