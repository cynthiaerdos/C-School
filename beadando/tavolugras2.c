#include <stdio.h>

int main(void) {

int sorszam, rajtszam, rajtszam_hiba;
int eredmeny, eredmeny_hiba, regi_eredmeny, ujra;

sorszam = 0;
rajtszam_hiba = 0;
eredmeny_hiba = 0;


		while(0 == 0){
		
			if (rajtszam_hiba == 1) {
				printf("Hiba! Nem 1 es 20 kozotti rajtszam lett megadva!");
			}
		
		printf("\nKerem adja meg a(z) %d. versenyzo rajtszamat 1 es 20 kozott: ", sorszam+1);
		scanf("%d", &rajtszam);
		
			if (rajtszam < 0 || rajtszam > 20) {
				rajtszam_hiba = 1;
			} else {
				rajtszam_hiba = 0;
				
						
						ujra == 0;
						
						if (eredmeny_hiba == 1) {
							printf("Hiba! Nem 0.0 es 10.0 kozotti eredmeny lett megadva!");
						}
					
					printf("\nKerem adja meg a(z) %d. versenyzo eredmenyet 0.0 es 10.0 kozott: ", sorszam+1);
					scanf("%d", &eredmeny);
					
						if (eredmeny < 0.0 || eredmeny > 10.0) {
							eredmeny_hiba = 1;
						} else {
							eredmeny_hiba = 0;
							sorszam++;
							if (rajtszam == 0){
								return (0);
							}
						}
					}
			}
		
		}
	

	
	return (0);
}