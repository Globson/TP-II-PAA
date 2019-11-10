#ifndef MEMOIZATION_H
#define MEMOIZATION_H
#include "Funcoes.h"
int TopMemoization(int Matriz[][100],int QuantLinhas,int x,int y);
int Memoization(int Matriz[][100],int QuantLinhas,int x,int y,int MatrizAux[][100]);
void CaminhoMemoization(int Matriz[][100],int QuantLinhas);

#endif
