#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

struct estudante 
{
	int dia;
	int mes;
	int ano;
	int situacao;
	long int cpf;
	long int ID;
	char nome[max];
};
typedef struct estudante Testudante;

void cadastrar(Testudante cadastros[10], int posicao)
{
  posicao--; //para iniciar o vetor na posicao zero, mas continuar fazendo a contagem de cadastros certa
	printf("\nOpção selecionada: CADASTRAR\n\n");
	printf("Entre com o nome:\n");
	getchar();
	fgets(cadastros[posicao].nome, max - 1, stdin);
	printf("Entre com a data de nascimento(formato: DD/MM/AAAA):\n");
	scanf("%d/%d/%d", &cadastros[posicao].dia, &cadastros[posicao].mes, &cadastros[posicao].ano);
	printf("Entre com o CPF(apenas números):\n");
	scanf("%ld", &cadastros[posicao].cpf);
	getchar();
	cadastros[posicao].situacao = 1;
	if(cadastros[posicao].dia > 31 || cadastros[posicao].dia<1){
		printf("O cadastro de data de nascimento foi realizado de forma errada quanto ao dia\n");
	}
	if(cadastros[posicao].mes > 12 || cadastros[posicao].mes<1){
		printf("O cadastro de data de nascimento foi realizado de forma errada quanto ao mes, o calendario solar tem apenas 12 meses validos, o mes %d nao esta entre eles\n",cadastros[posicao].mes);
	}
	if(cadastros[posicao].ano > 2019){
		printf("O cadastro de data de nascimento foi realizado de forma errada quanto ao ano, essa pessoa ainda nao nasceu no ano de %d, seria voce um vidente?\n",cadastros[posicao].ano);
	}
	if(cadastros[posicao].ano < 1800){
		printf("O cadastro de data de nascimento foi realizado de forma errada quanto ao ano, essa pessoa teria mais de 200 anos se tivesse nascido em %d, infelizmente nao trabalhamos com vampiros\n",cadastros[posicao].ano);
	}
	printf("\nCadastro realizado com sucesso!\n");
}

void listar(Testudante cadastros[10], int posicao) 
{	
	int i;
  printf("\nOpção selecionada: LISTAR\n\n");
  if(posicao == 0){
  	printf("O cadstro esta vazio\n");
	return;
  }
    for (i=0;i<posicao;i++)
    {
      if(cadastros[i].situacao==1)
      {
        printf("\nDados do estudante %d:\n", i);
        printf("Nome = %s", cadastros[i].nome);
        printf("ID = %d\n", i);
        printf("Data de Nascimento = %d/%d/%d\n", cadastros[i].dia, cadastros[i].mes,cadastros[i].ano);
        printf("CPF = %ld\n\n", cadastros[i].cpf);
      }
    }
    printf("Exibição da lista de cadastros realizada com sucesso!\n");
}

void pesquisar(Testudante cadastros[10], int posicao) 
{
	int i, conf=0;
	char nome[max];
	printf("\nOpção selecionada: PESQUISAR\n\n");
	printf("Entre com o nome:\n");
	getchar();
	fgets(nome, max-1, stdin);

	for (i=0;i<posicao;i++) 
  {
    if(cadastros[i].situacao==1)
    {
      if (strcmp(nome,cadastros[i].nome) == 0) 
      {
        printf("\nDocumento encontrado!\n");
        printf("\nDados do estudante:\n");
        printf("Nome = %s", cadastros[i].nome);
        printf("ID = %d\n", i);
        printf("Data de Nascimento = %d/%d/%d\n", cadastros[i].dia, cadastros[i].mes, cadastros[i].ano);
        printf("CPF = %ld\n\n", cadastros[i].cpf);
        printf("Pesquisa realizada com sucesso!\n");
        conf++; //confirmacao de que existe o nome
      }
    }
	}
  if(conf!=1)
  {
    printf("Documento não encontrado!\n");
  }
}

void atualizar(Testudante cadastros[10])
{
  	int id;
  	printf("\nOpção selecionada: ATUALIZAR\n\n");
  	printf("Entre com o número da ID:\n");
  	scanf("%d", &id);
  	printf("Entre com o nome:\n");
	getchar();
	fgets(cadastros[id].nome, max-1, stdin);
	printf("Entre com a data de nascimento(formato: DD/MM/AAAA):\n");
	scanf("%d/%d/%d", &cadastros[id].dia, &cadastros[id].mes, &cadastros[id].ano);
	printf("Entre com o CPF(apenas números):\n");
	scanf("%ld", &cadastros[id].cpf);
	getchar();
	cadastros[id].situacao = 1;
	//Reativaçao do cadastro
	printf("\nAtualização realizada com sucesso!\n");
}

void remover(Testudante cadastros[10])
{
  int id, i;
  printf("\nOpção selecionada: REMOVER\n\n");
  printf("Entre com o número da ID:\n");
  scanf("%d", &id);
  cadastros[id].situacao = 0;
  printf("\nRemoção realizada com sucesso!\n");
}
void main() {
	int opcao;
	Testudante cadastros[10];
	int posicao = 0;

	while (0==0) 
  {
		printf("#########################\n");
		printf("#                       #\n");
		printf("# Cadastro de pessoas:  #\n");
		printf("#  1-Cadastrar          #\n");
		printf("#  2-Listar             #\n");
		printf("#  3-Pesquisar          #\n");
		printf("#  4-Atualizar          #\n");
		printf("#  5-Remover            #\n");
		printf("#  6-Sair               #\n");
		printf("#########################\n\n");
		scanf("%d", &opcao);

		switch (opcao) 
    {
      case 1:
        posicao++;
        if(posicao<=10)
        {
          cadastrar(cadastros, posicao);
        }
        else
        {
          printf("\nNúmero de vagas já preenchidas\n");
        }
        break;

      case 2:
        listar(cadastros, posicao);
        break;

      case 3:
        pesquisar(cadastros, posicao);
        break;

      case 4:
        atualizar(cadastros);
        break;

      case 5:
        remover(cadastros);
        break;

      case 6:
        printf("Operações finalizadas!\n");
        exit(0);
      
      default:
        printf("Operação invalida!\n");

		}
	}
	return;
}
