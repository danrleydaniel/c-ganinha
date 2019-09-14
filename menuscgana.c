/* BIBLIOTECA QUE PRINTA MENUS E LÊ OPÇÕES DO USUÁRIO COM RELAÇÃO À NAVEGAÇÃO */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "cadastrosevalidacoes.h"

void logotipoPrincipal(void){
 	printf("//////////////////////////////////\n");
	printf("//     SANDRA ROSA MADALENA     //\n");
	printf("//////////////////////////////////");
	printf("\n\n");
}

char mainMenu(void){
	char opcao;
	printf("Escolha uma opção: \n\n");
	printf("1 - MENU CLIENTES\n");
	printf("2 - MENU PREVISÕES\n");
	printf("3 - SOBRE\n");
	printf("0 - FECHAR PROGRAMA\n");
	scanf("%c", &opcao);
	return opcao;
}

char menuClientes(void){
  char opcao;
  system("clear");
  printf("O que deseja fazer agora?");
  printf("\nEscolha uma opção: ");
  printf("\n1 - Cadastrar Cliente");
  printf("\n2 - Lista de Clientes");
  printf("\n3 - Modificar Cliente");
  printf("\n4 - Deletar Cliente");
  printf("\n0 - Voltar ao Menu Principal\n");
  scanf("%c",&opcao);
  while (opcao != '0'){
    switch (opcao){
      case '1':
      cdCliente();
      sleep(30);
      break;

      case '2':
      printf("Em breve.\n");
      sleep(5);
      break;

      case '3':
      printf("Em breve.\n");
      sleep(5);
      break;

      case '4':
      printf("Em breve.\n");
      sleep(5);
      break;

      default:
      printf("\nOpção inválida\n");

    }
    opcao = menuClientes();
  }
  return opcao;
}

char menuPrevisoes(void){
  char opcao;
  system("clear");
  printf("\nO que deseja fazer agora?\n");
  printf("\nEscolha uma opção: ");
  printf("\n1 - Consultar Previsões");
  printf("\n2 - Consultar Cor da Sorte");
  printf("\n3 - Consultar Frase do Dia");
  printf("\n0 - Voltar ao Menu Principal\n");
  scanf("%c",&opcao);
  while(opcao != '0'){
    switch(opcao){
      case '1':
      printf("Em breve.\n");
     // consultarPrevisoes();
     sleep(5);
      break;

      case '2':
      printf("Em breve.\n");
     // consultarCorDaSorte();
     sleep(5);
      break;

      case '3':
      printf("Em breve.\n");
     // consultarFraseDia();
     sleep(5);
      break;

      default:
      printf("\nOpção inválida\n");
    }
  opcao = menuPrevisoes();
  }
  return opcao;
}

void creditos(void){
	system("clear");
	printf("\nDesenvolvido por: Danrley Daniel e Hiago Roque\n");
	printf("Sob orientação do professoe Flavius Gorgônio\n");
	printf("Email: danrleydaniel21@gmail.com\n");
	printf("medeiroshiago70@gmail.com\n");
}

