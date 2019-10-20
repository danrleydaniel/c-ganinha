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

void logoMenuPrevisoes(void){
  printf("====================\n"
  "|| MENU PREVISÕES ||\n"
  "====================\n"
  "");
}

void logoCadastrarBolaCristal(void){
  printf("==================================\n"
  "|| CADASTRAR NA BOLA DE CRISTAL ||\n"
  "==================================\n"
  "");
}

void logoListarConsultores(void){
  printf("==========================\n"
  "|| LISTA DE CONSULTORES ||\n"
  "==========================\n"
  "");
}

void logoEditarBolaCristal(void){
  printf("=====================================\n"
  "|| EDITAR DADOS DA BOLA DE CRISTAL ||\n"
  "=====================================\n"
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
  printf("\n\n");
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
  if(encontrado){
    exibeCliente(usu);
    resp = menuEditarCliente();
    switch(resp){
      case '1': editaNome(usu);
                fwrite(usu, sizeof(Usuario), 1, fp);
                break;
      case '2': editaEmail(usu);
                fwrite(usu, sizeof(Usuario), 1, fp);
                break;
      case '3': editaDataNascimento(usu);
                fwrite(usu, sizeof(Usuario), 1, fp);
                break;
      default: printf("\nOpção inválida!\n");
    }
  } else{
    printf("\nAparentemente, nenhum usuário com o CPF %s está cadastrado.\n",procurado);
  }
  fclose(fp);
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
  logoMenuPrevisoes();
  printf("\nEscolha uma opção: ");
  printf("\n1 - Cadastrar-se na Bola de Cristal");
  printf("\n2 - Lista de Consultores");
  printf("\n3 - Atualizar Dados da Bola de Cristal");
  printf("\n4 - Consultar Cigana");
  printf("\n5 - Romper Contrato com a Cigana");
  printf("\n0 - Voltar ao Menu Principal\n");
  scanf("%c",&opcao);
  while(opcao != '0'){
    switch(opcao){
      case '1':
      cadastraBolaCristal();
      sleep(15);
      break;

      case '2':
      listarConsultores();
      sleep(15);
      break;

      case '3':
      editarDadosBolaCristal();
      sleep(15);
      break;

      case '4':
      printf("Em breve.\n");
      sleep(5);

      case '5':
      printf("Em breve\n");
      sleep(5);

      default:
      printf("\nOpção inválida\n");
    }
  printf("\nO que deseja fazer agora?\n");
  opcao = menuPrevisoes();
  }
  return opcao;
}

void cadastraBolaCristal(void){
  system("clear||cls");
  char procurado[15];
  int encontrado = 0;
  FILE* fp;
  Usuario* usu;
  logoCadastrarBolaCristal();
  printf("Se você já possui cadastro no sistema, digite o seu CPF: ");
  scanf(" %15[^\n]",procurado);
  fp = fopen("usuarios.dat","rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado. Tente novamente.\n");
  }
  usu = (Usuario*) malloc(sizeof(Usuario));
  while((!encontrado) && (fread(usu,sizeof(Usuario), 1, fp))){
    if(strcmp(usu->cpf, procurado) == 0 && (usu->status == 'c')){
      encontrado = 1;
    }
  }
  fclose(fp);
  if(encontrado){
    printf("\nO seguinte cliente foi encontrado: \n");
    exibeCliente(usu);
    Consultor* consu;
    consu = (Consultor*) malloc(sizeof(Consultor));

    strcpy(consu->nome, usu->nome);
    strcpy(consu->cpf, usu->cpf);
    consu->numNativo = numerologia(usu->dia, usu->mes, usu->ano);
    strcpy(consu->signos, signo(usu->dia, usu->mes, usu->ano));
    strcpy(consu->china, horoscopo(usu->ano));
    consu->status = 'c';

    gravaConsultor(consu);
    printf("\nPÁRABÉNS! VOCÊ FOI CADASTRADO COMO CONSULTOR!\n");
    free(consu);
  } else{
    printf("\nNenhum usuário com este CPF foi cadastrado. Você precisa cadastrar-se primeiramente no Menu Clientes para ter acesso às funcionalidades da cigana...\n");
  }
  free(usu);
}

void exibeConsultor(Consultor* consu){
  printf("Nome: %s \n",consu->nome);
  printf("CPF: %s \n",consu->cpf);
  printf("Signo: %s \n",consu->signos);
  printf("Animal no horóscopo chinês: %s \n",consu->china);
  printf("Nativo do número %d \n",consu->numNativo);
  printf("\n\n");
}

void listarConsultores(void){
  system("clear||cls");
  FILE* fp2;
  Consultor* consu;
  logoListarConsultores();
  consu = (Consultor*) malloc(sizeof(Usuario));
  fp2 = fopen("consultores.dat","rb");
  if(fp2 == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado. Tente novamente\n");
  }
  while(fread(consu, sizeof(Consultor), 1, fp2)){
    if(consu->status == 'c'){
      exibeConsultor(consu);
    }
  }
  free(consu);
  fclose(fp2);
}

void editarDadosBolaCristal(void){
  system("clear||cls");
  logoEditarBolaCristal();
  FILE* fp;
  FILE* fp2;
  Usuario* usu;
  Consultor* consu;
  int encontrado = 0;
  char procurado[15];
  fp = fopen("usuarios.dat", "r+b");
  fp2 = fopen("consultores.dat", "r+b");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado. Tente novamente\n");
  } else if(fp2 == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado. Tente novamente\n");
  }
  printf("Digite o seu CPF: \n");
  scanf(" %15[^\n]",procurado);
  usu = (Usuario*) malloc(sizeof(Usuario));
  consu = (Consultor*) malloc(sizeof(Consultor));
  while((!encontrado) && (fread(usu,sizeof(Usuario), 1, fp)) && (fread(consu,sizeof(Consultor), 1, fp))){
    if(strcmp(usu->cpf, procurado) == 0 && strcmp(consu->cpf, procurado) == 0 && (usu->status == 'c') && (consu->status == 'c')){
      encontrado = 1;
    }
  }
  fclose(fp);
  if(encontrado){
    printf("Cadastro no sistema: \n");
    exibeCliente(usu);
    printf("Cadastro na bola de cristal: \n");
    exibeConsultor(consu);
    strcpy(consu->nome, usu->nome);
    consu->numNativo = numerologia(usu->dia, usu->mes, usu->ano);
    strcpy(consu->cpf, usu->cpf);
    strcpy(consu->signos, signo(usu->dia, usu->mes, usu->ano));
    strcpy(consu->china, horoscopo(usu->ano));
    fwrite(consu, sizeof(Consultor), 1, fp2);
    printf("\nDados atualizados com sucesso!\n");
  } else{
    printf("\nAparentemente, o usuário com este CPF não está cadastrado no sistema geral ou não está cadastrado na bola de cristal da cigana...\n");
  }
  fclose(fp2);
  free(usu);
  free(consu);
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

void gravaConsultor(Consultor* consu){
  FILE* fp2;
  fp2 = fopen("consultores.dat","ab");
  if(fp2 == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado. Tente novamente\n");
  }
  fwrite(consu, sizeof(Consultor), 1, fp2);
  fclose(fp2);
}
