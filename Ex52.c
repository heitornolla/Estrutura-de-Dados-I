#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* newNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->prox = NULL;
    return no;
}

typedef struct Pilha {
    No* top;
} Pilha;

Pilha* newPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->top = NULL;
    return p;
}

int isEmpty(Pilha* p) {
    return p->top==NULL;
}

void push(Pilha* p, int x) {
    No* aux = newNo(x);
    aux->prox = p->top;
    p->top = aux;
}

int pop(Pilha* p) {
    int valor;
    int vazio = isEmpty(p);
    if (vazio==1) {
        printf("Pilha vazia\n");
        exit(1);
    }
    
    valor = p->top->valor;
    No* aux = p->top;
    p->top = p->top->prox;
    free(aux);
    return valor;
}

int size(Pilha* p) {
    int tamanho = 0;
    int vazio = isEmpty(p);
    No* aux = p->top;
    
    if (vazio == 1) {
        printf("Pilha sem elementos\n");
        return tamanho;
    }
    
    for (No* aux = p->top; aux!=NULL ; aux = aux->prox) {
        tamanho++;
    }
    return tamanho;
}

void printPilha(Pilha* p) {
    for(No* aux = p->top; aux!=NULL; aux = aux->prox) {
        printf("%d ", aux->valor);
    }
}

int main() {
    Pilha* p = newPilha();
    push(p, 1);
    push(p, 3);
    
    printPilha(p);
    
    printf("%d\n", pop(p));
    return 0;
}



