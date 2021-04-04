//
//  rk4.cpp
//
//  Source file of the library 'rk4'
//
//  Created by João Lucas Correia Barbosa de Farias
//  See https://github.com/jotafarias13/rk4
//


#include "rk4.h"



// Computes one integration loop of Runge-Kutta 4, updating the state array after the process. Suited for systems with multiple inputs and multiple outputs (MIMO).
// Note: the function takes a pointer to a eqSys_mimo function (eqSystem), a pointer to the state array (x), a pointer to the input array (u), a time value (t), the integration step (dt) and the order of the system (order).

void rk4(eqSys_mimo eqSystem, double* x, const double* u, const double& t, const double& dt, const int& order) {
    
    int n = order;
    double xp[n];
    double k1[n];
    double k2[n];
    double k3[n];
    double k4[n];
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i];
    }
    
    eqSystem(xp, k1, u, t);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k1[i]*dt/2.0;
    }
    
    eqSystem(xp, k2, u, t+dt/2.0);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k2[i]*dt/2.0;
    }
    
    eqSystem(xp, k3, u, t+dt/2.0);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k3[i]*dt;
    }
    
    eqSystem(xp, k4, u, t+dt);
    
    for (int i=0; i<n; i++) {
        x[i] = x[i] + (k1[i] + 2.0*k2[i] + 2.0*k3[i] + k4[i])*(dt/6.0);
    }
    
}


// Computes one integration loop of Runge-Kutta 4, updating the state array after the process. Suited for systems with a single input and a single output (SISO).
// Note: the function takes a pointer to a eqSys_siso function (eqSystem), a pointer to the state array (x), an input value (u), a time value (t), the integration step (dt) and the order of the system (order).

void rk4(eqSys_siso eqSystem, double* x, const double& u, const double& t, const double& dt, const int& order) {
    
    int n = order;
    double xp[n];
    double k1[n];
    double k2[n];
    double k3[n];
    double k4[n];
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i];
    }
    
    eqSystem(xp, k1, u, t);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k1[i]*dt/2.0;
    }
    
    eqSystem(xp, k2, u, t+dt/2.0);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k2[i]*dt/2.0;
    }
    
    eqSystem(xp, k3, u, t+dt/2.0);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k3[i]*dt;
    }
    
    eqSystem(xp, k4, u, t+dt);
    
    for (int i=0; i<n; i++) {
        x[i] = x[i] + (k1[i] + 2.0*k2[i] + 2.0*k3[i] + k4[i])*(dt/6.0);
    }
    
}
