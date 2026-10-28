# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 28/10/2026
Objetivo    : Converter uma expressao da forma infixa para a pos-fixa.
Dificuldade : <<<Entender a logica do exercicio e como implementar a pilha de forma correta >>>
Uso de IA   : <<<Usei a IA me auxiliar na minha dificuldade>>>
-------------------------------------------------------------------------- */
#include <stdio.h>

int prioridade(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    int n, i, j, topo;
    char expressao[512], pilha[512], c;

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        fgets(expressao, 512, stdin);
        topo = -1;

        for (j = 0; expressao[j] != '\0'; j++) {
            c = expressao[j];

            if (c == ' ' || c == '\n' || c == '\r')
                continue;

            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')) {
                printf("%c", c);
            }
            else if (c == '(') {
                pilha[++topo] = c;
            }
            else if (c == ')') {
                while (topo >= 0 && pilha[topo] != '(') {
                    printf("%c", pilha[topo]);
                    topo--;
                }
                topo--;
            }
            else {
                while (topo >= 0 && pilha[topo] != '(' &&
                       (prioridade(pilha[topo]) > prioridade(c) ||
                       (prioridade(pilha[topo]) == prioridade(c) && c != '^'))) {
                    printf("%c", pilha[topo]);
                    topo--;
                }

                pilha[++topo] = c;
            }
        }

        while (topo >= 0) {
            printf("%c", pilha[topo]);
            topo--;
        }

        printf("\n");
    }

    return 0;
