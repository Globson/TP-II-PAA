#include <stdio.h>
#include <stdlib.h>
//#include <math.h>  //adicionar -lm no fim do comando do gcc

int main(int argc, char const *argv[]) {
  int Matriz[100][100];//Utilizaremos apenas as dimensoes que precisarmos, o maximo é 100;
  FILE *f;
  char NomeArquivo[20]="Arquivo.txt"; //retirar dps
  int Contador=0,QuantLinhas;
  //int Valores[5050]; //5050 é o valor da soma dos 100 primeiros numeros de 1 a 100;
  int *Valores = (int*)malloc(sizeof(int)); //utilizei um vetor dinamico para diminuir gasto exagerado de memoria em vetor de 5050 posicoes.
  printf("\nDigite o nome do arquivo que deseja abrir:");    //Abrindo arquivo//
  //scanf("%s",NomeArquivo);
  f = fopen(NomeArquivo,"r");
  if(f == NULL){
    printf("\n\tErro!Nao foi possivel abrir arquivo!\n");}  //Caso erro de abertura, programa solicita novamente entrada//
  else{
    printf("\n\tArquivo aberto com sucesso!\n");
    for(int k=0;k<100;k++){
      for(int l=0;l<100;l++){
        Matriz[k][l]=0;
      }
    }
    while(!feof(f)){
      fscanf(f,"%d",&Valores[Contador]);
      Contador++;
      Valores = (int*)realloc(Valores,sizeof(int)*(Contador+1));
    }
    printf("\n\tContador: %d\n",Contador); //Para debugar
    Contador-=1;  //Descontado 1 devido ao feof() rodar uma ultima vez ao quebrar a ultima linha.
    int Quant=1; //Valor inicial para multiplas subtracoes.
    do{
      Contador-=Quant;
      Quant++;
    }while(Contador!=0);

    QuantLinhas = Quant-1; //Quantidade de linhas da piramide, decontando -1 => valor inicial.
    printf("\n\tQuantLinhas: %d\n",QuantLinhas); //Para debugar

    Contador = 0; //Setando para 0 parar poder tranferir de vetor para matriz.
    for(int i=0;i<QuantLinhas;i++){
        for(int j=0;j<i+1;j++){
          Matriz[i][j]=Valores[Contador];
          Contador++;
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
