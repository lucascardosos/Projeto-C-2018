#include "apagavalor.h"

void apagaValor()
{

	int valor;
	int chave;
	int nulo;
	int comparaString;
	int i;
	int j;
	int escolheColuna;
	int colunas;
	int contador;
	char ch;
	char nomeTabela[50];
	char caminhoArquivo[50] = "./Tabelas/";
	char chavePrimaria[20] = "./Chaves/chaves_";
	char tabelaaux[50] = "./Tabelas/tabelaaux.txt";
	char caminhoLog[50] = "./Log/";
	char imprimeTabela[50];

	i = 1;
	nulo = 0;
	j = 1;
	colunas = 0;
	contador = 1;
	
	printf("Insira o nome da tabela (sem espaços): ");	//Nome da tabela a ser feita a remoção do valor
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


	while((fscanf(arquivoChave, "%i\n", &chave)) != EOF)	//Impressão das chaves primarias da tabela
	{
		printf("%i\n", chave);
	}

	printf("Insira a chave primaria do valor a se excluido: ");	//Escolha da CP
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

	while((ch = fgetc(arquivoTabela)) != '\n')	//Contagem do numero de colunas
	{
		if(ch == '\t')
		{
			colunas++;
		}
	}
	printf("A tabela possui %i colunas! Escolha qual o numero da coluna a ser deletada: ", colunas);	//Escolha da coluna a ser deletada
	scanf("%i", &escolheColuna);

	rewind(arquivoTabela);	//Exclusão da coluna escolhida, sendo impresso 0 no lugar do valor original em uma tabela auxiliar
	while((fscanf(arquivoTabela, "%s", imprimeTabela)) != EOF)
	{
		if((contador == escolheColuna) && (j == i))
		{
			fprintf(tabelaAux, "%i\t", nulo);	
		}
			
		if((contador != escolheColuna) || (j != i))
		{
			fprintf(tabelaAux, "%s\t", imprimeTabela);
		}
		if(contador == (colunas))
		{
			contador = 0;
			fprintf(tabelaAux, "\n");
			j++;
		}
		contador++;
	}
	
	fclose(arquivoTabela);
	fclose(arquivoChave);
	fclose(tabelaAux);
	fclose(arquivoLog);

	remove(caminhoArquivo);	//Remoção do arquivo original, renomeando o auxiliar para o nome que ele tinha
	rename(tabelaaux, caminhoArquivo);
}
