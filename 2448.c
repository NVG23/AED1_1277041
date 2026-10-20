# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 29/09/2026
Objetivo    : Calcular o tempo para fazer entrega das encomendas.
Dificuldade : <<<Pensar em como calcular o delta do tempo>>>
Uso de IA   : <<<Usei a IA apenas pra me ajudar com o presentation error>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 45000

int buscabin(int ni[], int qtdN, int mi[], int qtdM){
    int tempo=0;
    int ini = 0,meio,fim = qtdN-1;
    int i, patual = 0;

    meio = (ini + qtdN)/2;
    for (i=0;i<qtdM;i++){
        ini = 0;
        fim = qtdN-1;
        while (ini <= fim){
            if (ni[meio] < mi[i]){
                ini = meio+1;
                meio = (ini+fim)/2;
            }
            if (ni[meio] > mi[i]){
                fim = meio-1;
                meio = (ini+fim)/2;
            }
            if (ni[meio] == mi[i]){
                // O meio sera o destino
                if (meio > patual){
                    tempo = tempo + (meio-patual);
                    patual = meio;
                    
                }
                if (meio < patual){
                    tempo = tempo + (patual-meio);
                    patual = meio;
                }
                break;
            }
        }
    }
    return tempo;
}


int main(){
    int qtdN, qtdM, *ni, *mi, tempo,i;
    scanf("%d%d", &qtdN,&qtdM);
    ni = malloc(qtdN*(sizeof(int)));
    mi = malloc(qtdM*(sizeof(int)));
    for (i=0;i<qtdN;i++){
        scanf("%d", &ni[i]);
    }
    for (i=0;i<qtdM;i++){
        scanf("%d", &mi[i]);
    }
    tempo = buscabin(ni,qtdN,mi,qtdM);
    printf("%d\n", tempo);

    free(ni);
    free(mi);
    return 0;
}
