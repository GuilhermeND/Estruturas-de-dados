#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
    ListaCircular* lista = criarListaCircular();
    int opcao = 0, valor, pos, resultado;
    NoCircular* encontrado;

    while (opcao != 11) {
        printf("\n=== MENU LISTA CIRCULAR ===\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Inserir em posicao\n");
        printf("4. Remover do inicio\n");
        printf("5. Remover do fim\n");
        printf("6. Remover em posicao\n");
        printf("7. Remover por valor\n");
        printf("8. Buscar valor (retorna endereco)\n");
        printf("9. Buscar valor (retorna posicao)\n");
        printf("10. Exibir lista\n");
        printf("11. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirInicioCircular(lista, valor);
                printf("Valor %d inserido no inicio.\n", valor);
                break;

            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirFimCircular(lista, valor);
                printf("Valor %d inserido no fim.\n", valor);
                break;

            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posicao (0 a %d): ", lista->tamanho);
                scanf("%d", &pos);
                inserirPosicaoCircular(lista, valor, pos);
                printf("Valor %d inserido na posicao %d.\n", valor, pos);
                break;

            case 4:
                resultado = removerInicioCircular(lista);
                if (resultado != -1)
                    printf("Valor %d removido do inicio.\n", resultado);
                else
                    printf("Erro: lista vazia.\n");
                break;

            case 5:
                resultado = removerFimCircular(lista);
                if (resultado != -1)
                    printf("Valor %d removido do fim.\n", resultado);
                else
                    printf("Erro: lista vazia.\n");
                break;

            case 6:
                printf("Digite a posicao (0 a %d): ", lista->tamanho - 1);
                scanf("%d", &pos);
                resultado = removerPosicaoCircular(lista, pos);
                if (resultado != -1)
                    printf("Valor %d removido da posicao %d.\n", resultado, pos);
                else
                    printf("Posicao invalida ou lista vazia.\n");
                break;

            case 7:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                resultado = removerValorCircular(lista, valor);
                if (resultado != -1)
                    printf("Valor %d removido.\n", resultado);
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 8:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                encontrado = buscarCircular(lista, valor);
                if (encontrado)
                    printf("Valor %d encontrado no endereco %p.\n", valor, (void*)encontrado);
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 9:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                pos = buscarPosicaoCircular(lista, valor);
                if (pos >= 0)
                    printf("Valor %d encontrado na posicao %d.\n", valor, pos);
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 10:
                exibirCircular(lista);
                break;

            case 11:
                destruirListaCircular(lista);
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}