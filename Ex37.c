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

void printPilhaReverse() {
    for (int i=top-1; i>=0; i--) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main () {
    printf("Complete a pilha! Negativo para sair\n");
    int digitado;
    scanf("%d", &digitado);
    
    while(digitado > 0) {
        push(digitado);
        printf("Digite o próximo número!\n");
        scanf("%d", &digitado);
    }
    
    if(digitado < 0) {
        printf("Negativo digitado. Observe a pilha atual: \n");
        printPilha();
        printf("Em reverso: \n");
        printPilhaReverse();
    }
    
}