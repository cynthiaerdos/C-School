#include <stdio.h>

int main(void) {

int sorszam, rajtszam, rajtszam_hiba;
int eredmeny, eredmeny_hiba, regi_eredmeny, ujra;

	sorszam = 0;

	while(0 == 0){
	
		printf("\nKerem adja meg a(z) %d. versenyzo rajtszamat 1 es 20 kozott: ", sorszam+1);
		scanf("%d", &rajtszam);

		if (rajtszam < 0 || rajtszam > 20) {
			printf("Hiba! Nem 1 es 20 kozotti rajtszam lett megadva!");
			return (0);
		} else if (0 == 1){
		
		
		
		} else {
			
			printf("\nKerem adja meg a(z) %d. versenyzo eredmenyet 0.0 es 10.0 kozott: ", sorszam+1);
			scanf("%d", &eredmeny);

			if (eredmeny < 0.0 || eredmeny > 10.0) {
				printf("Hiba! Nem 0.0 es 10.0 kozotti eredmeny lett megadva!");
				return (0);
			}
		}
	sorszam++;
	}
return (0);
}