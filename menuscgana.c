/* BIBLIOTECA QUE PRINTA MENUS E LÊ OPÇÕES DO USUÁRIO COM RELAÇÃO À NAVEGAÇÃO */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "cadastrosevalidacoes.h"
#include "menuscgana.h"

void logotipoPrincipal(void){
 	printf("//////////////////////////////////\n");
	printf("//     SANDRA ROSA MADALENA     //\n");
	printf("//////////////////////////////////");
	printf("\n\n");
}

void logoCadastrarCliente(void){
  printf("==========================\n"
"||CADASTRAR NOVO USUÁRIO||\n"
"==========================\n"
"");
}

void logoMenuClientes(void){
  printf("===================\n"
"|| MENU CLIENTES ||\n"
"===================\n"
"");
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
  logoMenuClientes();
  Usuario* novoUsuario;
  novoUsuario = (Usuario*) malloc(sizeof(Usuario));
  printf("O que deseja fazer agora?");
  printf("\nEscolha uma opção: ");
  printf("\n1 - Cadastrar Cliente");
  printf("\n2 - Lista de Clientes");
  printf("\n3 - Buscar Cliente");
  printf("\n4 - Modificar Cliente");
  printf("\n5 - Deletar Cliente");
  printf("\n0 - Voltar ao Menu Principal\n");
  scanf("%c",&opcao);
  while (opcao != '0'){
    switch (opcao){
      case '1':
      novoUsuario = cdCliente();
      sleep(10);
      break;

      case '2':
      listarClientes(novoUsuario);
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
  free(novoUsuario);
  return opcao;
}

Usuario* cdCliente(void){
  system("clear");
  logoCadastrarCliente();
  Usuario* usu;
  usu = (Usuario*) malloc(sizeof(Usuario));

  printf("Digite seu nome: ");
  scanf(" %80[^\n]", usu->nome);


  printf("\nDigite sua data de nascimento: ");
  scanf("%d/%d/%d", &usu->dia, &usu->mes, &usu->ano);
  while(!(dataValida(usu->dia, usu->mes, usu->ano))){
    printf("\nData inválida. Digite novamente: ");
    scanf("%d/%d/%d", &usu->dia, &usu->mes, &usu->ano);
  }
    
  printf("\nDigite seu email: ");
  scanf(" %40[^\n]", usu->email);
  
  while(!(validaEmail(usu->email))){
    printf("Email inválido. Digite novamente: ");
    scanf(" %40[^\n]", usu->email);
  }
  

  printf("\nDigite o seu CPF: ");
	scanf(" %15[^\n]",usu->cpf);
  
  while(!(validaCpf(usu->cpf))){
    printf("CPF inválido. Digite novamente: ");
    scanf(" %15[^\n]",usu->cpf);
  }
    
  usu->numNativo = numerologia(usu->dia, usu->mes, usu->ano);
  usu->signos = signo(usu->dia, usu->mes, usu->ano);
  usu->china = horoscopo(usu->ano);

  usu->status = 'c';

  printf("USUÁRIO CADASTRADO COM SUCESSO!");


  printf("\n");

  free(usu);
  return usu;
}

void listarClientes(Usuario* usu){
  printf("Usuários cadastrados: \n");
  printf("\nNome: %s",usu->nome);
  printf("\nData de nascimento: %d/%d/%d",usu->dia, usu->mes, usu->ano);
  printf("\nEmail: %s", usu->email);
  printf("\nCPF: %s",usu->cpf);
  printf("\nUsuário nativo do número %d", usu->numNativo);
  printf("\nSigno: %s", usu->signos);
  printf("\nAnimal no horóscopo chinês: %s", usu->china);
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
