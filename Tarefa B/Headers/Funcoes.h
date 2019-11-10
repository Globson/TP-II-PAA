#ifndef FUNCOES_H
#define FUNCOES_H
#include "time.h"
//Estruturas para contagem de tempo de execucao;
typedef struct {
    clock_t TempoInicial;
    clock_t TempoFinal;
    double TempoTotal;
} Timer;
void IniciarTimer(Timer *timer);
void PararTimer(Timer *timer);
double TempoTotal(Timer timer);


int ** DistanciaEdicao(char *palavra01, char *palavra02);
int Minimo(int num1, int num2);
void ExibirMatriz(int ** matrizDistancia, int linha, int coluna);
int **InicializaMatriz(int linha, int coluna);
void ReconstruirSolucao(int ** matrizDistancia, int linha, int coluna,char* palavra01, char* palavra02, int contAux);
#endif
