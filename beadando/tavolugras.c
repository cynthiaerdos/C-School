#include <stdio.h>

int main(void) {
int versenyzok, versenyzok_hiba;

 // versenyzok letszamanak bekerese

versenyzok = 0;
versenyzok_hiba = 0;

	while (versenyzok <= 0 || versenyzok > 20) {
		if (versenyzok_hiba == 1) {
			printf("Hiba! Nem 1 es 20 kozotti versenyzo szam lett megadva!");
		}
		
		printf("\nKerem adja meg a versenyzok letszamat 1 es 20 kozott: ");
		scanf("%d", &versenyzok);
		versenyzok_hiba = 1;
	}
	
int i;
int verseny_rajtszamok[versenyzok];
float verseny_eredmenyek[versenyzok];
int versenyzok_hiba2, versenyzok_hiba3;

versenyzok_hiba2 = 0;
versenyzok_hiba3 = 0;

// tomb esetleges ertekeinek uritese

	for(i = 0 ; versenyzok > i ; i++){
		verseny_rajtszamok[i] = 0;
	}
	
	for(i = 0 ; versenyzok > i ; i++){
		verseny_eredmenyek[i] = 11;
	}

	for (i = 0 ; versenyzok > i ; i++){
		while (verseny_rajtszamok[i] <= 0 || verseny_rajtszamok[i] > versenyzok){
		
			if (versenyzok_hiba2 == 1) {
				printf("Hiba! Nem 1 es %d kozotti rajtszam lett megadva!", versenyzok);
			}
			
			printf("\nKerem adja meg a(z) %d. versenyzo rajtszamat 1 es %d kozott: ", i+1, versenyzok);
			scanf("%d", &verseny_rajtszamok[i]);
			
			if (verseny_rajtszamok[i] <= 0 || verseny_rajtszamok[i] > versenyzok) {
				versenyzok_hiba2 = 1;
			} else {
				versenyzok_hiba2 = 0;
			}
		}
		
		while (verseny_eredmenyek[i] < 0.0 || verseny_eredmenyek[i] > 10.0){
		
			if (versenyzok_hiba3 == 1) {
				printf("Hiba! Nem 0.0 es 10.0 kozotti eredmeny lett megadva!");
			}
			
			printf("Kerem adja meg a(z) %d. versenyzo eredmenyet meterben 0.0 es 10.0: ", i+1);
			scanf("%f", &verseny_eredmenyek[i]);
			
			if (verseny_eredmenyek[i] < 0.0 || verseny_eredmenyek[i] > 10.0) {
				versenyzok_hiba3 = 1;
			} else {
				versenyzok_hiba3 = 0;
			}
		}
	}

// legjobb ugro
	
int i_max, max;
	
	
	max = 0;
	
	for(i_max=0;versenyzok>i_max;i_max++){
		if (verseny_eredmenyek[max]<verseny_eredmenyek[i_max]){
			max = i_max;
		}
	}
	
	printf("\n\nA legjobb eredmenyt ugro jatekos rajtszama: %d, eredmenye: %fm.", verseny_rajtszamok[max], verseny_eredmenyek[max]);
	
	// legrosszabbul ugro
	
	int i_min, min;
	
	
	min = 0;
	
	for(i_min=0;versenyzok>i_min;i_min++){
		if (verseny_eredmenyek[min]>verseny_eredmenyek[i_min]){
			min = i_min;
		}
	}
	
	printf("\nA legrosszabb eredmenyt ugro jatekos rajtszama: %d, eredmenye: %fm.", verseny_rajtszamok[min], verseny_eredmenyek[min]);
	
	// atlagos ugras
	
	int i_atlag;
	float osszesen, atlag;
	
	osszesen = 0.0;
	
	for (i_atlag = 0; i_atlag < versenyzok; i_atlag++){
		osszesen = osszesen + verseny_eredmenyek[i_atlag];
	}
	
	atlag = osszesen / versenyzok;
	
	printf("\nAz ugrok atlagos ugrastavolsaga %fm", atlag);
	
	return (0);
}