#include <stdio.h>

typedef void (*PAppFunc)(void *dest, void **ppElem);

void accumulerInt(void *acc, void **ppElem) {
    int *pAcc   = (int *)acc;
    int **pElem = (int **)ppElem;
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
    int  tab[10];
    const int nElem = 10;
    int k;
    int       somme = 0;
    for(k = 0; k<nElem; k++) {
        scanf("%d",tab+k);
    }
    balayerAppliquer(tab,10,accumulerInt,&somme);
    printf("%d\n",somme);
    return 0;
}
