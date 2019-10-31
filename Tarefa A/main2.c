#include <stdio.h>
#include <stdlib.h>
//#include <math.h>  //adicionar -lm no fim do comando do gcc

int main(int argc, char const *argv[]) {
  int Matriz[100][100];//Utilizaremos apenas as dimensoes que precisarmos, o maximo é 100;
  FILE *f;
  char NomeArquivo[20];
  // char NomeArquivo[20]="Arquivo.txt"; //retirar dps
  int QuantLinhas=-1;
  printf("\nDigite o nome do arquivo que deseja abrir:");    //Abrindo arquivo//
  scanf("%s",NomeArquivo);
  f = fopen(NomeArquivo,"r");
  if(f == NULL){
    printf("\n\tErro!Nao foi possivel abrir arquivo!\n");}  //Caso erro de abertura, programa solicita novamente entrada//
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
      }
      QuantLinhas++;
      if(feof(f)){
        break;
      }
    }
    //Printando matriz para testar
    for(int i=0;i<QuantLinhas;i++){
      printf("\n");
      for(int j=0;j<i+1;j++){
        printf("%d ",Matriz[i][j]);
      }
    }
    printf("\n");
    /* TODO
     Parte de leitura pronta, matriz em int pronta para realizar operacoes.
    */
  }
  return 0;
}
