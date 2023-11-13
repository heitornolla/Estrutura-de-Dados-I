#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Estrutura coordenada 
typedef struct Coordenada{
    int x,y;
}Coordenada;

//Construtor da estrutura
Coordenada * newCoordenada(int x, int y){
    Coordenada * aux = (Coordenada *)malloc(sizeof(Coordenada));
    aux->x = x;
    aux->y = y;
    return aux;
}

void printCoordenada(Coordenada *c){
    printf("(%d,%d)",c->x,c->y);
}

//Distancia euclidiana entre duas coordenadas
double euclideanDist(Coordenada * c1, Coordenada * c2){
    double dx = (c1->x)-(c2->x);
    double dy = (c1->y)-(c2->y);
    return sqrt(dx*dx+dy*dy);
}

//Segmento de reta composto de duas
//coordenadas, uma de inicio e outra de fim.
typedef struct Segmento{
    Coordenada *ini, *fim;
}Segmento;

Segmento * newSegmento(Coordenada *ini, Coordenada *fim){
    Segmento * aux = (Segmento *)malloc(sizeof(Segmento));
    aux->ini = ini;
    aux->fim =fim;
    return aux;
}

void printSegmento(Segmento * s){
    printf("[");
    printCoordenada(s->ini);
    printCoordenada(s->fim);
    printf("]");
}

double comprimentoSegmento(Segmento * s){
    return euclideanDist(s->ini,s->fim);
}

//Poligono
typedef struct Poligono{
    Coordenada * v[100];
    int top;
}Poligono;

//Construtor
Poligono * newPoligono(){
    Poligono * pol = (Poligono *)malloc(sizeof(Poligono));
    pol->top=0;
    return pol;
}

//Imprime
void printPoligono(Poligono *pol){
    printf("[");
    for(int i=0;i<pol->top;i++){
        printCoordenada(pol->v[i]);
    }
    printf("]");
}

//Adiciona coordenada ao poligono
void addCoord(Poligono *pol, Coordenada *c){
    pol->v[pol->top++]=c;
}

//soma dos comprimentos dos lados de um poligono
double perimentro(Poligono *pol){
    double per=0;
    //coordenada i com i+1
    for(int i=0;i<pol->top-1;i++){
        per+=euclideanDist(pol->v[i],pol->v[i+1]);
    }
    //fechamento: ultima coordenada com a primeira
    if(pol->top>1){
        per+=euclideanDist(pol->v[0],pol->v[pol->top-1]);
    }
    return per;
}

void translacaoPol (Poligono *pol , int deltax, int deltay) {
    for (int i=0; i<pol->top; i++) {
        pol->v[i]->x += deltax;
        pol->v[i]->y += deltay;
    }
}


//Uso do tipo abstrato de dados Poligono.
int main(void){
    Poligono * pol = newPoligono();
    addCoord(pol,newCoordenada(0,0));
    addCoord(pol,newCoordenada(1,1));
    addCoord(pol,newCoordenada(2,0));
    
    printPoligono(pol);printf("\n");
    
    translacaoPol(pol, 3, 3);
    printPoligono(pol);
    
    
}