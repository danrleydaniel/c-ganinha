int numerologia(int, int, int);

int main(void){
	int dia, mes, ano;
	
	
	printf("\nDigite sua data de nascimento: ");
	scanf("%d/%d/%d",&dia,&mes,&ano);
	}
	
	int numNativo = numerologia(dia, mes, ano);
	
	printf("\nVocê é nativo do número %d",numNativo);
	
	return 0;
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
