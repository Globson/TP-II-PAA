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
    return Matriz[x][y];
  }
  else{
    if(MatrizAux[x][y] == -1){
       MatrizAux[x][y] = Matriz[x][y] + Maior(Memorization(Matriz,QuantLinhas,x+1,y+1,MatrizAux),Memorization(Matriz,QuantLinhas,x+1,y,MatrizAux));
    }
    return MatrizAux[x][y];
  }
}

void ImprimeMelhorCaminho(int Matriz[][100],int QuantLinhas){
  int MatrizAux[100][100];
  CopiaMatriz(Matriz,MatrizAux,QuantLinhas);
  MaiorCaminho(MatrizAux,QuantLinhas,0,0);
  for(int i=0;i<QuantLinhas;i++){
    for(int j=0;j<i+1;j++){
      if(MatrizAux[i][j]==-1){
        printf("(%d) ",Matriz[i][j]);
      }
      else{
        printf("%d ",Matriz[i][j]);
      }
    }
    printf("\n");
  }
}
void MaiorCaminho(int Matriz[][100],int QuantLinhas,int x,int y){
  if(QuantLinhas <= x){
    return;
  }
  Matriz[x][y] = -1;
  if(QuantLinhas-1 == x){
    return;
  }
  if(Matriz[x+1][y] > Matriz[x+1][y+1]){
    MaiorCaminho(Matriz,QuantLinhas,x+1,y);
  }
  else{
    MaiorCaminho(Matriz,QuantLinhas,x+1,y+1);
  }
}
