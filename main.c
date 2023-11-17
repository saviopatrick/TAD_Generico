#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cofo.h"

int main() {
    Cofo* cofo = NULL;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Crie uma Time\n");
        printf("2 - Insira tres elementos no time\n");
        printf("3 - Liste os elementos do time\n");
        printf("4 - Consulte um dos elementos do time\n");
        printf("5 - Remova o segundo elemento inserido no time\n");
        printf("6 - Liste os elementos do time\n");
        printf("7 - Esvazie o time\n");
        printf("8 - Destrua o time\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (cofo == NULL) {
                    cofo = criarCofo();
                    printf("Time de debate criado.\n");
                } else {
                    printf("Time ja existe.\n");
                }
                break;

            case 2:
                if (cofo != NULL) {
                    TipoEscolhido elemento1, elemento2, elemento3;
                    strcpy(elemento1.campo_char, "Jogador1");
                    elemento1.campo_int = 10;
                    elemento1.campo_float = 8.54;

                    strcpy(elemento2.campo_char, "Jogador2");
                    elemento2.campo_int = 9;
                    elemento2.campo_float = 7.35;

                    strcpy(elemento3.campo_char, "Jogador3");
                    elemento3.campo_int = 20;
                    elemento3.campo_float = 9.40;

                    inserirElemento(cofo, elemento1);
                    inserirElemento(cofo, elemento2);
                    inserirElemento(cofo, elemento3);

                    printf("Tres jogadore inseridos com sucesso.\n");
                } else {
                    printf("O time nao foi criado ainda..\n");
                }
                break;

            case 3:
                if (cofo != NULL) {
                    printf("Elementos na colecao:\n");
                    listarElementos(cofo);
                } else {
                    printf("O time nao foi criado ainda.\n");
                }
                break;

            case 4:
                if (cofo != NULL) {
                    char campo_char[30];
                    int campo_int;
                    float campo_float;

                    printf("Informe o nome: ");
                    scanf("%s", campo_char);
                    printf("Informe a camisa: ");
                    scanf("%d", &campo_int);
                    printf("Informe a taxa de acerto: ");
                    scanf("%f", &campo_float);

                    TipoEscolhido* consulta = consultarElemento(cofo, campo_char, campo_int, campo_float);
                    if (consulta != NULL) {
                        printf("\nJogador consultado: Nome: %s,Camisa: %d, Taxa de Acerto: %.2f\n",
                               consulta->campo_char, consulta->campo_int, consulta->campo_float);
                    } else {
                        printf("\nJogador nao encontrado.\n");
                    }
                } else {
                    printf("O time nao foi criado ainda.\n");
                }
                break;

            case 5:
                if (cofo != NULL) {
                    int removido = removerElemento(cofo, "Jogador2", 9, 7.35);
                    if (removido) {
                        printf("Jogador 2 removido com sucesso.\n");
                    } else {
                        printf("Jogador nao encontrado ou o time esta vazio.\n");
                    }
                } else {
                    printf("O time nao foi criado ainda.\n");
                }
                break;

            case 6:
                if (cofo != NULL) {
                    printf("Jogador no time:\n");
                    listarElementos(cofo);
                } else {
                    printf("O time nao foi criado ainda.\n");
                }
                break;

            case 7:
                if (cofo != NULL) {
                    esvaziarCofo(cofo);
                    printf("Time esvaziado.\n");
                } else {
                    printf("O time nao foi criado ainda.\n");
                }
                break;

            case 8:
                if (cofo != NULL) {
                    destruirCofo(cofo);
                    cofo = NULL;
                    printf("Time destruido.\n");
                } else {
                    printf("O time nao foi criado ainda.\n");
                }
                break;

            case 0:
                if (cofo != NULL) {
                    destruirCofo(cofo);
                }
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
