Funções solicitadas implementadas:
- Criar tabela
- Listar todas as tabelas
- Criar nova linha na tabela
- Listar todos os dados de uma tabela
- Pesquisar valor em uma tabela
- Apagar valor (linha) de uma tabela
- Apagar tabela

Funções Extras implementadas:
- Log de Erro
- Apagar valor (coluna de uma linha) de uma tabela

O que faria de forma diferente?
Sem duvidas na pesquisa. Eu faria o menu de forma mais dinamica, usando o retorno de uma função para indicar qual o tipo da coluna, para não ser necessario ser perguntado ao usuario.

Como compilar o projeto?
É MUITO importante que todos os arquivos e pastas do projeto estejam na mesma pasta, para tudo ser salvo em seu respectivo lugar sem erros.
antes de compilar deve ser feito o comando para entrar na pasta em que todos os arquivos do projeto foram salvos:

cd *caminho da pasta onde os arquivos estão salvos*

e depois compilar tudo usando o comando:

gcc main.c pesquisa.c apagar.c tabela.c tabela2.c apagavalor.c apagarlinha.c logerro.c -o *nome do executável*

para assim executar o codigo usando o comando:

./*nome do executável*

Nome do autor: Lucas Cardoso da Silva

Justificativa para as funções extras:
- Log de erro: Importante caso as funções não funcionem como o esperado, podendo ser visto o que houve de errado nelas. Salvando tudo em um arquivo torna mais certo do usuario enxergar que erro aconteceu, pois ele pode acabar não lendo o print feito na tela.
- Apagar valor (coluna de uma linha): Importante caso queira apagar apenas um valor, sem a necessidade de apagar uma linha e criar uma nova.
