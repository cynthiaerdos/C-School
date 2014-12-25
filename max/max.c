#include <stdio.h>

#define MAX_ELEM 10

int main(void) {
int n, a[MAX_ELEM];
int i, max, sorszam;

	// adatok bekerese felhasznalotol

	printf("\nElemek szama [1-10]:");
	scanf("%d", &n);

	for (i=0; i<n; i++) {
		printf("- %2d. elem erteke [10-99]: ", i+1);
		scanf("%d", &a[i]);
	}

	// legnagyobb ertek keresese

	sorszam = 0;
	max = a[sorszam];

	for (i=1; i<n; i++) {
		if (max<a[i]) {
			sorszam = i;
			max = a[i];
		}
	}

	// eredmeny kijelzese

	printf("\nA tomb %d. eleme a legnagyobb, erteke: %d!", sorszam+1, max);

	return (0);
}
