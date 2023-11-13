#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * prox;
}No;

typedef struct Lista {
    struct No * ini;
}Lista;

//construtor
No * newNo(int valor){
    No * no = (No *)malloc(sizeof(No));
    no->valor=valor;
    no->prox = NULL;
    return no;
}

//Construtor
Lista * newLista(){
    Lista * li = (Lista *)malloc(sizeof(Lista));
    li->ini=NULL;
    return li;
}

int estaVazia(Lista *li){
    return li->ini==NULL;
}

//numero de elementos na lista
int size(Lista *li){
    int size=0;
    No * aux = li->ini;
    while(aux!=NULL){
        aux = aux->prox;
        size++;
    }
    return size;
}

void printLista(Lista *li){
    printf("[");
    No * aux = li->ini;
    while(aux!=NULL){
        printf("%d",aux->valor);
        aux = aux->prox;
        if(aux!=NULL){
            printf(",");
        }
    }
    
    printf("]");
    printf("(%d)\n",size(li));
}

void addFim(Lista *li,int valor){
    No * no = newNo(valor);
    if(li->ini==NULL){
        li->ini = no;
    }else{
        No * aux;
        aux = li->ini;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
}

//devolve um apontador para o elemento
//na posicao idx.
No * get(Lista *li, int idx){
    No * aux = li->ini;
    for(int i=0;i<idx;i++){
        if(aux!=NULL)
            aux = aux->prox;
    }
    if(aux==NULL){
        printf("Fora dos limites");
        exit(1);
    }
    return aux;
}

//remove o elemento da posicao idx
int remover(Lista *li, int idx){
    No * no;
    if(idx==0){
        no = li->ini;
        li->ini = li->ini->prox;
    }else{
        No * anterior = get(li,idx-1);
        no = anterior->prox;
        anterior->prox = anterior->prox->prox;
    }
    int valor = no->valor;
    free(no);
    return valor;
}

//substitui o valor da posicao idx pelo
//parametro 'valor'
void set(Lista *li, int valor, int idx){
    No * aux = get(li,idx);
    aux->valor = valor;
}


//insere o valor na posicao idx. Elementos apos
//esta posicao sao deslocados para a direita.
void add(Lista *li, int valor, int idx){
    No * no = newNo(valor);
    if(idx==0){
        no->prox = li->ini;
        li->ini = no;
    }else{
        No * anterior = get(li,idx-1);
        no->prox = anterior->prox;
        anterior->prox = no;
    }
}

void concatLista(Lista* li1, Lista* li2) {
    No* aux = li1->ini;
    
    if(estaVazia(li1)) {
        li1->ini = li2->ini;
    }
    
    while (aux->prox!=NULL) {
        aux = aux->prox;
    }
    
    aux->prox = li2->ini;
}

void removeElementos(Lista* li, int chave) {
    No* aux = li->ini;
    int index = 0;
    
    while(aux!=NULL) {
        if(aux->valor == chave) {
            aux = aux->prox;
            remover(li, index);
            index--;
        } else aux = aux->prox;
        
        index++;
    }
    return;
}

int main(){
    Lista* li = newLista();
    addFim(li, 1);
    addFim(li, 2);
    addFim(li, 3);
    addFim(li, 4);
    addFim(li, 5);
    addFim(li, 2);
    addFim(li, 6);
    addFim(li, 7);
    addFim(li, 2);
    printLista(li);
    
    removeElementos(li, 2);
    printLista(li);
    
    return 0;
}
