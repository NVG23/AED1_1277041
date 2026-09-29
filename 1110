# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 29/09/2026
Objetivo    : Uma fila de cartas tirando a primeira e colocando a seguida pro final, retornando a que sobrar e as cartas descartadas.
Dificuldade : <<<Organizar o pensamento e fazer por meio de uma fila>>>
Uso de IA   : <<<Usei a IA para me ajudar a organizar meu raciocinio e corrigir o que eu estava errando>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100


typedef struct cel{
    int vcarta;
    struct cel *prox;
} Celula;


int operacao(int n,int v[], Celula **s, Celula **t){
    Celula *p;
    Celula *lixo;
    int res = n, x, tam=0;

    while (res >= 2){

        // Removendo o topo e guardando esse valor
        lixo = *s;
        x = lixo->vcarta;
        (*s) = (*s)->prox;
        free(lixo);

        v[tam] = x;
        tam++;

        res--;

        // Jogando a carta seguinte pra base
        if (res >= 2){
            p = *s;
            (*s) = (*s)->prox;
            p->prox = NULL;
            (*t)->prox = p;
            *t = p;
        }
    }

    return (*s)->vcarta;
}


void imprimir(int resto, int v[], int x){
    int i;

    printf("Discarded cards:");

    for (i=0;i<x;i++){
        if (i==0) printf(" %d", v[i]);
        else printf(", %d", v[i]);
    }

    printf("\nRemaining card: %d\n", resto);
}


int main(){
    int v[50];
    int n, i, resto;

    Celula *s = NULL;
    Celula *t = NULL;
    Celula *nova;

    while (scanf("%d", &n) == 1 && n != 0){

        s = NULL;
        t = NULL;

        for (i=1;i<=n;i++){

            nova = malloc(sizeof(Celula));
            nova->vcarta = i;
            nova->prox = NULL;

            if (s==NULL){
                s = t = nova;
            }
            else {
                t->prox = nova;
                t = nova;
            }
        }

        resto = operacao(n,v,&s,&t);

        imprimir(resto,v,n-1);

        free(s);
    }

    return 0;
}
