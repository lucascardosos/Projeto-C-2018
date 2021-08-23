#include "apagar.h"

void apagarTabela()
{
	char nomeTabela[50];
	char caminhoArquivo[50] = "./Tabelas/";
	char chavePrimaria[20] = "./Chaves/chaves_";
	char caminhoLog[50] = "./Log/";
	


	printf("Insira o nome da tabela a ser removida(sem espaços): ");	//Nome da tabela a ser excluida
	scanf("%s", nomeTabela);

	strcat(caminhoArquivo, nomeTabela);	//concatenações de strings para formar o caminho correto da tabela a ser excluida
	strcat(caminhoArquivo, ".txt");
	strcat(chavePrimaria, nomeTabela);
	strcat(chavePrimaria, ".txt");
	strcat(caminhoLog, nomeTabela);
	strcat(caminhoLog, ".txt");

	remove(caminhoArquivo);	//Remoção de todos os arquivos relacionados a tabela excluida
	remove(chavePrimaria);
	remove(caminhoLog);
}
