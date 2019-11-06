#include "../Headers/DeTrasPraFrente.h"

int DeTrasPraFrente(int Matriz[][100],int QuantLinhas){
  for(int i=QuantLinhas-2;i>=0;i--){    //QuantLinhas-2 devido a começar do 0;
    for(int j=0;j<i+1;j++){
      Matriz[i][j] += Maior(Matriz[i+1][j],Matriz[i+1][j+1]);
    }
  }
  return Matriz[0][0];
}

int TopDeTrasPraFrente(int Matriz[][100],int QuantLinhas){
  int MatrizAux[QuantLinhas][100];
  CopiaMatriz(Matriz,MatrizAux,QuantLinhas);
  return DeTrasPraFrente(MatrizAux,QuantLinhas);
}

void CaminhoDeTrasPraFrente(int Matriz[][100],int QuantLinhas){
  int MatrizAux[QuantLinhas][100];
  CopiaMatriz(Matriz,MatrizAux,QuantLinhas);
  DeTrasPraFrente(MatrizAux,QuantLinhas);
  printf("\n\tCaminho partindo do topo: \n");
  MelhorCaminho(QuantLinhas,0,0,MatrizAux);
  for(int x=0;x<QuantLinhas;x++){
    printf("\n");
    for(int y=0;y<x+1;y++){
      if(MatrizAux[x][y]==-2){
        printf("(%d) ",Matriz[x][y]);
      }
      else{
        printf("%d ",Matriz[x][y]);
      }
    }
  }
}
