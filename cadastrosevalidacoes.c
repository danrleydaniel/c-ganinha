/* BIBLIOTECA RESPONSÁVEL PELOS CADASTROS E VALIDAÇÕES DE INFORMAÇÕES DADAS PELO USUÁRIO */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "cadastrosevalidacoes.h"
#include "menuscgana.h"

int chartoint(char c){
    return c - '0';
}

char inttochar(int n){
  return n + 48;
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
	
	if((ano - 1960) % 12 == 0){
		return "Rato";
	} else if((ano - 1961) % 12 == 0){
		return "Boi";
	} else if((ano - 1962) % 12 == 0){
		return "Tigre";
	} else if((ano - 1963) % 12 == 0){
		return "Lebre";
	} else if((ano - 1964) % 12 == 0){
		return "Dragão";
	} else if((ano - 1965) % 12 == 0){
		return "Cobra";
	} else if((ano - 1966) % 12 == 0){
		return "Cavalo";
	} else if((ano - 1967) % 12 == 0){
		return "Ovelha";
	} else if((ano - 1968) % 12 == 0){
		return "Macaco";
	} else if((ano - 1969) % 12 == 0){
		return "Galo";
	} else if((ano - 1970) % 12 == 0){
		return "Cão";
	} else if((ano - 1971) % 12 == 0){
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
	if(tamanho != 11){
    return 0;
  }
  else{
    int num;
    int soma1 = 0;
    char digito1, digito2;
    int j = 0;
    for(int i = 10; i >= 2; i--){
      num = chartoint(cpf[j]);
      num *= i;
      soma1 += num;
      j++;
    }
    soma1 = soma1 % 11;
    soma1 = 11 - soma1;
    if(soma1 > 9)
      soma1 = 0;
    digito1 = inttochar(soma1);
    if(digito1 != cpf[9])
      return 0;
    else{
      j = 0;
      soma1 = 0;
      for(int i = 11; i >= 2; i--){
        num = chartoint(cpf[j]);
        num *= i;
        soma1 += num;
        j++;
      }
      soma1 = soma1 % 11;
      soma1 = 11 - soma1;
      if(soma1 > 9)
        soma1 = 0;
      digito2 = inttochar(soma1);
      if(digito2 != cpf[10])
        return 0;
      else
        return 1;
    }
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

void ariesCarac(void){
  printf("   .-.   .-.\n");
  printf("  (_  \\ /  _)    \n");
  printf("       |\n");
  printf("       |\n");
  printf("\nÁRIES - CARACTERÍSTICAS");
  printf("\n   *Tendem a ser impacientes");
  printf("\n   *São pessoas alegres");
  printf("\n   *Sinceridade, pra você, é tudo");
  printf("\n   *Nada de repetição, nem indecisão");
}

void touroCarac(void){
  printf("    .     .\n");
  printf("    '.___.'\n");
  printf("    .'   `.\n");
  printf("   :       :\n");
  printf("   :       :\n");
  printf("    `.___.'\n");
  printf("");
  printf("\n TOURO - CARACTERÍSTICAS");
  printf("\n   *Pessoa muito possessiva");
  printf("\n   *Teimoso, mas realista");
  printf("\n   *Construtivo, determinado, forte");
  printf("\n   *Apegado às pessoas");
}

void gemeosCarac(void){
  printf("    ._____.\n");
  printf("      | |  \n");
  printf("      | |\n");
  printf("     _|_|_\n");
  printf("    '     '\n");
  printf("");
  printf("\nGÊMEOS - CARACTERÍSTICAS: ");
  printf("\n   *Indeciso");
  printf("\n   *Inquieto");
  printf("\n   *Criativo e comunicativo");
  printf("\n   *Razão acima da emoção");
}

void cCarac(void){
  printf("      .--.\n");
  printf("     /   _`.     \n");
  printf("    (_) ( )\n");
  printf("   '.    /\n");
  printf("     `--'\n");
  printf("Cancer-  The Crab\n");
  printf("");
  printf("CARACTERÍSTICAS:");
  printf("\n   *Contraditórios");
  printf("\n   *Adaptável");
  printf("\n   *Transparente");
  printf("\n   *Resistente a mudança");
}

void leaoCarac(void){
  printf("      .--.\n");
  printf("     (    )\n");
  printf("    (_)  /\n");
  printf("        (_,\n");
  printf("\n");
  printf("LEÃO - CARACTERÍSTICAS\n");
  printf("   *Autoritário\n");
  printf("   *Dominador\n");
  printf("   *Ardente nas paixões\n");
  printf("   *Benevolente");
}

void virgemCarac(void){
  printf("  ' `:--.--.\n");
  printf("     |  |  |\n");
  printf("     |  |  | )\n");
  printf("     |  |  |/\n");
  printf("          (J\n");
  printf("\n");
  printf("VIRGEM - CARACTERÍSTICAS\n");
  printf("   *Dedicado\n");
  printf("   *Racional\n");
  printf("   *Exigente\n");
  printf("   *Organizado");
}

void libraCarac(void){
    printf("        __\n");
    printf("   ___.'  '.___\n");
    printf("   ____________\n");
    printf("\n");
    printf("LIBRA - CARACTERÍSTICAS\n");
    printf("   *Simpático\n");
    printf("   *Observador\n");
    printf("   *Delicado\n");
    printf("   *Extrovertido");
}

void escorpiaoCarac(void){
  printf("   _\n"
  "  ' `:--.--.\n"
  "     |  |  |\n"
  "     |  |  |\n"
  "     |  |  |  ..,\n"
  "           `---':\n"
  "\n"
  "ESCORPIÃO - CARACTERÍSTICAS\n"
  "   *Independente\n"
  "   *Inteligente\n"
  "   *Extremista\n"
  "   *Emotivo");
}

void sagiCarac(void){
  printf("          ...\n"
  "          .':\n"
  "        .'\n"
  "    `..'\n"
  "    .'`.\n"
  "\n"
  "SAGITÁRIO - CARACTERÍSTICAS\n"
  "   *Simpático\n"
  "   *Estudioso\n"
  "   *Honesto\n"
  "   *Otimista");
}

void capricornioCarac(void){
  printf("            _\n"
  "    \\      /_)\n"
  "     \\    /`.\n"
  "      \\  /   ;\n"
  "       \\/ __.'\n"
  "\n"
  "CAPRICÓRNIO - CARACTERÍSTICAS\n"
  "   *Personalidade marcante\n"
  "   *Sabichão\n"
  "   *Responsável\n"
  "   *Disciplinado");
}

void aquarioCarac(void){
  printf(" .-\"-._.-\"-._.-\n"
  " .-\"-._.-\"-._.-\n"
  "\n"
  "AQUÁRIO - CARACTERÍSTICAS\n"
  "   *Excêntrico\n"
  "   *Idealista\n"
  "   *Humanitário\n"
  "   *Vive no mundo da lua");
}

void peixesCarac(void){
  printf("   `-.    .-'\n"
  "      :  :\n"
  "    --:--:--\n"
  "      :  :\n"
  "   .-'    `-.\n"
  "\n"
  "PEIXES - CARACTERÍSTICAS\n"
  "   *Temeroso\n"
  "   *Gentil\n"
  "   *Sábio\n"
  "   *Confiante em si e nas outras pessoas");
}

void signCarac(char* s){
  if(strcmp(s,"Aries") == 0)
    ariesCarac();
  else if(strcmp(s,"Touro") == 0)
    touroCarac();
  else if(strcmp(s,"Gemeos") == 0)
    gemeosCarac();
  else if(strcmp(s,"Cancer ") == 0)
    cCarac();
  else if(strcmp(s,"Leão") == 0)
    leaoCarac();
  else if(strcmp(s,"Virgem") == 0)
    virgemCarac();
  else if(strcmp(s,"Libra") == 0)
    libraCarac();
  else if(strcmp(s,"Escorpião") == 0)
    escorpiaoCarac();
  else if(strcmp(s,"Sagitário") == 0)
    sagiCarac();
  else if(strcmp(s,"Capricórnio") == 0)
    capricornioCarac();
  else if(strcmp(s,"Aquário") == 0)
    aquarioCarac();
  else if(strcmp(s,"Peixes") == 0)
    peixesCarac();
}
