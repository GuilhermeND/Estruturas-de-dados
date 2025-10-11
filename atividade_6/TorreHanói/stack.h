#include <stdbool.h>
#define MAX 100


typedef struct {
    int itens[MAX];
    int topo;
    char nome;
} Pilha;

bool estaVazia(Pilha *p);

bool estaCheia(Pilha *p);

void inicializaPilha(Pilha *p, char nome);

void pushP(Pilha *p, int valor);

int popP(Pilha *p);

void moverDisco(Pilha *origem, Pilha *destino);

void torreDeHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar);
