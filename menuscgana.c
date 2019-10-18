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

void logoListaClientes(void){
  printf("=======================\n"
"|| LISTA DE USUÁRIOS ||\n"
"=======================\n"
"");
}

void logoBuscarCliente(void){
  printf("======================\n"
"|| PROCURAR USUÁRIO ||\n"
"======================\n"
"");
}

void logoDeletarCliente(void){
  printf("=====================\n"
"|| DELETAR USUÁRIO ||\n"
"=====================\n"
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
      cdCliente();
      sleep(10);
      break;

      case '2':
      listarClientes();
      sleep(5);
      break;

      case '3':
      buscarCliente();
      sleep(5);
      break;

      case '4':
      printf("Em breve.\n");
      sleep(5);
      break;

      case '5':
      deletarCliente();
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

void cdCliente(void){
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
    
  usu->status = 'c';

  gravaUsuario(usu);

  printf("USUÁRIO CADASTRADO COM SUCESSO!");


  printf("\n");

  free(usu);
}

void listarClientes(void){
  FILE* fp;
  Usuario* usu;
  logoListaClientes();
  usu = (Usuario*) malloc(sizeof(Usuario));
  fp = fopen("usuarios.dat","rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado. Tente novamente\n");
  }
  while(fread(usu, sizeof(Usuario), 1, fp)){
    if(usu->status == 'c'){
      exibeCliente(usu);
    }
  }
  free(usu);
  fclose(fp);
}

void exibeCliente(Usuario* usu){
  printf("Nome: %s \n",usu->nome);
  printf("Email: %s \n",usu->email);
  printf("CPF: %s",usu->cpf);
  printf("Data de Nascimento: %d/%d/%d",usu->dia,usu->mes,usu->ano);
}

void buscarCliente(void){
  FILE* fp;
  Usuario* usu;
  int encontrado = 0;
  char procurado[80];
  fp = fopen("usuarios.dat", "rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado. Tente novamente\n");
  }
  printf("\n");
  logoBuscarCliente();
  printf("Digite o nome do usuário que está buscando: ");
  scanf(" %80[^\n]", procurado);
  usu = (Usuario*) malloc(sizeof(Usuario));
  while((!encontrado) && (fread(usu, sizeof(Usuario), 1, fp))){
    if(strcmp(usu->nome, procurado) == 0 && (usu->status == 'c')){
      encontrado = 1;
    }
  }
  fclose(fp);
  if(encontrado){
    exibeCliente(usu);
  } else{
    printf("Aparentemente, o cliente %s não está cadastrado.\n", procurado);
  }
}

void deletarCliente(void){
  system("clear");
  FILE* fp;
  Usuario* usu;
  int encontrado = 0;
  char resp;
  char procurado[15];
  fp = fopen("usuarios.dat", "r+b");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado. Tente novamente\n");
  }
  printf("\n");
  logoDeletarCliente();
  printf("Digite o CPF do usuário que deseja deletar: \n");
  scanf(" %15[^\n]", procurado);
  usu = (Usuario*) malloc(sizeof(Usuario));
  while((!encontrado) && (fread(usu, sizeof(Usuario), 1, fp))){
    if(strcmp(usu->cpf, procurado) == 0 && (usu->status == 'c')){
      encontrado = 1;
    }
  }
  fclose(fp);
  if(encontrado){
    exibeCliente(usu);
    printf("\nDeseja realmente deletar esse usuário?[S/N] ");
    if(resp == 's' || resp == 'S'){
      usu->status = 'x';
      fseek(fp, -1*sizeof(Usuario), SEEK_CUR);
      fwrite(usu, sizeof(Usuario), 1, fp);
      printf("Usuário deletado.\n");
    } else{
      printf("\nAção interrompida.\n");
    }
  } else{
    printf("Aparentemente, nenhum usuário com o CPF %s está cadastrado. \n", procurado);
  }
  free(usu);
}

char menuPrevisoes(void){
  char opcao;
  system("clear");
  printf("\nEscolha uma opção: ");
  printf("\n1 - Cadastrar-se na Bola de Cristal");
  printf("\n2 - Atualizar Dados da Bola de Cristal");
  printf("\n3 - Consultar Cigana");
  printf("\n4 - Romper Contrato com a Cigana");
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

      case '4':
      printf("Em breve.\n");

      default:
      printf("\nOpção inválida\n");
    }
  printf("\nO que deseja fazer agora?\n");
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

void gravaUsuario(Usuario* usu){
  FILE* fp;
  fp = fopen("usuarios.dat", "ab");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado. Tente novamente\n");
  }
  fwrite(usu, sizeof(Usuario), 1, fp);
  fclose(fp);
}
