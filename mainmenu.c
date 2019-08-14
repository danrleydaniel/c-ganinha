int main(){
	int opcao;
  logotipoPrincipal();
	opcao = mainMenu();
	
	while(opcao != 0){
	switch(opcao){
		case 1:
    menuClientes();
		break;
		
		case 2:
		menuPrevisoes();
		break;
		
		case 3:
		creditos();
		break;
		
		default:
		printf("\nOpção inválida\n");
	}
	printf("\nO que deseja fazer agora? \n");
	opcao = mainMenu();
	}
}
