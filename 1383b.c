/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Vendramin Gatti
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 29/08/2026
Objetivo    : Verificar se a matriz fornecida e uma solucao de sudoku.
Dificuldade : Corrigir pequenos erros que o beecrowd nao aceita
Uso de IA   : Usei para me ajudar a entender o conceito de alocao dinamica para matrizes e me ajudar a encontrar os pequenos erros que o beecrowd nao aceitava.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int sudoku (int **M){
    int i,j,k;
// Verificar Colunas

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            for(k=i+1;k<9;k++){
                if (M[i][j] == M[k][j]){
                    return 0;
                }
            }
        }
    }
// Verificar Linhas
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            for(k=j+1;k<9;k++){
                if (M[i][j] == M[i][k]){
                    return 0;
                }
            }
        }
    }

// Verificar Matriz 3x3
int c,l,v[9],pos,q;
    for (i=0;i<9; i+=3){
        for (j=0;j<9; j+=3){
            pos = 0;
            for(l=i;l<i+3;l++){
                for(c=j;c<j+3;c++){
                    v[pos] = M[l][c];
                    pos++;
                    
                }
            }
            for (k=0;k<9;k++){
                for(q=k+1;q<9;q++){
                    if (v[k] == v[q]) return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    int **M;
    int i,n,s,j,t;
    scanf("%d", &n);
    M = malloc(9 * sizeof(int *));
    for (i=0;i<9;i++){
        M[i] = malloc(9 * sizeof(int));
    }
    for (t=0;t<n;t++){
        for (i=0;i<9;i++){
            for (j=0;j<9;j++){
                scanf("%d", &M[i][j]);
        }
    }
        s = sudoku(M);
        if (s == 1) {
            printf("Instancia %d\nSIM\n\n", t+1);
        }
        if (s == 0) {
            printf("Instancia %d\nNAO\n\n", t+1);
        }
    }
    for (i=0;i<9;i++){
        free(M[i]);
    }
    free(M);
    return 0;
}
