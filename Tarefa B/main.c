#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>

#include "Headers/Funcoes.h"
#include "Headers/Menu.h"
#define DEBUG 0  //1 para ativado, 0 para desativado
int main(int argc, char const *argv[]) {
  Timer timer;
  int opcao = 0, confere = 0;
  int contAux = 0;
  int ** matrizDistancia;
  char* palavra01 = NULL;
  char* palavra02 = NULL;


  while(1){
    system("clear");
    MenuPrincipal();
    scanf("%d", &opcao);
    getchar();
    system("clear");
    //printf("%d", opcao);
    switch (opcao) {
      case 1:
        palavra01 = (char*)malloc(sizeof(char));
        palavra02 = (char*)malloc(sizeof(char));
        printf("Digite a primeira palavra: ");
        scanf("%s", palavra01);
        printf("Digite a segunda palavra: ");
        scanf("%s", palavra02);
        confere = 1;
        system("read -p 'Pressione Enter para continuar...' var");
        break;
      case 2:
        if(confere == 0){
          printf("Erro!! Entre com as palavras antes.\n");
          system("read -p 'Pressione Enter para continuar...' var");
          break;
        }
        if(DEBUG){
          IniciarTimer(&timer);
          printf("Palavra 01: %s\n", palavra01);
          printf("Palavra 02: %s\n\n", palavra02);
          matrizDistancia = DistanciaEdicao(palavra01, palavra02);
          printf("Matriz de Distancia\n\n");
          ExibirMatriz(matrizDistancia, strlen(palavra01), strlen(palavra02));
          printf("\n");
          ReconstruirSolucao(matrizDistancia, strlen(palavra01), strlen(palavra02), palavra01, palavra02, contAux);
          PararTimer(&timer);
          printf("\n-> O tempo de execucao foi de %lf segundos\n\n", TempoTotal(timer));
        }
        else{
          printf("Palavra 01: %s\n", palavra01);
          printf("Palavra 02: %s\n\n", palavra02);
          matrizDistancia = DistanciaEdicao(palavra01, palavra02);
          printf("Matriz de Distancia\n\n");
          ExibirMatriz(matrizDistancia, strlen(palavra01), strlen(palavra02));
          printf("\n");
          ReconstruirSolucao(matrizDistancia, strlen(palavra01), strlen(palavra02), palavra01, palavra02, contAux);
        }
        free(palavra01);
        free(palavra02);
        confere = 0;
        system("read -p 'Pressione Enter para continuar...' var");
        break;
      default:
        MenuSaida();
        printf("Saindo !!\n");
        exit(0);
    }
  }
  return 0;
}
