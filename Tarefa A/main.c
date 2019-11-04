#include "Headers/Funcoes.h"
//#include <math.h>  //adicionar -lm no fim do comando do gcc

int main(int argc, char const *argv[]) {
  int Matriz[100][100];//Utilizaremos apenas as dimensoes que precisarmos, o maximo é 100;
  int QuantLinhas = LeituraArquivo(Matriz);
  printf("\n\tQuantidade de linhas: %d\n",QuantLinhas);
  if(QuantLinhas>-1){
    //Printando matriz para testar
    for(int i=0;i<QuantLinhas;i++){
      printf("\n");
      for(int j=0;j<i+1;j++){
        printf("%d ",Matriz[i][j]);
      }
    }
    printf("\n");
  }
    /* TODO
     Parte de leitura pronta, matriz em int pronta para realizar operacoes.
    */
  return 0;
}
