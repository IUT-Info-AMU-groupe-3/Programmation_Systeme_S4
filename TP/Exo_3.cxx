#include <iostream>

using namespace std;

int mettreBitAUn(int valeur, int rang) {
    int masque = 1 << rang;
    return valeur | masque;
}

int inverserBit(int valeur, int rang) {
    int masque = 1 << rang;
    return valeur ^ masque;
}

int testerBitAUn(int valeur, int rang) {
    int masque = 1 << rang;
    return ((valeur & masque) == masque)? 0 : 1;
}

int testerBitAZero(int valeur, int rang) {
    int masque = 1 << rang;
    return ((valeur & masque) == masque)? 1 : 0;
}

void rebelotte(int *pA, int *pB) {
    *pA = ((*pA) ^ (*pB));
    *pB = ((*pA) ^ (*pB));
    *pA = ((*pA) ^ (*pB));
}

int min(int *p1, int *p2) {
    return *p2 ^ ((*p1 ^ *p2) & -(*p1 < *p2));
}
//question 4
int max(int *p1, int *p2) {
    return *p1 ^ ((*p1 ^ *p2) & -(*p1 < *p2));
}

int main(){
    int mbaun = mettreBitAUn(2, 0);
    cout << "mbaun : " << mbaun << endl;

    int a = 1;
    int b = 3;
    rebelotte(&a, &b);
    cout << "a et b : " << a << b << endl;
    cout << "min(1, 3) : " << min(&a, &b) << endl;
    cout << "max(1, 3) : " << max(&a, &b) << endl;
}
