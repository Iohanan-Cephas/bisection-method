#include <math.h>
#include "bissection.h"

int iterationsNumber(double a, double b, double E){
    double K = (log10(b-a) - log10(E)) / log10(2);
    (int)K;
    return K + 1;
}

double C(double a, double b){
    return (a + b) / 2;
}

double calculatePolynomial(double coefficients[], int degree, double x) {
    double result = 0;
    
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    
    return result;
}

double absolute(double x){
    return (x < 0) ? -x : x;
}