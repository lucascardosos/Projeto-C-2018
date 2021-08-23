#include "logerro.h"

void logErro()
{
	char dadosLog[100];
	char nomeTabela[50];
	char caminhoLog[50] = "./Log/";

	printf("Insira o nome da tabela a ser vista os erros: ");	//Nome da tabela a ter seus erros lidos
	scanf("%s", nomeTabela);

	strcat(caminhoLog, nomeTabela);
	strcat(caminhoLog, ".txt");

	FILE *arquivoLog;	

	arquivoLog = fopen(caminhoLog, "r");
	
	if(arquivoLog == NULL)	//teste para saber se o arquivo foi iniciado com sucesso
	{	
		printf("Erro na abertura do arquivo log!\n");
		exit(1);
	}
	else
	{
		while(fgets(dadosLog, sizeof(dadosLog), arquivoLog) != NULL)	//Impressão dos dados inseridos na tabela
		{
			printf("%s", dadosLog);
		}
	}
	fclose(arquivoLog);	
	
}
