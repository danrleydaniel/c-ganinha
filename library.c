#include <stdio.h>
#include <stdlib.h>

void logotipoPrincipal(){
    printf("//////////////////////////////////\n");
	printf("//     SANDRA ROSA MADALENA     //\n");
	printf("//////////////////////////////////");
	printf("\n\n");
}

int mainMenu(void){
	int opcao;
	printf("Escolha uma opção: \n\n");
	printf("1 - MENU CLIENTES\n");
	printf("2 - MENU PREVISÕES\n");
	printf("3 - CRÉDITOS\n");
	printf("0 - FECHAR PROGRAMA\n");
	scanf("%d", &opcao);
	return opcao;
}

int menuClientes(){
  int opcao;
  system("clear");
  printf("O que deseja fazer agora?");
  printf("\nEscolha uma opção: ");
  printf("\n1 - Cadastrar Cliente");
  printf("\n2 - Lista de Clientes");
  printf("\n3 - Modificar Cliente");
  printf("\n4 - Deletar Cliente");
  printf("\n0 - Voltar ao Menu Principal\n");
  scanf("%d",&opcao);
  while (opcao != 0){
    switch (opcao){
      case 1:
      printf("Em breve.\n");
      printf("Aguarde...\n");
      sleep(5);
      break;

      case 2:
      printf("Em breve.\n");
      sleep(5);
      break;

      case 3:
      printf("Em breve.\n");
      sleep(5);
      break;

      case 4:
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

int menuPrevisoes(){
  int opcao;
  system("clear");
  printf("\nO que deseja fazer agora?\n");
  printf("\nEscolha uma opção: ");
  printf("\n1 - Consultar Previsões");
  printf("\n2 - Consultar Cor da Sorte");
  printf("\n3 - Consultar Frase do Dia");
  printf("\n0 - Voltar ao Menu Principal\n");
	scanf("%d",&opcao);
  while(opcao != 0){
    switch(opcao){
      case 1:
      printf("Em breve.\n");
     // consultarPrevisoes();
      break;

      case 2:
      printf("Em breve.\n");
     // consultarCorDaSorte();
      break;

      case 3:
      printf("Em breve.\n");
     // consultarFraseDia();
      break;

      default:
      printf("\nOpção inválida\n");
    }
  opcao = menuPrevisoes();
  }
  return opcao;
}

void creditos(){
	system("clear");
	printf("\nDesenvolvido por: Danrley Daniel e Hiago Roque\n");
	printf("Sob orientação do professoe Flavius Gorgônio\n");
	printf("Email: danrleydaniel21@gmail.com\n");
	printf("medeiroshiago70@gmail.com\n");
}

void cadastrarCliente(){
 // system("clear");
  printf("\nFunção Cadastrar Cliente em breve\n");
 // system("pause");
}

void listaClientes(){
  system("clear");
  printf("\nFunção Lista de Clientes em breve\n");
  system("pause");
}

void modificarCliente(){
  system("clear");
  printf("\nFunção Modificar Cliente em breve\n");
  system("pause");
}

void deletarCliente(){
  system("clear");
  printf("\nFunção Deletar Cliente\n");
  system("pause");
}

void consultarPrevisoes(){
  system("clear");
  printf("\nFunção Consultar Previsões em breve\n");
  system("pause");
}

void consultarCorDaSorte(){
  system("clear");
  printf("\nFunção Consultar Cor da Sorte em breve\n");
  system("pause");
}

void consultarFraseDia(){
  system("clear");
  printf("\nFunção Consultar Frase do Dia em breve\n");
  system("pause");
}
