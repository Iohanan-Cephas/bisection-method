#include <stdlib.h>
#include <stdio.h>
#include "bissection.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    printf("======== Bisection Method ========\n");
    int degree, opt = 1;
    double a, b, x, E;

    do {
        printf("Digite o grau do polinomio: ");
        if (scanf("%d", &degree) != 1 || degree < 1) {
            printf("Grau invalido. Por favor, tente novamente.\n");
            continue;
        }

        double *coefficients = (double *)malloc((degree + 1) * sizeof(double));
        
        if (coefficients == NULL) {
            printf("Erro de alocacao de memoria.\n");
            return 1;
        }

        printf("Digite os coeficientes do polinomio, comecando pelo termo de maior grau: ");
        for (int i = 0; i <= degree; i++) {
            if (scanf("%lf", &coefficients[i]) != 1) {
                printf("Entrada invalida. Por favor, tente novamente.\n");
                free(coefficients);
                return 1;
            }
        }

        printf("Digite o valor de 'a': ");
        if (scanf("%lf", &a) != 1) {
            printf("Entrada invalida. Por favor, tente novamente.\n");
            free(coefficients);
            return 1;
        }

        printf("Digite o valor de 'b': ");
        if (scanf("%lf", &b) != 1) {
            printf("Entrada invalida. Por favor, tente novamente.\n");
            free(coefficients);
            return 1;
        }

        double fa = calculatePolynomial(coefficients, degree, a);
        double fb = calculatePolynomial(coefficients, degree, b);

        while ((fa * fb) > 0) {
            printf("O intervalo nao e aplicavel. Digite um novo intervalo!\n");
            printf("Digite o valor de 'a': ");
            if (scanf("%lf", &a) != 1) {
                printf("Entrada invalida. Por favor, tente novamente.\n");
                free(coefficients);
                return 1;
            }
            printf("Digite o valor de 'b': ");
            if (scanf("%lf", &b) != 1) {
                printf("Entrada invalida. Por favor, tente novamente.\n");
                free(coefficients);
                return 1;
            }
            fa = calculatePolynomial(coefficients, degree, a);
            fb = calculatePolynomial(coefficients, degree, b);
        }

        printf("Digite a tolerancia (epsilon): ");
        if (scanf("%lf", &E) != 1 || E <= 0) {
            printf("Tolerancia invalida. Por favor, tente novamente.\n");
            free(coefficients);
            return 1;
        }

        clear_screen();

        int aux = iterationsNumber(a, b, E);
        double result;
        for (int i = 0; i <= aux; i++) {
            double c = C(a, b);
            double fc = calculatePolynomial(coefficients, degree, c);
            printf("| iteracao %d | a = %.4lf | b = %.4lf | c = %.4lf | |b - a| = %.4lf | f(c) = %.4lf |\n", i, a, b, c, absolute(b - a), fc);
            if (calculatePolynomial(coefficients, degree, a) * fc < 0) {
                b = c;
            } else {
                a = c;
            }
            result = c;
        }

        printf("A raiz aproximada e: %.4lf\n\n", result);
        printf("Deseja continuar? (0/1): ");
        if (scanf("%d", &opt) != 1 || (opt != 0 && opt != 1)) {
            printf("Opcao invalida. Encerrando o programa.\n");
            free(coefficients);
            return 1;
        }

        clear_screen();
        free(coefficients);

    } while (opt != 0);

    return 0;
}