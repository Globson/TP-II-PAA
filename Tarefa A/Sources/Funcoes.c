#include "../Headers/Funcoes.h"
int LeituraArquivo(int Matriz[][100]){
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
         if(feof(f)){
           break;
         }
      }
      QuantLinhas++;
      if(feof(f)){
        break;
      }
    }
  }
  fclose(f);
  return QuantLinhas;
}
