/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Nicolas Vendramin Gatti>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 28/10/2026
Objetivo    : Imprimir uma arvore binaria em nivel.
Dificuldade : <<<Aplicar a logica da fila no conceito pedido pelo exercicio>>>
Uso de IA   : <<<Usei para me auxiliar a aplicar a logica da fila para fazer a impressao>>>
-------------------------------------------------------------------------- */

#include <stdio.h>

// Criando estrutura da arvore
struct arv {
    int conteudo;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv no;
typedef no *arvore;

// Criando estrutura da fila
typedef struct cel {
    no *valor;
    struct cel *prox;
} celula;

// ------------------ Inserindo na arvore ------------------

void inserir(arvore *r, int v[], int n) {
    int i;
    no *p, *f;

    for (i = 0; i < n; i++) {
        no *novo;
        novo = malloc(sizeof(no));

        novo->esq = NULL;
        novo->dir = NULL;
        novo->conteudo = v[i];

        if (*r == NULL) {
            *r = novo;
            continue;
        }
        else {
            f = *r;

            while (f != NULL) {
                p = f;

                if (f->conteudo > novo->conteudo) {
                    f = f->esq;
                }
                else {
                    f = f->dir;
                }
            }

            if (p->conteudo > novo->conteudo) {
                p->esq = novo;
            }
            else {
                p->dir = novo;
            }
        }
    }
}

// ------------------ Logica da fila ------------------

void enfileirar(celula **s, celula **t, no *x) {
    celula *novo;
    novo = malloc(sizeof(celula));

    novo->prox = NULL;
    novo->valor = x;

    if (*s == NULL) {
        *s = *t = novo;
    }
    else {
        (*t)->prox = novo;
        *t = novo;
    }
}

no *desinfileirar(celula **s, celula **t) {
    celula *lixo;
    no *x;

    lixo = *s;
    x = lixo->valor;

    *s = (*s)->prox;

    if (*s == NULL)
        *t = NULL;

    free(lixo);
    return x;
}

// ------------------ Listagem em nivel ------------------

void listnivel(arvore r) {
    celula *s = NULL;
    celula *t = NULL;
    no *atual;
    int primeiro = 1;

    if (r == NULL)
        return;

    enfileirar(&s, &t, r);

    while (s != NULL) {
        atual = desinfileirar(&s, &t);

        if (primeiro == 0)
            printf(" ");

        printf("%d", atual->conteudo);
        primeiro = 0;

        if (atual->esq != NULL) {
            enfileirar(&s, &t, atual->esq);
        }

        if (atual->dir != NULL) {
            enfileirar(&s, &t, atual->dir);
        }
    }

    printf("\n");
}

// ------------------ Liberar arvore ------------------

void liberar(arvore r) {
    if (r != NULL) {
        liberar(r->esq);
        liberar(r->dir);
        free(r);
    }
}

// ------------------ Main ------------------

int main() {
    int c, n, i, caso;
    int *v;
    arvore r;

    scanf("%d", &c);

    for (caso = 1; caso <= c; caso++) {
        scanf("%d", &n);

        v = malloc(n * sizeof(int));

        for (i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        r = NULL;

        inserir(&r, v, n);

        printf("Case %d:\n", caso);
        listnivel(r);
        printf("\n");

        liberar(r);
        free(v);
    }

    return 0;
}
