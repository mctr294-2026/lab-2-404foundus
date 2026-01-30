#include "roots.hpp"

bool bisection(std::function<double(double)> f,
               double a, double b,
               double *root) {

                if (f(a) * f(b) >= 0) {
        return false;
    }

    double c;
    for (int i = 0; i < 1e6; ++i) {
        double c = (a + b) / 2.0;

        if (std::abs(f(c)) < 1e-6) {
            *root = c;
            return true;
        }

        if (f(a) * f(c) < 0) {
            b = c; 
        } else {
            a = c; 
        }
    }

    return false;
}


bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root) {
                if (f(a) * f(b) >= 0) {
        return false;
    }

    double c;
    for (int i = 0; i < 1e6; ++i) {
        double c = a - (f(a) * (b - a)) / (f(b) - f(a));

        if (std::abs(f(c)) < 1e-6) {
            *root = c;
            return true;
        }

                if (f(a) * f(c) < 0) {
            b = c; 
        } else {
            a = c; 
        }
    }
    return false;
}

bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root) {
    double x = c; 

    for (int i = 0; i < 1e6; ++i) { 
        double fx = f(x);
        double gx = g(x); 

        if (std::abs(gx) < 1e-12) {
            return false;
        }

        double x_next = x - (fx / gx);


        if (x_next < a || x_next > b) {
            return false;
        }


        if (std::abs(f(x_next)) < 1e-6) {
            *root = x_next;
            return true;
        }

        x = x_next; 
    }
    return false;
}

bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root) {
    double x_0 = c;
    double x_1 = c+1e-6;

for (int i = 0; i < 1e6; ++i) {
    double f_0 = f(x_0);
    double f_1 = f(x_1); 


    
    double x_2 = x_1 - (f_1 * ((x_1 - x_0)/(f_1-f_0))); 

    if (x_2 < a || x_2 > b) {
        return false;
    }

    if (std::abs(f(x_2)) < 1e-6) {
            *root = x_2;
            return true;
        }
    
    x_0 = x_1;
    x_1 = x_2;}
    
 
    return false;
}