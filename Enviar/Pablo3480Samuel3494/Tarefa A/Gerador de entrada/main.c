#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[]) {
  FILE *f;
  int a;
  srand(time(NULL));
  char Nome[20];
  printf("Entre com o nome do arquivo de saida a ser criado: ");
  scanf("%s",Nome);
  f = fopen(Nome,"w");
  printf("Entre com a quantidade de linhas desejadas:");
  scanf("%d",&a);
  for(int i=0;i<a;i++){
    for(int j=0;j<i+1;j++){
      fprintf(f,"%d ",rand()%100);
    }
    fprintf(f,"\n");
  }
  printf("Arquivo gerado com sucesso!\n");
  fclose(f);
  return 0;
}
