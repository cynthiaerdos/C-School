#include <stdio.h>

int main(void) {
int versenyzok;

printf("\nUdvozlom! Ez a program egy tavolugrasi verseny eredmenyeit kezeli. Elso sorban kerem adja meg, hogy a versenyen hany versenyzo vett reszt, mely minimum 1 es maximum 20 versenyzo lehet. Majd ezutan adja meg az elso versenyzo rajtszamat es a versenyen elert eredmenyet 0 es 10 meter kozott. Ezt ismetelje meg amig el nem fogynak a versenyzok. A program ezutan megmondja, hogy melyik versenyzo teljesitett a legjobban, illetve legrosszabbul tovabba mennyit ugrottak atlagosan a versenyzok!");

 // versenyzok letszamanak bekerese

versenyzok = 0;

		
printf("\nKerem adja meg a versenyzok letszamat 1 es 20 kozott: ");
scanf("%d", &versenyzok);
	
int i;
int verseny_rajtszamok[versenyzok];
float verseny_eredmenyek[versenyzok];


// tomb esetleges ertekeinek uritese

	for(i = 0 ; versenyzok > i ; i++){
		verseny_rajtszamok[i] = 0;
	}
	
	for(i = 0 ; versenyzok > i ; i++){
		verseny_eredmenyek[i] = 11;
	}

	for (i = 0 ; versenyzok > i ; i++){

			printf("\nKerem adja meg a(z) %d. versenyzo rajtszamat 1 es 20 kozott: ", i+1);
			scanf("%d", &verseny_rajtszamok[i]);
			

			printf("\nKerem adja meg a(z) %d. versenyzo eredmenyet meterben 0.0 es 10.0 kozott (pl. '6.28'): ", i+1);
			scanf("%f", &verseny_eredmenyek[i]);
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
	
	printf("\nAz ugrok atlagos ugrastavolsaga %fm.", atlag);
	
	return (0);

}