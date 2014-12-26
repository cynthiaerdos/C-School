#include <stdio.h>

int main(void) {

int sorszam, rajtszam, max_rajtszam, min_rajtszam;
float eredmeny, max_eredmeny, min_eredmeny, atlag_eredmeny, osszeg_eredmeny;

	sorszam = 0;
	max_eredmeny = -1;
	min_eredmeny = 11;
	osszeg_eredmeny = 0;

	printf("\nUdvozlom! Ez a program egy tavolugrasi verseny eredmenyeit kezeli. Adja meg az elso versenyzo rajtszamat es a versenyen elert eredmenyet 0 es 10 meter kozott. Ezt ismetelje meg addig ahany versenyzot be szeretne 'vinni'. Majd ezutan adja meg, hogy a versenyzo rajtaszama '0' es ezutan a program megmondja, hogy melyik versenyzo teljesitett a legjobban, illetve legrosszabbul tovabba mennyit ugrottak atlagosan a versenyzok!");
	
	while(0 == 0){
	
		printf("\nKerem adja meg a(z) %d. versenyzo rajtszamat 1 es 20 kozott (vagy 0-at): ", sorszam+1);
		scanf("%d", &rajtszam);

		if (rajtszam == 0){
			if (max_eredmeny == -1){
				printf("Nem lett versenyzo megadva!");
				return (0);
			}
			printf("\nA legjobb ugrast a %d. rajtszamu versenyzo ugrotta %fm-es eredmennyel!",max_rajtszam , max_eredmeny);
			printf("\nA legrosszabb ugrast a %d. rajtszamu versenyzo ugrotta %fm-es eredmennyel!",min_rajtszam , min_eredmeny);
			printf("\nA versenyzok atlagosan %fm-t ugrottak!", atlag_eredmeny);
			return (0);
		
		}
		printf("Kerem adja meg a(z) %d. versenyzo eredmenyet meterben 0.0 es 10.0 kozott (pl. '6.28'): ", sorszam+1);
		scanf("%f", &eredmeny);

		
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