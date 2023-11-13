#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Alunos que participaram da atividade:
//Heitor Pavani Nolla 173233
//Nataly Stychnicki 173722
//Victor Ferreira da Silva 177950

typedef struct Aluno {
    long RA;
    float CR;
    char Nome[80];
} Aluno;

Aluno * NewAluno(char *nome, long RA, float CR) {
    Aluno * aux = (Aluno *)malloc(sizeof(Aluno));
    strcpy(aux->Nome, nome);
    aux->RA = RA;
    aux->CR = CR;
    return aux;
}

void printAluno(Aluno *aluno) {
    printf("%s, %ld, %.1f\n", aluno->Nome, aluno->RA, aluno->CR);
}

void trocar(Aluno **a, Aluno **b) {
    Aluno *temp = *a;
    *a = *b;
    *b = temp;
}

void ordenaPorCR(Aluno * alunos[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (alunos[j]->CR > alunos[j+1]->CR) {
                trocar(&alunos[j], &alunos[j+1]);
            }
        }
    }
}

void ordenaPorRA(Aluno * alunos[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (alunos[j]->RA > alunos[j+1]->RA) {
                trocar(&alunos[j], &alunos[j+1]);
            }
        }
    }
}

void ordenaPorNome(Aluno * alunos[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(alunos[j]->Nome, alunos[j+1]->Nome) > 0) {
                trocar(&alunos[j], &alunos[j+1]);
            }
        }
    }
}

int main() {
    Aluno * alunos[5];
    
    alunos[0] = NewAluno("heitor", 173233, 811.5);
    alunos[1] = NewAluno("nataly", 173722, 800.0);
    alunos[2] = NewAluno("rian", 260664, 743.4);
    alunos[3] = NewAluno("pedro", 173779, 743.5);
    alunos[4] = NewAluno("victor", 177950, 780.7);
    
    printf("\nBem vindo! O que deseja fazer hoje?\n");
    printf("1 - Ordenar alunos por nome!\n");
    printf("2 - Ordenar alunos por RA!\n");
    printf("3 - Ordenar alunos por CR!\n");
    printf("0 - Sair\n");
    
    int escolha;
    scanf("%d", &escolha);
    
    while(escolha != 0) {
        switch(escolha) {
            case 1:
                ordenaPorNome(alunos, 5);
                for(int i = 0; i < 5; i++) {
                    printAluno(alunos[i]);
                }
                printf("\n");
                break;
           case 2:
                ordenaPorRA(alunos, 5);
                for(int i = 0; i < 5; i++) {
                    printAluno(alunos[i]);
                }
                printf("\n");
                break;
            case 3:
                ordenaPorCR(alunos, 5);
                for(int i = 0; i < 5; i++) {
                    printAluno(alunos[i]);
                }
                printf("\n");
                break;
            case 0:
                exit(1);
        }
        scanf("%d", &escolha);
    }
    
    return 0;
}
