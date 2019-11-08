#ifndef FUNCOES_H
#define FUNCOES_H

int ** DistanciaEdicao(char *palavra01, char *palavra02);
int Minimo(int num1, int num2);
void ExibirMatriz(int ** matrizDistancia, int linha, int coluna);
int **InicializaMatriz(int linha, int coluna);
void ReconstruirSolucao(int ** matrizDistancia, int linha, int coluna,char* palavra01, char* palavra02, int contAux);
#endif
