#include <stdio.h>
#include "MyLIB.h"

#define MAXTANULO 50
#define MINDOBAS 3.0
#define MAXDOBAS 50.0

#define MAXSZOVEG 128

#define LIMIT1 25.0
#define LIMIT2 40.0

int main(void) {
int i, db, db1, db2;
float dobasok[MAXTANULO], ossz1, dobasok2[MAXTANULO];
char szoveg[MAXSZOVEG];

        db = getint("\nTanulok szama:", 1, MAXTANULO);
	printf("\nDobaseredmenyek tanulonkent:\n");

	db1 = db2 = 0;
	ossz1 =  0.0;
        for (i=0; i<db; i++) {
		sprintf(szoveg, "- %d. tanulo dobasa", i+1);
		dobasok[i] = getfloat(szoveg, MINDOBAS, MAXDOBAS);

		if (dobasok[i]>LIMIT1) {
			ossz1 += dobasok[i];
			db1++;
		}

		if (dobasok[i]>LIMIT2) {
			dobasok2[db2++] = dobasok[i];
		}
        }

        if (db1>0) {
        	printf("\nA %.0fm feletti dobasok atlaga: %.3fm", LIMIT1, ossz1/(float) db1);
        } else {
        	printf("\nNincs %.0fm feletti dobas!", LIMIT1);
        }

        if (db2>0) {
	        printf("\nA %.0fm feletti dobasok:", LIMIT2);
        	for (i=0; i<db2; i++) {
	        	printf("\n- %.3fm", dobasok2[i]);
        	}
        } else  {
        	printf("\nNincs %.0fm feletti dobas!", LIMIT2);
        }

        return (0);
}
