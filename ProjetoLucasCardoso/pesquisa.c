#include "pesquisa.h"

void pesquisaValor()
{
	int contador;
	int escolhaColuna;
	int menu1;
	int menu2;
	int tamanhoString;
	float Valor;
	float numeroTabela;
	char nomeTabela[50];
	char caminhoArquivo[50] = "./Tabelas/";
	char imprimeCaracter;
	char aux;
	char comparaString[50];
	char imprimeTabela[100];
	char escolhaString[100];
	char stringTabela[100];
	char caminhoLog[50] = "./Log/";
	
	contador = 0;
	
	printf("Insira o nome da tabela (sem espaços): ");	//Nome da tabela a ser feita a pesquisa
	scanf("%s", nomeTabela);

	strcat(caminhoArquivo, nomeTabela);	//concatenações de strings para formar o caminho correto da tabela a ser lida
	strcat(caminhoArquivo, ".txt");
	strcat(caminhoLog, nomeTabela);
	strcat(caminhoLog, ".txt");

	FILE *arq;
	FILE *arqaux;
	FILE *arquivoLog;

	arq = fopen(caminhoArquivo, "r");
	arqaux = fopen("guardaColuna.txt", "w+");
	arquivoLog = fopen(caminhoLog, "a");

	if(arq == NULL)	//Testes de erro ao abrir os arquivos, as mensagens são salvas no log de erro
	{
		printf("Erro na abertura do arquivo tabela, verifique o nome do arquivo e tente novamente!\n");
		fprintf(arquivoLog, "Erro na abertura do arquivo tabela, verifique o nome do arquivo e tente novamente!\n");
		exit(1);
	}
	if(arqaux == NULL)
	{
		printf("Erro na abertura do arquivo Armazena Coluna\n");
		fprintf(arquivoLog, "Erro na abertura do arquivo Armazena Coluna!\n");
		exit(1);
	}
	if(arquivoLog == NULL)
	{
		printf("Erro na abertura do arquivo Log\n");
		exit(1);
	}

	rewind(arq);	//Retorno do ponteiro de leitura para o inicio da tabela, para ser contado o numero de colunas da tabela
	while((imprimeCaracter = fgetc(arq)) != '\n')
	{
		if(imprimeCaracter == '\t')
		{
			contador++;
			printf("Col %i\t", contador);
		}
	}

	printf("\n");

	rewind(arq);	//Retorno do ponteiro de leitura para o inicio da tabela, para imprimir o conteudo da tabela
	while(fgets(imprimeTabela, sizeof(imprimeTabela), arq) != NULL)
	{
		printf("%s", imprimeTabela);
	}
		
	printf("Digite a coluna a ser feita a pesquisa: ");
	scanf("%i", &escolhaColuna);
	contador = 0;

	rewind(arq);	//Retorno do ponteiro de leitura para o inicio da tabela, para ser feita a impressão da coluna escolhida numa tabela auxiliar
	while((imprimeCaracter = fgetc(arq)) != EOF)
	{
		if(contador == (escolhaColuna-1)&&imprimeCaracter != '\t')
		{
			fprintf(arqaux, "%c", imprimeCaracter);
		}
		if(imprimeCaracter == '\t')
		{
			contador++;
		}
		if(imprimeCaracter == '\n')
		{
			fprintf(arqaux, "\n");
			contador = 0;
		}
	}
	printf("Digite o valor a ser pesquisado: ");	//Valor a ser pesquisado, é desconsiderado caso seja escolhida a opção 6	
	scanf("%f", &Valor);

	printf("Qual o tipo do valor a ser procurado:\n1 - Int/Double/Float\n2 - String/Char\n");	//Separação do menu por tipo de coluna
	scanf("%i", &menu1);

	rewind(arqaux); //Retorno do ponteiro de leitura para o inicio da tabela, para ser feita a escolha da opção de pesquisa e a leitura dos valores da coluna escolhida
	contador = 0;
	switch(menu1)
	{
		case 1:	//Para variaveis numericas
				
			printf("Escolha o que exibir:\n1 - valores maior que o valor informado\n2 - valores maior ou igual que o valor informado\n3 - valores igual o valor informado\n4 - valores menor que o valor informado\n5 - valores menor ou igual que o valor informado\n");
			scanf("%i", &menu2);
			switch(menu2)
			{
				case 1:
					while(fscanf(arqaux, "%f", &numeroTabela) != EOF)
					{
						if(numeroTabela > Valor)
						{
							printf("%.2f\n", numeroTabela);
						}
					}
					break;

				case 2:
					while(fscanf(arqaux, "%f", &numeroTabela) != EOF)
					{
						if(numeroTabela >= Valor)
						{
							printf("%.2f\n", numeroTabela);
						}
					}
					break;

				case 3:
					while(fscanf(arqaux, "%f", &numeroTabela) != EOF)
					{
						if(numeroTabela == Valor)
						{
							printf("%.2f\n", numeroTabela);
						}
					}
					break;

				case 4:
					while(fscanf(arqaux, "%f", &numeroTabela) != EOF)
					{
						if(numeroTabela < Valor)
						{
							printf("%.2f\n", numeroTabela);
						}
					}
					break;

				case 5:
					while(fscanf(arqaux, "%f", &numeroTabela) != EOF)
					{
						if(numeroTabela <= Valor)
						{
							printf("%.2f\n", numeroTabela);
						}
					}
					break;
			}
			break;

		case 2:	//Para variaveis em caracter ou string
			printf("Escolha o que exibir:\n1 - valores maior que o valor informado\n2 - valores maior ou igual que o valor informado\n3 - valores igual o valor informado\n4 - valores menor que o valor informado\n5 - valores menor ou igual que o valor informado\n6 - valores próximo ao valor informado\n");
			scanf("%i", &menu2);
			switch(menu2)
			{
				case 1:
					while((fgets(stringTabela, sizeof(stringTabela), arqaux)) != NULL)
					{
						tamanhoString = strlen(stringTabela);
						if(tamanhoString > Valor + 1)
						{
							printf("%s", stringTabela);
						}
					}		
							
					break;

				case 2:
					while((fgets(stringTabela, sizeof(stringTabela), arqaux)) != NULL)
					{
						tamanhoString = strlen(stringTabela);
						if(tamanhoString >= Valor + 1)
						{
							printf("%s", stringTabela);
						}
					}		
							
					break;

				case 3:
					while((fgets(stringTabela, sizeof(stringTabela), arqaux)) != NULL)
					{
						tamanhoString = strlen(stringTabela);
						if(tamanhoString == Valor + 1)
						{
							printf("%s", stringTabela);
						}
					}		
							
					break;

				case 4:
					while((fgets(stringTabela, sizeof(stringTabela), arqaux)) != NULL)
					{
						tamanhoString = strlen(stringTabela);
						if(tamanhoString < Valor + 1)
						{
							printf("%s", stringTabela);
						}
					}		
							
					break;

				case 5:
					while((fgets(stringTabela, sizeof(stringTabela), arqaux)) != NULL)
					{
						tamanhoString = strlen(stringTabela);
						if(tamanhoString <= Valor + 1)
						{
							printf("%s", stringTabela);
						}
					}		
								
					break;
				case 6:
					printf("Digite a string a ser comparada: ");
					scanf("%s", comparaString);
					while((fgets(stringTabela, sizeof(stringTabela), arqaux)) != NULL)
					{
						if((strstr(stringTabela, comparaString) != NULL) || (strstr(comparaString, stringTabela) != NULL))
						{
							printf("%s", stringTabela);
						}
					}	

					break;
			}
			break;
	}

	fclose(arq);
	fclose(arqaux);
	fclose(arquivoLog);
	remove("guardaColuna.txt");
}
