#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"
#include "tabela2.h"
#include "pesquisa.h"
#include "apagar.h"
#include "apagavalor.h"
#include "apagarlinha.h"
#include "logerro.h"

int main()
{
	int a;
	int i;

	i = 0;
	
	while(i < 2)		//Menu principal, onde serão iniciadas as funções correspondentes
	{
		printf("O que deseja fazer?\n1 - Criar Tabela\n2 - Listar Tabelas\n3 - Criar uma nova linha para uma tabela ja existente\n4 - Listar dados de uma tabela\n5 - Pesquisar valor em uma tabela\n6 - Apagar linha em uma tabela\n7 - Apagar uma tabela\n8 - Ver log de erros\n9 - Apagar uma coluna em uma tabela\n10 - Sair\n");
		scanf("%i", &a);

		switch(a)
		{
			case 1:
				criarTabela();
				break;
	
			case 2:;
				listarTabelas();
				break;
	
			case 3:
				criarTabela();
				break;

			case 4:
				lerTabela();
				break;

			case 5:
				pesquisaValor();
				break;

			case 6:
				apagaLinha();
				break;

			case 7:
				apagarTabela();
				break;

			case 8:
				logErro();
				break;			
	
			case 9:
				apagaValor();
				break;

			case 10:
				i=2;
				break;
		}
	}
	return 0;
}
