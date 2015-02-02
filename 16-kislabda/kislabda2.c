#include <stdio.h>
#include "MyLIB.h"

#define MAXTANULO 50
#define MINDOBAS 3.0
#define MAXDOBAS 50.0

#define MAXSZOVEG 128

#define LIMIT1 25.0

int main(void) {
int i, db, db1;
float dobasok[MAXTANULO], ossz1;
char szoveg[MAXSZOVEG];

        db = getint("\nTanulok szama:", 1, MAXTANULO);
	printf("\nDobaseredmenyek tanulonkent:\n");

	db25 = 0;
	ossz25 =  0.0;
        for (i=0; i<db; i++) {
		sprintf(szoveg, "- %d. tanulo dobasa", i+1);
		dobasok[i] = getfloat(szoveg, MINDOBAS, MAXDOBAS);

		if (dobasok[i]>LIMIT1) {
			ossz1 += dobasok[i];
			db1++;
		}
        }

        if (db1>0) {
        	printf("\nA %.0fm feletti dobasok atlaga: %.2fm", LIMIT1, ossz1/(float) db1);
        } else {
        	printf("\nNincs %.0fm feletti dobas!", LIMIT1);
        }
        return (0);
}
