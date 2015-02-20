#include <stdio.h>
#include "MyLIB.h"

#define MINDOBAS 1
#define MAXDOBAS 7 // 1-el nagyobb szamnak kell lennie mint a valodi maximum.
#define DOBASSZAM 10

int letezik(int dobasok[], int tombhossz, int szam){
	int i;
	
	for(i = 0; i < tombhossz; i++){
		if(szam == dobasok[i]){
			return (0);
		}
	}
	
	return (1);
}

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

int maxDobas(int osszes[]){
	int max, i;
	max = MINDOBAS-1;

	for(i = 0; i < (DOBASSZAM*3); i++){
		if(max < osszes[i]){
			max = osszes[i];
		}
	}
	
	return max;
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
	
	printf("\nA dobasokban 3 tanulo vesz reszt.\nMind a 3-an 10 alkalommal dobnak egy szabalyos dobokockaval.\nA dobokocka 1-6-ig adhat ertekeket.");
	
	rndintarr(MINDOBAS, MAXDOBAS, diak1, DOBASSZAM);
	rndintarr(MINDOBAS, MAXDOBAS, diak2, DOBASSZAM);
	rndintarr(MINDOBAS, MAXDOBAS, diak3, DOBASSZAM);
	
	atlag1 = atlagDiak(diak1, DOBASSZAM);
	atlag2 = atlagDiak(diak2, DOBASSZAM);
	atlag3 = atlagDiak(diak3, DOBASSZAM);
	
	//------------1. feldat------------
	int min;
	
	atlagosDobas(diak1, atlag1, 1);
	atlagosDobas(diak2, atlag2, 2);
	atlagosDobas(diak3, atlag3, 3);
	
	//------------2. feladat------------
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
	
	//------------3. feladat------------
	int kozos[DOBASSZAM], kozos1[DOBASSZAM], kozos2[DOBASSZAM], kozos3[DOBASSZAM];
	int a, b, c, d;
	int j, l;
	int jelzes = 0;
	
	a = b = c = d = 0;
	// 1. es 2. diak kozos dobasai
	for(i = 0; i < DOBASSZAM; i++){
		for(j = 0; j < DOBASSZAM && diak2[i]!=diak1[j]; j++){;}
		if(diak2[i]==diak1[j]){
			for(l = 0; l < b; l++){
				if(kozos1[l] == diak2[i]){
					jelzes = 1;
				}
			}
			
			if(jelzes == 0){
				kozos1[b++] = diak2[i];
			}
			
			jelzes = 0;
		}
	}
	
	// 2. es 3. diak kozos dobasai
	for(i = 0; i < DOBASSZAM; i++){
		for(j = 0; j < DOBASSZAM && diak3[i]!=diak2[j]; j++){;}
		if(diak3[i]==diak2[j]){
			for(l = 0; l < c; l++){
				if(kozos2[l] == diak3[i]){
					jelzes = 1;
				}
			}
			
			if(jelzes == 0){
				kozos2[c++] = diak3[i];
			}
			
			jelzes = 0;
		}
	}
	
	// 1. es 3. diak kozos dobasai
	for(i = 0; i < DOBASSZAM; i++){
		for(j = 0; j < DOBASSZAM && diak1[i]!=diak3[j]; j++){;}
		if(diak1[i]==diak3[j]){
			for(l = 0; l < d; l++){
				if(kozos3[l] == diak1[i]){
					jelzes = 1;
				}
			}
			
			if(jelzes == 0){
				kozos3[d++] = diak1[i];
			}
			
			jelzes = 0;
		}
	}
	
	jelzes = 0;
	
	int osszesKozos[(b+c+d)];
	int kozosHossz = 0;

	for(i = 0; i < b; i++){
		osszesKozos[kozosHossz] = kozos1[i];
		kozosHossz++;
	}
	
	for(i = 0; i < c; i++){
		osszesKozos[kozosHossz] = kozos2[i];
		kozosHossz++;
	}
	
	for(i = 0; i < d; i++){
		osszesKozos[kozosHossz] = kozos3[i];
		kozosHossz++;
	}
		
	for(i = MINDOBAS; i < MAXDOBAS+1; i++){
		if(letezik(osszesKozos, kozosHossz, i) == 0){
			kozos[a++] = i;
		}
	}
		
	//------------4. feladat------------
	
	printf("\n\nKozos dobasok: ");
	
	for(i = 0; i < a; i++){
		if(i == (a-1)){
			printf("%d.", kozos[i]);
		} else {
			printf("%d, ", kozos[i]);
		}
	}
	
	//------------5. feladat------------
	int kozosMennyiseg[DOBASSZAM*3];
	int maxDobasok[(b+c+d)];
	int cs;
	
	for(i = 0; i < DOBASSZAM*3; i++){
		kozosMennyiseg[i] = 0;
	}
	for (i=0; i<kozosHossz-1; i++) {
		for (j=i+1; j<kozosHossz; j++) {
			if (osszesKozos[i]>osszesKozos[j]) {
				cs = osszesKozos[i];
				osszesKozos[i] = osszesKozos[j];
				osszesKozos[j] = cs;
			}
		}
	}

	

	jelzes = 0;
	
	for(i = 0; i < a; i++){
		for(j = 0; j < kozosHossz; j++){
			if(kozos[i]==osszesKozos[j]){
				jelzes++;
			}
		}
		kozosMennyiseg[i] = jelzes;
		jelzes = 0;
	}
	
	int maximumDobas = maxDobas(kozosMennyiseg);

	for (i=0; kozosMennyiseg[i]!=maximumDobas; i++) { ; }
			
	int legtobbErtek = osszesKozos[i];
	
	printf("\n\nA jatek soran legtobbszor a(z) %d-es szamot dobtak.\nEzt a szamot osszesen %d alkalommal dobtak a jatek soran.\nEz az osszes dobashoz viszonyitva %.2f%%.", legtobbErtek, maximumDobas, ((float) maximumDobas/(float) DOBASSZAM)*100);

	return (0);
}