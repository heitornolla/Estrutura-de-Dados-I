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
    printf("[Tamanho %d]\n",size(p));
}

void push2(Pilha *p, int valor) {
    No *no = newNo(valor);
    no->prox = NULL;  // O novo nó será o último, portanto, o próximo é NULL

    // Se a pilha está vazia, o novo nó será a topo
    if (estaVazia(p)) {
        p->topo = no;
        return;
    }

    // Se não estiver vazia, percorremos a lista para encontrar o último nó
    No *atual = p->topo;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Conectamos o último nó ao novo nó
    atual->prox = no;
}

int pop2(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha Vazia\n");
        exit(6);
    }

    // Se a pilha tem apenas um elemento
    if (p->topo->prox == NULL) {
        int valor = p->topo->valor;
        free(p->topo);
        p->topo = NULL;  // A pilha está vazia agora
        return valor;
    }

    // Se a pilha tem mais de um elemento
    No *penultimo = p->topo;
    while (penultimo->prox->prox != NULL) {
        penultimo = penultimo->prox;
    }

    // Agora, penultimo é o nó antes do último nó
    int valor = penultimo->prox->valor;
    free(penultimo->prox);
    penultimo->prox = NULL;  // Atualiza o próximo para NULL (novo último nó)
    return valor;
}

void push3(Pilha *p, int valor) {
    No *no = newNo(valor);

    // Se a pilha está vazia, o novo nó será a topo
    if (estaVazia(p)) {
        p->topo = no;
        return;
    }

    // Caso contrário, o novo nó será inserido na segunda posição
    No *proximo = p->topo->prox;
    p->topo->prox = no;
    no->prox = proximo;
}

int pop3(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha Vazia\n");
        exit(6);
    }

    // Se a pilha tem apenas um elemento
    if (p->topo->prox == NULL) {
        int valor = p->topo->valor;
        free(p->topo);
        p->topo = NULL;  // A pilha está vazia agora
        return valor;
    }

    // Se a pilha tem mais de um elemento, remove o segundo elemento
    No *segundo = p->topo->prox;
    p->topo->prox = segundo->prox;

    int valor = segundo->valor;
    free(segundo);

    return valor;
}



int main(){
    Pilha* p = newPilha(); 
    push(p, 3);
    push(p, 4);
    push(p, 9);
    printPilha(p);
    
    push2(p, 5);
    printPilha(p);
    
    pop2(p);
    printPilha(p);
    
    push3(p, 5);
    printPilha(p);
    
    pop3(p);
    printPilha(p);
}