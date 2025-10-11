#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool estaVazia(Pilha *p) {
    return p->topo == -1;
}

bool estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void inicializaPilha(Pilha *p, char nome) {
    p->topo = -1;
    p->nome = nome;
}

void pushP(Pilha *p, int valor) {
    if (!estaCheia((Pilha *)p)) {
        p->itens[++p->topo] = valor;
    }
}

int popP(Pilha *p) {
    if (!estaVazia((Pilha *)p)) {
        return p->itens[p->topo--];
    }
    return -1;
}

void moverDisco(Pilha *origem, Pilha *destino) {
    int disco = popP(origem);
    pushP(destino, disco);
    printf("Move disco %d de %c -> %c\n", disco, origem->nome, destino->nome);
}

void torreDeHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar) {
    if (n == 1) {
        moverDisco(origem, destino);
        return;
    }

    torreDeHanoi(n - 1, origem, auxiliar, destino);
    moverDisco(origem, destino);
    torreDeHanoi(n - 1, auxiliar, destino, origem);
}