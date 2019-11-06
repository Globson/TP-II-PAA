#include "../Headers/Funcoes.h"
int LeituraArquivo(int Matriz[][100]){
  FILE *f;
  char NomeArquivo[20];
  int QuantLinhas=-1;
  printf("\nDigite o nome do arquivo que deseja abrir:"); 
  scanf("%s",NomeArquivo);
  f = fopen(NomeArquivo,"r");
  if(f == NULL){
    printf("\n\tErro!Nao foi possivel abrir arquivo!\n");}
  else{
    printf("\n\tArquivo aberto com sucesso!\n");
    /*for(int k=0;k<100;k++){  //Refleti muito e acredito q se o algoritmo estiver 100% dentro dos limites não ha necessidade de inicilizar toda matriz com 0;
      for(int l=0;l<100;l++){  //Porem durante a manipulacao e visualizacao da matriz,o tamanho QuantLinhas DEVE SER RESPEITADO!
        Matriz[k][l]=0;
      }
    }*/
    for(int i=0;i<100;i++){
      for(int j=0;j<i+1;j++){
         fscanf(f,"%d",&Matriz[i][j]);
         if(feof(f)){
           break;
         }
      }
      QuantLinhas++;
      if(feof(f)){
        break;
      }
    }
    fclose(f);
  }
  return QuantLinhas;
}

int Maior(int a,int b){
  if(a>=b){
    return a;
  }
  return b;
}

int Menu(){
  int a;
  printf("\n-----------------------Menu-----------------------\n");
  printf("\n1 -> Metodo Recursivo:");
  printf("\n2 -> Metodo Programacao Dinamica:");
  printf("\n3 -> De Tras para Frente:");
  printf("\n4 -> Imprimir Rota utilizando Programacao Dinamica:");
  printf("\n5 -> Imprimir Rota utilizando De Tras para Frente:");
  printf("\n6 -> Finalizar:");
  do{
  printf("\nEntre com a opcao: ");
  scanf("%d",&a);
  if(a!=1 && a!=2 && a!=3 && a!=4 && a!=5 && a!=6){
    printf("\nOpcao invalida!\n");
  }
}while(a!=1 && a!=2 && a!=3 && a!=4 && a!=5 && a!=6);
  return a;
}

void CopiaMatriz(int MatrizOrigem[][100],int MatrizDestino[][100],int QuantLinhas){
  for(int i=0;i<QuantLinhas;i++)
    for(int j=0;j<i+1;j++){
      MatrizDestino[i][j]=MatrizOrigem[i][j];
    }
}

void MelhorCaminho(int QuantLinhas,int x,int y,int MatrizAux[][100]){
  MatrizAux[x][y]=-2; //Valor de referencia.
  if(x<QuantLinhas-1){
    if(MatrizAux[x+1][y]>MatrizAux[x+1][y+1]){
      MelhorCaminho(QuantLinhas,x+1,y,MatrizAux);
    }
    else{
      MelhorCaminho(QuantLinhas,x+1,y+1,MatrizAux);
    }
  }
  return;
}

//Funcoes para contagem de tempo de execucao//
void IniciarTimer(Timer *timer){
timer->TempoInicial = clock();
}

void PararTimer(Timer *timer){
timer->TempoFinal = clock();
timer->TempoTotal = (double)(timer->TempoFinal - timer->TempoInicial)/CLOCKS_PER_SEC;
}

double TempoTotal(Timer timer){
    return timer.TempoTotal;
}
