#include <stdlib.h>
#include <stdio.h>
#include "bissection.h"

int main(){
    printf("======== Bisection Method ========\n");
    int grau, opt = 1;
    double a, b, x, E;

    do{
        printf("Digite o grau do polinomio: ");
        scanf("%d", &grau);
        double coeficientes[grau];
        printf("Digite os coeficientes do polinomio, comecando pelo termo de maior grau: ");
        for (int i = 0; i <= grau; i++) {
            scanf("%lf", &coeficientes[i]);
        }

        printf("Digite o valor de 'a': ");
        scanf("%lf", &a);
        printf("Digite o valor de 'b': ");
        scanf("%lf", &b);
        double fa = calculatePolynomial(coeficientes, grau, a);
        double fb = calculatePolynomial(coeficientes, grau, b);
        if((fa * fb) > 0){
            do{
                printf("O intervalo nao e aplicavel. Digite um novo intervalo!\n");
                printf("Digite o valor de 'a': ");
                scanf("%lf", &a);
                printf("Digite o valor de 'b': ");
                scanf("%lf", &b);
                fa = calculatePolynomial(coeficientes, grau, a);
                fb = calculatePolynomial(coeficientes, grau, b);
            }while(fa*fb > 0);
        }

        printf("Digite a tolerancia (epsilon): ");
        scanf("%lf", &E);

        system("cls");

        int aux = iterationsNumber(a, b, E);
        double result;
        for(int i = 0; i <= aux; i++){
            double c = C(a ,b);
            printf("| iteracao %d | a = %.4lf | b = %.4lf | c = %.4lf | |b - a| = %.4lf | f(c) = %.4lf |\n", i, a, b, c, (b-a),calculatePolynomial(coeficientes, grau, c));
            if(calculatePolynomial(coeficientes, grau, a) * calculatePolynomial(coeficientes, grau, c) < 0){
                b = c;
            }else{
                a = c;
            }
            result = c;
        }
        
        printf("A raiz aproximada e: %.4lf\n\n", result);
        printf("Deseja continuar? (0/1): ");
        scanf("%d", &opt);

        system("cls");
    }while(opt != 0);

    return 0;
}