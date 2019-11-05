#include "../Headers/DeTrasPraFrente.h"

int DeTrasPraFrente(int Matriz[][100],int QuantLinhas){
  for(int i=QuantLinhas-1;i>=0;i--){
    for(int j=0;j<i+1;j++){
      Matriz[i][j] += Maior(Matriz[i+1][j],Matriz[i+1][j+1]);
    }
  }
  return Matriz[0][0];
}

int TopDeTrasPraFrente(int Matriz[][100],int QuantLinhas){
  int MatrizAux[100][100];
  CopiaMatriz(Matriz,MatrizAux,QuantLinhas);
  return DeTrasPraFrente(MatrizAux,QuantLinhas);
}
