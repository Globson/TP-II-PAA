#include "../Headers/Memorization.h"
int TopMemorization(int Matriz[][100],int QuantLinhas,int x,int y){
  int MatrizAux[QuantLinhas][100];
  for(int i=0;i<QuantLinhas;i++)
    for(int j=0;j<i+1;j++){
      MatrizAux[i][j] = -1;
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


void ExibeMelhorCaminho(int Matriz[][100],int QuantLinhas,int x,int y){
  int MatrizAux[QuantLinhas][100];
  int VetorPosicoes[QuantLinhas];
  for(int i=0;i<QuantLinhas;i++)
    for(int j=0;j<i+1;j++){
      MatrizAux[i][j] = -1;
    }
  Memorization(Matriz,QuantLinhas,x,y,MatrizAux); //MatrizAux é modificada atraves dessa chamada, ela recebe os pesos.
  /*for(int i=0;i<QuantLinhas;i++){
    printf("\n");
    for(int j=0;j<i+1;j++){
      printf("%d ",MatrizAux[i][j]);
    }
  }*/

  int MaiorLinha;

  for(int x=0;x<QuantLinhas;x++){
    MaiorLinha = MatrizAux[x][0]; //Valor inicial da variavel
    VetorPosicoes[x] = 0;
    for(int y=1;y<x+1;y++){
      if(MatrizAux[x][y]>MaiorLinha){
        MaiorLinha = MatrizAux[x][y];
        VetorPosicoes[x] = y;
      }
    }
  }
  printf("\n->Caminho : ");
  for(int k=0;k<QuantLinhas;k++){
    printf("%d ",Matriz[k][VetorPosicoes[k]]);
  }
  printf("\n");
}
