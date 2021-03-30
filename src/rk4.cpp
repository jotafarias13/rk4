//
//  rk4.h
//  funcoes
//
//  Created by Jota Farias on 19/08/20.
//  Copyright © 2020 Jota Farias. All rights reserved.
//

#include "rk4.h"




// Calcula um loop de integração de Runge-Kutta 4, atualizando o vetor de estados (x) após a integração. Feita para sistemas com múltiplas entradas e múltiplas saídas (MIMO)
// Obs: a função recebe como parâmetros um ponteiro para a função eqSistema, o vetor de estados (x), o vetor de entradas (u), o tempo (t), o passo de integração (dt) e a ordem dos sistema (ordem)
void rk4(eqSis_mimo eqSistema, double* x, const double* u, const double& t, const double& dt, const int& ordem) {
    
    int n = ordem;
    double xp[n];
    double k1[n];
    double k2[n];
    double k3[n];
    double k4[n];
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i];
    }
    
    eqSistema(xp, k1, u, t);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k1[i]*dt/2.0;
    }
    
    eqSistema(xp, k2, u, t+dt/2.0);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k2[i]*dt/2.0;
    }
    
    eqSistema(xp, k3, u, t+dt/2.0);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k3[i]*dt;
    }
    
    eqSistema(xp, k4, u, t+dt);
    
    for (int i=0; i<n; i++) {
        x[i] = x[i] + (k1[i] + 2.0*k2[i] + 2.0*k3[i] + k4[i])*(dt/6.0);
    }
    
}










// Calcula um loop de integração de Runge-Kutta 4, atualizando o vetor de estados (x) após a integração. Feita para sistemas com uma entrada e uma saída (SISO)
// Obs: a função recebe como parâmetros um ponteiro para a função eqSistema, o vetor de estados (x), o vetor de entradas (u), o tempo (t), o passo de integração (dt) e a ordem dos sistema (ordem)
void rk4(eqSis_siso eqSistema, double* x, const double& u, const double& t, const double& dt, const int& ordem) {
    
    int n = ordem;
    double xp[n];
    double k1[n];
    double k2[n];
    double k3[n];
    double k4[n];
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i];
    }
    
    eqSistema(xp, k1, u, t);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k1[i]*dt/2.0;
    }
    
    eqSistema(xp, k2, u, t+dt/2.0);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k2[i]*dt/2.0;
    }
    
    eqSistema(xp, k3, u, t+dt/2.0);
    
    for (int i=0; i<n; i++) {
        xp[i] = x[i] + k3[i]*dt;
    }
    
    eqSistema(xp, k4, u, t+dt);
    
    for (int i=0; i<n; i++) {
        x[i] = x[i] + (k1[i] + 2.0*k2[i] + 2.0*k3[i] + k4[i])*(dt/6.0);
    }
    
}
