#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura No
typedef struct No{
    int valor;
    struct No * prox;
}No;

//construtor
No * newNo(int valor){
    No * no = (No *)malloc(sizeof(No));
    no->valor=valor;
    no->prox = NULL;
    return no;
}

//Estrutura Pilha
typedef struct Pilha{
    No * topo;
}Pilha;

//Construtor
Pilha * newPilha(){
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));
    p->topo=NULL;
    return p;
}

//empilha
void push(Pilha *p,int x){
    No * no = newNo(x);//(a)
    no->prox = p->topo;//(b)
    p->topo = no;//(c)
}

//desempilha
int pop(Pilha *p){
    int valor;
    if(p->topo==NULL){
        printf("Pilha Vazia\n");
        exit(1);
    }
    valor = p->topo->valor;
    No * no = p->topo;
    p->topo = p->topo->prox;
    free(no);
    return valor;
}

int estaVazia(Pilha *p){
    return p->topo==NULL;
}

//numero de elementos na pilha
int size(Pilha *p){
    int size=0;
    No * aux = p->topo;
    while(aux!=NULL){
        aux = aux->prox;
        size++;
    }
    return size;
}

//implementacao alternativa da funcao size
int size2(Pilha *p){
    int size=0;
    for(No * aux = p->topo;aux!=NULL;aux = aux->prox){
        size++;
    }
    return size;
}

//Size recursivo
int sizeRec(No *no){
    if(no==NULL){
        return 0;
    }
    return 1+sizeRec(no->prox);
}

//chamada do size recursivo
int size3(Pilha *p){
    return sizeRec(p->topo);
}


void printPilha(Pilha *p){
    printf("(");
    No * aux = p->topo;
    while(aux!=NULL){
        printf("%d",aux->valor);
        aux = aux->prox;
        if(aux!=NULL){
            printf("<-");
        }
    }
    
    printf(")");
    printf("[%d]\n",size(p));
}

void printPilha1(No* n) {
    if (n == NULL) return;
    
    
    printf("%d ", n->valor);
    
    printPilha1(n->prox);
}

void printPilha2(No* n) {
    if (n == NULL) {
        //printf("Pilha vazia.\n");
        return;
    }
    printPilha2(n->prox);

    printf("%d ", n->valor);
}

void printPilha3(Pilha* p) {
    if (p == NULL || p->topo == NULL) {
        printf("Pilha vazia.\n");
        return;
    }

    // Criar uma pilha auxiliar para inverter a ordem
    Pilha* pilhaAux = newPilha();

    // Copiar os elementos da pilha original para a pilha auxiliar
    No* atual = p->topo;
    while (atual != NULL) {
        push(pilhaAux, atual->valor);
        atual = atual->prox;
    }

    // Agora, desempilhar e imprimir os valores da pilha auxiliar (topo à direita)
    while (!estaVazia(pilhaAux)) {
        printf("%d ", pop(pilhaAux));
    }

    printf("\n");

    // Liberar a memória da pilha auxiliar
    free(pilhaAux);
}



int main(){
    Pilha *p = newPilha();
    push(p, 1);
    push(p, 3);
    push(p, 5);
    push(p, 7);
    push(p, 9);
    
    
    printPilha1(p->topo);
    printf("\n");
    printPilha2(p->topo);
    printf("\n");
    printPilha3(p);
    printf("\n");
}