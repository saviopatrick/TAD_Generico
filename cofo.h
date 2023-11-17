#ifndef COFO_H
#define COFO_H

// Defina a estrutura do TIPO ESCOLHIDO aqui
typedef struct {
    char campo_char[30];
    int campo_int;
    float campo_float;
} TipoEscolhido;

typedef struct Cofo Cofo;

Cofo* criarCofo();
void inserirElemento(Cofo* cofo, TipoEscolhido elemento);
int removerElemento(Cofo* cofo, char campo_char[30], int campo_int, float campo_float);
TipoEscolhido* consultarElemento(Cofo* cofo, char campo_char[30], int campo_int, float campo_float);
void listarElementos(Cofo* cofo);
void destruirCofo(Cofo* cofo);
void esvaziarCofo(Cofo* cofo);

#endif
