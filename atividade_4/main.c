#include <stdio.h>
#include <stdlib.h>
#include "lista-dupla.h"

int main() {
    ListaDupla* lista = criarListaDupla();
    int opcao = 0, valor, pos, resultado;
    No* encontrado;

    while (opcao != 9) {
        printf("\n=== MENU LISTA DUPLA ===\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Inserir em posicao\n");
        printf("4. Remover valor\n");
        printf("5. Buscar valor\n");
        printf("6. Buscar posicao\n");
        printf("7. Exibir da cabeca para cauda\n");
        printf("8. Exibir da cauda para cabeca\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirInicio(lista, valor);
                printf("Valor %d inserido no inicio.\n", valor);
                break;

            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirFim(lista, valor);
                printf("Valor %d inserido no fim.\n", valor);
                break;

            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posicao (0 a %d): ", lista->tamanho);
                scanf("%d", &pos);
                inserirPosicao(lista, valor, pos);
                printf("Valor %d inserido na posicao %d.\n", valor, pos);
                break;

            case 4:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                resultado = removerValor(lista, valor);
                if (resultado)
                    printf("Valor %d removido.\n", valor);
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 5:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                encontrado = buscar(lista, valor);
                if (encontrado)
                    printf("Valor %d encontrado no endereco %p.\n", valor, (void*)encontrado);
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 6:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                pos = buscarPosicao(lista, valor);
                if (pos >= 0)
                    printf("Valor %d encontrado na posicao %d.\n", valor, pos);
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 7:
                printf("Lista (cabeca -> cauda): ");
                exibirFrente(lista);
                break;

            case 8:
                printf("Lista (cauda -> cabeca): ");
                exibirTras(lista);
                break;

            case 9:
                destruirListaDupla(lista);
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}
