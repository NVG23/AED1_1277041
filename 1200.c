# AED1_1277041
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 09/11/2026
Objetivo    : Realizar varias funcoes de acordo com a entrada.
Dificuldade : <<<Fazer a leitura da entrada e deixar a saida na forma que o beecrowd deseja>>>
Uso de IA   : <<<Usei a IA para me ajudar na parte da leitura da entrada e para deixar de uma forma que o beecrowd aceitasse>>>
-------------------------------------------------------------------------- */
//Sem a saida com o modelo do beecrowd
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cel{
    char conteudo;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel no;
typedef no *arvore;

void inserir(arvore *r, char x){
    no *novo;
    no *f;
    no *p;
    novo = malloc(sizeof(no));
    novo->conteudo = x;
    novo->esq = NULL;
    novo->dir = NULL;
    if (*r == NULL){
        *r = novo;
    }
    else{
        f = *r;
        while (f != NULL){
            p = f;
            if (f->conteudo > novo->conteudo){
                f = f->esq;
            }
            else f = f->dir;
        }
        if (p->conteudo > novo->conteudo){
                p->esq = novo;
            }
        else p->dir = novo;
        }
}


int busca(arvore r, char x){
    while (r != NULL && r->conteudo != x){
        if (r->conteudo > x) r = r->esq;
        else r = r->dir;
    }
    if (r == NULL) return 0;
    else return 1;
}

void infixa(arvore r){
    if (r != NULL){
        infixa(r->esq);
        printf("%c", r->conteudo);
        infixa(r->dir);
    }
}

void prefixa(arvore r){
    if (r!=NULL){
        printf("%c", r->conteudo);
        prefixa(r->esq);
        prefixa(r->dir);
    }
}

void posfixa(arvore r){
    if (r!=NULL){
        posfixa(r->esq);
        posfixa(r->dir);
        printf("%c", r->conteudo);
    }
}

int main(){
    arvore r = NULL;
    char comando[20];
    char letra;
    
    while (scanf("%19s", comando) != EOF){
        if (strcmp(comando,"I") == 0){
            scanf(" %c", &letra);
            inserir(&r,letra);
        }
        if (strcmp(comando,"P") == 0){
            scanf(" %c", &letra);
            if (busca(r,letra) == 1) printf("%c existe\n", letra);
            if (busca(r,letra) == 0) printf("%c nao existe\n", letra);

        }
        if (strcmp(comando, "INFIXA") == 0){
            infixa(r);
            printf("\n");
        }
        if (strcmp(comando, "PREFIXA") == 0){
            prefixa(r);
            printf("\n");
        }
        if (strcmp(comando, "POSFIXA") == 0){
            posfixa(r);
            printf("\n");
        }
    }
    return 0;
}

// Com a saida do modelo do beecrowd


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cel{
    char conteudo;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel no;
typedef no *arvore;

void inserir(arvore *r, char x){
    no *novo;
    no *f;
    no *p;

    novo = malloc(sizeof(no));
    novo->conteudo = x;
    novo->esq = NULL;
    novo->dir = NULL;

    if (*r == NULL){
        *r = novo;
    }
    else{
        f = *r;

        while (f != NULL){
            p = f;
            if (f->conteudo > novo->conteudo){
                f = f->esq;
            }
            else f = f->dir;
        }

        if (p->conteudo > novo->conteudo){
            p->esq = novo;
        }
        else p->dir = novo;
    }
}

int busca(arvore r, char x){
    while (r != NULL && r->conteudo != x){
        if (r->conteudo > x) r = r->esq;
        else r = r->dir;
    }

    if (r == NULL) return 0;
    else return 1;
}

void infixa(arvore r, int *primeiro){
    if (r != NULL){
        infixa(r->esq, primeiro);

        if (*primeiro == 0) printf(" ");
        printf("%c", r->conteudo);
        *primeiro = 0;

        infixa(r->dir, primeiro);
    }
}

void prefixa(arvore r, int *primeiro){
    if (r != NULL){
        if (*primeiro == 0) printf(" ");
        printf("%c", r->conteudo);
        *primeiro = 0;

        prefixa(r->esq, primeiro);
        prefixa(r->dir, primeiro);
    }
}

void posfixa(arvore r, int *primeiro){
    if (r != NULL){
        posfixa(r->esq, primeiro);
        posfixa(r->dir, primeiro);

        if (*primeiro == 0) printf(" ");
        printf("%c", r->conteudo);
        *primeiro = 0;
    }
}

int main(){
    arvore r = NULL;
    char comando[20];
    char letra;
    int primeiro;

    while (scanf("%19s", comando) != EOF){

        if (strcmp(comando, "I") == 0){
            scanf(" %c", &letra);
            inserir(&r, letra);
        }

        if (strcmp(comando, "P") == 0){
            scanf(" %c", &letra);

            if (busca(r, letra) == 1)
                printf("%c existe\n", letra);

            if (busca(r, letra) == 0)
                printf("%c nao existe\n", letra);
        }

        if (strcmp(comando, "INFIXA") == 0){
            primeiro = 1;
            infixa(r, &primeiro);
            printf("\n");
        }

        if (strcmp(comando, "PREFIXA") == 0){
            primeiro = 1;
            prefixa(r, &primeiro);
            printf("\n");
        }

        if (strcmp(comando, "POSFIXA") == 0){
            primeiro = 1;
            posfixa(r, &primeiro);
            printf("\n");
        }
    }

    return 0;
}
