#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    clock_t TempoInicial;
    clock_t TempoFinal;
    double TempoTotal;
} Timer;

void IniciarTimer(Timer *timer);
void PararTimer(Timer *timer);
double TempoTotal(Timer timer);
int LeituraArquivo(int Matriz[][100]);
int Maior(int a,int b);
int Menu();
#endif
