#include <iostream>
using namespace std;

int main() {
	int tab[10]; 
	const int nElem(10);
	int *p2 = tab;
	for(int k(0); k<nElem; k++) {
	 	scanf("%d",p2+k);
	}
	int somme(0);
	for(int* k=tab; k<tab+10; k++) {
		somme += *k;
	}
	printf("%d\n",somme);
	return 0;
}
