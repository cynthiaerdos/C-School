//
// Sajat fejlesztesu fuggvenyek
//

// Ellenorzott adatok bevitele

void baddata(void);
float getfloat(char s[], float ah, float fh);
int getint(char s[], int ah, int fh);

// Veletlenszamok generalasa

float rndfloat(float ah, float fh);
void  rndfloatarr(float ah, float fh, float v[], int n);
void  rndfloatarrunq(float ah, float fh, float v[], int n);

int   rndint(int ah, int fh);
void  rndintarr(int ah, int fh, int v[], int n);
void  rndintarrunq(int ah, int fh, int v[], int n);
