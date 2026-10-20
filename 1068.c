# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 29/09/2026
Objetivo    : Analisar se a colocacao de parenteses esta correta.
Dificuldade : <<<Enxergar essa colocacao de parenteses como uma pilha>>>
Uso de IA   : <<<Usei a IA para me ajudar a organizar meu raciocinio e corrigir o que eu estava errando>>>
-------------------------------------------------------------------------- */

MODO 1: 
#include <stdio.h>
int main(){
    char exp[1001];
    while (fgets(exp,sizeof(exp),stdin) != NULL){
        int cont = 0, verdade = 1;
        int i;
        for (i=0; exp[i] != '\0';i++){
            if (exp[i] == '(') cont++;
            if (exp[i] == ')') cont--;
            if (cont < 0){
                verdade = 0;
                break;
            }
        }
        if (cont != 0) verdade = 0;
        if (verdade == 1) printf("correct\n");
        if (verdade == 0) printf("incorrect\n");
    }
    return 0;

    MODO 2:
    #include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    char valor;
    struct cel *prox;
} Celula;

void empilhar(Celula **t, char c){
    Celula *nova;
    nova = malloc(sizeof(Celula));
    nova->valor = c;
    nova->prox = *t;
    *t = nova;
}

void desempilhar(Celula **t){
    Celula *lixo;
    lixo = *t;
    *t = lixo->prox;
    free(lixo);
}

int main(){
    char exp[1001];
    int i;

    while (fgets(exp, sizeof(exp), stdin) != NULL){

        Celula *pilha = NULL;
        int verdade = 1;

        for (i = 0; exp[i] != '\0'; i++){

            if (exp[i] == '(')
                empilhar(&pilha, '(');

            if (exp[i] == ')'){

                if (pilha == NULL){
                    verdade = 0;
                    break;
                }

                desempilhar(&pilha);
            }
        }

        if (pilha != NULL)
            verdade = 0;

        while (pilha != NULL){
            desempilhar(&pilha);
        }

        if (verdade == 1)
            printf("correct\n");

        if (verdade == 0)
            printf("incorrect\n");
    }

    return 0;
}
