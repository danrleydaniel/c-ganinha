/* BIBLIOTECA RESPONSÁVEL PELOS CADASTROS E VALIDAÇÕES DE INFORMAÇÕES DADAS PELO USUÁRIO */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "cadastrosevalidacoes.h"
#include "menuscgana.h"

void pausaPrograma(void){
  printf("\nDigite ENTER para continuar\n");
  getchar();
  getchar();
}

int chartoint(char c){
    return c - '0';
}

char inttochar(int n){
  return n + 48;
}

int numDaSorte(char* n, int num, char* s, char* c){
  return strlen(n) + num + strlen(s) + strlen(c);
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


    if (num == 11 || num == 22){
      numf = num;
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

int validaEmail(char* email) {

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
    return 0;
}

void ariesCarac(void){
  printf("\n");
  printf("   .-.   .-.\n");
  printf("  (_  \\ /  _)    \n");
  printf("       |\n");
  printf("       |\n");
  printf("\n");
  printf("\nÁRIES - CARACTERÍSTICAS\n");
  printf("\n  * Tendem a ser impacientes");
  printf("\n  * São pessoas alegres");
  printf("\n  * Sinceridade, pra você, é tudo");
  printf("\n  * Nada de repetição, nem indecisão\n");
}

void touroCarac(void){
  printf("\n");
  printf("    .     .\n");
  printf("    '.___.'\n");
  printf("    .'   `.\n");
  printf("   :       :\n");
  printf("   :       :\n");
  printf("    `.___.'\n");
  printf("\n");
  printf("\n TOURO - CARACTERÍSTICAS\n");
  printf("\n  * Pessoa muito possessiva");
  printf("\n  * Teimoso, mas realista");
  printf("\n  * Construtivo, determinado, forte");
  printf("\n  * Apegado às pessoas\n");
}

void gemeosCarac(void){
  printf("\n");
  printf("    ._____.\n");
  printf("      | |  \n");
  printf("      | |\n");
  printf("     _|_|_\n");
  printf("    '     '\n");
  printf("\n");
  printf("\nGÊMEOS - CARACTERÍSTICAS\n");
  printf("\n  * Indeciso");
  printf("\n  * Inquieto");
  printf("\n  * Criativo e comunicativo");
  printf("\n  * Razão acima da emoção\n");
}

void cCarac(void){
  printf("\n");
  printf("      .--.\n");
  printf("     /   _`.     \n");
  printf("    (_) ( )\n");
  printf("   '.    /\n");
  printf("     `--'\n");
  printf("\n");
  printf("\nCANCER - CARACTERÍSTICAS\n");
  printf("\n  * Contraditórios");
  printf("\n  * Adaptável");
  printf("\n  * Transparente");
  printf("\n  * Resistente a mudança\n");
}

void leaoCarac(void){
  printf("\n");
  printf("      .--.\n");
  printf("     (    )\n");
  printf("    (_)  /\n");
  printf("        (_,\n");
  printf("\n");
  printf("LEÃO - CARACTERÍSTICAS\n\n");
  printf("  * Autoritário\n");
  printf("  * Dominador\n");
  printf("  * Ardente nas paixões\n");
  printf("  * Benevolente\n\n");
}

void virgemCarac(void){
  printf("\n");
  printf("  ' `:--.--.\n");
  printf("     |  |  |\n");
  printf("     |  |  | )\n");
  printf("     |  |  |/\n");
  printf("          (J\n");
  printf("\n");
  printf("VIRGEM - CARACTERÍSTICAS\n\n");
  printf("  * Dedicado\n");
  printf("  * Racional\n");
  printf("  * Exigente\n");
  printf("  * Organizado\n\n");
}

void libraCarac(void){
  printf("\n");
  printf("        __\n");
  printf("   ___.'  '.___\n");
  printf("   ____________\n");
  printf("\n");
  printf("LIBRA - CARACTERÍSTICAS\n\n");
  printf("  * Simpático\n");
  printf("  * Observador\n");
  printf("  * Delicado\n");
  printf("  * Extrovertido\n\n");
}

void escorpiaoCarac(void){
  printf("\n");
  printf("   _\n"
  "  ' `:--.--.\n"
  "     |  |  |\n"
  "     |  |  |\n"
  "     |  |  |  ..,\n"
  "           `---':\n"
  "\n"
  "ESCORPIÃO - CARACTERÍSTICAS\n\n"
  "  * Independente\n"
  "  * Inteligente\n"
  "  * Extremista\n"
  "  * Emotivo\n\n");
}

void sagiCarac(void){
  printf("\n");
  printf("          ...\n"
  "          .':\n"
  "        .'\n"
  "    `..'\n"
  "    .'`.\n"
  "\n"
  "SAGITÁRIO - CARACTERÍSTICAS\n\n"
  "  * Simpático\n"
  "  * Estudioso\n"
  "  * Honesto\n"
  "  * Otimista\n\n");
}

void capricornioCarac(void){
  printf("\n");
  printf("            _\n"
  "    \\      /_)\n"
  "     \\    /`.\n"
  "      \\  /   ;\n"
  "       \\/ __.'\n"
  "\n"
  "CAPRICÓRNIO - CARACTERÍSTICAS\n\n"
  "  * Personalidade marcante\n"
  "  * Sabichão\n"
  "  * Responsável\n"
  "  * Disciplinado\n\n");
}

void aquarioCarac(void){
  printf("\n");
  printf(" .-\"-._.-\"-._.-\n"
  " .-\"-._.-\"-._.-\n"
  "\n"
  "AQUÁRIO - CARACTERÍSTICAS\n\n"
  "  * Excêntrico\n"
  "  * Idealista\n"
  "  * Humanitário\n"
  "  * Vive no mundo da lua\n\n");
}

void peixesCarac(void){
  printf("\n");
  printf("   `-.    .-'\n"
  "      :  :\n"
  "    --:--:--\n"
  "      :  :\n"
  "   .-'    `-.\n"
  "\n"
  "PEIXES - CARACTERÍSTICAS\n\n"
  "  * Temeroso\n"
  "  * Gentil\n"
  "  * Sábio\n"
  "  * Confiante em si e nas outras pessoas\n\n");
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
  printf("\n");
  printf(" _  _\n"
  "(o)(o)--.\n"
  " \\../ (  )\n"
  " m\\/m--m'`--.\n"
  "\n"
  "RATO - CARACTERÍSTICAS\n\n"
  "  * Grande importância para a família\n"
  "  * Trabalhador e ambicioso\n"
  "  * Gosto refinado e requintado\n"
  "  * Apaixonado e sentimental\n"
  "\n");
}

void boiCarac(void){
  printf("\n");
  printf("             (__)    \n"
  "     `\\------(oo)\n"
  "       ||    (__)\n"
  "       ||---||\n"
  "\n"
  "BOI - CARACTERÍSTICAS\n\n"
  "  * Vigoroso e robusto\n"
  "  * Muito inteligente e bem informado\n"
  "  * Apegado às tradições e valores morais\n"
  "  * Amante dos prazeres que a vida proporciona\n"
  "\n");
}

void tigreCarac(void){
  printf("\n");
  printf("     (^\\-==-/^)\n"
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
  "TIGRE - CARACTERÍSTICAS\n\n"
  "  * Grande força física e mental\n"
  "  * Admirado pelos amigos\n"
  "  * Líder nato\n"
  "  * Extremamente competitivo\n"
  "\n");
}

void coelhoCarac(void){
  printf("\n");
  printf("     \\\\\n"
  "      \\\\_\n"
  "      ( _\\\n"
  "      / \\__\n"
  "     / _/`\"`\n"
  "    {\\  )_\n"
  "      `\"\"\"`\n"
  "\n"
  "COELHO - CARACTERÍSTICAS\n\n"
  "  * Estabelece fortes laços com os amigos\n"
  "  * O mais introvertido do zodíaco\n"
  "  * Defende os mais injustiçados\n"
  "  * Meigo, delicado e sentimental\n"
  "\n");
}

void dragaoCarac(void){
  printf("\n");
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
  "DRAGÃO - CARACTERÍSTICAS\n\n"
  "  * Personalidade magnética, extravagante e teatral\n"
  "  * Bastante generoso\n"
  "  * Dotado de uma inteligência excepcional\n"
  "  * Fogoso e sensual\n"
  "\n" );
}

void cobraCarac(void){
  printf("\n");
  printf("                           ____\n"
  "  ________________________/ O  \\___/\n"
  " <_/_\\_/_\\_/_\\_/_\\_/_\\_/_______/   \\\n"
  "\n"
  "COBRA - CARACTERÍSTICAS\n\n"
  "  * Curioso e ávido de conhecimento\n"
  "  * Calmo, inteligente e de lucidez perfeita\n"
  "  * Interesse por assuntos esotéricos\n"
  "  * Gosta de ficar no comando\n"
  "\n");
}

void cavaloCarac(void){
  printf("\n");
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
  "CAVALO - CARACTERÍSTICAS\n\n"
  "  * Porte altivo e caráter nobre\n"
  "  * É muito curioso\n"
  "  * Leal, amoroso e simpático\n"
  "  * Gosta de se dedicar aos menos favorecidos\n"
  "\n");
}

void cabraCarac(void){
  printf("\n");
  printf("       _))\n"
  "      > *\\     _~\n"
  "      `;'\\\\__-' \\_\n"
  "         | )  _ \\ \\\n"
  "        / / ``   w w\n"
  "       w w\n"
  "OVELHA - CARACTERÍSTICAS\n\n"
  "  * Cheio de amigos\n"
  "  * Precisa sempre se sentir apoiado e protegido\n"
  "  * Doce, sensível e um pouquinho frágil\n"
  "  * Instável, sempre propício a mudar de ideias\n"
  "\n");
}

void macacoCarac(void){
  printf("\n");
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
  "MACACO - CARACTERÍSTICAS\n\n"
  "  * Adora popularidade\n"
  "  * Intelectual, de uma cultura geral impressionante\n"
  "  * Inventivo, criativo e entusiasta\n"
  "  * Sempre pronto para ajudar os amigos\n"
  "\n");
}

void galoCarac(void){
  printf("\n");
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
  "GALO - CARACTERÍSTICAS\n\n"
  "  * Gosta de ser venerado, um pouco egocêntrico\n"
  "  * Orgulhoso e determinado\n"
  "  * Não se assusta com responsabilidades\n"
  "  * Um companheiro muito leal\n"
  "\n");
}

void caoCarac(void){
  printf("\n");
  printf("                            __\n"
  "     ,                    ,\" e`--o\n"
  "    ((                   (  | __,'\n"
  "     \\\\~----------------' \\_;/\n"
  "     (                      /\n"
  "     /) ._______________.  )\n"
  "    (( (               (( (\n"
  "     ``-'               ``-'\n"
  "CACHORRO - CARACTERÍSTICAS\n\n"
  "  * Dá valor à fidelidade e lealdade\n"
  "  * Idealista e tolerante\n"
  "  * Receia cometer qualquer injustiça\n"
  "  * Nem pense em enganá-lo!\n"
  "\n");
}

void porcoCarac(void){
  printf("\n");
  printf("        __,---.__\n"
  "     ,-'         `-.__\n"
  "   &/           `._\\ _\\\n"
  "   /               ''._\n"
  "   |   ,             (\")\n"
  "   |__,'`-..--|__|--''\n"
  "\n"
  "PORCO - CARACTERÍSTICAS\n\n"
  "  * Gentil, generoso e tolerante\n"
  "  * Odeia confrontos, gosta de viver em harmonia\n"
  "  * É bastante erudito, gosta de ler e estudar\n"
  "  * Apesar de sua natureza pura, não é ingênuo\n"
  "\n");
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

int Tarot(int num){
    srand(num);
    num = (rand() % 23);

    if (num == 0 || num == 22)
    {
        TheFoolCard();
        return 0;
    }
    else if (num == 1)
    {
        TheMagicianCard();
        return 0;
    }
    else if (num == 2)
    {
        TheHighPriestessCard();
        return 0;
    }
    else if (num == 3)
    {
        TheEmpressCard();
        return 0;
    }
    else if (num == 4)
    {
        TheEmperorCard();
        return 0;
    }
    else if (num == 5)
    {
        TheHierophantCard();
        return 0;
    }
    else if (num == 6)
    {
        TheLoversCard();
        return 0;
    }
    else if (num == 7)
    {
        TheChariotCard();
        return 0;
    }
    else if (num == 8)
    {
        StrengthCard();
        return 0;
    }
    else if (num == 9)
    {
        TheHermitCard();
        return 0;
    }
    else if (num == 10)
    {
        TheWheelOfFortuneCard();
        return 0;
    }
    else if (num == 11)
    {
        JusticeCard();
        return 0;
    }
    else if (num == 12)
    {
        TheHangedManCard();
        return 0;
    }
    else if (num == 13)
    {
        DeathCard();
        return 0;
    }
    else if (num == 14)
    {
        TemperanceCard();
        return 0;
    }
    else if (num == 15)
    {
        TheDevilCard();
        return 0;
    }
    else if (num == 16)
    {
        TheTowerCard();
        return 0;
    }
    else if (num == 17)
    {
        TheStarCard();
        return 0;
    }
    else if (num == 18)
    {
        TheMoonCard();
        return 0;
    }
    else if (num == 19)
    {
        TheSunCard();
        return 0;
    }
    else if (num == 20)
    {
        JudgementCard();
        return 0;
    }
    else if (num == 21)
    {
        TheWorldCard();
        return 0;
    }
}

void carac1(void){
    printf("\n");
    printf("Nativo 1:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Positivismo\n"
    "  * Criatividade\n"
    "  * Pionerismo\n"
    "  * Coragem\n"
    "  * Independêcia\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Prepotência\n"
    "  * Autoritarismo\n"
    "  * Agressividade\n"
    "  * Orgulhoso\n"
    "  * Preguiça\n\n");
}

void carac2(void){
    printf("\n");
    printf("Nativo 2:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Paciêcia\n"
    "  * Solidárismo\n"
    "  * Companheirismo\n"
    "  * Amável\n"
    "  * Diplomata\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Dualidade\n"
    "  * Indecisão\n"
    "  * Timidez\n"
    "  * Passividade\n"
    "  * Submissão\n\n");
}

void carac3(void){
    printf("\n");
    printf("Nativo 3:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Otimismo\n"
    "  * comunicação\n"
    "  * Sociável\n"
    "  * Coldial\n"
    "  * Entusiasmo\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Exibicionismo\n"
    "  * Supercialidade\n"
    "  * Imaturidade\n"
    "  * Ostentação\n"
    "  * Dispersão\n\n");
}

void carac4(void){
    printf("\n");
    printf("Nativo 4:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Lealdade\n"
    "  * Diciplina\n"
    "  * Honestidade\n"
    "  * Dedicação\n"
    "  * Confiança\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Crítico\n"
    "  * Insegurânça\n"
    "  * Avareza\n"
    "  * Conformista\n"
    "  * Inlfexível\n\n");
}

void carac5(void){
    printf("\n");
    printf("Nativo 5:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Empreendedorismo\n"
    "  * Versátilidade\n"
    "  * Sensualidade\n"
    "  * Curiosidade\n"
    "  * Inteligência\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Inrresponsabilidade\n"
    "  * Inquietação\n"
    "  * Infidelidade\n"
    "  * Impulsividade\n"
    "  * Ansiedade\n\n");
}

void carac6(void){
    printf("\n");
    printf("Nativo 6:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Equilíbrio\n"
    "  * Organização\n"
    "  * Honestidade\n"
    "  * Solidariedade\n"
    "  * Tolerância\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Preguiça\n"
    "  * Vitimísmo\n"
    "  * Espírito de mártir\n"
    "  * Inconformista\n"
    "  * Rancoroso(a)\n\n");
}

void carac7(void){
    printf("\n");
    printf("Nativo 7:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Tranquilidade\n"
    "  * Sabedoria\n"
    "  * Meticulosidade\n"
    "  * Perfeccionismo\n"
    "  * Autocontrole\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Melancolismo\n"
    "  * Criticismo\n"
    "  * Exigente\n"
    "  * Solitário(a)\n"
    "  * Confiança em excesso\n\n");
}

void carac8(void){
    printf("\n");
    printf("Nativo 8:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Liderança\n"
    "  * Justiça\n"
    "  * Honestidade\n"
    "  * Perseverança\n"
    "  * Compreensivos\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Ambiciosidade\n"
    "  * Materialismo\n"
    "  * Arrogancia\n"
    "  * Autoritáriedade\n"
    "  * Impaciência\n\n");
}

void carac9(void){
    printf("\n");
    printf("Nativo 9:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Paciencia\n"
    "  * Generosidade\n"
    "  * Espiritualidade\n"
    "  * Amigáveis\n"
    "  * Carinhoso(a)\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Fanatismo\n"
    "  * Solitário(a)\n"
    "  * Intimidação\n"
    "  * Abuso emocional\n"
    "  * Arrependimento\n\n");
}

void carac11(void){
    printf("\n");
    printf("Nativo 11:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Idealismo\n"
    "  * Paciência\n"
    "  * Sabedoria\n"
    "  * Humanitarismo\n"
    "  * Simpatia\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Fanatismo\n"
    "  * Charlatanismo\n"
    "  * Pragmastismo\n"
    "  * Cinismo\n"
    "  * Desonestidade\n\n");
}

void carac22(void){
    printf("\n");
    printf("Nativo 22:\n"
    "Caracteristicas positivas:\n"
    "\n"
    "  * Generosidade\n"
    "  * Esforçado(a)\n"
    "  * Sagacidade\n"
    "  * Otimismo\n"
    "  * Lealdade\n"
    "\n"
    "Caracteristicas negativas:\n"
    "\n"
    "  * Vaidade\n"
    "  * Complexo de inferioridade\n"
    "  * Cinismo\n"
    "  * Criticismo\n"
    "  * Inlfexível\n\n");
}


void TheFoolCard(void){
    printf("\n");
    printf("\nCarta O Tolo Caracteristicas");
    printf("\n");
    printf("Ás vezes na vida é necessário retornamos para o ponto de partida, o novo ciclo e esta é a energia da carta do Tarot o Louco.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Impetuosidade\n"
    "  * Vontade de viver\n"
    "  * Entusiasmo temporário\n"
    "  * Integridade\n"
    "  * Otimismo\n\n"
    "Pontos negativos:\n\n"
    "  * Imprudência\n"
    "  * Falta de paciência\n"
    "  * Precipitação\n\n"
    );
    printf("\n");
    system("display English/0the_fool.jpg");
}

void TheMagicianCard(void){
    printf("\n");
    printf("\nCarta O Mago Caracteristicas");
    printf("\n");
    printf("Possui as ferramentas necessárias para desbravar um universo desconhecido de possibilidades.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Força de vontade\n"
    "  * Conhecimento\n"
    "  * Esperteza\n\n"
    "Pontos negativos:\n\n"
    "  * Ilusão\n"
    "  * Falta de controle\n\n"
    );
    printf("\n");
    system("display English/1the_magician.jpg");
}

void TheHighPriestessCard(void){
    printf("\n");
    printf("\nCarta A Papisa Caracteristicas");
    printf("\n");
    printf("Indica a sabedoria e a paciência de saber ouvir para poder concluir.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Preparo\n"
    "  * Intuição\n"
    "  * Resignação\n"
    "  * fé\n"
    "  * Sabedoria\n"
    "  * Piedade\n\n"
    "Pontos negativos:\n\n"
    "  * Medo do novo\n"
    "  * Evolução lenta\n\n"
    );
    printf("\n");
    system("display English/2the_high_priestess.jpg");
}

void TheEmpressCard(void){
    printf("\n");
    printf("\nCarta A Imperatriz Caracteristicas");
    printf("\n");
    printf("Poder de solução de problemas e melhora de qualquer situação.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Estabilidade\n"
    "  * Beleza\n"
    "  * Riqueza\n"
    "  * Intuição\n"
    "  * Sabedoria\n\n"
    "Pontos negativos:\n\n"
    "  * Intrigas\n"
    "  * Desavenças\n\n"
    );
    printf("\n");
    system("display English/3the_empress.jpg");
}

void TheEmperorCard(void){
    printf("\n");
    printf("\nCarta O Emperador Caraxteristicas");
    printf("\n");
    printf("Representa uma pessoa extremamente intransigente, dominador e soberano.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Organização\n"
    "  * Respeito\n"
    "  * Orientação\n"
    "  * Proteção\n"
    "  * Cautela\n\n"
    "Pontos negativos:\n\n"
    "  * Ser reprimido\n"
    "  * Ser rebaixado\n\n"
    );
    printf("\n");
    system("display English/4the_emperor.jpg");
}

void TheHierophantCard(void){
    printf("\n");
    printf("\nCarta O Sacerdote Caraxteristicas");
    printf("\n");
    printf("Conexão do poder e da sabedoria divina com o mundo humano.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Justiça\n"
    "  * Ordem\n"
    "  * Organização\n"
    "  * Lealdade\n"
    "  * Amizade\n\n"
    "Pontos negativos:\n\n"
    "  * Indecisão\n\n"
    );
    printf("\n");
    system("display English/5the_hierophant.jpg");
}

void TheLoversCard(void){
    printf("\n");
    printf("Carta Os Enamorados Caracteristicas:\n");
    printf("\n");
    printf("Representa oportunidades, benefícios e possíveis ofertas em sua vida neste momento.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Familiar\n"
    "  * União\n"
    "  * Dúvidas\n"
    "  * Desejos\n\n"
    "Pontos negativos:\n\n"
    "  * Medo de errar\n"
    "  * Pressão externa\n"
    "  * Tensão\n\n"
    );
    printf("\n");
    system("display English/6the_lovers.jpg");
}

void TheChariotCard(void){
    printf("\n");
    printf("Carta A Carruagem Caracteristicas:\n");
    printf("\n");
    printf("Representa um período de grande afeto e proteção, que pode trazer grandes e intensas atividades.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Viajante\n"
    "  * Dedicação\n"
    "  * Honra\n"
    "  * Motivação\n"
    "  * Movimento\n"
    "  * Mudanças\n"
    "  * Visão dos caminhos\n"
    "  * Decisão\n"
    "  * Determinação\n"
    "  * Coragem\n"
    "  * Planejamento\n\n"
    "Pontos negativos:\n\n"
    "  * Alvo de oportunistas\n"
    "  * Ambição\n"
    "  * Orgulho\n"
    "  * Ser manipulado facilmente\n\n"
    );
    system("display English/7the_chariot.jpg");
}

void StrengthCard(void){
    printf("\n");
    printf("Carta Força Caracteristicas:\n");
    printf("\n");
    printf("Controle sobre as paixões, o amor e a eficiência das conquistas.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Coragem\n" 
    "  * Domínio emocional\n"
    "  * Força visceral\n"
    "  * Superação\n" 
    "  * Ímpeto\n"
    "  * Segurança\n"
    "  * Realização\n\n"
    "Pontos negativos:\n\n"
    "  * Agressividade\n"
    "  * Impaciência\n\n"
    );
    printf("\n");
    system("display English/8strength.jpg");
}

void TheHermitCard(void){
    printf("\n");
    printf("Carta Eremita Caracteristicas:\n");
    printf("\n");
    printf("Ensina a desligar a mente e aproveitar o silêncio para obter iluminação e autoconhecimento.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Iluminação\n" 
    "  * Sabedoria\n"
    "  * Autoconhecimento\n"
    "  * Prudência\n"
    "  * Concentração\n\n"
    "Pontos negativos:\n\n"
    "  * Solidão\n\n"
    );
    printf("\n");
    system("display English/9the_hermit.jpg");
}

void TheWheelOfFortuneCard(void){
    printf("\n");
    printf("Carta Roda Da Fortuna Caracteristicas:\n");
    printf("\n");
    printf("simboliza riqueza, imediatamente conclui-se que o consulente será alvo de ganhos materiais e prosperidade.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Recompensas\n" 
    "  * Boa sorte\n"
    "  * Ciclo da vida\n\n"
    "Pontos negativos:\n\n"
    "  * Recompensas\n"
    "  * Má sorte\n"
    "  * Ciclo da vida\n\n"
    );
    printf("\n");
    system("display English/10the_wheel_of_fortune.jpg");
}

void JusticeCard(void){
    printf("\n");
    printf("Carta Justiça Caracteristicas:\n");
    printf("\n");
    printf("Ela pede que tenha sabedoria e saiba pensar com cautela nas suas tomadas de decisões.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Autoconhecimento\n" 
    "  * Clareza\n"
    "  * Sabedoria\n"
    "  * Karma\n\n"
    "Pontos negativos:\n\n"
    "  * Más interpretações\n"
    "  * Karma\n\n"
    );
    printf("\n");
    system("display English/11justice.jpg");
}

void TheHangedManCard(void){
    printf("\n");
    printf("Carta O Enforcado Caracteristicas:\n");
    printf("\n");
    printf("Não faça nada sem ponderar, sem observar, sem pensar.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Força física e espiritual\n"
    "  * Atenção\n"
    "  * Paciência\n\n"
    "Pontos negativos:\n\n"
    "  * Incertaza\n"
    "  * Cansaço\n\n"
    );
    printf("\n");
    system("display English/12the_hanged_man.jpg");
}

void DeathCard(void){
    printf("\n");
    printf("Carta Morte Caracteristicas:\n");
    printf("\n");
    printf("Ela não simboliza perder a vida e sim, uma transformação gigante.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Renascimento\n"
    "  * Amadurecimento\n"
    "  * Energia de superação\n\n"
    "Pontos negativos:\n\n"
    "  * Covardia\n"
    "  * Se prender ao passado\n\n"
    );
    printf("\n");
    system("display English/13death.jpg");
}

void TemperanceCard(void){
    printf("\n");
    printf("Carta Temeperança Caracteristicas:\n");
    printf("\n");
    printf("A Temperança traz a conexão com o mundo espiritual.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Renovação\n"
    "  * Equilíbrio\n"
    "  * Espírito\n"
    "  * Razão\n"
    "  * Emoção\n\n" 
    "Pontos negativos:\n\n"
    "  * Facilmente persuadido(a)\n"
    "  * Tenta agradar a todos\n\n"
    );
    printf("\n");
    system("display English/14temperance.jpg");
}

void TheDevilCard(void){
    printf("\n");
    printf("Carta O Diabo Caracteristicas:\n");
    printf("\n");
    printf("O poder e ambição unidos te levará aos diversos aspectos que poderão definir o seu futuro.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Fertilidade\n"
    "  * Ambição\n"
    "  * Desejo\n"
    "  * Audácia\n"
    "  * Paixão\n\n" 
    "Pontos negativos:\n\n"
    "  * Luxúria\n"
    "  * Ambição\n"
    "  * Cobiça\n\n"
    );
    system("display English/15the_devil.jpg");
}

void TheTowerCard(void){
    printf("\n");
    printf("Carta A Torre Caracteristicas:\n");
    printf("\n");
    printf("Uma força exterior te fará abandonar o seu conforto\n\n");
    printf("Pontos positivos:\n\n"
    "  * Amadurecimento\n"
    "  * Ciclo\n\n"
    "Pontos negativos:\n\n"
    "  * Teimosia\n\n"
    );
    system("display English/16the_tower.jpg");
}

void TheStarCard(void){
    printf("\n");
    printf("Carta A Estrela Caracteristicas:\n");
    printf("\n");
    printf("Traz o poder da orientação para a conquista dos objetivos.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Verdade e realidade\n"
    "  * Equilíbrio\n"
    "  * Inspiração\n"
    "  * Busca por orientação\n"
    "  * Alcance de desejos\n"
    "  * Renovação\n"
    "  * Sucesso\n"
    "  * Esperança\n"
    "  * Brilho\n"
    "  * Perfeição\n\n"
    "Pontos negativos:\n\n"
    "  * Passa dos limites\n"
    "  * Se cobra demais\n\n"
    );
    system("display English/17the_star.jpg");
}

void TheMoonCard(void){
    printf("\n");
    printf("Carta A Lua Caracteristicas:\n");
    printf("\n");
    printf("Conecta ao Universo de coisas escondidas que podem existir nos mais diversos processos.\n\n");
    printf("Pontos positivos:\n\n"
    "  * Simbolismo\n"
    "  * Sabedoria intelectual\n"
    "  * Conhecimento instintivo\n\n"
    "Pontos negativos:\n\n"
    "  * Receio\n"
    "  * Medo\n"
    "  * Insegurança\n\n"
    );
    system("display English/18the_moon.jpg");
}

void TheSunCard(void){
    printf("\n");
    printf("Carta O Sol Caracteristicas:\n");
    printf("\n");
    printf("É a hora de encontrar esclarecimentos à todas as dúvidas que te perseguiram e firmar com você mesmo o compromisso de empenho para conquista..\n\n");
    printf("Pontos positivos:\n\n"
    "  * Brilho\n"
    "  * Sucesso\n"
    "  * Glória\n"
    "  * Alegria\n"
    "  * Intuição\n"
    "  * Vitalidade\n"
    "  * Razão\n\n"
    "Pontos negativos:\n\n"
    "  * Orgulho\n"
    "  * Confusão\n\n"
    );
    system("display English/19the_sun.jpg");
}

void JudgementCard(void){
    printf("\n");
    printf("Carta Julgamento Caracteristicas:\n");
    printf("\n");
    printf("Renovação e novas oportunidades surgindo. Por outro lado tudo o que foi plantado no passado será colhido nos dias atuais.\n");
    printf("Pontos positivos:\n\n"
    "  * Organização\n"
    "  * Estratégia\n"
    "  * Crítica\n"
    "  * Curiosidade\n\n"
    "Pontos negativos:\n\n"
    "  * Infame\n"
    "  * Chateação\n\n"
    );
    system("display English/20judgement.jpg");
}

void TheWorldCard(void){
    printf("\n");
    printf("Carta O Mundo Caracteristicas:\n");
    printf("\n");
    printf("Coroação para quem sempre se empenhou muito e se dedicou em cada quesito da vida.\n");
    printf("Pontos positivos:\n\n"
    "  * Autoconhecimento\n"
    "  * Sucesso\n"
    "  * Plenitude\n"
    "  * Coquistas\n"
    "  * Boa vida\n"
    "  * Realização\n"
    "  * Virtuosidade\n"
    "  * Efeitos benéficos\n\n"
    "Pontos negativos:\n\n"
    "  * Nenhum\n\n"
    );
    system("display English/21the_world.jpg");
}
