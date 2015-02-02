#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "MyLIB.h"

//
// Hibauzenet nem megfelelo adat eseten
//

void baddata(void) {

	printf("Hibas adat, adja meg ujra!");
	return;
}

//
// FLOAT adat bevitele AH-FH zart tartomanyban
//

float getfloat(char s[], float ah, float fh) {
float value;

	do {
		printf("%s [%.2f-%.2f]: ", s, ah, fh);
		scanf("%f", &value);
		if (value<ah || fh<value) { baddata(); }
	} while (value<ah || fh<value);
	return (value);
}

//
// INT adat bevitele AH-FH zart tartomanyban
//

int getint(char s[], int ah, int fh) {
int value;

	do {
		printf("%s [%d-%d]: ", s, ah, fh);
		scanf("%d", &value);
		if (value<ah || fh<value) { baddata(); }
	} while (value<ah || fh<value);
	return (value);
}

//
// Veletlen FLOAT szamok generalasa AH-FH zart tartomanyban
//

float rndfloat(float ah, float fh) {
static int f = 0;
float v;
time_t t;
	
	if (f == 0) {
		t = time(&t);
		srand((int) t);
		rand();
		f = 1;
	}

	v = (float) rand() / (float) RAND_MAX;
	v = ah + v * (fh - ah);
	return v;
}

//
// 'n' darab veletlen FLOAT szam generalasa a 'v' t”mbbe, AH-FH zart tartomanyban
//

void rndfloatarr(float ah, float fh, float v[], int n) {
int i;	

	for (i=0; i<n; i++) {
		v[i] = rndfloat(ah, fh);
	}
	return;
}

//
// 'n' darab egyedi veletlen FLOAT szam generalasa a 'v' t”mbbe, AH-FH zart tartomanyban
//

void rndfloatarrunq(float ah, float fh, float v[], int n) {
int i, j, f;
float vsz;
	
	i = 0;
	do {
		vsz = rndfloat(ah, fh);
		f = 0;
		for (j=0;j<i;j++) {
			if (v[j]==vsz) {
				f = 1;
			}
		}
		if (f==0) {
			v[i++] = vsz;
		}
	} while (i < n);
	return;
}

//
// Veletlen INT szam generalasa AH-FH zart tartomanyban
//

int rndint(int ah, int fh) {
int v;
	
	v = (int) rndfloat((float) ah, (float) fh);
	return v;
}

//
// 'n' darab veletlen INT szam generalasa a 'v' t”mbbe, AH-FH zart tartomanyban
//

void rndintarr(int ah, int fh, int v[], int n) {
int i;
	for (i=0; i<n; i=i+1) {
		v[i] = rndint(ah, fh);
	}
	return;
}

//
// 'n' darab egyedi veletlen INT szam generalasa a 'v' t”mbbe, AH-FH zart tartomanyban
//

void rndintarrunq(int ah, int fh, int v[], int n) {
int i, j;
int vsz;
	
	i = 0;
	do {
		vsz = rndint(ah, fh);
		for (j=0; j<i && v[j]!=vsz; j++) { ; }
		if (j==i) {
			v[i++] = vsz;
		}
	} while (i < n);
	return;
}
