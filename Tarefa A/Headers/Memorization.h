#ifndef MEMORIZATION_H
#define MEMORIZATION_H
#include "Funcoes.h"
int TopMemorization(int Matriz[][100],int QuantLinhas,int x,int y);
int Memorization(int Matriz[][100],int QuantLinhas,int x,int y,int MatrizAux[][100]);
void ExibeMelhorCaminho(int Matriz[][100],int QuantLinhas);
void MelhorCaminho(int Matriz[][100],int QuantLinhas,int x,int y,int MatrizAux[][100]);
#endif
