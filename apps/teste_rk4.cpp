//
//  exemplo_rk4.h
//  funcoes
//
//  Created by Jota Farias on 20/08/20.
//  Copyright © 2020 Jota Farias. All rights reserved.
//

#include <iostream>
#include "rk4.h"
#include "gnuplot.h"
#include "tempo.h"

void eqSistema(const double* x, double* xp, const double& u, const double& t);
double g = 9.81;
double l = 0.25;
double b = 1.0;


int main() {
    
    clock_t inicio = Inicio();
    
    FILE *out;
    if ((out = fopen("results.txt", "w")) == NULL)
        printf("Cannot open the file results.txt!\n");
    
    int n_estados = 2;
    
    double t;
    double dt = 0.001;
    double T = 15.0;
    const int tamanho = int(T/dt);
    
    double x[n_estados];
    double xp[n_estados];
    x[0] = (M_PI/180.0)*90.0;
    x[1] = 0.0;
    double u = 0.0;
    
    for (int i=0; i<tamanho; i++) {
        
        t = dt*i;
        
        fprintf(out, "%.5e %.5e %.5e\n", t, x[0], x[1]);
        
        if (i < tamanho-1) {
            rk4(eqSistema, x, u, t, dt, n_estados);
        }
        
    }
    
    rk4(eqSistema, x, u, t, dt, n_estados);
    
    
    Gnuplot2D p1(2);
    p1.curve[0].set_plot("results.txt", 1, 2, "dark-blue");
    p1.curve[0].set_title("$\\theta(t)$");
    p1.curve[0].set_with_lines(3.0);
    p1.curve[1].set_plot("results.txt", 1, 3, "brown");
    p1.curve[1].set_title("$\\dot{\\theta}(t)$");
    p1.curve[1].set_with_lines(3.0);
    p1.set_title("Dinâmica do Pêndulo Simples");
    p1.set_xlabel("t $[s]$");
    p1.set_ylabel("$\\theta(t)$ [rad] \\quad $\\dot{\\theta}(t)$ [rad/s]");
    p1.set_key("r", "t");
    p1.add_string("set key box width 0.5 height 0.5 opaque spacing 1.5");
    p1.set_term_pdflatex_eps();
    
    clock_t fim = Fim();
    printf ("Tempo de Execução: %f segundos.\n", Tempo(inicio, fim));
    
    return 0;
}


void eqSistema(const double* x, double* xp, const double& u, const double& t) {
    
    xp[0] = x[1];
    xp[1] = -(g/l)*sin(x[0]) - b*x[1];
    
}
