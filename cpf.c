//essa função foi encontrada lo seguinte link: 
//https://www.clubedohardware.com.br/forums/topic/1256061-validar-cpf-linguagem-c-no-dev-c/
//função feita pelo usuario Eizy para fins didáticos.

//função será melhorada ao fim do projeto c-gana.

#include <stdio.h>
int main ( )
{
int cpf2,x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9, D1 , D2;
long long CPF,cpfval,cpfvali;

printf("\nDigite o CPF: ");
scanf("%lld",&cpfvali);
printf("\nDigite o CPF: ");
scanf("%9lld",&CPF);



x1 = CPF /100000000;
x2 = (CPF/10000000)%10;
x3 = (CPF/1000000)%10;
x4 = (CPF/100000)%10;
x5 = (CPF/10000)%10;
x6 = (CPF/1000)%10;
x7 = (CPF/100)%10;
x8 = (CPF/10)%10;
x9 = CPF%10;
D1 = ((x1*10)+(x2*9)+(x3*8)+(x4*7)+(x5*6)+(x6*5)+(x7*4)+(x8*3)+(x9*2))%11;
if(D1<2)
D1 = 0;
else
{
D1 = 11 - D1;
}
D2 = ((x1*11)+(x2*10)+(x3*9)+(x4*8)+(x5*7)+(x6*6)+(x7*5)+(x8*4)+(x9*3)+(D1*2))%11;
if(D2<2)
D2=0;
else
{

D2=11 - D2;
}

cpf2 = D1*10+D2;
cpfval = CPF*100+cpf2;
if(cpfval == cpfvali)
    printf("CPF Valido:   %lld%d \n",CPF,cpf2);
else
    printf("\tINVALIDO\n Digite CPF Novamente\n\n");


return 0;
}
