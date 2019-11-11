#include "../Headers/Memoization.h"
int TopMemoization(int Matriz[][100],int QuantLinhas,int x,int y){
  int MatrizAux[QuantLinhas][100];
  for(int i=0;i<QuantLinhas;i++)
    for(int j=0;j<i+1;j++){
      MatrizAux[i][j] = -1; //Inicializando matriz para chamada de Memoization.
    }
  return Memoization(Matriz,QuantLinhas,x,y,MatrizAux);
}

int Memoization(int Matriz[][100],int QuantLinhas,int x,int y,int MatrizAux[][100]){
  if(QuantLinhas-1 == x){
    MatrizAux[x][y] = Matriz[x][y]; //So preencho para poder usar matriz de pesos posteriormente
    return Matriz[x][y];
  }
  else{
    if(MatrizAux[x][y] == -1){
       MatrizAux[x][y] = Matriz[x][y] + Maior(Memoization(Matriz,QuantLinhas,x+1,y+1,MatrizAux),Memoization(Matriz,QuantLinhas,x+1,y,MatrizAux));
    }
    return MatrizAux[x][y];
  }
}


void CaminhoMemoization(int Matriz[][100],int QuantLinhas){
  int MatrizAux[QuantLinhas][100];
  for(int i=0;i<QuantLinhas;i++)
    for(int j=0;j<i+1;j++){
      MatrizAux[i][j] = -1; //Inicializando matriz para chamada de Memoization.
    }
  Memoization(Matriz,QuantLinhas,0,0,MatrizAux); //Inicializando matriz de custos.
  /*for(int x=0;x<QuantLinhas;x++){
    printf("\n");
    for(int y=0;y<x+1;y++){
      printf("%d ",MatrizAux[x][y]);
    }
  }*/
  printf("\n\tRota Programacao Dinamica: \n");
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
