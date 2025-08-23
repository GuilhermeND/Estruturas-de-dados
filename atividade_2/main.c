#include <stdio.h>
#include "playlists.h"  

int main(){

    _playlist playlist;
    criarPlaylsit(&playlist);

    int choice;
    int option;
    int veri = 1;
    int position = 0;
    
    printf("===MINHA PLAYLIST===\n");
    printf("1. Adicionar musica\n");
    printf("2. Remover musica\n");
    printf("3. Buscar musica\n");
    printf("4. Mostrar playlist\n");
    printf("5. Sair\n");

    while(veri){
        printf("\nEscolha uma opcao: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Digite o id da musica: ");
                scanf("%d", &option);
                position = adicionarMusica(&playlist, option);
                if(!position) printf("Passou do limite de 20 musicas!");
                break;
            case 2:
                printf("Digite a posicao da musica: ");
                scanf("%d", &option);
                position = removerMusica(&playlist, option);
                if(!position) printf("Este nao e um endereco valido!\n");
                break;
            case 3: 
                printf("Digite o id da musica para buscar: ");
                scanf("%d", &option);
                position = buscarMusica(&playlist, option);
                printf("Musica %d esta na posicao: %d ", option, position);
                break;
            case 4:
                printf( "===MINHA PLAYLIST===\n");
                mostrarPlaylist(&playlist);
                break;
            case 5:
                veri = 0;
                break;
            default:
                printf("Valor invalido digite novamente!\n");
        }
    }
}