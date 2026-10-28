# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1094
Data        : 28/10/2026
Objetivo    : Organizar em uma especie de relatorio as experiencias ocorridas as longo do tempo.
Dificuldade : <<<Nenhuma>>>
Uso de IA   : <<<Corrigir o presentation error + tirar umas duvidas basicas do que se pode fazer em C>>>
-------------------------------------------------------------------------- */
#include <stdio.h>

void info (int n){
    int qtdC=0, qtdR=0,qtdS=0;
    int numero, total;
    char letra;

    while (n > 0){
        scanf("%d %c", &numero, &letra);
        if (letra == 'C'){
            qtdC += numero;
        }
        if (letra == 'R'){
            qtdR += numero;
        }
        if (letra == 'S'){
            qtdS += numero;
        }
        n--;
    }
    total = qtdC + qtdR + qtdS;
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", qtdC);
    printf("Total de ratos: %d\n", qtdR);
    printf("Total de sapos: %d\n", qtdS);
    printf("Percentual de coelhos: %.2f %% \n", (qtdC*100.0)/total);
    printf("Percentual de ratos: %.2f %% \n", (qtdR*100.0)/total);
    printf("Percentual de sapos: %.2f %% \n", (qtdS*100.0)/total);

}

int main(){
    int n;
    scanf("%d", &n);
    info(n);
    return 0;
}

