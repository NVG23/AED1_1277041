# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 28/10/2026
Objetivo    : Imprimir uma sequencia IJ, seguindo a logica.
Dificuldade : <<<Nenhuma>>>
Uso de IA   : <<<Nenhum>>>
-------------------------------------------------------------------------- */
void sequencia(){
    int i=1,j=60,k;
    while (j >= 0){
        printf("I=%d J=%d\n", i,j);
        i+=3;
        j-=5;
    }
}

int main(){
    sequencia();
    return 0;
}
