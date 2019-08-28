#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void logotipoPrincipal(void);
int mainMenu(void);
int menuClientes(void);
int menuPrevisoes(void);
void creditos(void);
void cdCliente(void);
int numerologia(int, int, int);
char * horoscopo(int);
char * signo(int, int, int);
int bissexto(int);
int dataValida(int, int, int);
int validaCpf(char *);
int validaEmail(char *);





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

void logotipoPrincipal(void){
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
	printf("3 - SOBRE\n");
	printf("0 - FECHAR PROGRAMA\n");
	scanf("%d", &opcao);
	return opcao;
}

int menuClientes(void){
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
      cdCliente();
      sleep(30);
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

int menuPrevisoes(void){
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
     sleep(5);
      break;

      case 2:
      printf("Em breve.\n");
     // consultarCorDaSorte();
     sleep(5);
      break;

      case 3:
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

void cdCliente(void){
    system("clear");

    char nome[50], email[40], cpf[15];
    int dia, mes, ano, numNativo;
    char* signos;
    char* china;

    printf("Digite seu primeiro nome: ");
    scanf("%s", &nome[0]);
    
    
    printf("\nDigite sua data de nascimento: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    while(!(dataValida(dia, mes, ano))){
    	printf("\nData inválida. Digite novamente: ");
    	scanf("%d/%d/%d", &dia, &mes, &ano);
    }

    
    printf("\nDigite seu email: ");
    scanf("%s", &email[0]);
    
    while(!(validaEmail(email))){
    	printf("Email inválido. Digite novamente: ");
    	scanf("%s", &email[0]);
    }
    	

	printf("\nDigite o seu CPF: ");
	scanf("%s",&cpf[0]);
	
    while(!(validaCpf(cpf))){
    	printf("CPF inválido. Digite novamente: ");
    	scanf("%s",&cpf[0]);
    }
    	

    signos = signo(dia,mes,ano);
    china = horoscopo(ano);
    numNativo = numerologia(dia, mes, ano);

    printf("\n\nDados do usuário: \n");
    printf("\nNome: %s",nome);
    printf("\nData de nascimento: %d/%d/%d", dia,mes,ano);
    printf("\nEmail: %s",email);
    printf("\nCPF: %s",cpf);
    printf("\nSigno: %s",signos);
    printf("\nAnimal no horóscopo chinês: %s",china);
    printf("\nVocê é nativo do número %d\n",numNativo);
    printf("\n\nAguarde... O programa voltará ao Menu Clientes automaticamente. Enquanto isso, confira seus dados.");
    printf("\n");
}

int numerologia(int dia, int mes, int ano){

	int calc1, num;
    int  diaf=0, mesf=0, anof=0, numf=0, calc1f=0;

     if (ano < 0)
        ano *= -1;
    while (ano){
        anof += ano%10;
        ano/=10;
    }

     if (dia < 0)
        dia *= -1;
    while (dia){
        diaf += dia%10;
        dia/=10;
    }

     if (mes < 0)
        mes *= -1;
    while (mes){
        mesf += mes%10;
        mes/=10;
    }

     calc1 = (diaf + mesf);
    if (calc1 < 0)
        calc1 *= -1;
    while (calc1){
        calc1f += calc1%10;
        calc1/=10;
    }

     num = (anof + calc1f);
    if (num < 0)
        num *= -1;
    while (num){
        numf += num%10;
        num/=10;
    }
    return numf;
}

char * horoscopo(int ano){
	int anoRato = 1960;
	int anoBoi = 1961;
	int anoTigre = 1962;
	int anoLebre = 1963;
	int anoDragao = 1964;
	int anoCobra = 1965;
	int anoCavalo = 1966;
	int anoOvelha = 1967;
	int anoMacaco = 1968;
	int anoGalo = 1969;
	int anoCao = 1970;
	int anoPorco = 1971;
	
	if((ano - anoRato) % 12 == 0){
		return "Rato";
	} else if((ano - anoBoi) % 12 == 0){
		return "Boi";
	} else if((ano - anoTigre) % 12 == 0){
		return "Tigre";
	} else if((ano - anoLebre) % 12 == 0){
		return "Lebre";
	} else if((ano - anoDragao) % 12 == 0){
		return "Dragão";
	} else if((ano - anoCobra) % 12 == 0){
		return "Cobra";
	} else if((ano - anoCavalo) % 12 == 0){
		return "Cavalo";
	} else if((ano - anoOvelha) % 12 == 0){
		return "Ovelha";
	} else if((ano - anoMacaco) % 12 == 0){
		return "Macaco";
	} else if((ano - anoGalo) % 12 == 0){
		return "Galo";
	} else if((ano - anoCao) % 12 == 0){
		return "Cão";
	} else if((ano - anoPorco) % 12 == 0){
		return "Porco";
	} else{
		return "Erro";
	}
}

char * signo(int dia, int mes, int ano){
  if (((mes==3) && (dia>=21)) || ((mes==4) && (dia<=20))){
    return "Aries";
  } else if (((mes==4) && (dia>=21 && dia<=30)) || ((mes==5) && (dia<=20))){
    return "Touro";
  } else if (((mes==5) && (dia>=21)) || ((mes==6) && (dia<=20))){
    return "Gemeos";
  } else if (((mes==6) && (dia>=21 && dia<=30)) || ((mes==7) && (dia<=21))){
    return "Cancer ";
  } else if (((mes==7) && (dia>=22)) || ((mes==8) && (dia<=22))){
    return "Leão";
  } else if (((mes==8) && (dia>=23)) || ((mes==9) && (dia<=22))){
    return "Virgem";
  } else if (((mes==9) && (dia>=23 && dia<=30)) || ((mes==10) && (dia<=22))){
    return "Libra";
  } else if (((mes==10) && (dia>=23)) || ((mes==11) && (dia<=21))){
    return "Escorpião";
  } else if (((mes==11) && (dia>=22 && dia<=30)) || ((mes==12) && (dia<=21))){
    return "Sagitário";
  } else if (((mes==12) && (dia>=22)) || ((mes==1) && (dia<=20))){
    return "Capricórnio";
  } else if (((mes==1) && (dia>=21)) || ((mes==2) && (dia<=19))){
    return "Aquário";
  } else if (((mes==2) && (dia>=20 && dia<=29)) || ((mes==3) && (dia<=20))){
    return "Peixes";
  } else{
    return "Erro \n";
  }
}

int bissexto(int aa) {
    //Função feita pelo professor Flavius Gorgônio.
    if ((aa % 4 == 0) && (aa % 100 != 0)) {
        return 1;
    } 
    else if (aa % 400 == 0) {
        return 1;
    } 
    else{
        return 0;
    }
}


int dataValida(int dd, int mm, int aa) {
    //Função feita pelo professor Flavius Gorgônio.
    int maiorDia;
    if (aa < 0 || mm < 1 || mm > 12){
        return 0;
    }
    if (mm == 2) {
        if (bissexto(aa)){
            maiorDia = 29;
        } 
        else{
            maiorDia = 28;
        }
    } 
    else if (mm == 4 || mm == 6 ||
    mm == 9 || mm == 11) {
        maiorDia = 30;
    } 
    else{
        maiorDia = 31;
    }
    
    if (dd < 1 || dd > maiorDia){
        return 0;
    }

    return 1;
}

int validaCpf(char * cpf){
	int tamanho = strlen(cpf);
	int i;
	int cont = 0;
	for(i = 0; i < tamanho; i++){
		char digito = cpf[i];
		if(!(isdigit(digito))){
			cont++;
		}
	}
	if(tamanho == 11){
		return 1;
	} else if(cont != 0){
		return 0;
	} else{
		return 1;
	}
}
	


int validaEmail(char * email){
  int i = 0;
  int tamanho = strlen(email);
  int cont = 0;
  for(i = 0; i < tamanho; i++){
    if(email[i] == '@'){
      cont++;
    }
  }
  if(cont != 1){
    return 0;
  } else{
    return 1;
  }
}
