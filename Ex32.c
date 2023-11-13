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
    aux->fim = fim;
    return aux;
}

Segmento* inverteSegmento(Segmento* s){
    Segmento * aux = (Segmento *)malloc(sizeof(Segmento));
    aux->fim = s->ini;
    aux->ini = s->fim;
    return aux;
}

void printSegmento(Segmento * s){
    printf("[");
    printCoordenada(s->ini);
    printCoordenada(s->fim);
    printf("]");
}

double comprimentoSegmento(Segmento * s) {
    return euclideanDist(s->ini,s->fim);
}

void inverterSegmento(Segmento *s) {
    Coordenada *temp = s->ini;  
    s->ini = s->fim;            
    s->fim = temp;              
}

void translaCoord (Coordenada *c, int x, int y) {
    c->x = c->x + x;
    c->y = c->y + y;
}

void translaSeg (Segmento *s, int x, int y) {
    Coordenada *temp = s->ini;
    translaCoord(temp, x, y);
    s->ini = temp;
    
    temp = s->fim;
    translaCoord(temp, x, y);
    s->fim = temp;
}

typedef struct Triangulo{
    Coordenada* p1;
    Coordenada* p2;
    Coordenada* p3;
}Triangulo;

Triangulo *newTriangulo (Coordenada* p1, Coordenada* p2, Coordenada* p3) {
    Triangulo* temp = (Triangulo*)malloc(sizeof(Triangulo));
    temp->p1 = p1;
    temp->p2 = p2;
    temp->p3 = p3;
}

void printTriangulo (Triangulo* t) {
    printf("[");
    printCoordenada(t->p1);
    printCoordenada(t->p2);
    printCoordenada(t->p3);
    printf("]\n");
}

double perimetroTriangulo (Triangulo* t) {
    double perimetro = 0.0;
    perimetro = euclideanDist(t->p1, t->p2) + euclideanDist(t->p2, t->p3);
    return perimetro;
}

//Poligono
typedef struct Poligono{
    Coordenada * v[100];
    int top;
}Poligono;

//Construtor
Poligono * newPoligono(){
    Poligono * pol = (Poligono *)
                malloc(sizeof(Poligono));
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
double perimetro(Poligono *pol){
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

int main() {
    Coordenada *p1 = newCoordenada(5,5);
    Coordenada *p2 = newCoordenada(10,10);
    Coordenada *p3 = newCoordenada(20,20);
    
    Triangulo *t1 = newTriangulo(p1, p2, p3);
    printTriangulo(t1);
    printf("Perimetro: %.2f\n", perimetroTriangulo(t1));

    return 0;
}
