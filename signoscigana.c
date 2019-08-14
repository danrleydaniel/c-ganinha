#include <stdio.h>
#include <stdlib.h>

char * signo(int dia, int mes, int ano){
  if (((mes==3) && (dia>=21)) || ((mes==4) && (dia<=20))){
    return "Aries \n";
  } else if (((mes==4) && (dia>=21 && dia<=30)) || ((mes==5) && (dia<=20))){
    return "Touro \n";
  } else if (((mes==5) && (dia>=21)) || ((mes==6) && (dia<=20))){
    return "Gemeos \n";
  } else if (((mes==6) && (dia>=21 && dia<=30)) || ((mes==7) && (dia<=21))){
    return "Cancer \n";
  } else if (((mes==7) && (dia>=22)) || ((mes==8) && (dia<=22))){
    return "Leão \n";
  } else if (((mes==8) && (dia>=23)) || ((mes==9) && (dia<=22))){
    return "Virgem \n";
  } else if (((mes==9) && (dia>=23 && dia<=30)) || ((mes==10) && (dia<=22))){
    return "Libra \n";
  } else if (((mes==10) && (dia>=23)) || ((mes==11) && (dia<=21))){
    return "Escorpião \n";
  } else if (((mes==11) && (dia>=22 && dia<=30)) || ((mes==12) && (dia<=21))){
    return "Sagitário \n";
  } else if (((mes==12) && (dia>=22)) || ((mes==1) && (dia<=20))){
    return "Capricórnio \n";
  } else if (((mes==1) && (dia>=21)) || ((mes==2) && (dia<=19))){
    return "Aquário \n";
  } else if (((mes==2) && (dia>=20 && dia<=29)) || ((mes==3) && (dia<=20))){
    return "Peixes \n";
  } else{
    return "Erro \n";
  }
}

int main(void){
  int dia, mes, ano;
  printf("Digite uma data: (dia/mês/ano) ");
  scanf("%d/%d/%d",&dia, &mes, &ano);
  printf("O signo é...\n");
  printf("%s", signo(dia, mes, ano));
}
