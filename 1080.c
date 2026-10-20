# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 25/08/2026
Objetivo    : Pegar um vetor de 100 numeros e encontrar o maior, mostrando sua posicao.
Dificuldade : <<<Fazer o beecrowd aceitar meu codigo>>>
Uso de IA   : <<<Usei a IA pra confirmar que meu codigo estava correto>>>
-------------------------------------------------------------------------- */
#include <stdio.h>

int maiornum(int v[], int *p) {
    int i, maior;

    maior = v[0];
    *p = 1;

    for (i = 1; i < 100; i++) {
        if (v[i] > maior) {
            maior = v[i];
            *p = i + 1;
        }
    }

    return maior;
}

int main() {
    int v[100], j, p;

    for (j = 0; j < 100; j++) {
        scanf("%d", &v[j]);
    }

    printf("%d\n", maiornum(v, &p));
    printf("%d\n", p);

    return 0;
}
