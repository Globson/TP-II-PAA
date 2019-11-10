#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <malloc.h>

#include "../Headers/Funcoes.h"
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

int ** DistanciaEdicao(char *palavra01, char *palavra02){
  int tamanhoPalavra01 = 0, tamanhoPalavra02 = 0;
  int valor = 0;
  int auxMinimo;
  int **matrizDistancia = InicializaMatriz(strlen(palavra01), strlen(palavra02));
  tamanhoPalavra01 = strlen(palavra01);
  tamanhoPalavra02 = strlen(palavra02);
  for(int i = 0; i <= tamanhoPalavra01; i++){
    matrizDistancia[i][0] = i;
  }
  for(int j = 0; j <= tamanhoPalavra01; j++){
    matrizDistancia[0][j] = j;
  }
  for(int i = 1; i <= tamanhoPalavra01; i++){
    for(int j = 1; j <= tamanhoPalavra02; j++){
      if(palavra01[j-1] == palavra02[i-1]){
        valor = 0;
      }
      else{
        valor = 1;
      }
        auxMinimo = Minimo(matrizDistancia[i-1][j-1] + valor, matrizDistancia[i-1][j] + 1);
        matrizDistancia[i][j] = Minimo(auxMinimo, matrizDistancia[i][j-1] + 1);

    }
  }
  return matrizDistancia;
}
int Minimo(int num1, int num2){
  if(num1 <= num2){
    return num1;
  }
  else{
    return num2;
  }
}
void ReconstruirSolucao(int ** matrizDistancia, int linha, int coluna, char* palavra01, char* palavra02, int contAux){
  int i, j;
  i = linha;
  j = coluna;
  if(linha > 0 && coluna > 0){
    if(palavra01[j-1] == palavra02[i-1]){
      printf("Mantém letra: (%c) \n", palavra01[j-1]);
      ReconstruirSolucao(matrizDistancia, linha-1, coluna-1, palavra01, palavra02, contAux);
    }
    else{
      if(matrizDistancia[linha][coluna-1] <= matrizDistancia[linha-1][coluna]
      && matrizDistancia[linha][coluna-1] <= matrizDistancia[linha-1][coluna-1]){
        if(contAux < (int) (strlen(palavra02) - strlen(palavra01))){
          printf("Apaga letra: (%c) \n", palavra02[j-1]);
          ReconstruirSolucao(matrizDistancia, linha, coluna-1, palavra01, palavra02, contAux);
        }
        else{
          printf("Insere letra: (%c) \n", palavra01[j-1]);
          ReconstruirSolucao(matrizDistancia, linha, coluna-1, palavra01, palavra02, contAux);
        }
      }
      else if(matrizDistancia[linha-1][coluna] <= matrizDistancia[linha][coluna-1]
      && matrizDistancia[linha-1][coluna] <= matrizDistancia[linha-1][coluna-1]){
        if(contAux < (int) (strlen(palavra01) - strlen(palavra02))){
          printf("Insere letra: (%c) \n", palavra01[i-1]);
          contAux ++;
          ReconstruirSolucao(matrizDistancia, linha-1, coluna, palavra01, palavra02, contAux);
        }
        else{
          printf("Apaga letra: (%c) \n", palavra02[i-1]);
          ReconstruirSolucao(matrizDistancia, linha-1, coluna, palavra01, palavra02, contAux);
        }
      }
      else if(matrizDistancia[linha-1][coluna-1] <= matrizDistancia[linha][coluna-1]
      && matrizDistancia[linha-1][coluna-1] <= matrizDistancia[linha-1][coluna]){
        printf("Substituir letra: (%c) por (%c)\n", palavra02[i-1], palavra01[j-1]);
        ReconstruirSolucao(matrizDistancia, linha-1, coluna-1, palavra01, palavra02, contAux);
      }
    }
  }
}
void ExibirMatriz(int **matrizDistancia, int linha, int coluna){
  for(int i = 0; i <= linha; i++){
    for(int j = 0; j <= coluna; j++){
      printf("%d ", matrizDistancia[i][j]);
    }
    printf("\n");
  }
}
int **InicializaMatriz(int linha, int coluna){
  int **matrizDistancia;
  matrizDistancia = (int**)calloc((linha+1),sizeof(int*));
  for(int i = 0; i <= linha; i++){
      matrizDistancia[i] = (int*)calloc((coluna+1),sizeof(int));
  }
  return matrizDistancia;
}
