#include <stdio.h>
#include "stack.h"


int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (ehPalindromo(palavra))
        printf("'%s' eh um palindromo!\n", palavra);
    else
        printf("'%s' nao eh um palindromo.\n", palavra);

    return 0;
}