//
//  rk4-test.cpp
// 
//  Test file for the library 'rk4'.
//
//  Created by João Lucas Correia Barbosa de Farias
//  See https://github.com/jotafarias13/rk4
//
//  If the library 'gnuplot' is installed you can
//  use it to plot the results of this program, just
//  uncomment the commented lines.
//


#include <stdio.h>
#include <math.h>

#include "rk4.h"
// #include "gnuplot.h"

void eqSystem(const double* x, double* xp, const double& u, const double& t);
double g = 9.81;
double l = 0.25;
double b = 1.0;


int main() {
    
    const char file[] = "./output/results.txt";

    FILE* out = fopen(file, "w");

    if (out == NULL) {
      printf("Error: cannot open %s for writing!\n", file);
    }
    
    const int n_states = 2;
    
    double t;
    double dt = 0.001;
    double T = 15.0;
    const int length = int(T/dt);
    
    double x[n_states];
    double xp[n_states];
    x[0] = (M_PI/180.0)*90.0;
    x[1] = 0.0;
    double u = 0.0;
    
    for (int i=0; i<length; i++) {
        
        t = dt*i;
        
        fprintf(out, "%.5e %.5e %.5e\n", t, x[0], x[1]);
        
        if (i < length-1) {
            rk4(eqSystem, x, u, t, dt, n_states);
        }
        
    }
    

    fclose(out);
    
    // Gnuplot2D p1(2);
    // p1.curve[0].set_plot(file, 1, 2, "dark-blue");
    // p1.curve[0].set_title("$\\theta(t)$");
    // p1.curve[0].set_with_lines(3.0);
    // p1.curve[1].set_plot(file, 1, 3, "brown");
    // p1.curve[1].set_title("$\\dot{\\theta}(t)$");
    // p1.curve[1].set_with_lines(3.0);
    // p1.set_title("Simple Pendulum Dynamics");
    // p1.set_xlabel("t $[s]$");
    // p1.set_ylabel("$\\theta(t)$ [rad] \\quad $\\dot{\\theta}(t)$ [rad/s]");
    // p1.set_key("r", "t");
    // p1.add_string("set key box width 0.5 height 0.5 opaque spacing 1.5");
    // p1.bundle_files("./output");
    // p1.set_term_pdflatex_eps();
    
    return 0;
}


void eqSystem(const double* x, double* xp, const double& u, const double& t) {
    
    xp[0] = x[1];
    xp[1] = -(g/l)*sin(x[0]) - b*x[1];
    
}
