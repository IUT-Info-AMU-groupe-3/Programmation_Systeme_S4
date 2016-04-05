#include <stdio.h>

typedef void (*PAppFunc)(void *dest, void **ppElem);

void accumulerDouble(void *acc, void **ppElem) {
    double *pAcc   = (double *)acc;
    double **pElem = (double **)ppElem;
    *pAcc += **pElem;
    (*pElem)++;
}

void balayerAppliquer(void *tableau, const int nElem, PAppFunc pAppFunc, void *base) {
    int k;
    for(k = 0; k<nElem; k++) {
        pAppFunc(base,&tableau);
    }
}

int main() {
    double  tab[10];
    const int nElem = 10;
    int k;
    double somme = 0.0;
    for(k = 0; k<nElem; k++) {
        scanf("%lf",tab+k);
    }
    balayerAppliquer(tab,10,accumulerDouble,&somme);
    printf("%lf\n",somme);
    return 0;
}
