#include <stdio.h>
#include "MyLIB.h"

#define MINDOBAS 1
#define MAXDOBAS 6
#define DOBASSZAM 10

int minDobas(int osszes[]){
	int min, i;
	min = MAXDOBAS+1;
	
	for(i = 0; i < (DOBASSZAM*3); i++){
		if(min > osszes[i]){
			min = osszes[i];
		}
	}
	
	return min;
}

void atlagosDobas(int diak[], float atlag, int diakszam){
	int i;

	printf("\n\nAz %d. diak dobasai: ", diakszam);
	for(i = 0; i < DOBASSZAM; i++){
		if(i==(DOBASSZAM-1)){
			printf("%d.", diak[i]);
		} else {
			printf("%d, ", diak[i]);
		}
	}
	printf("\nAz %d. diak dobasainak atlaga: %.2f.", diakszam, atlag);
	
}

float atlagDiak(int diak[], int n){
	int i, osszeg = 0;
	float atlag;
	
	for(i = 0; i < DOBASSZAM; i++){
		osszeg = osszeg + diak[i];
	}
	
	atlag = (float) osszeg / (float) DOBASSZAM;
	
	return (atlag);
}

int main(void){
	int n, m, o;
	int diak1[DOBASSZAM], diak2[DOBASSZAM], diak3[DOBASSZAM];
	int i;
	float atlag1, atlag2, atlag3;
	
	printf("A dobasokban 3 tanulo vesz reszt.\nMind a 3-an 10 alkalommal dobnak egy szabalyos dobokockaval.\nA dobokocka 1-6-ig adhat ertekeket.");
	
	rndintarr(MINDOBAS, MAXDOBAS, diak1, DOBASSZAM);
	rndintarr(MINDOBAS, MAXDOBAS, diak2, DOBASSZAM);
	rndintarr(MINDOBAS, MAXDOBAS, diak3, DOBASSZAM);
	
	atlag1 = atlagDiak(diak1, DOBASSZAM);
	atlag2 = atlagDiak(diak2, DOBASSZAM);
	atlag3 = atlagDiak(diak3, DOBASSZAM);
	
	// 1. feldat
	int min;
	
	atlagosDobas(diak1, atlag1, 1);
	atlagosDobas(diak2, atlag2, 2);
	atlagosDobas(diak3, atlag3, 3);
	
	//2. feladat
	int osszesitett[DOBASSZAM*3];
	int osszHossz = 0;
	
	for(i = 0; i < DOBASSZAM; i++){
		osszesitett[osszHossz] = diak1[i];
		osszHossz++;
	}
	
	for(i = 0; i < DOBASSZAM; i++){
		osszesitett[osszHossz] = diak2[i];
		osszHossz++;
	}
	
	for(i = 0; i < DOBASSZAM; i++){
		osszesitett[osszHossz] = diak3[i];
		osszHossz++;
	}
	
	min = minDobas(osszesitett);
	
	printf("\n\nA jatek soran elert legkisebb dobas a(z) %d.", min);
	
	return (0);
}