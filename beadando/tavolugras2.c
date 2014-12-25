#include <stdio.h>

int main(void) {

int sorszam, rajtszam, max_rajtszam, min_rajtszam;
float eredmeny, max_eredmeny, min_eredmeny, atlag_eredmeny, osszeg_eredmeny;

	sorszam = 0;
	max_eredmeny = -1;
	min_eredmeny = 11;
	osszeg_eredmeny = 0;

	while(0 == 0){
	
		printf("\nKerem adja meg a(z) %d. versenyzo rajtszamat 1 es 20 kozott: ", sorszam+1);
		scanf("%d", &rajtszam);

		if (rajtszam < 0 || rajtszam > 20) {
			printf("Hiba! Nem 1 es 20 kozotti rajtszam lett megadva!");
			return (0);
		} else if (rajtszam == 0){
			if (max_eredmeny == -1){
				printf("Nem lett versenyzo megadva!");
				return (0);
			}
			printf("\nA legjobb ugrast a %d. rajtszamu versenyzo ugrotta %fm-es eredmennyel!",max_rajtszam , max_eredmeny);
			printf("\nA legrosszabb ugrast a %d. rajtszamu versenyzo ugrotta %fm-es eredmennyel!",min_rajtszam , min_eredmeny);
			printf("\nA versenyzok atlagosan %fm-t ugrottak!", atlag_eredmeny);
			return (0);
		
		}
		printf("Kerem adja meg a(z) %d. versenyzo eredmenyet 0.0 es 10.0 kozott: ", sorszam+1);
		scanf("%f", &eredmeny);

		if (eredmeny < 0.0 || eredmeny > 10.0) {
			printf("Hiba! Nem 0.0 es 10.0 kozotti eredmeny lett megadva!");
			return (0);
			
		}
		
		if (max_eredmeny < eredmeny){
			max_eredmeny = eredmeny;
			max_rajtszam = rajtszam;
		}
		
		if (min_eredmeny > eredmeny){
			min_eredmeny = eredmeny;
			min_rajtszam = rajtszam;
		}
		
		osszeg_eredmeny = osszeg_eredmeny + eredmeny;
		atlag_eredmeny = osszeg_eredmeny / (sorszam+1);
		
		
		sorszam++;
	}
return (0);
}