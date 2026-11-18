# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 18/11/2026
Objetivo    : Implementar a estrutura de um grafo dirigido e analisar a existencia de cilcos.
Dificuldade : <<<Adaptar o codigo dfs para identificar um ciclo>>>
Uso de IA   : <<<Usei a IA para me auxiliar na parte do codigo dfs em como fazer indentificar o ciclo. Tambem para fazer a lista de adjacencia>>>
-------------------------------------------------------------------------- */
// COM MATRIZ DE ADJACENCIA:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **criargrafo(int n){
    int **grafo;
    int i,j;
    grafo = malloc(n * sizeof(int *));
    for (i=0;i<n;i++){
        grafo[i] = malloc(n *sizeof(int));
    }
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            grafo[i][j] = 0;
        }
    }
    return grafo;
}

void inserirgrafo(int **grafo, int a, int b){
    grafo[a][b] = 1;
}

int dfs(int **grafo, int *visitado,int n, int v){
    int i;
    visitado[v] = 1;
    for (i=0;i<n;i++){
        if (grafo[v][i] == 1){
            if (visitado[i] == 1){
                return 1;
            }
            if (visitado[i] == 0){
                if (dfs(grafo,visitado,n,i) == 1){
                    return 1;
                }
            }
        }
    }
    visitado[v] = 2;
    return 0;
}


int main(){
    int n,m,t,a,b;
    int i,s, ciclo = 0;
    int **grafo;
    int *visitado;
    scanf("%d", &t);
    while (t != 0){
        scanf("%d %d", &n, &m);
        visitado = malloc(n * sizeof(int));
        for (i=0;i<n;i++){
            visitado[i] = 0;
        }
        grafo = criargrafo(n);
        for (i=0;i<m;i++){
            scanf("%d %d", &a,&b);
            inserirgrafo(grafo,a-1,b-1);
        }
        for (i=0;i<n;i++){
            if (visitado[i] == 0){
                if (dfs(grafo,visitado,n,i) == 1){
                    ciclo = 1;
                    break;
                }
            }
        }
        if (ciclo == 1) printf("SIM\n");
        else printf("NAO\n");
        for (i=0;i<n;i++){
            free(grafo[i]);
        }
        free(grafo);
        free(visitado);
        t--;
    }
    return 0;
}

// USANDO LISTA DE ADJACENCIA (para evitar excesso de memoria):

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int destino;
    struct no *prox;
} No;

No **criargrafo(int n){
    return calloc(n, sizeof(No *));
}

void inserirgrafo(No **grafo, int a, int b){
    No *novo = malloc(sizeof(No));

    novo->destino = b;
    novo->prox = grafo[a];
    grafo[a] = novo;
}

int dfs(No **grafo, int *visitado, int v){
    No *p;
    int i;

    visitado[v] = 1;

    for (p = grafo[v]; p != NULL; p = p->prox){
        i = p->destino;

        if (visitado[i] == 1){
            return 1;
        }

        if (visitado[i] == 0){
            if (dfs(grafo, visitado, i) == 1){
                return 1;
            }
        }
    }

    visitado[v] = 2;
    return 0;
}

int main(){
    int n, m, t, a, b;
    int i, ciclo;
    No **grafo;
    No *p, *aux;
    int *visitado;

    scanf("%d", &t);

    while (t != 0){
        ciclo = 0;

        scanf("%d %d", &n, &m);

        visitado = calloc(n, sizeof(int));
        grafo = criargrafo(n);

        for (i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            inserirgrafo(grafo, a-1, b-1);
        }

        for (i = 0; i < n; i++){
            if (visitado[i] == 0){
                if (dfs(grafo, visitado, i) == 1){
                    ciclo = 1;
                    break;
                }
            }
        }

        if (ciclo == 1) printf("SIM\n");
        else printf("NAO\n");

        for (i = 0; i < n; i++){
            p = grafo[i];
            while (p != NULL){
                aux = p;
                p = p->prox;
                free(aux);
            }
        }

        free(grafo);
        free(visitado);

        t--;
    }

    return 0;
}
