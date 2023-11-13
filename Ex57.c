// Trabalho por Heitor Pavani Nolla, Victor Ferreira da Silva e Nataly Stychnicki
// RAs 173233, 177950 e 173722, respectivamente
// Tivemos uma certa dificuldade com o trabalho. Tivemos ajuda dos PADs, tiramos dúvidas com o ChatGPT
// e aproveitamos muito de conteúdos online, em principal produzidos por William Fiset, disponíveis no Youtube.
// Ao final, creio que chegamos em uma conclusão aceitável ao problema.

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORITIES 100  // Número máximo de prioridades

// FIFO. Deve ter duas ops principais, enqueue e dequeue
// Inserir elementos pelo fim e tirar pelo começo, como uma fila real...
typedef struct {
    int *elementos;  
    int front;   
    int rear;   
    int tamMaximo;
} Fila;

typedef struct {
    Fila *filas[MAX_PRIORITIES];  // Vetor de filas de prioridades
    int maxPrioridade;              
} FilaPrioridade;

Fila *initializeQueue(int tamMaximo) {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->elementos = (int *)malloc(sizeof(int) * tamMaximo);
    fila->front = -1;
    fila->rear = -1;
    fila->tamMaximo = tamMaximo;
    return fila;
}

int isQueueEmpty(Fila *fila) {
    return fila->front == -1;
}

// Função para enfileirar um elemento
// enqueue == adding == offering, 
void enqueue(Fila *fila, int elemento) {
    if (fila->rear == fila->tamMaximo - 1) {
        printf("A fila está cheia.\n");
        return;
    }
    if (fila->front == -1)
        fila->front = 0;
    fila->rear++;
    fila->elementos[fila->rear] = elemento;
}

// Função para desenfileirar um elemento
// dequeue == polling/pulling == removing
int dequeue(Fila *fila) {
    if (isQueueEmpty(fila)) {
        printf("A fila está vazia.\n");
        return -1;
    }
    int elemento = fila->elementos[fila->front];
    if (fila->front == fila->rear)
        fila->front = fila->rear = -1;
    else
        fila->front++;
    return elemento;
}

void printQueue(FilaPrioridade *filaPrioridade, int prioridade) {
    if (prioridade < 0 || prioridade >= filaPrioridade->maxPrioridade) {
        printf("Prioridade inválida.\n");
        return;
    }

    printf("Fila de prioridade %d: ", prioridade);
    Fila *fila = filaPrioridade->filas[prioridade];
    for (int i = fila->front; i <= fila->rear; i++)
        printf("%d ", fila->elementos[i]);
    printf("\n");
}

int main() {
    int maxPrioridade;
    printf("Digite o número máximo de prioridades: ");
    scanf("%d", &maxPrioridade);
    
    if (maxPrioridade <= 0 || maxPrioridade > MAX_PRIORITIES) {
        printf("Número de prioridades inválido.\n");
        return 1;
    }
    
    int tamMaximo[maxPrioridade];
    for (int i = 0; i < maxPrioridade; i++) {
        printf("Digite o tamanho máximo para a fila de prioridade %d: ", i);
        scanf("%d", &tamMaximo[i]);
    }

// Com a implementação anterior, a fila era inicializada com o valor no #DEFINE.
// Encontrei outra implementação, que definia o tamanho da fila como o valor maxPrioridade definido pelo usuário
// Não estava satisfeito com ambas, por isso, tentei adaptar o programa, para que peça ao usuário que defina
// a mãos o tamanho de cada fila. Depois de quebrar a cabeça um pouco, creio que roda OK.

    FilaPrioridade *filaPrioridade = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));
    filaPrioridade->maxPrioridade = maxPrioridade;
    for (int i = 0; i < maxPrioridade; i++)
        filaPrioridade->filas[i] = initializeQueue(tamMaximo[i]);

    int escolha;
    int elemento, prioridade;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir filas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o elemento e a prioridade: ");
                scanf("%d %d", &elemento, &prioridade);
                if (prioridade >= 0 && prioridade < maxPrioridade)
                    enqueue(filaPrioridade->filas[prioridade], elemento);
                else
                    printf("Prioridade inválida.\n");
                break;

            case 2:
                for (int i = 0; i < maxPrioridade; i++) {
                    if (!isQueueEmpty(filaPrioridade->filas[i])) {
                        printf("Elemento removido: %d (prioridade %d)\n", dequeue(filaPrioridade->filas[i]), i);
                        break;
                    }
                }
                break;

            case 3:
                for (int i = 0; i < maxPrioridade; i++)
                    printQueue(filaPrioridade, i);
                break;

            case 4:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 4);

    for (int i = 0; i < maxPrioridade; i++)
        free(filaPrioridade->filas[i]->elementos);

    free(filaPrioridade);

    return 0;
}
