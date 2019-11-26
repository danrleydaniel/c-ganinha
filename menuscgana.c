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
  printf("////////////////////////////\n");
  printf("//  SANDRA ROSA MADALENA  //\n");
  printf("////////////////////////////");
  printf("\n\n");
}

void logoCadastrarCliente(void){
  printf("==========================\n"
  "|| CADASTRAR NOVO USUÁRIO ||\n"
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

void logoConsultarCigana(void){
  printf("======================\n"
  "|| CONSULTAR CIGANA ||\n"
  "======================\n"
  "");
}

void logoTarotDiario(void){
  printf("==================\n"
  "|| TAROT DO DIA ||\n"
  "==================\n"
  "");
}

void logoDeletarConsultor(void){
  printf("=======================\n"
  "|| DELETAR CONSULTOR ||\n"
  "=======================\n"
  "");
}

void logoRelatorios(void){
  printf("================\n"
  "|| RELATÓRIOS ||\n"
  "================\n"
  "");
}

char mainMenu(void){
  char opcao;
  system("clear||cls");
  logotipoPrincipal();
  printf("Escolha uma opção: \n\n");
  printf("1 - MENU CLIENTES\n");
  printf("2 - MENU PREVISÕES\n");
  printf("3 - RELATÓRIOS\n");
  printf("4 - SOBRE\n");
  printf("0 - FECHAR PROGRAMA\n");
  scanf("%c", &opcao);

  return opcao;
}

char menuClientes(void){
  char opcao;
  system("clear||cls");
  logoMenuClientes();
  printf("\nEscolha uma opção: \n");
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
      pausaPrograma();
      break;

      case '2':
      listarClientes();
      pausaPrograma();
      break;

      case '3':
      buscarCliente();
      pausaPrograma();
      break;

      case '4':
      editarCliente();
      pausaPrograma();
      break;

      case '5':
      deletarCliente();
      pausaPrograma();
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
    printf("O CPF informado é inválido ou já está cadastrado. Digite novamente: ");
    scanf(" %15[^\n]",usu->cpf);
  }
    
  usu->status = 'c';

  gravaUsuario(usu);

  printf("\n\nUSUÁRIO CADASTRADO COM SUCESSO!\n");


  printf("\n");

  free(usu);
}

char menuListarCliente(void){
  char opcao;
  printf("\nQual tipo de lista deseja ver?\n"
  "1 - Lista Normal\n"
  "2 - Lista Ordenada\n"
  "3 - Lista De Clientes Recentes\n");
  scanf(" %c",&opcao);
  return opcao;
}

void listarClientes(void){
  system("clear||cls");
  char op;
  logoEditarCliente();
  op = menuListarCliente();
  switch(op){
    case '1': 
      listaDireta(); 
      break;

    case '2':
      listaOrdenada();
      break;

    case '3': 
      listaInvertida();
      break;

    default:
      printf("\nOpção inválida.\n");
  }
}

void listaInvertida(void){
  system("clear||cls");
  logoListaClientes();
  FILE* fp;
  Usuario* usu;
  NoUsuario* noUsu;
  NoUsuario* lista;

  lista = NULL;
  fp = fopen("usuarios.dat", "rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado.\n");
    printf("Tente novamente mais tarde.\n");
    exit(1);
  }

  usu = (Usuario*) malloc(sizeof(Usuario));
  while(fread(usu, sizeof(Usuario), 1, fp)){
    if(usu->status == 'c'){
      noUsu = (NoUsuario*) malloc(sizeof(NoUsuario));
      strcpy(noUsu->nome, usu->nome);
      strcpy(noUsu->email, usu->email);
      strcpy(noUsu->cpf, usu->cpf);
      noUsu->dia = usu->dia;
      noUsu->mes = usu->mes;
      noUsu->ano = usu->ano;
      noUsu->status = usu->status;
      noUsu->prox = lista;
      lista = noUsu;
    }
  }
  fclose(fp);
  exibeListaUsuario(lista);
  free(usu);
  liberaLista(lista);
}

void listaDireta(void){
  system("clear||cls");
  logoListaClientes();
  FILE* fp;
  Usuario* usu;
  NoUsuario* noUsu;
  NoUsuario* lista;
  NoUsuario* ult;

  lista = NULL;
  fp = fopen("usuarios.dat", "rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado.\n");
    printf("Tente novamente mais tarde.\n");
    exit(1);
  }
  usu = (Usuario*) malloc(sizeof(Usuario));
  while(fread(usu, sizeof(Usuario), 1, fp)){
    if(usu->status == 'c'){
      noUsu = (NoUsuario*) malloc(sizeof(NoUsuario));
      strcpy(noUsu->nome, usu->nome);
      strcpy(noUsu->email, usu->email);
      strcpy(noUsu->cpf, usu->cpf);
      noUsu->dia = usu->dia;
      noUsu->mes = usu->mes;
      noUsu->ano = usu->ano;
      noUsu->status = usu->status;
      noUsu->prox = NULL;
    }
    if (lista == NULL){
      lista = noUsu;
    } else{
      ult->prox = noUsu;
    }
    ult = noUsu;
  }
  fclose(fp);
  exibeListaUsuario(lista);
  free(usu);
  liberaLista(lista);
}

void listaOrdenada(void){
  system("clear||cls");
  logoListaClientes();
  FILE* fp;
  Usuario* usu;
  NoUsuario* noUsu;
  NoUsuario* lista;

  lista = NULL;
  fp = fopen("usuarios.dat", "rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'usuarios.dat' não foi encontrado.\n");
    printf("Tente novamente mais tarde.\n");
    exit(1);
  }
  usu = (Usuario*) malloc(sizeof(Usuario));
  while(fread(usu, sizeof(Usuario), 1, fp)){
    if(usu->status == 'c'){
      noUsu = (NoUsuario*) malloc(sizeof(NoUsuario));
      strcpy(noUsu->nome, usu->nome);
      strcpy(noUsu->email, usu->email);
      strcpy(noUsu->cpf, usu->cpf);
      noUsu->dia = usu->dia;
      noUsu->mes = usu->mes;
      noUsu->ano = usu->ano;
      noUsu->status = usu->status;

      if (lista == NULL){
        lista = noUsu;
        noUsu->prox = NULL;
      } else if (strcmp(noUsu->nome,lista->nome) < 0) {
        noUsu->prox = lista;
        lista = noUsu;
      } else {
        NoUsuario* ant = lista;
        NoUsuario* atu = lista->prox;
        while ((atu != NULL) && strcmp(atu->nome,noUsu->nome) < 0) {
          ant = atu;
          atu = atu->prox;
        }
        ant->prox = noUsu;
        noUsu->prox = atu;
      }
    }
  }
  fclose(fp);
  exibeListaUsuario(lista);
  free(usu);
  liberaLista(lista);
}

void exibeListaUsuario(NoUsuario* lista){
  while(lista != NULL){
    printf("\nNome: %s \n", lista->nome);
    printf("Email: %s \n",lista->email);
    printf("CPF: %s \n",lista->cpf);
    printf("Data de nascimento: %d/%d/%d \n", lista->dia, lista->mes, lista->ano);
    if(lista->status == 'c'){
      printf("Usuário cadastrado normalmente\n");
    } else{
      printf("Obs: este usuário encontra-se deletado.\n");
    }
    lista = lista->prox;
  }
}

void liberaLista(NoUsuario* lista){
  NoUsuario* aux = lista;
  while (lista != NULL) {
		lista = lista->prox;
		free(aux);
		aux = lista;
	}
}

void liberaListaConsultor(NoConsultor* lista){
  NoConsultor* aux = lista;
  while (lista != NULL) {
		lista = lista->prox;
		free(aux);
		aux = lista;
	}
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
      case '1': editaNome(usu, fp);
                break;
      case '2': editaEmail(usu, fp);
                break;
      case '3': editaDataNascimento(usu, fp);
                break;
      default: printf("\nOpção inválida!\n");
    }
  } else{
    printf("\nAparentemente, nenhum usuário com o CPF %s está cadastrado.\n",procurado);
  }
  fclose(fp);
  free(usu);
}

void editaNome(Usuario* usu, FILE* fp){
  char novoNome[80];
  printf("\nDigite o novo nome: ");
  scanf(" %80[^\n]",novoNome);
  strcpy(usu->nome,novoNome);
  fseek(fp, -1*sizeof(Usuario), SEEK_CUR);
  fwrite(usu, sizeof(Usuario), 1, fp);
  printf("\nUsuário editado. Lembre-se de atualizar seus dados na bola de cristal da cigana.\n");
}

void editaEmail(Usuario* usu, FILE* fp){
  char novoEmail[40];
  printf("\nDigite o novo email: ");
  scanf(" %40[^\n]",novoEmail);
  while(!validaEmail(novoEmail)){
    printf("\nEmail inválido. Digite novamente: ");
    scanf(" %40[^\n]",novoEmail);
  }
  strcpy(usu->email,novoEmail);
  fseek(fp, -1*sizeof(Usuario), SEEK_CUR);
  fwrite(usu, sizeof(Usuario), 1, fp);
  printf("\nUsuário editado. Lembre-se de atualizar seus dados na bola de cristal da cigana.\n");
}

void editaDataNascimento(Usuario* usu, FILE* fp){
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
  fseek(fp, -1*sizeof(Usuario), SEEK_CUR);
  fwrite(usu, sizeof(Usuario), 1, fp);
  printf("\nUsuário editado. Lembre-se de atualizar seus dados na bola de cristal da cigana.\n");
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
  fclose(fp);
  free(usu);
}

char menuPrevisoes(void){
  char opcao;
  system("clear||cls");
  logoMenuPrevisoes();
  printf("\nEscolha uma opção: \n");
  printf("\n1 - Cadastrar-se na Bola de Cristal");
  printf("\n2 - Lista de Consultores");
  printf("\n3 - Atualizar Dados da Bola de Cristal");
  printf("\n4 - Consultar Cigana");
  printf("\n5 - Tarot do Dia");
  printf("\n6 - Romper Contrato com a Cigana");
  printf("\n0 - Voltar ao Menu Principal\n");
  scanf("%c",&opcao);
  while(opcao != '0'){
    switch(opcao){
      case '1':
      cadastraBolaCristal();
      pausaPrograma();
      break;

      case '2':
      listarConsultores();
      pausaPrograma();
      break;

      case '3':
      editarDadosBolaCristal();
      pausaPrograma();
      break;

      case '4':
      consultarCigana();
      pausaPrograma();
      break;

      case '5':
      chamaTarot();
      pausaPrograma();
      break;

      case '6':
      deletaConsultor();
      pausaPrograma();

      default:
      printf("\nOpção inválida\n");
    }
  printf("\n");
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
    printf("\nPARABÉNS! VOCÊ FOI CADASTRADO COMO CONSULTOR!\n");
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

int menuListarConsultor(void){
  char opcao;
  printf("\nQual tipo de lista deseja ver?\n\n"
  "1 - Lista Normal\n"
  "2 - Lista Ordenada\n"
  "3 - Lista De Clientes Recentes\n");
  scanf(" %c",&opcao);
  return opcao;
}

void listarConsultores(void){
  system("clear||cls");
  char op;
  logoListarConsultores();
  op = menuListarConsultor();
  switch(op){
    case '1': 
      listaDiretaConsultor(); 
      break;

    case '2':
      listaOrdenadaConsultor();
      break;

    case '3': 
      listaInvertidaConsultor();
      break;

    default:
      printf("\nOpção inválida.\n");
  }
}

void listaInvertidaConsultor(void){
  system("clear||cls");
  logoListarConsultores();
  FILE* fp;
  Consultor* consu;
  NoConsultor* noConsu;
  NoConsultor* lista;

  lista = NULL;
  fp = fopen("consultores.dat", "rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado.\n");
    printf("Tente novamente mais tarde.\n");
    exit(1);
  }

  consu = (Consultor*) malloc(sizeof(Consultor));
  while(fread(consu, sizeof(Consultor), 1, fp)){
    if(consu->status == 'c'){
      noConsu = (NoConsultor*) malloc(sizeof(NoConsultor));
      strcpy(noConsu->nome, consu->nome);
      strcpy(noConsu->cpf, consu->cpf);
      noConsu->numNativo = consu->numNativo;
      strcpy(noConsu->signos, consu->signos);
      strcpy(noConsu->china, consu->china);
      noConsu->status = consu->status;
      noConsu->prox = lista;
      lista = noConsu;
    }
  }
  fclose(fp);
  exibeListaConsultor(lista);
  free(consu);
  liberaListaConsultor(lista);
}


void listaDiretaConsultor(void){
  system("clear||cls");
  logoListarConsultores();
  FILE* fp;
  Consultor* consu;
  NoConsultor* noConsu;
  NoConsultor* lista;
  NoConsultor* ult;

  lista = NULL;
  fp = fopen("consultores.dat", "rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado.\n");
    printf("Tente novamente mais tarde.\n");
    exit(1);
  }
  consu = (Consultor*) malloc(sizeof(Consultor));
  while(fread(consu, sizeof(Consultor), 1, fp)){
    if(consu->status == 'c'){
      noConsu = (NoConsultor*) malloc(sizeof(NoConsultor));
      strcpy(noConsu->nome, consu->nome);
      strcpy(noConsu->cpf, consu->cpf);
      noConsu->numNativo = consu->numNativo;
      strcpy(noConsu->signos, consu->signos);
      strcpy(noConsu->china, consu->china);
      noConsu->status = consu->status;
      noConsu->prox = NULL;
    }
    if (lista == NULL){
      lista = noConsu;
    } else{
      ult->prox = noConsu;
    }
    ult = noConsu;
  }
  fclose(fp);
  exibeListaConsultor(lista);
  free(consu);
  liberaListaConsultor(lista);
}

void listaOrdenadaConsultor(void){
  system("clear||cls");
  logoListaClientes();
  FILE* fp;
  Consultor* consu;
  NoConsultor* noConsu;
  NoConsultor* lista;

  lista = NULL;
  fp = fopen("consultores.dat", "rb");
  if(fp == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado.\n");
    printf("Tente novamente mais tarde.\n");
    exit(1);
  }
  consu = (Consultor*) malloc(sizeof(Consultor));
  while(fread(consu, sizeof(Consultor), 1, fp)){
    if(consu->status == 'c'){
      noConsu = (NoConsultor*) malloc(sizeof(NoConsultor));
      strcpy(noConsu->nome, consu->nome);
      strcpy(noConsu->cpf, consu->cpf);
      noConsu->numNativo = consu->numNativo;
      strcpy(noConsu->signos, consu->signos);
      strcpy(noConsu->china, consu->china);
      noConsu->status = consu->status;

      if (lista == NULL){
        lista = noConsu;
        noConsu->prox = NULL;
      } else if (strcmp(noConsu->nome,lista->nome) < 0) {
        noConsu->prox = lista;
        lista = noConsu;
      } else {
        NoConsultor* ant = lista;
        NoConsultor* atu = lista->prox;
        while ((atu != NULL) && strcmp(atu->nome,noConsu->nome) < 0) {
          ant = atu;
          atu = atu->prox;
        }
        ant->prox = noConsu;
        noConsu->prox = atu;
      }
    }
  }
  fclose(fp);
  exibeListaConsultor(lista);
  free(consu);
  liberaListaConsultor(lista);
}

void exibeListaConsultor(NoConsultor* lista){
    while(lista != NULL){
        printf("\nNome: %s \n", lista->nome);
        printf("CPF: %s \n",lista->cpf);
        printf("Numero Nativo: %d \n",lista->numNativo);
        printf("Signo: %s \n",lista->signos);
        printf("Horoscopo Chinês: %s \n",lista->china);
        if(lista->status == 'c'){
        printf("Consultor cadastrado normalmente\n");
        } else{
        printf("Obs: este consultor encontra-se deletado.\n");
        }
        lista = lista->prox;
    }
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

void consultarCigana(void){
  system("clear||cls");
  logoConsultarCigana();
  char procurado[15];
  int encontrado = 0;
  FILE* fp2;
  Consultor* consu;
  printf("\nDigite o seu CPF: ");
  scanf(" %15[^\n]",procurado);
  fp2 = fopen("consultores.dat","rb");
  if(fp2 == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado. Tente novamente\n");
    fclose(fp2);
  } else{
    consu = (Consultor*) malloc(sizeof(Consultor));
    while((!encontrado) && (fread(consu,sizeof(Consultor),1,fp2))){
      if(strcmp(consu->cpf,procurado) == 0 && (consu->status == 'c')){
        encontrado = 1;
      }
    }
    fclose(fp2);
    if(encontrado){
      printf("\nO seguinte consultor foi encontrado: \n");
      exibeConsultor(consu);
      previsaoDiaria(consu);

      Relatorio* rel;
      rel = (Relatorio*) malloc(sizeof(Relatorio));
      strcpy(rel->nomeUsuario,consu->nome);
      time_t mytime;
      mytime = time(NULL);
      struct tm tm = *localtime(&mytime);
      rel->dia = tm.tm_mday;
      rel->mes = tm.tm_mon + 1;
      rel->ano = tm.tm_year + 1900;
      strcpy(rel->cpfUsuario, consu->cpf);
      strcpy(rel->acao, "checou sua previsão diária");
      gravaRelatorio(rel);
      printf("\nSua previsão diária com a cigana foi registrada!\n");
      free(rel);
    } else{
      printf("\nAparentemente, você não está cadastrado na bola de cristal da cigana. Você precisa estar cadastrada nela para poder checar suas previsões.\n");
    }
  }
  free(consu);
}

void previsaoDiaria(Consultor* consu){
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  int nds;
  printf("\nCaracterísticas segundo seu número nativo: \n");
  numCarac(consu->numNativo);
  printf("\n\n");


  printf("\nCaracterísticas do seu signo: \n");
  signCarac(consu->signos);
  printf("\n\n");

  printf("\nCaracterísticas do seu animal no horóscopo chinês: \n");
  animalCarac(consu->china);
  printf("\n\n");

  nds = numDaSorte(consu->nome, consu->numNativo, 
  consu->signos, consu->china);
  nds = nds + tm.tm_mday + tm.tm_mon + 1;
  printf("Sua previsão diária: \n");
  previsao(nds);
}


void previsao(int x){
  FILE* fp5;
  int linha = 0;
  int tamLinha = 0;
  int c;

  fp5 = fopen("previsoes.txt","r");
  while((c = getc(fp5)) != EOF & linha < x){
    if(linha == x-1){
      tamLinha++;
    }
    if(c == '\n'){
      linha++;
    }
  }
  ungetc(c, fp5);
  fseek(fp5, -tamLinha, SEEK_CUR);
  char line_value[tamLinha];
  fgets(line_value, tamLinha, fp5);
  puts(line_value);
}


void deletaConsultor(void){
  system("clear||cls");
  logoDeletarConsultor();
  FILE* fp2;
  Consultor* consu;
  int encontrado = 0;
  char resp;
  char procurado[15];
  fp2 = fopen("consultores.dat","r+b");
  if(fp2 == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado. Tente novamente\n");
  }
  printf("\nDigite o CPF do consultor que deseja deletar: ");
  scanf(" %14[^\n]",procurado);
  consu = (Consultor*) malloc(sizeof(Consultor));
  while((!encontrado) && (fread(consu,sizeof(Consultor),1,fp2))){
    if((strcmp(consu->cpf,procurado) == 0) && (consu->status == 'c')){
      encontrado = 1;
    }
  }
  if(encontrado){
    exibeConsultor(consu);
    printf("Deseja realmente excluir este consultor? [S/N] ");
    scanf(" %c",&resp);
    if(resp == 's' || resp == 'S'){
      consu->status = 'x';
      fseek(fp2,(-1)*sizeof(Consultor),SEEK_CUR);
      fwrite(consu,sizeof(Consultor),1,fp2);
      printf("\nO consultor foi removido da bola de cristal da cigana...\n");
    } else{
      printf("\nAção interrompida\n");
    }

  } else{
    printf("\nAparentemente, nenhum consultor com este CPF está cadastrado");
  }
  free(consu);
  fclose(fp2);
}

void relatorios(void){
  system("clear||cls");
  FILE* fp3;
  Relatorio* rel;
  logoRelatorios();
  rel = (Relatorio*) malloc(sizeof(Relatorio));
  fp3 = fopen("relatorios.dat","rb");
  if(fp3 == NULL){
    printf("\nOps! Aparentemente o arquivo 'relatorios.dat' não foi encontrado. Tente novamente\n");
  } else{
    while(fread(rel, sizeof(Relatorio), 1, fp3)){
      exibeRelatorio(rel);
    }
  }
  free(rel);
  fclose(fp3);
}

void exibeRelatorio(Relatorio* rel){
  printf("\n====Atividade no dia %d/%d/%d====",rel->dia, rel->mes, rel->ano);
  printf("\nO usuário %s, CPF: %s %s. \n\n",rel->nomeUsuario, rel->cpfUsuario, rel->acao);
}

void creditos(void){
  printf("===========\n"
  "|| SOBRE ||\n"
  "===========\n"
  "\n"
  "Desenvolvido por: \n"
  "Danrley Daniel\n"
  "GITHUB: https://github.com/danrleydaniel\n"
  "EMAIL: danrleydaniel21@gmail.com\n"
  "\n"
  "Hiago Roque\n"
  "GITHUB: https://github.com/hiagor1\n"
  "EMAIL: medeiroshiago70@gmail.com \n"
  "\n"
  "Sob orientação do professor Flavius Gorgônio\n"
  "\n"
  "Programa desenvolvido para a disciplina de Programação, do curso Sistemas de Informação (CERES - UFRN, Caicó, 2019).\n"
  "\n"
  "Créditos das ASCII Arts usadas no projeto para os sites:\n"
  "https://asciiart.website\n"
  "https://www.asciiart.eu\n"
  "http://www.ascii-art.de\n"
  "https://ascii.co.uk\n\n"
  "Créditos pelos scans das cartas de tarot:"
  "http://askthecards.info/\n"
  );
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

void gravaRelatorio(Relatorio* rel){
  FILE* fp3;
  fp3 = fopen("relatorios.dat","ab");
  if(fp3 == NULL){
    printf("\nOps! Aparentemente o arquivo 'relatorios.dat' não foi encontrado. Tente novamente\n");
  }
  fwrite(rel, sizeof(Relatorio), 1, fp3);
  fclose(fp3);
}

void limparArquivos(void){
  int diaDoMes;
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  diaDoMes = tm.tm_mon + 1;
  if(diaDoMes == 1){
    exclusaoFisicaUsuarios();
    exclusaoFisicaConsultores();
  } else{
    printf("\n");
  }
}

void exclusaoFisicaUsuarios(void){
  Usuario* usu;
  FILE* fp;
  FILE* fp4;
  fp = fopen("usuarios.dat","rb");
  fp4 = fopen("backup.dat","wb");
  if(fp == NULL || fp4 == NULL){
    printf("\nUm dos arquivos não foi encontrado ou não existe.\n");
    fclose(fp);
    fclose(fp4);
  } else{
    usu = (Usuario*) malloc(sizeof(Usuario));
    while(fread(usu,sizeof(Usuario),1,fp)){
      if(usu->status == 'c'){
        fwrite(usu,sizeof(Usuario),1,fp4);
      }
    }
    free(usu);
    fclose(fp);
    fclose(fp4);
    fp4 = fopen("backup.dat","rb");
    fp = fopen("usuarios.dat","wb");
    usu = (Usuario*) malloc(sizeof(Usuario));
    while(fread(usu,sizeof(Usuario),1,fp4)){
      fwrite(usu,sizeof(Usuario),1,fp);
    }
    free(usu);
    fclose(fp);
    fclose(fp4);
  }
}

void exclusaoFisicaConsultores(void){
  Consultor* consu;
  FILE* fp2;
  FILE* fp4;
  fp2 = fopen("consultores.dat","rb");
  fp4 = fopen("backup.dat","wb");
  if(fp2 == NULL || fp4 == NULL){
    printf("\nUm dos arquivos não foi encontrado ou não existe\n");
    fclose(fp2);
    fclose(fp4);
  } else{
    consu = (Consultor*) malloc(sizeof(Consultor));
    while(fread(consu,sizeof(Consultor),1,fp2)){
      if(consu->status == 'c'){
        fwrite(consu,sizeof(Consultor),1,fp4);
      }
    }
    free(consu);
    fclose(fp2);
    fclose(fp4);
    fp4 = fopen("backup.dat","rb");
    fp2 = fopen("consultores.dat","wb");
    consu = (Consultor*) malloc(sizeof(Consultor));
    while(fread(consu,sizeof(Consultor),1,fp4)){
      fwrite(consu,sizeof(Consultor),1,fp2);
    }
    free(consu);
    fclose(fp2);
    fclose(fp4);
  }
}

void chamaTarot(void){
  system("clear||cls");
  logoTarotDiario();
  int nds, dia, mes;
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  dia = tm.tm_mday;
  mes = tm.tm_mon + 1;
  char procurado[15];
  int encontrado = 0;
  FILE* fp2;
  Consultor* consu;
  printf("\nDigite o seu CPF: ");
  scanf(" %15[^\n]",procurado);
  fp2 = fopen("consultores.dat","rb");
  if(fp2 == NULL){
    printf("\nOps! Aparentemente o arquivo 'consultores.dat' não foi encontrado. Tente novamente\n");
    fclose(fp2);
  } else{
    consu = (Consultor*) malloc(sizeof(Consultor));
    while((!encontrado) && (fread(consu,sizeof(Consultor),1,fp2))){
      if(strcmp(consu->cpf,procurado) == 0 && (consu->status == 'c')){
        encontrado = 1;
      }
    }
    fclose(fp2);
    if(encontrado){
      nds = numDaSorte(consu->nome, consu->numNativo, consu->signos, consu->china);
      nds = nds + dia + mes;
      Tarot(nds);

      Relatorio* rel;
      rel = (Relatorio*) malloc(sizeof(Relatorio));
      strcpy(rel->nomeUsuario,consu->nome);
      time_t mytime;
      mytime = time(NULL);
      struct tm tm = *localtime(&mytime);
      rel->dia = tm.tm_mday;
      rel->mes = tm.tm_mon + 1;
      rel->ano = tm.tm_year + 1900;
      strcpy(rel->cpfUsuario, consu->cpf);
      strcpy(rel->acao, "checou seu tarot diário");
      gravaRelatorio(rel);
    }
  }
}
