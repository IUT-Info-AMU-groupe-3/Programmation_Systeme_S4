#include <iostream>
using namespace std;

int main() {
    int       tab[10]; 
    const int nElem(10);
    for(int k(0); k<nElem; k++) {
	 scanf("%d",&(tab[k]));
    }
    int       somme(0);
    for(int k(0); k<nElem; k++) {
	somme += tab[k];
    }
    printf("%d\n",somme);

    return 0;
}
