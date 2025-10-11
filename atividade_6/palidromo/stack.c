#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void inicializa(Pilha *p) {
    p->topo = -1;
}

bool estaVazia(Pilha *p) {
    return p->topo == -1;
}

bool estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, char valor) {
    if (!estaCheia(p)) {
        p->itens[++p->topo] = valor;
    }
}

char pop(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[p->topo--];
    }
    return '\0';
}

bool ehPalindromo(char *palavra) {
    Pilha p;
    inicializa(&p);

    int tamanho = strlen(palavra);
    int metade = tamanho / 2;

    for (int i = 0; i < metade; i++) {
        push(&p, palavra[i]);
    }

    int inicioSegundaMetade = (tamanho % 2 == 0) ? metade : metade + 1;

    for (int i = inicioSegundaMetade; i < tamanho; i++) {
        if (palavra[i] != pop(&p)) {
            return false;
        }
    }

    return true;
}