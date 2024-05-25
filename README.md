# Método da Bisseção

Este projeto implementa o método da bisseção para encontrar raízes de polinômios. O programa solicita ao usuário os coeficientes do polinômio, o intervalo inicial [a, b], e a tolerância desejada (epsilon). Em seguida, realiza o método da bisseção para encontrar uma raiz aproximada do polinômio dentro do intervalo especificado.

## Estrutura do Projeto

O projeto consiste em três arquivos principais:

- `bissection.h`: Cabeçalho que contém as declarações das funções utilizadas no método da bisseção.
- `bissection.c`: Implementação das funções declaradas em `bissection.h`.
- `main.c`: Contém a lógica principal do programa e a interação com o usuário.

## Funções

### `bissection.c`

- **`int iterationsNumber(double a, double b, double E)`**: 
  - Calcula o número de iterações necessárias para o método da bisseção com base no intervalo inicial [a, b] e na tolerância desejada E.
  - **Parâmetros**:
    - `a`: Limite inferior do intervalo.
    - `b`: Limite superior do intervalo.
    - `E`: Tolerância desejada.
  - **Retorno**: Número de iterações necessárias.
  
- **`double C(double a, double b)`**:
  - Calcula o ponto médio entre dois valores a e b.
  - **Parâmetros**:
    - `a`: Primeiro valor.
    - `b`: Segundo valor.
  - **Retorno**: O ponto médio entre a e b.
  
- **`double calculatePolynomial(double coefficients[], int degree, double x)`**:
  - Calcula o valor de um polinômio em um ponto x.
  - **Parâmetros**:
    - `coefficients`: Array de coeficientes do polinômio, começando pelo coeficiente do termo de maior grau.
    - `degree`: Grau do polinômio.
    - `x`: Valor no qual o polinômio será avaliado.
  - **Retorno**: O valor do polinômio em x.

### `main.c`

- **Função `main`**:
  - Interage com o usuário para obter os coeficientes do polinômio, os valores de `a` e `b` para o intervalo inicial, e a tolerância `E`.
  - Verifica se o intervalo inicial é válido, ou seja, se os valores do polinômio em `a` e `b` têm sinais opostos.
  - Realiza o método da bisseção para encontrar uma raiz aproximada do polinômio dentro do intervalo especificado, imprimindo cada iteração do processo.
  - Permite ao usuário realizar múltiplas execuções do método, caso deseje continuar.

## Compilação e Execução

### Compilação

Para compilar o projeto, você pode usar um compilador de C como `gcc`. No terminal, navegue até o diretório onde os arquivos estão localizados e execute o seguinte comando:

```sh
gcc -o exec main.c bissection.c
```
### Execução

Após compilado, para executar o projeto basta utilizar o seguinte comando no terminal:

```sh
./exec.exe
```