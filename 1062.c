# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 12/10/2026
Objetivo    : Verificar se e possivel reorganizar os vagoes de um trem de acordo com uma sequencia fornecida na entrada.
Dificuldade : <<<Entender a logica do exercicio e seu objetivo>>>
Uso de IA   : <<<Usei a IA para basicamente todo o exercicio, pois tive grande dificuldade em entender o objetivo e a logica do exercicio.
                  Tambem para deixar na forma como o beecrowd exige.>>>
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} celula;

int verificar(int n, int q[], celula **t) {
    int i, j, pos = 0, verdade = 1, prox = 1;
    int *v;

    v = malloc(n * sizeof(int));

    for (j = 0; j < n; j++) {

        while (*t == NULL || q[j] != (*t)->valor) {

            if (prox > n) {
                verdade = 0;
                break;
            }

            // Empilhar
            celula *nova;
            nova = malloc(sizeof(celula));
            nova->valor = prox;
            nova->prox = *t;
            *t = nova;
            prox++;
        }

        if (verdade == 0) break;

        // Desempilhar
        celula *lixo;
        lixo = *t;
        *t = (*t)->prox;
        v[pos] = lixo->valor;
        free(lixo);
        pos++;
    }

    // Comparar vetores
    if (verdade == 1) {
        for (i = 0; i < n; i++) {
            if (v[i] != q[i]) {
                verdade = 0;
                break;
            }
        }
    }

    // Limpar pilha restante
    while (*t != NULL) {
        celula *lixo;
        lixo = *t;
        *t = (*t)->prox;
        free(lixo);
    }

    free(v);
    return verdade;
}

int main() {
    celula *t = NULL;
    int n, i, vdd;
    int *q;

    while (scanf("%d", &n) == 1 && n != 0) {

        q = malloc(n * sizeof(int));

        while (1) {
            scanf("%d", &q[0]);

            if (q[0] == 0) break;

            for (i = 1; i < n; i++) {
                scanf("%d", &q[i]);
            }

            vdd = verificar(n, q, &t);

            if (vdd == 1) printf("Yes\n");
            if (vdd == 0) printf("No\n");
        }

        printf("\n");
        free(q);
    }

    return 0;
}
