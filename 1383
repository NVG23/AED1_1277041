# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 28/08/2026
Objetivo    : Verificar se a matriz e uma solucao para um sudoku 9x9.
Dificuldade : <<<Fazer o programa verificar as matrizes menores 3x3>>>
Uso de IA   : <<<Usei a IA para me ajudar a encontrar uma forma de verificar as matrizes menores 3x3>>>
-------------------------------------------------------------------------- */
#include <stdio.h>

int verificarM (int M[9][9]){
    int i,j,k;
// Lendo a Matriz
    for (i=0;i<9;i++){
        for (j=0;j<9;j++){
            scanf("%d", &M[i][j]);
        }
    }

// Verificando Linhas
    for (i=0;i<9;i++){
        for (j=0;j<9;j++){
            for (k= j + 1;k<9;k++){
                if (M[i][j] == M[i][k]){
                    return 0;
                }
                
            }
        }
    }

// Verificando Colunas
    for (i=0;i<9;i++){
        for (j=0;j<9;j++){
            for (k= i + 1;k<9;k++){
                if (M[i][j] == M[k][j]){
                    return 0;
                    }
                    
                }
            }
    }

// Verificar Matriz 3x3
    int v[9];
    int l,c,u,pos;
    
    for (i=0;i<9; i+=3){
        for (j=0;j<9;j+=3){
            pos = 0;
            for (l=i;l< i+3;l++){
                for (c=j;c<j+3;c++){
                    v[pos] = M[l][c];
                    pos++;
                }
            }
            for (k=0;k<9;k++){
                for (u=k+1;u<9;u++){
                    if (v[k] == v[u]){
                        return 0;
        
                    }
                }
            }
        }
    }
    
    
    return 1;
}

int main() {
    int M[9][9];
    int h,n,i;
    int instancia;
    scanf("%d", &n);
    for (instancia=1; instancia<=n; instancia++){
        h = verificarM(M);
        printf("Instancia %d\n", instancia);
        if (h == 0){
            printf("NAO\n\n");
        }
        if (h == 1){
            printf("SIM\n\n");
        }
    }
    return 0;
}
