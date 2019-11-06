#include "../Headers/Memorization.h"
int TopMemorization(int Matriz[][100],int QuantLinhas,int x,int y){
  int MatrizAux[QuantLinhas][100];
  for(int i=0;i<QuantLinhas;i++)
    for(int j=0;j<i+1;j++){
      MatrizAux[i][j] = -1; //Inicializando matriz para chamada de memorization.
    }
  return Memorization(Matriz,QuantLinhas,x,y,MatrizAux);
}

int Memorization(int Matriz[][100],int QuantLinhas,int x,int y,int MatrizAux[][100]){
  if(QuantLinhas-1 == x){
    MatrizAux[x][y] = Matriz[x][y]; //So preencho para poder usar matriz de pesos posteriormente
    return Matriz[x][y];
  }
  else{
    if(MatrizAux[x][y] == -1){
       MatrizAux[x][y] = Matriz[x][y] + Maior(Memorization(Matriz,QuantLinhas,x+1,y+1,MatrizAux),Memorization(Matriz,QuantLinhas,x+1,y,MatrizAux));
    }
    return MatrizAux[x][y];
  }
}


void ExibeMelhorCaminho(int Matriz[][100],int QuantLinhas){
  int MatrizAux[QuantLinhas][100];
  for(int i=0;i<QuantLinhas;i++)
    for(int j=0;j<i+1;j++){
      MatrizAux[i][j] = -1; //Inicializando matriz para chamada de memorization.
    }
  Memorization(Matriz,QuantLinhas,0,0,MatrizAux); //Inicializando matriz de custos.
  /*for(int x=0;x<QuantLinhas;x++){
    printf("\n");
    for(int y=0;y<x+1;y++){
      printf("%d ",MatrizAux[x][y]);
    }
  }*/
  printf("\n\tCaminho partindo do topo: \n");
  MelhorCaminho(Matriz,QuantLinhas,0,0,MatrizAux);

}


void MelhorCaminho(int Matriz[][100],int QuantLinhas,int x,int y,int MatrizAux[][100]){
  printf("(%d)",Matriz[x][y]);
  if(x<QuantLinhas-1){
    printf(" -> ");
    if(MatrizAux[x+1][y]>MatrizAux[x+1][y+1]){
      MelhorCaminho(Matriz,QuantLinhas,x+1,y,MatrizAux);
    }
    else{
      MelhorCaminho(Matriz,QuantLinhas,x+1,y+1,MatrizAux);
    }
  }
  return;
}
