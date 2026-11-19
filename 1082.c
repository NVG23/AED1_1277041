# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 18/11/2026
Objetivo    : Identificar quantidade de componentes conexos e imprimir.
Dificuldade : <<<Adaptar o codigo dfs para identificar um ciclo>>>
Uso de IA   : <<<Usei a IA para me ajudar a deixar a impressao na em ordem alfabetica como o beecrowd exigia>>>
-------------------------------------------------------------------------- */
//Sem estar em ordem alfabetica
#include <stdio.h>
#include <stdlib.h>


void inserirgrafo(int **grafo, int a, int b){
    grafo[a][b] = 1;
    grafo[b][a] = 1;
}

void dfs(int **grafo,int *visitado,int v, int n){
    int i;
    visitado[v] = 1;
    printf("%c,", v + 'a');
    for (i=0;i<n;i++){
        if (grafo[v][i] == 1 && visitado[i] == 0){
            dfs(grafo,visitado,i,n);
        }
    }
}

int main(){
    int n,v,e,s=1;
    int i,j;
    int cont;
    int **grafo;
    int *visitado;
    char a,b;
    scanf("%d", &n);
    
    while (n!=0){
        scanf("%d %d", &v,&e);
        // Criar grafo
        grafo = malloc(v*sizeof(int *));
        for (i=0;i<v;i++){
            grafo[i] = malloc(v*sizeof(int));
        }
        // Criar visitado
        visitado = malloc(v*sizeof(int));
        //Zerar o Grafo e Visitado
        for (i=0;i<v;i++){
            visitado[i] = 0;
            for(j=0;j<v;j++){
                grafo[i][j] = 0;
            }
        }
        //Zerar contador
        cont=0;

        for (i=0;i<e;i++){
            scanf(" %c %c", &a,&b);
            inserirgrafo(grafo,a - 'a', b - 'a');
        }
        printf("Case #%d:\n", s);
        // Analisar dfs com todos os vertices
        for (i=0;i<v;i++){
            if (visitado[i] == 0){
                cont++;
                dfs(grafo,visitado,i,v);
                printf("\n");
            }
        }
        printf("%d connected components\n\n", cont);
        //Liberar o grafo e o vetor
        for (i=0;i<v;i++){
            free(grafo[i]);
        }
        free(grafo);
        free(visitado);
        s++;
        n--;
    }
}

// Em ordem alfabetica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void inserirgrafo(int **grafo, int a, int b){
    grafo[a][b] = 1;
    grafo[b][a] = 1;
}

void dfs(int **grafo, int *visitado, int v, int n, int componente){
    int i;
    visitado[v] = componente;

    for (i=0;i<n;i++){
        if (grafo[v][i] == 1 && visitado[i] == 0){
            dfs(grafo,visitado,i,n,componente);
        }
    }
}

int main(){
    int n,v,e,s=1;
    int i,j,k;
    int cont;
    int **grafo;
    int *visitado;
    char a,b;

    scanf("%d", &n);

    while (n!=0){
        scanf("%d %d", &v,&e);

        // Criar grafo
        grafo = malloc(v*sizeof(int *));
        for (i=0;i<v;i++){
            grafo[i] = malloc(v*sizeof(int));
        }

        // Criar visitado
        visitado = malloc(v*sizeof(int));

        // Zerar o Grafo e Visitado
        for (i=0;i<v;i++){
            visitado[i] = 0;
            for(j=0;j<v;j++){
                grafo[i][j] = 0;
            }
        }

        cont=0;

        for (i=0;i<e;i++){
            scanf(" %c %c", &a,&b);
            inserirgrafo(grafo,a - 'a', b - 'a');
        }

        printf("Case #%d:\n", s);

        // Identificar todas as componentes
        for (i=0;i<v;i++){
            if (visitado[i] == 0){
                cont++;
                dfs(grafo,visitado,i,v,cont);
            }
        }

        // Imprimir cada componente em ordem alfabética
        for (k=1;k<=cont;k++){
            for (i=0;i<v;i++){
                if (visitado[i] == k){
                    printf("%c,", i + 'a');
                }
            }
            printf("\n");
        }

        printf("%d connected components\n\n", cont);

        // Liberar o grafo e o vetor
        for (i=0;i<v;i++){
            free(grafo[i]);
        }
        free(grafo);
        free(visitado);

        s++;
        n--;
    }

    return 0;
}
