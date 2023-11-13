#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int *v;
    int max,top;
}Pilha;

Pilha * newPilha(int max){
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));
    p->v = (int *)malloc(sizeof(int)*max);
    p->max = max;
    p->top = max-1;
    return p;
}

//empilha
void push(Pilha *p,int x){
    //verifica se a pilha esta cheia
    if(p->top<0){
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    p->v[p->top--]=x;
}

//desempilha
int pop(Pilha *p){
    //verifica se a pilha esta vazia
    if(p->top==p->max){
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    p->top++;
    return p->v[p->top];
}

int estaVazia(Pilha *p){
    return p->top==0;
}

//numero de elementos na pilha
int size(Pilha *p){
    return p->max-p->top;
}

void printPilha(Pilha *p){
    printf("(");
    for(int i = p->max-1; i>=p->top;i--){
        printf("%d",p->v[i]);
        if(i>0){
            printf("<-");
        }
    }
    printf(")");
    printf("\n");
}

int main(){
   Pilha* p = newPilha(10);
   push(p, 1);
   push(p, 2);
   push(p, 3);
   push(p, 4);
   push(p, 5);
   push(p, 6);
   push(p, 7);
   push(p, 8);
   push(p, 9);
   push(p, 10);
   printPilha(p);
   
   printf("Elemento removido: %d, no índice %d\n", pop(p), p->max-p->top-1);
   printf("Elemento removido: %d, no índice %d\n", pop(p), p->max-p->top-1);
   printf("Elemento removido: %d, no índice %d\n", pop(p), p->max-p->top-1);  
   printf("Elemento removido: %d, no índice %d\n", pop(p), p->max-p->top-1);   
   
   return 0;
}