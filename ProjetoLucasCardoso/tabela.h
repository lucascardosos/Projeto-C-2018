#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	char a;
	int b;
	double c;
	float d;
	char e[20];
}valor;

void criarTabela();
void criarLinha(FILE *arquivoTabela, FILE *arquivoChave, FILE *arquivoLog, valor *v, int tamanhoVetor);
void listarTabelas();
