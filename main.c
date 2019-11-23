#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "cadastrosevalidacoes.h"
#include "menuscgana.h"

int main(){
  limparArquivos();
  char opcao;
  opcao = mainMenu();
  
  while(opcao != '0'){
    switch(opcao){
      case '1':
      menuClientes();
      break;
      
      case '2':
      menuPrevisoes();
      break;
      
      case '3':
      relatorios();
      pausaPrograma();
      break;
      
      case '4':
      creditos();
      pausaPrograma();
      break;
      
      default:
      printf("\nOpção inválida\n");
		}
  printf("\nO que deseja fazer agora? \n");
  opcao = mainMenu();
  }
  return 0;
}
