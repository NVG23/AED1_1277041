/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Nicolas Vendramin Gatti
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 29/08/2026
Objetivo    : Ler um vetor de 100 inteiros, apresentar o maior numero e sua posicao. Porem usando alocacao de memoria.
Dificuldade : Fazer o beecrowd aceitar meu codigo.
Uso de IA   : Entender porque o beecrowd estava recusando meu codigo.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int verificar (int *v, int *p){
    int i, maior;
    maior = v[0];
    *p = 1;
    for (i=1;i<100;i++){
        if (v[i] > maior) {
            maior = v[i];
            *p = i+1;
        }
    }
    return maior;
}
int main(){
    int *v,i,p,maior;
    p = 0;
    v = malloc(100*sizeof(int));
    for (i=0;i<100;i++){
        scanf("%d", &v[i]);
    }
    maior = verificar(v,&p);
    printf("%d\n%d\n", maior,p);
    free(v);
    return 0;
}
