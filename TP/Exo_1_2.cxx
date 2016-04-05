#include <iostream>
using namespace std;

int main() {
	int tab[10]; 
	const int nElem(10);
	int *p2 = tab;
	for(int k(0); k<nElem; k++) {
	 scanf("%d",p2+k);
	}
	int       somme(0);
	for(int k(0); k<nElem; k++) {
	somme += *(p2+k);
	}
	printf("%d\n",somme);
	return 0;
}
