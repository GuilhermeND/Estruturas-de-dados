#include <stdio.h>

#define MAX 20

typedef struct playlists
{
    int musicas[MAX];
    int total;

}_playlist;

void criarPlaylsit(_playlist *p);

int estaVazia(_playlist *p);

int estaCheia(_playlist *p);

int adicionarMusica(_playlist *p, int idMusica);

int removerMusica(_playlist *p, int posicao);

int buscarMusica(_playlist *p, int idMusica);

void mostrarPlaylist(_playlist *p);




