#include "tabela.h"

void lerTabela()
{
	char dadosTabela[100];
	char nomeTabela[50];
	char caminhoArquivo[50] = "./Tabelas/";	//onde será colocada as tabelas
	char caminhoLog[50] = "./Log/";

	printf("Insira o nome da tabela a ser lida: ");
	scanf("%s", nomeTabela);

	strcat(caminhoArquivo, nomeTabela);
	strcat(caminhoArquivo, ".txt");	//concatenação para criar um caminho e tipo de arquivo valido no "fopen"
	strcat(caminhoLog, nomeTabela);
	strcat(caminhoLog, ".txt");

	FILE *arquivoTabela;
	FILE *arquivoLog;

	arquivoTabela = fopen(caminhoArquivo, "r");
	arquivoLog = fopen(caminhoLog, "a");
	
	if(arquivoTabela == NULL)	//teste para saber se o arquivo foi iniciado com sucesso
	{	
		printf("Erro na abertura do arquivo tabela!\n");
		fprintf(arquivoLog, "Erro na abertura do arquivo tabela!\n");
		exit(1);
	}
	if(arquivoLog == NULL)
	{
		printf("Erro na abertura do arquivo Log\n");
		exit(1);
	}
	else
	{
		while(fgets(dadosTabela, sizeof(dadosTabela), arquivoTabela) != NULL)	//Impressão dos dados da tabela escolhida
		{
			printf("%s", dadosTabela);
		}
	}
	fclose(arquivoTabela);
	fclose(arquivoLog);
}
