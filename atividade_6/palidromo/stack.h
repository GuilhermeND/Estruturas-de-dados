#include <stdbool.h>
#define MAX 100

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p);

bool estaVazia(Pilha *p);

bool estaCheia(Pilha *p);

void push(Pilha *p, char valor);

char pop(Pilha *p);

bool ehPalindromo(char *palavra);