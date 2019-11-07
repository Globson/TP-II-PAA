#include "Headers/Funcoes.h"
#include "Headers/Recursiva.h"
#include "Headers/Memorization.h"
#include "Headers/DeTrasPraFrente.h"
#define DEBUG 1
//#include <math.h>  //adicionar -lm no fim do comando do gcc

int main(int argc, char const *argv[]) {
  Timer timer;
  int Matriz[100][100];//Utilizaremos apenas as dimensoes que precisarmos, o maximo é 100;
  int QuantLinhas = LeituraArquivo(Matriz);
  printf("\n\tQuantidade de linhas: %d\n",QuantLinhas);
  if(QuantLinhas>-1){

    for(int i=0;i<QuantLinhas;i++){
      printf("\n");
      for(int j=0;j<i+1;j++){
        printf("%d ",Matriz[i][j]);
      }
    }
    printf("\n\n\tPiramide Carregada!\n\n");
      int a = Menu();
      if(a==1){
        if(DEBUG){
          IniciarTimer(&timer);
          int MaiorCaminho = Recursiva(Matriz,QuantLinhas,0,0);
          PararTimer(&timer);
          printf("\n-> O caminho de maior custo na piramide utilizando recursividade tem valor total de: %d",MaiorCaminho);
          printf("\n-> O tempo de execucao foi de %lf segundos\n\n", TempoTotal(timer));
        }
        else{
          int MaiorCaminho = Recursiva(Matriz,QuantLinhas,0,0);
          printf("\n-> O caminho de maior custo na piramide utilizando recursividade tem valor total de: %d\n",MaiorCaminho);
        }
      }
      if(a==2){
        if(DEBUG){
          IniciarTimer(&timer);
          int MaiorCaminho = TopMemorization(Matriz,QuantLinhas,0,0);
          PararTimer(&timer);
          printf("\n-> O caminho de maior custo na piramide utilizando programacao dinamica tem valor total de: %d",MaiorCaminho);
          printf("\n-> O tempo de execucao foi de %lf segundos\n\n", TempoTotal(timer));
        }
        else{
          int MaiorCaminho = TopMemorization(Matriz,QuantLinhas,0,0);
          printf("\n-> O caminho de maior custo na piramide utilizando programacao dinamica tem valor total de: %d\n",MaiorCaminho);
        }

      }
      if(a==3){
        if(DEBUG){
          IniciarTimer(&timer);
          int MaiorCaminho = TopDeTrasPraFrente(Matriz,QuantLinhas);
          PararTimer(&timer);
          printf("\n-> O caminho de maior custo na piramide utilizando de tras pra frente tem valor total de: %d",MaiorCaminho);
          printf("\n-> O tempo de execucao foi de %lf segundos\n\n", TempoTotal(timer));
        }
        else{
          int MaiorCaminho = TopDeTrasPraFrente(Matriz,QuantLinhas);
          printf("\n-> O caminho de maior custo na piramide utilizando de tras pra frente tem valor total de: %d\n",MaiorCaminho);
        }

      }
      if(a==4){
        CaminhoMemorization(Matriz,QuantLinhas);
        printf("\n");
      }
      if(a==5){
        CaminhoDeTrasPraFrente(Matriz,QuantLinhas);
        printf("\n");
      }
      printf("\n\tOBRIGADO POR UTILIZAR O PROGRAMA!\n");
  }
  return 0;
}
