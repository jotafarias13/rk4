//
//  rk4.h
//
//  Header file of the library 'rk4'
//
//  Created by João Lucas Correia Barbosa de Farias
//  See https://github.com/jotafarias13/rk4
//


#ifndef rk4_h
#define rk4_h



// Defines a variable of type: pointer to a function that takes three pointers to double and one double value and returns void.
// Note: the system function takes a pointer to the state array (x), a pointer to the derivative of the state array (xp), a pointer to the input array (u) and a time value (t).

typedef void (*eqSys_mimo)(const double*, double*, const double*, const double&);


// Defines a variable of type: pointer to a function that takes two pointers to double and two double values and returns void.
// Note: the system function takes a pointer to the state array (x), a pointer to the derivative of the state array (xp), an input value (u) and a time value (t).

typedef void (*eqSys_siso)(const double*, double*, const double&, const double&);


// Computes one integration loop of Runge-Kutta 4, updating the state array after the process. Suited for systems with multiple inputs and multiple outputs (MIMO).
// Note: the function takes a pointer to a eqSys_mimo function (eqSystem), a pointer to the state array (x), a pointer to the input array (u), a time value (t), the integration step (dt) and the order of the system (order).

void rk4(eqSys_mimo eqSystem, double* x, const double* u, const double& t, const double& dt, const int& order);


// Computes one integration loop of Runge-Kutta 4, updating the state array after the process. Suited for systems with a single input and a single output (SISO).
// Note: the function takes a pointer to a eqSys_siso function (eqSystem), a pointer to the state array (x), an input value (u), a time value (t), the integration step (dt) and the order of the system (order).

void rk4(eqSys_siso eqSystem, double* x, const double& u, const double& t, const double& dt, const int& order);



#endif /* rk4_h */
