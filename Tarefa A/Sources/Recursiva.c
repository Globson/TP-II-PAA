#include "../Headers/Recursiva.h"

int Recursiva(int Matriz[][100],int QuantLinhas,int x,int y){
  if(QuantLinhas-1 == x){
    return Matriz[x][y];
  }
  else{
    return Matriz[x][y] + Maior(Recursiva(Matriz,QuantLinhas,x+1,y+1),Recursiva(Matriz,QuantLinhas,x+1,y));
  }
}

/*int Recursiva(int Matriz[][100],int QuantLinhas,int x,int y){
  if(QuantLinhas-1 == x){
    return Matriz[x][y];
  }
  else{
    if(Matriz[x+1][y]>Matriz[x+1][y+1]){
      return Matriz[x][y] + Recursiva(Matriz,QuantLinhas,x+1,y);
    }
    else{
      return Matriz[x][y] + Recursiva(Matriz,QuantLinhas,x+1,y+1);
    }
  }
}*/
