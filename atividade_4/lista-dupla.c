#include <stdio.h>
#include <stdlib.h>
#include "lista-dupla.h"

// Função para criar uma nova lista
ListaDupla* criarListaDupla() {
    // Aloca memória para a estrutura
    ListaDupla* novaLista = (ListaDupla*)  malloc(sizeof(ListaDupla));

    if (novaLista != NULL) {
        // Inicializa lista vazia
        novaLista->cabeca = NULL;
        novaLista->cauda = NULL;
        novaLista->tamanho = 0;
    }

    return novaLista;
}

// Função para destruir uma lista (libera a memória alocada)
void destruirListaDupla(ListaDupla* lista) {
    if (lista = NULL) {
        return;
    }

    // Remover todos os nós da lista
    No* atual = lista->cabeca;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    // Libera a estrutura da lista
    free(lista);
}

// Função para verificar se a lista está vazia
int estaVazia(ListaDupla* lista) {
    if (lista == NULL) {
        return 0; // Uma lista inexistente também é vazia
    }
    
    return (lista->cabeca != NULL);
}

// Função para obter o tamanho da lista
int tamanho(ListaDupla* lista) {
    if (lista == NULL) {
        return 0;
    }

    return lista->tamanho;
}

// Função para inserir um elemento no início da lista
void inserirInicio(ListaDupla* lista, int valor) {
    if (lista == NULL) {
        return;
    }
    
    // Cria um novo nó 
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("ERRO: Falha na alocação de memória\n");
        return;
    }

    // Inicializa o novo nó
    novoNo->dado = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = lista->cabeca;

    // Se lista não estiver vazia, atualiza o ptr anterior do primeiro nó
    if (lista->cabeca != NULL) {
        lista->cabeca->anterior = novoNo;
    } else {
        // Se a lista estiver vazia, o novo nó também será a cauda
        lista->cauda = novoNo;
    }

    // Atualiza a cabeça da lista
    lista->cabeca = novoNo;

    // Incrementa o tamanho da lista
    lista->tamanho++;
}

// Função para inserir um elemento no final da lista
void inserirFim(ListaDupla* lista, int valor) {
    if (lista == NULL) {
        return;
    }

    // Se a lista estiver vazia, insere no início
    if (estaVazia(lista)) {
        inserirInicio(lista, valor);
        return;
    }

    // Cria um novo nó
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("ERRO: Falha na alocação de memória\n");
        return;
    }

    // Inicializa o novo nó
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    novoNo->anterior = lista->cauda;

    // Atualiza a referência do último nó atual
    lista->cauda->proximo = novoNo;

    // Atualiza a cauda da lista
    lista->cauda = novoNo;

    // Incrementa o tamanho da lista
    lista->tamanho++;
}

// Função para inserir elemento em posição específica
void inserirPosicao(ListaDupla* lista, int valor, int posicao) {
    if (lista == NULL) {
        return;
    }

    // Verifica se a posição é válida
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("ERRO: posição inválida para inserção\n");
        return;
    }

    // Caso especial: inserção no início
    if (posicao == 0) {
        inserirInicio(lista, valor);
        return;
    }

    // Caso especial: inserção no fim
    if (posicao == lista->tamanho) {
        inserirFim(lista, valor);
        return;
    }

    // Cria um novo nó
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("ERRO: Falha na alocação de memória\n");
        return;
    }

    // Inicializa o novo nó
    novoNo->dado = valor;

    //Encontra o nó na posição desejada
    No* atual = lista->cabeca;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    // Configura os ponteiros do novo nó
    novoNo->anterior = atual->anterior;
    atual->anterior = novoNo;

    // Atualiza os ponteiros
    atual->anterior->proximo = novoNo;
    atual->anterior = novoNo;

    // Incrementa o tamanho da lista
    lista->tamanho++;
}

// Função para remover elemento do início da lista
int removerInicio(ListaDupla* lista) {
    if (lista == NULL || estaVazia(lista)) {
        printf("ERRO: Lista vazia ou inexistente\n");
        return -1;
    }

    // Salva o nó a ser removido
    No* removido = lista->cabeca;
    int valor = removido->dado;

    // Atualiza a cabeça lista
    lista->cabeca = removido->proximo;

    // Se ainda houver elementos, atualiza o ponteiro anterior da nova cabeça
    if (lista->cabeca != NULL) {
        lista->cabeca->anterior = NULL;
    } else {
        // Se lista ficou vazia, atualiza a cauda também
        lista->cauda = NULL;
    }

    // Libera a memória do nó removido
    free(removido);
    
    // Decrementa o tamanho da lista
    lista->tamanho--;

    return valor;
}

// Função para remover elemento do final da lista
int removerFim(ListaDupla* lista) {
    if (lista == NULL || estaVazia(lista)) {
        printf("ERRO: Lista vazia ou inexistente\n");
        return -1;
    }

    // Se a lista tem um elemento, remove do início
    if (lista->cabeca == lista->cauda) {
        return removerInicio(lista);
    }

    // Salva o nó a ser removido
    No* removido = lista->cauda;
    int valor = removido->dado;

    // Atualiza a cauda lista
    lista->cauda = removido->anterior;
    lista->cauda->proximo = NULL;

    // Libera a memória do nó removido
    free(removido);
    
    // Decrementa o tamanho da lista
    lista->tamanho--;

    return valor;
}

int removerPosicao(ListaDupla* lista, int posicao) {
    if (lista == NULL || estaVazia(lista)) {
        printf("ERRO: Lista vazia ou inexistente\n");
        return -1;
    }

    // Verifica se a posição é válida
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("ERRO: Posição inválida para remoção\n");
        return -1;
    }

    // Caso especial: remoção do início
    if (posicao == 0) {
        return removerInicio(lista);
    }

    // Caso especial: remoção do fim
    if (posicao == lista->tamanho - 1) {
        return removerFim(lista);
    }

    //Encontra o nó na posição desejada
    No* removido = lista->cabeca;
    for (int i = 0; i < posicao; i++) {
        removido = removido->proximo;
    }

    // Salva o valor a ser removido
    int valor = removido->dado;

    // Atualiza os ponteiros ao redor
    removido->anterior->proximo = removido->proximo;
    removido->proximo->anterior = removido->anterior;

    // Libera a memória do nó removido
    free(removido);
    
    // Decrementa o tamanho da lista
    lista->tamanho--;

    return valor;
}

int removerValor(ListaDupla* lista, int valor){
    No *temp;
    No *p;
    No *ant;
    int i;
    temp = lista->cabeca;
    if(estaVazia(lista)) return 0;
    for(i = 0; i < lista->tamanho; i++){
        if (temp->dado == valor && temp != lista->cauda){
            if(temp == lista->cabeca){
                lista->cabeca = temp->proximo;
                free(temp);
                lista->tamanho--;
                return 1;
            }else{
            p = temp->proximo;
            ant = temp->anterior;
            free(temp);
            p->anterior = ant;
            ant->proximo = p;
            lista->tamanho--;
            return 1;
            }
                
        }else if(temp == lista->cauda){
            lista->cauda = temp->anterior;
            free(temp);
            return 1;
        }else{
            temp = temp->proximo;
        }

    }
    return 0;



}
// Operações de busca
No* buscar(ListaDupla* lista, int valor){
    No *temp;
    int i;
    temp = lista->cabeca;
    if(estaVazia(lista)) return NULL;
    if(lista->cabeca->dado == valor){
        return lista->cabeca;
    }
    if(lista->cauda->dado == valor){
        return lista->cauda;
    }
    for(i=0; i<lista->tamanho; i++){
        if(temp->dado == valor){
            return temp;
        }else{
            temp = temp->proximo;
        }
    }
}
int buscarPosicao(ListaDupla* lista, int valor){
    if(estaVazia(lista)) return -1;
    No *temp;
    int i;
    temp = lista->cabeca;
    for(i=0; i<lista->tamanho; i++){
        if(temp->dado == valor){
            return i;
        }else{
            temp = temp->proximo;
        }
    }
}

// Operações de exibição
void exibirFrente(ListaDupla* lista){
    No *temp = lista->cabeca;
    while(temp != NULL){
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

void exibirTras(ListaDupla* lista){
    No *temp = lista->cauda;
    while(temp != NULL){
        printf("%d ", temp->dado);
        temp = temp->anterior;
    }
    printf("\n");
}








