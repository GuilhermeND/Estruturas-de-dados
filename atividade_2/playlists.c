#include "playlists.h" 
#include <stdio.h> 

void criarPlaylsit(_playlist *p){
    p->total = 0;
}

int estaVazia(_playlist *p){
    return(p->total == 0);
}

int estaCheia(_playlist *p){
    return(p->total == MAX);
}

int adicionarMusica(_playlist *p, int idMusica){

    if(estaCheia(p)) return 0;
    p->musicas[p->total] = idMusica;
    p->total++;
    return 1;
}

int removerMusica(_playlist *p, int posicao) {
    if (posicao < 0 || posicao >= p->total) {
        return 0;
    }
    for (int i = posicao; i < p->total - 1; i++) {
        p->musicas[i] = p->musicas[i + 1];
    }
    p->musicas[p->total - 1] = 0;
    p->total--;

    return 1;
}

int buscarMusica(_playlist *p, int idMusica){

    int i;
    for(i = 0; i < p->total; i++){
        if(p->musicas[i] == idMusica) return i;
    }
    return -1;
}

void mostrarPlaylist(_playlist *p){
    int i;
    printf("A playlist e composta de: \n");
    for(i=0; i < p->total; i++){
        printf("%d. %d ", i, p->musicas[i]);
    }
}