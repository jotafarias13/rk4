//
//  rk4.h
//  funcoes
//
//  Created by Jota Farias on 19/08/20.
//  Copyright © 2020 Jota Farias. All rights reserved.
//

#ifndef rk4_h
#define rk4_h





// Define um variável tipo ponteiro que aponta para uma função que retorna void e tem como parâmetros 3 ponteiros double e um double escalar.
// Obs: a função do sistema recebe como parâmetros o estado (x), a derivada dos estados (xp), o vetor de entradas (u) e o tempo (t)
typedef void (*eqSis_mimo)(const double*, double*, const double*, const double&);


// Define um variável tipo ponteiro que aponta para uma função que retorna void e tem como parâmetros 2 ponteiros double e 2 doubles escalar.
// Obs: a função do sistema recebe como parâmetros o vetor de estados (x), o vetor da derivada dos estados (xp), a entrada (u) e o tempo (t)
typedef void (*eqSis_siso)(const double*, double*, const double&, const double&);





// Calcula um loop de integração de Runge-Kutta 4, atualizando o vetor de estados (x) após a integração. Feita para sistemas com múltiplas entradas e múltiplas saídas (MIMO)
// Obs: a função recebe como parâmetros um ponteiro para a função eqSistema, o vetor de estados (x), o vetor de entradas (u), o tempo (t), o passo de integração (dt) e a ordem dos sistema (ordem)
void rk4(eqSis_mimo eqSistema, double* x, const double* u, const double& t, const double& dt, const int& ordem);





// Calcula um loop de integração de Runge-Kutta 4, atualizando o vetor de estados (x) após a integração. Feita para sistemas com uma entrada e uma saída (SISO)
// Obs: a função recebe como parâmetros um ponteiro para a função eqSistema, o vetor de estados (x), o vetor de entradas (u), o tempo (t), o passo de integração (dt) e a ordem dos sistema (ordem)
void rk4(eqSis_siso eqSistema, double* x, const double& u, const double& t, const double& dt, const int& ordem);





#endif /* rk4_h */
