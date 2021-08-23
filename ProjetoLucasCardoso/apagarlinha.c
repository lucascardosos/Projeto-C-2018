#include "apagarlinha.h"

void apagaLinha()
{

	int valor;
	int chave;
	int nulo;
	int comparaString;
	int i;
	int j;
	int colunas;
	int contador;
	char nomeTabela[50];
	char caminhoArquivo[50] = "./Tabelas/";
	char chavePrimaria[20] = "./Chaves/chaves_";
	char tabelaaux[50] = "./Tabelas/tabelaaux.txt";
	char caminhoLog[50] = "./Log/";
	char imprimeTabela[50];
	char ch;
	i = 1;
	nulo = 0;
	j = 1;
	colunas = 0;
	contador = 0;
	
	printf("Insira o nome da tabela (sem espaços): ");	//Nome da tabela que tera a linha excluida
	scanf("%s", nomeTabela);

	strcat(caminhoArquivo, nomeTabela);	//concatenações de strings para formar o caminho correto da tabela a ser lida
	strcat(caminhoArquivo, ".txt");	
	strcat(chavePrimaria, nomeTabela);
	strcat(chavePrimaria, ".txt");
	strcat(caminhoLog, nomeTabela);
	strcat(caminhoLog, ".txt");

	FILE *arquivoTabela;
	FILE *arquivoChave;
	FILE *tabelaAux;
	FILE *arquivoLog;

	arquivoTabela = fopen(caminhoArquivo, "r");
	arquivoChave = fopen(chavePrimaria, "r");
	arquivoLog = fopen(caminhoLog, "a");
	tabelaAux = fopen(tabelaaux, "a+");

	if(arquivoTabela == NULL)	//Testes de erro ao abrir os arquivos, as mensagens são salvas no log de erro
	{	
		printf("Erro na abertura do arquivo tabela, verifique o nome do arquivo e tente novamente!\n");
		fprintf(arquivoLog, "Erro na abertura do arquivo tabela, verifique o nome do arquivo e tente novamente!\n");
		exit(1);
	}
	if(arquivoChave == NULL)
	{
		printf("Erro na abertura do arquivo chave!\n");
		fprintf(arquivoLog, "Erro na abertura do arquivo Chave!\n");
		exit(1);
	}
	if(tabelaAux == NULL)
	{
		printf("Erro na abertura do arquivo tabela auxiliar\n");
		fprintf(arquivoLog, "Erro na abertura do arquivo Tabela Aux!\n");
		exit(1);
	}
	if(arquivoLog == NULL)
	{
		printf("Erro na abertura do arquivo Log\n");
		exit(1);
	}

	while((fscanf(arquivoChave, "%i\n", &chave)) != EOF)	//Leitura e exibição das chaves primarias existentes na tabela
	{
		printf("%i\n", chave);
	}

	printf("Insira a chave primaria do valor a se excluido: ");	//Escolha da chave a ser excluida
	scanf("%i", &valor);
	
	rewind(arquivoChave);	//Retorno do ponteiro de leitura para o inicio da tabela, para ser estabelecida a linha na qual a CP escolhida pertence
	
	while((fscanf(arquivoChave, "%i\n", &chave)) != EOF)
	{			
		if(chave == valor)
		{
			break;
		}
		else
		{
			i++;
		}
	}

	while((ch = fgetc(arquivoTabela)) != '\n')	//Contagem do numero de colunas da tabela
	{
		if(ch == '\t')
		{
			colunas++;
		}
	}
	
	rewind(arquivoTabela);	//Retorno do ponteiro de leitura para o inicio da tabela, para ser feita a remoção da linha ligada a CP escolhida
	while((fscanf(arquivoTabela, "%s", imprimeTabela)) != EOF)
	{
		if(j == i)
		{
			fprintf(tabelaAux, "%i\t", nulo);
			contador++;
		}
			
		if(j != i)
		{
			fprintf(tabelaAux, "%s\t", imprimeTabela);
			contador++;
		}
		if(contador == colunas)
		{
			contador = 0;
			fprintf(tabelaAux, "\n");
			j++;
		}
	}
	
	fclose(arquivoTabela);	//Remoção dos arquivos antigos e renomea os novos para os nomes corretos
	fclose(arquivoChave);
	fclose(tabelaAux);
	fclose(arquivoLog);

	remove(caminhoArquivo);
	rename(tabelaaux, caminhoArquivo);
}
