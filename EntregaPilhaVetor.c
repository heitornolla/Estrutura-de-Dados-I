#include <stdio.h>

#define MAX 100

int top=0;
int v[MAX];

void push(int x) {
    v[top++] = x;
}

int pop () {
    return v[--top];
}

void printPilha () {
    for(int i=0; i<top; i++) {
        printf("Elemento %d = %d\n", i+1, v[i]);
    }
    
    if (top == 0) printf("Pilha vazia");
}

int main (){
    push (3);
    push (5);
    push (7);
    printPilha();
    printf ("Removido: %d\n",pop());
    printf ("Removido: %d\n",pop());
    printf ("Removido: %d\n",pop());
    printPilha();
}