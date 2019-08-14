#include <stdio.h>
#include <stdlib.h>



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



int main(){
	int ano;
	char * animal;
	while(1){
		printf("\n\nDigite seu ano de nascimento: ");
		scanf("%d",&ano);
		
		animal = horoscopo(ano);
		printf("%s",animal);
	}
	
}
