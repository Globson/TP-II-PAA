#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Estruturas para contagem de tempo de execucao;
typedef struct {
    clock_t TempoInicial;
    clock_t TempoFinal;
    double TempoTotal;
} Timer;
void IniciarTimer(Timer *timer);
void PararTimer(Timer *timer);
double TempoTotal(Timer timer);

//Funcoes auxiliares para execucao de programa.
int LeituraArquivo(int Matriz[][100]);
int Maior(int a,int b);
int Menu();
void CopiaMatriz(int MatrizOrigem[][100],int MatrizDestino[][100],int QuantLinhas);
void MelhorCaminho(int QuantLinhas,int x,int y,int MatrizAux[][100]);
//Estrutura de dados para contabilizar caminho.

#endif
