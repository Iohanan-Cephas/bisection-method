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

double calculatePolynomial(double coeficientes[], int grau, double x) {
    double resultado = 0;
    int i;
    
    for (i = 0; i <= grau; i++) {
        resultado += coeficientes[i] * pow(x, grau - i);
    }
    
    return resultado;
}