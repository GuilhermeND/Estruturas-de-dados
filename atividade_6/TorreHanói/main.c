#include "stack.h"
#include<stdio.h>

int main() {
    Pilha origem, destino, auxiliar;
    inicializaPilha(&origem, 'A');
    inicializaPilha(&destino, 'C');
    inicializaPilha(&auxiliar, 'B');

    int n;
    printf("Digite o numero de discos: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        pushP(&origem, i);
    }

    printf("\n--- Movimentos ---\n");
    torreDeHanoi(n, &origem, &destino, &auxiliar);

    return 0;
}