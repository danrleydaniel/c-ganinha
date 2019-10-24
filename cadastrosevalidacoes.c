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
      if (num == 11 || num == 22){
        return numf = num;
      }
      else if (num == 10){
        numf = (num - 9);
        return numf;
      }	
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
  int tam = strlen(email);
  int arroba = 0, ponto = 0, Aponto = 0, Dponto = 0, i;

  for (i = 0; i < tam; i++){
    char c = email[i];

    if(c == '@'){
      if (arroba)
        break;
      arroba = 1;
      if (i < 3)
        break;
    }
    else if (arroba){ 
      if (ponto){ 
        Dponto++;
      }
      else if (c == '.'){
        ponto = 1;
        if (Aponto < 3){
          break;
        }
      }
      else{
        Aponto++;
      }
    }
  } 

  if (i == tam && Dponto > 1)
    return 1;
  else
    return 0;;
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

void ratoCarac(void){
  printf(" _  _\n"
  "(o)(o)--.\n"
  " \\../ (  )\n"
  " m\\/m--m'`--.\n"
  "\n"
  "RATO - CARACTERÍSTICAS\n"
  "  * Grande importância para a família\n"
  "  * Trabalhador e ambicioso\n"
  "  * Gosto refinado e requintado\n"
  "  * Apaixonado e sentimental\n"
  "");
}

void boiCarac(void){
  printf("             (__)    \n"
  "     `\\------(oo)\n"
  "       ||    (__)\n"
  "       ||---||\n"
  "\n"
  "BOI - CARACTERÍSTICAS\n"
  "  * Vigoroso e robusto\n"
  "  * Muito inteligente e bem informado\n"
  "  * Apegado às tradições e valores morais\n"
  "  * Amante dos prazeres que a vida proporciona\n"
  "");
}

void tigreCarac(void){
  printf("    (^\\-==-/^)\n"
  "     >\\\\ == //<\n"
  "    :== q''p ==:     _\n"
  "     .__ qp __.    .' )\n"
  "      / ^--^ \\    /\\.'\n"
  "     /_`    / )  '\\/\n"
  "     (  )  \\  |-'-/\n"
  "     \\^^,   |-|--'\n"
  "    ( `'    |_| )\n"
  "     \\-     |-|/\n"
  "    (( )^---( ))\n"
  "\n"
  "TIGRE - CARACTERÍSTICAS\n"
  "  * Grande força física e mental\n"
  "  * Admirado pelos amigos\n"
  "  * Líder nato\n"
  "  * Extremamente competitivo\n"
  "");
}

void coelhoCarac(void){
  printf("  \\\\\n"
  "      \\\\_\n"
  "      ( _\\\n"
  "      / \\__\n"
  "     / _/`\"`\n"
  "    {\\  )_\n"
  "      `\"\"\"`\n"
  "\n"
  "COELHO - CARACTERÍSTICAS\n"
  "  * Estabelece fortes laços com os amigos\n"
  "  * O mais introvertido do zodíaco\n"
  "  * Defende os mais injustiçados\n"
  "  * Meigo, delicado e sentimental\n"
  "");
}

void dragaoCarac(void){
  printf("                \\||/\n"
"                |  @___oo\n"
"      /\\  /\\   / (__,,,,|\n"
"     ) /^\\) ^\\/ _)\n"
"     )   /^\\/   _)\n"
"     )   _ /  / _)\n"
" /\\  )/\\/ ||  | )_)\n"
"<  >      |(,,) )__)\n"
" ||      /    \\)___)\\\n"
" | \\____(      )___) )___\n"
"  \\______(_______;;; __;;; \n"
  "\n"
  "DRAGÃO - CARACTERÍSTICAS\n"
  "  * Personalidade magnética, extravagante e teatral\n"
  "  * Bastante generoso\n"
  "  * Dotado de uma inteligência excepcional\n"
  "  * Fogoso e sensual\n"
  "" );
}

void cobraCarac(void){
  printf("                           ____\n"
  "  ________________________/ O  \\___/\n"
  " <_/_\\_/_\\_/_\\_/_\\_/_\\_/_______/   \\\n"
  "\n"
  "COBRA - CARACTERÍSTICAS\n"
  "  * Curioso e ávido de conhecimento\n"
  "  * Calmo, inteligente e de lucidez perfeita\n"
  "  * Interesse por assuntos esotéricos\n"
  "  * Gosta de ficar no comando\n"
  "");
}

void cavaloCarac(void){
  printf("                   ;;\n"
  "                 ,;;'\\\n"
  "      __       ,;;' ' \\\n"
  "    /'  '\\'~~'~' \\ /'\\.)\n"
  " ,;(      )    /  |\n"
  ",;' \\    /-.,,(   )\n"
  "     ) /       ) /\n"
  "    //         ||\n"
  "   (_\\         (_\\\n"
  "\n"
  "CAVALO - CARACTERÍSTICAS\n"
  "  * Porte altivo e caráter nobre\n"
  "  * É muito curioso\n"
  "  * Leal, amoroso e simpático\n"
  "  * Gosta de se dedicar aos menos favorecidos\n"
  "");
}

void cabraCarac(void){
  printf("       _))\n"
  "      > *\\     _~\n"
  "      `;'\\\\__-' \\_\n"
  "         | )  _ \\ \\\n"
  "        / / ``   w w\n"
  "       w w\n"
  "OVELHA - CARACTERÍSTICAS\n"
  "  * Cheio de amigos\n"
  "  * Precisa sempre se sentir apoiado e protegido\n"
  "  * Doce, sensível e um pouquinho frágil\n"
  "  * Instável, sempre propício a mudar de ideias\n"
  "");
}

void macacoCarac(void){
  printf("           .\"`\".\n"
  "       .-./ _=_ \\.-.\n"
  "      {  (,(oYo),) }}\n"
  "      {{ |   \"   |} }\n"
  "      { { \\(---)/  }}\n"
  "      {{  }'-=-'{ } }\n"
  "      { { }._:_.{  }}\n"
  "      {{  } -:- { } }\n"
  "      {_{ }`===`{  _}\n"
  "     ((((\\)     (/))))\n"
  "\n"
  "MACACO - CARACTERÍSTICAS\n"
  "  * Adora popularidade\n"
  "  * Intelectual, de uma cultura geral impressionante\n"
  "  * Inventivo, criativo e entusiasta\n"
  "  * Sempre pronto para ajudar os amigos\n"
  "");
}

void galoCarac(void){
  printf("   ,~.\n"
  "   ,-'__ `-,\n"
  "  {,-'  `. }              ,')\n"
  " ,( a )   `-.__         ,',')~,\n"
  "<=.) (         `-.__,==' ' ' '}\n"
  "  (   )                      /)\n"
  "   `-'\\   ,                    )\n"
  "       |  \\        `~.        /\n"
  "       \\   `._        \\      /\n"
  "        \\     `._____,'    ,'\n"
  "         `-.             ,'\n"
  "            `-._     _,-'\n"
  "                77jj'\n"
  "               //_||\n"
  "            __//--'/`          \n"
  "          ,--'/`  '\n"
  "\n"
  "GALO - CARACTERÍSTICAS\n"
  "  * Gosta de ser venerado, um pouco egocêntrico\n"
  "  * Orgulhoso e determinado\n"
  "  * Não se assusta com responsabilidades\n"
  "  * Um companheiro muito leal\n"
  "");
}

void caoCarac(void){
  printf("                            __\n"
  "     ,                    ,\" e`--o\n"
  "    ((                   (  | __,'\n"
  "     \\\\~----------------' \\_;/\n"
  "     (                      /\n"
  "     /) ._______________.  )\n"
  "    (( (               (( (\n"
  "     ``-'               ``-'\n"
  "CACHORRO - CARACTERÍSTICAS\n"
  "  * Dá valor à fidelidade e lealdade\n"
  "  * Idealista e tolerante\n"
  "  * Receia cometer qualquer injustiça\n"
  "  * Nem pense em enganá-lo!\n"
  "");
}

void porcoCarac(void){
  printf("        __,---.__\n"
  "     ,-'         `-.__\n"
  "   &/           `._\\ _\\\n"
  "   /               ''._\n"
  "   |   ,             (\")\n"
  "   |__,'`-..--|__|--''\n"
  "\n"
  "PORCO - CARACTERÍSTICAS\n"
  "  * Gentil, generoso e tolerante\n"
  "  * Odeia confrontos, gosta de viver em harmonia\n"
  "  * É bastante erudito, gosta de ler e estudar\n"
  "  * Apesar de sua natureza pura, não é ingênuo\n"
  "");
}

void animalCarac(char* a){
  if(strcmp(a, "Rato") == 0)
    ratoCarac();
  else if(strcmp(a, "Boi") == 0)
    boiCarac();
  else if(strcmp(a, "Tigre") == 0)
    tigreCarac();
  else if(strcmp(a, "Lebre") == 0)
    coelhoCarac();
  else if(strcmp(a, "Dragão") == 0)
    dragaoCarac();
  else if(strcmp(a, "Cobra") == 0)
    cobraCarac();
  else if(strcmp(a, "Cavalo") == 0)
    cavaloCarac();
  else if(strcmp(a, "Ovelha") == 0)
    cabraCarac();
  else if(strcmp(a, "Macaco") == 0)
    macacoCarac();
  else if(strcmp(a, "Galo") == 0)
    galoCarac();
  else if(strcmp(a, "Cão") == 0)
    caoCarac();
  else if(strcmp(a, "Porco") == 0)
    porcoCarac();
}

void numCarac(int numf){
    if (numf == 1)
        carac1();
    else if (numf == 2)
        carac2();
    else if (numf == 3)
        carac3();
    else if (numf == 4)
        carac4();
    else if (numf == 5)
        carac5();
    else if (numf == 6)
        carac6();
    else if (numf == 7)
        carac7();
    else if (numf == 8)
        carac8();
    else if (numf == 9)
        carac9();
    else if (numf == 11)
        carac11();
    else if (numf == 22)
        carac22();
}

void carac1(void){
    printf("Nativo 1:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Positivismo\n"
    "Criatividade\n"
    "Pionerismo\n"
    "Coragem\n"
    "Independêcia\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Prepotência\n"
    "Autoritarismo\n"
    "Agressividade\n"
    "Orgulhoso\n"
    "Preguiça\n");
}

void carac2(void){
    printf("Nativo 2:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Paciêcia\n"
    "Solidárismo\n"
    "Companheirismo\n"
    "Amável"
    "Diplomata"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Dualidade\n"
    "Indecisão\n"
    "Timidez\n"
    "Passividade\n"
    "Submissão\n");
}

void carac3(void){
    printf("Nativo 3:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Otimismo\n"
    "comunicação\n"
    "Sociável\n"
    "Coldial\n"
    "Entusiasmo\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Exibicionismo\n"
    "Supercialidade\n"
    "Imaturidade\n"
    "Ostentação\n"
    "Dispersão\n");
}

void carac4(void){
    printf("Nativo 4:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Lealdade\n"
    "Diciplina\n"
    "Honestidade\n"
    "Dedicação\n"
    "Confiança\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Crítico\n"
    "Insegurânça\n"
    "Avareza\n"
    "Conformista\n"
    "Inlfexível\n");
}

void carac5(void){
    printf("Nativo 5:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Empreendedorismo\n"
    "Versátilidade\n"
    "Sensualidade\n"
    "Curiosidade\n"
    "Inteligência\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Inrresponsabilidade\n"
    "Inquietação\n"
    "Infidelidade\n"
    "Impulsividade\n"
    "Ansiedade\n");
}

void carac6(void){
    printf("Nativo 6:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Equilíbrio\n"
    "Organização\n"
    "Honestidade\n"
    "Solidariedade\n"
    "Tolerância\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Preguiça\n"
    "Vitimísmo\n"
    "Espírito de mártir\n"
    "Inconformista\n"
    "Rancoroso(a)\n");
}

void carac7(void){
    printf("Nativo 7:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Tranquilidade\n"
    "Sabedoria\n"
    "Meticulosidade\n"
    "Perfeccionismo\n"
    "Autocontrole\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Melancolismo\n"
    "Criticismo\n"
    "Exigente\n"
    "Solitário(a)\n"
    "Confiança em excesso\n");
}

void carac8(void){
    printf("Nativo 8:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Liderança\n"
    "Justiça\n"
    "Honestidade\n"
    "Perseverança\n"
    "Compreensivos\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Ambiciosidade\n"
    "Materialismo\n"
    "Arrogancia\n"
    "Autoritáriedade\n"
    "Impaciência\n");
}

void carac9(void){
    printf("Nativo 9:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Paciencia\n"
    "Generosidade\n"
    "Espiritualidade\n"
    "Amigáveis\n"
    "Carinhoso(a)\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Fanatismo\n"
    "Solitário(a)\n"
    "Intimidação\n"
    "Abuso emocional\n"
    "Arrependimento\n");
}

void carac11(void){
    printf("Nativo 11:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Idealismo\n"
    "Paciência\n"
    "Sabedoria\n"
    "Humanitarismo\n"
    "Simpatia\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Fanatismo\n"
    "Charlatanismo\n"
    "Pragmastismo\n"
    "Cinismo\n"
    "Desonestidade\n");
}

void carac22(void){
    printf("Nativo 22:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "Generosidade\n"
    "Esforçado(a)\n"
    "Sagacidade\n"
    "Otimismo\n"
    "Lealdade\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "Vaidade\n"
    "Complexo de inferioridade\n"
    "Cinismo\n"
    "Criticismo\n"
    "Inlfexível\n");
}

