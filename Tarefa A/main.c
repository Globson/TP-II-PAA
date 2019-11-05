#include "Headers/Funcoes.h"
#include "Headers/Recursiva.h"
#include "Headers/Memorization.h"
#include "Headers/DeTrasPraFrente.h"
//#include <math.h>  //adicionar -lm no fim do comando do gcc

int main(int argc, char const *argv[]) {
  system("clear");
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
    //system("read -p 'Pressione Enter para continuar...' var");
    while(1){
      int a = Menu();
      if(a==1){
        IniciarTimer(&timer);
        int MaiorCaminho = Recursiva(Matriz,QuantLinhas,0,0);
        PararTimer(&timer);
        printf("\n-> O caminho de maior custo na piramide utilizando recursividade tem valor total de: %d",MaiorCaminho);
        printf("\n-> O tempo de execucao foi de %lf segundos\n\n", TempoTotal(timer));
      }
      if(a==2){
        IniciarTimer(&timer);
        int MaiorCaminho = TopMemorization(Matriz,QuantLinhas,0,0);
        PararTimer(&timer);
        printf("\n-> O caminho de maior custo na piramide utilizando programacao dinamica tem valor total de: %d",MaiorCaminho);
        printf("\n-> O tempo de execucao foi de %lf segundos\n\n", TempoTotal(timer));
        //ImprimeMelhorCaminho(Matriz,QuantLinhas);
      }
      if(a==3){
        IniciarTimer(&timer);
        int MaiorCaminho = TopDeTrasPraFrente(Matriz,QuantLinhas);
        PararTimer(&timer);
        printf("\n-> O caminho de maior custo na piramide utilizando de tras pra frente tem valor total de: %d",MaiorCaminho);
        printf("\n-> O tempo de execucao foi de %lf segundos\n\n", TempoTotal(timer));
      }
      if(a==4){
        int b;
        printf("\nDeseja mesmo finalizar?");
        printf("\n\t1 -> Sim");
        printf("\n\t2 -> Nao");
        do {
          printf("\nEntre: ");
          scanf("%d",&b);
          if(b!=1 && b!=2){
            printf("\nOpcao Invalida!\n");
          }
        } while(b!=1 && b!=2);
        if(b==1){
          break;
        }
        continue;
      }
    }
  }
  return 0;
}
