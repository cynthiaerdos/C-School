#include <stdio.h>
#include "MyLIB.h"

#define MAXTANULO 50
#define MINDOBAS   3.0
#define MAXDOBAS  50.0

#define MAXSZOVEG 128

int main(void) {
int i, db;
float dobasok[MAXTANULO];
char szoveg[MAXSZOVEG];

        db = getint("\nTanulok szama:", 1, MAXTANULO);
	printf("\nDobaseredmenyek tanulonkent:\n");
        for (i=0; i<db; i++) {
		sprintf(szoveg, "- %d. tanulo dobasa", i+1);
		dobasok[i] = getfloat(szoveg, MINDOBAS, MAXDOBAS);
        }
        return (0);
}
