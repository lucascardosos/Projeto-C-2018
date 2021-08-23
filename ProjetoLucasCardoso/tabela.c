#include "tabela.h"

void criarLinha(FILE *arquivoTabela, FILE *arquivoChave, FILE *arquivoLog, valor *v, int tamanhoVetor)	//Paramentros para função criarLinha
{
	int i, j, m, aux3;
	int aux;
	int cp;
	int auxcp;
	int contadorChave;
	int contadorColuna[tamanhoVetor];
	int armazenaInteiro[tamanhoVetor];
	int armazenaOp[tamanhoVetor];

	i = 0;
	m = 0;
	j = 0;
	contadorChave = 0;

	v = (valor *)malloc(tamanhoVetor * sizeof(valor));	//Cria um vetor de struct para receber os valores para a tabela
	
	if(v == NULL)
		{
			printf("Erro na alocação de memoria!\n");
			fprintf(arquivoLog, "Erro na alocação de memoria!\n");
			exit(1);
		}
	
	while(i < tamanhoVetor){
		
		printf("Qual o tipo da variavel que vai ser inserida?\n1 - Char\n2 - Int\n3 - Float\n4 - Double\n5 - String\n");
		scanf("%i", &aux);
		armazenaOp[i] = aux;

		switch(aux)	//É inserido o tipo de variavel de acordo com a opção escolhida pelo usuario, sendo elas armazenadas em um vetor de struct
		{	
			case 1:
				printf("Insira o valor: ");
				scanf(" %c", &v[i].a);
				j++;
				break;

			case 2:
				printf("Insira o valor: ");
				scanf("%i", &v[i].b);
				j++;
				contadorColuna[m] = j;
				armazenaInteiro[m] = v[i].b;
				m++;
				break;

			case 3:
				printf("Insira o valor: ");
				scanf("%lf", &v[i].c);
				j++;
				break;

			case 4:
				printf("Insira o valor: ");
				scanf("%f", &v[i].d);
				j++;
				break;

			case 5:	
				printf("Insira o valor: ");
				scanf("%s", v[i].e);
				j++;
				break;
		}		
		i++;
	}
	i = 0;
	aux3 = m;
	m = 1;

	printf("Escolha qual coluna vai ser a Chave Primaria:\n");	//Exibição das colunas de inteiros
	while(i < aux3)
	{
		printf("%i - Coluna %i - Valor = %i\n", m, contadorColuna[i], armazenaInteiro[i]);
		m++;
		i++;
	}
	scanf("%i", &cp);	//Escolha da coluna
	cp = cp-1;

	rewind(arquivoChave);	//Retorno do ponteiro de leitura para o inicio da tabela, para ser feito o teste de validação da chave
	while(fscanf(arquivoChave, "%i", &auxcp) != EOF)
	{
		if(auxcp == armazenaInteiro[cp])
		{		
			contadorChave++;	//Contador que aciona se a coluna não for valida
		}
	}
	i = 0;
	if(contadorChave < 1)
	{	
		fprintf(arquivoChave, "%i\n", armazenaInteiro[cp]);
		while(i < tamanhoVetor)	//Impressão dos dados na tabela criada
		{
			switch(armazenaOp[i])
			{
				case 1:
				fprintf(arquivoTabela, "%c\t", v[i].a);
				break;

			case 2:
				fprintf(arquivoTabela, "%i\t", v[i].b);
				break;

			case 3:
				fprintf(arquivoTabela, "%lf\t", v[i].c);
				break;

			case 4:
				fprintf(arquivoTabela, "%f\t", v[i].d);
				break;

			case 5:	
				fprintf(arquivoTabela, "%s\t", v[i].e);
				break;
			}		
			i++;
		}
		fprintf(arquivoTabela, "\n");
	}
	else	//Se a validação falhar, a linha não será impressa
	{
		printf("Chave Invalida, recrie a linha e escolha outra chave primaria\n");
		fprintf(arquivoLog, "Chave Invalida, recrie a linha e escolha outra chave primaria\n");
	}

	free(v);
}
void criarTabela()
{
	valor *v;
	int tamanhoVetor;
	int i;
	char nomeTabela[50];
	char caminhoArquivo[50] = "./Tabelas/";	//onde será colocada as tabelas
	char chavePrimaria[20] = "./Chaves/chaves_";	//onde serao colocadas as chaves para facilitar seu teste
	char caminhoLog[50] = "./Log/";

	i = 0;

	printf("Insira o nome da tabela (sem espaços): ");
	scanf("%s", nomeTabela);

	strcat(caminhoArquivo, nomeTabela);
	strcat(caminhoArquivo, ".txt");	//concatenação para criar um caminho e tipo de arquivo valido no "fopen"
	strcat(chavePrimaria, nomeTabela);
	strcat(chavePrimaria, ".txt");
	strcat(caminhoLog, nomeTabela);
	strcat(caminhoLog, ".txt");

	FILE *arquivoTabela;
	FILE *arquivoChave;
	FILE *arquivoLog;

	arquivoTabela = fopen(caminhoArquivo, "a");
	arquivoChave = fopen(chavePrimaria, "a+");
	arquivoLog = fopen(caminhoLog, "a");

	if(arquivoTabela == NULL)	//Testes de erro ao abrir os arquivos, as mensagens são salvas no log de erro
	{	
		printf("Erro na abertura do arquivo tabela!\n");
		fprintf(arquivoLog, "Erro na abertura do arquivo tabela!\n");
		exit(1);
	}
	if(arquivoChave == NULL)
	{
		printf("Erro na abertura do arquivo chave!\n");
		fprintf(arquivoLog, "Erro na abertura do arquivo Chave!\n");
		exit(1);
	}
	if(arquivoLog == NULL)
	{
		printf("Erro na abertura do arquivo Log\n");
		exit(1);
	}
	else
	{
		printf("Quantas colunas possui a tabela? ");
		scanf("%i", &tamanhoVetor);
	
		while(i < 2)	//Chama a função responsavel por criar a linha, podendo ser criada outra sem a necessidade de voltar ao menu
		{	
			criarLinha(arquivoTabela, arquivoChave, arquivoLog, v, tamanhoVetor);
			printf("O que deseja fazer?\n1 - Criar nova linha\n2 - Voltar ao Menu Principal\n");
			scanf("%i", &i);
		}
	}
	fclose(arquivoTabela);
	fclose(arquivoChave);
	fclose(arquivoLog);
}
void listarTabelas()	
{
	system("ls ~/projeto/Tabelas");	//Usa um comando do sistema para exibir as tabela salvas
}
