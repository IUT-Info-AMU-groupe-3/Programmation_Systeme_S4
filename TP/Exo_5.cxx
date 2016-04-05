#include <stdio.h>
#include <stdlib.h>

int main() {
    int numberOfIter  = 5;
    int numberOfTabs  = 4;
    int eachTabLength = 4;
    int kIter;
    for(kIter = 0; kIter < numberOfIter; kIter++) {
        // alloc 'em
        char **tab = (char**)malloc(numberOfTabs * sizeof(char*));
        int kTab;
        for(kTab = 0; kTab < numberOfTabs; kTab++) {
            tab[kTab] = (char *)malloc(eachTabLength * sizeof(char));
            int kElem;
            for(kElem = 0; kElem < eachTabLength-1; kElem++) {
                tab[kTab][kElem] = 'A' + kTab + kElem;
            }
            tab[kTab][eachTabLength-1] = '\0';
        }
        // use 'em
        for(kTab = 0; kTab < numberOfTabs; kTab++) {
            printf("%s ",tab[kTab]);
            free(tab[kTab]);
        }
        // free 'em all
        free(tab); // or at least u think so
        printf("Free to go\n");
    }
    printf("Good bye.\n");
    return(0);
}
