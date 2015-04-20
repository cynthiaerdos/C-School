#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIP 500
#define LENIP 40
#define CSOPORT 4

char *ip[MAXIP];
int ipn;
char *csoport[] = {"2001:0db8", "2001:0e", "fc", "fd"};
char *csoportnev[] = {"Dokumentacios cim", "Globalis egyedi cim", "Helyi egyedi cim"};

void f1(void);
void f2(void);
void f3(void);
void f4(void);
void f5(void);
int tartomany(char *s);

void f1(void) {
FILE *fi;
char sor[LENIP+2];
char *p;

    puts("\n1. feladat:");
    fi = fopen("ip.txt", "r");
    if (fi) {
        ipn = 0;
        do {
            p = fgets(sor, LENIP+1, fi);
            if (p && strlen(sor)==LENIP) {
                ip[ipn] = (char *) malloc(LENIP+1);
                strcpy(ip[ipn], sor);
                ipn++;
            }
        } while (p);
        fclose(fi);
        puts("Adatok beolvasva!");
    } else {
        puts("\nFajl megnyitasi hiba!");
    }
    return;
}

void f2(void) {
    puts("\n2. feladat:");
    printf("Az allomanyban %d darab adatsor van!", ipn);
}

void f3(void){
    int ipmin;
    int i;
    ipmin = 0;

    puts("\n\n3. feladat:");

    for (i = 0; i<ipn; i++){
        if (strcmp(ip[ipmin], ip[i])>0){
            ipmin = i;
        }
    }

    puts("A legalacsonyabb tarolt IP cim:");
    puts(ip[ipmin]);

    return;
}

void f4(void){
    int i, cs;
    int sz[] = {0,0,0,0};
    printf("\n4. feladat:");
    for (i = 0; i<ipn; i++) {
        cs = tartomany(ip[i]);
        if (cs < CSOPORT) {
            sz[cs]++;
        }
    }
    sz[2] += sz[3];

    for(i=0; i<CSOPORT-1; i++) {
        printf("\n%s: %d darab.", csoportnev[i], sz[i]);
    }
    return;
}

int countZeros(char *ipLine) {
    int nullszamlalo;
    int i;

    nullszamlalo = 0;
    for (i = 0; i<LENIP; i++) {
        if (ipLine[i]=='0') {
            nullszamlalo++;
        }
    }
    return nullszamlalo;
}

void f5(void) {
    FILE *fi;
    int i;

    puts("\n\n5. feladat:");
    fi = fopen("sok.txt", "w");
    for (i = 0; i<ipn; i++) {
        if (countZeros(ip[i])>=18) {
            fprintf(fi, "%d. %s", i+1, ip[i]);
        }
    }
    fclose(fi);
    puts("Az adatok kiirasra kerultek a \"sok.txt\" allomanyba!");
    return;
}

int tartomany(char *s) {
    int i;
    for (i = 0; i<CSOPORT && strncmp(csoport[i], s, strlen(csoport[i])) != 0; i++) {
        ;
    }

    return i;

}

int main(void) {

    f1();
    f2();
    f3();
    f4();
    f5();

    return 0;
}
