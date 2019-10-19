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

void logoEditarCliente(void){
  printf("====================\n"
"|| EDITAR CLIENTE ||\n"
"====================\n"
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
  system("clear||cls");
  logoMenuClientes();
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
      editarCliente();
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
  return opcao;
}

void cdCliente(void){
  system("clear||cls");
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
  system("clear||cls");
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
  printf("CPF: %s \n",usu->cpf);
  printf("Data de Nascimento: %d/%d/%d \n",usu->dia,usu->mes,usu->ano);
}

void buscarCliente(void){
  system("clear||cls");
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
  free(usu);
}

char menuEditarCliente(void){
  char op;
  printf("\nQual informação do usuário deseja editar?\n"
  "1 - Nome\n"
  "2 - Email\n"
  "3 - Data de Nascimento\n");
  scanf(" %c",&op);
  return op;
}

void editarCliente(void){
  system("clear||cls");
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
  logoEditarCliente();
  printf("Digite o CPF do usuário que deseja editar: \n");
  scanf(" %15[^\n]",procurado);
  usu = (Usuario*) malloc(sizeof(Usuario));
  while((!encontrado) && (fread(usu,sizeof(Usuario), 1, fp))){
    if(strcmp(usu->cpf, procurado) == 0 && (usu->status == 'c')){
      encontrado = 1;
    }
  }
  fclose(fp);
  if(encontrado){
    exibeCliente(usu);
    resp = menuEditarCliente();
    switch(resp){
      case '1': editaNome(usu);
                break;
      case '2': editaEmail(usu);
                break;
      case '3': editaDataNascimento(usu);
                break;
      default: printf("\nOpção inválida!\n");
    }
  } else{
    printf("\nAparentemente, nenhum usuário com o CPF %s está cadastrado.\n",procurado);
  }
  free(usu);
}

void editaNome(Usuario* usu){
  char novoNome[80];
  printf("\nDigite o novo nome: ");
  scanf(" %80[^\n]",novoNome);
  strcpy(usu->nome,novoNome);
}

void editaEmail(Usuario* usu){
  char novoEmail[40];
  printf("\nDigite o novo email: ");
  scanf(" %40[^\n]",novoEmail);
  while(!validaEmail(novoEmail)){
    printf("\nEmail inválido. Digite novamente: ");
    scanf(" %40[^\n]",novoEmail);
  }
  strcpy(usu->email,novoEmail);
}

void editaDataNascimento(Usuario* usu){
  int novoDia, novoMes, novoAno;
  printf("\nDigite a nova de nascimento: ");
  scanf("%d/%d/%d", &novoDia, &novoMes, &novoAno);
  while(!dataValida(novoDia, novoMes, novoAno)){
    printf("\nData inválida. Digite novamente: ");
    scanf("%d/%d/%d", &novoDia, &novoMes, &novoAno);
  }
  usu->dia = novoDia;
  usu->mes = novoMes;
  usu->ano = novoAno;
}

void deletarCliente(void){
  system("clear||cls");
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
    scanf(" %c",&resp);
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
  system("clear||cls");
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
