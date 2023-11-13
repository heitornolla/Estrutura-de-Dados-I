#include <stdio.h>

int main() {
    printf("Qual o tamanho do quadrado?\n");
    
    int tamanho;
    int printado = 0;
    
    scanf("%d", &tamanho);
    
    if (tamanho <= 0) return 0;
    
    printf("\n");
    printf("\n");
    
    for (int i=0; i<tamanho; i++) {
        printf("*");
    }
    printf("\n");


    printado++;
    int linha = 1;
    
    
    while (printado < tamanho-1) {
        printf("*");
        
        for (linha=1; linha < tamanho-1; linha++) {
            printf(" ");
        }
        
        printado++;
        
        printf("*\n");
    }
    
    for (int i=0; i<tamanho; i++) {
        printf("*");
    }

    printf("\n");
    
    return 0;
}
