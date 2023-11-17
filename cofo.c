#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cofo.h"

// Estrutura do Nó da lista encadeada
typedef struct Node {
    TipoEscolhido elemento;
    struct Node* proximo;
} Node;

// Estrutura do Cofo
struct Cofo {
    Node* inicio;
};

// Função auxiliar para criar um novo nó
Node* criarNode(TipoEscolhido elemento) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode != NULL) {
        novoNode->elemento = elemento;
        novoNode->proximo = NULL;
    }
    return novoNode;
}

Cofo* criarCofo() {
    Cofo* cofo = (Cofo*)malloc(sizeof(Cofo));
    if (cofo != NULL) {
        cofo->inicio = NULL;
    }
    return cofo;
}

void inserirElemento(Cofo* cofo, TipoEscolhido elemento) {
    Node* novoNode = criarNode(elemento);
    if (novoNode != NULL) {
        novoNode->proximo = cofo->inicio;
        cofo->inicio = novoNode;
    }
}

int removerElemento(Cofo* cofo, char campo_char[30], int campo_int, float campo_float) {
    if (cofo->inicio == NULL) {
        return 0; // Cofo vazio, não é possível remover
    }

    Node* atual = cofo->inicio;
    Node* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->elemento.campo_char, campo_char) == 0 &&
            atual->elemento.campo_int == campo_int &&
            atual->elemento.campo_float == campo_float) {
            if (anterior == NULL) {
                cofo->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1; // Elemento removido com sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return 0; // Elemento não encontrado
}

TipoEscolhido* consultarElemento(Cofo* cofo, char campo_char[30], int campo_int, float campo_float) {
    Node* atual = cofo->inicio;

    while (atual != NULL) {
        if (strcmp(atual->elemento.campo_char, campo_char) == 0 &&
            atual->elemento.campo_int == campo_int &&
            atual->elemento.campo_float == campo_float) {
            return &(atual->elemento);
        }
        atual = atual->proximo;
    }

    return NULL; // Elemento não encontrado
}

void listarElementos(Cofo* cofo) {
    Node* atual = cofo->inicio;

    while (atual != NULL) {
        // Imprima ou manipule os elementos como necessário
        printf("Nome: %s, Camisa: %d, Taxa de acerto: %.2f\n",
               atual->elemento.campo_char, atual->elemento.campo_int, atual->elemento.campo_float);
        atual = atual->proximo;
    }
}

void destruirCofo(Cofo* cofo) {
    Node* atual = cofo->inicio;
    while (atual != NULL) {
        Node* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(cofo);
}

void esvaziarCofo(Cofo* cofo) {
    Node* atual = cofo->inicio;
    while (atual != NULL) {
        Node* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    cofo->inicio = NULL;
}
