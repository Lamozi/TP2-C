//
// Created by gedeon on 09/11/23.
//

#include "Date.h"


void SaisiDate(Date* A) {
    printf("Entrez le jour, le mois et l'année (séparés par des espaces) : ");
    scanf("%d %d %d", &(A->jour), &(A->mois), &(A->annee));
    printf("\n");
}
void AfficheDate (Date* A){
    printf(" %d/%d/%d\n", A->jour, A->mois, A->annee);
}

int ComparerDates(Date* d1, Date* d2) {
    if (d1->annee < d2->annee || (d1->annee == d2->annee && d1->mois < d2->mois) ||
        (d1->annee == d2->annee && d1->mois == d2->mois && d1->jour < d2->jour)) {
        return -1;
    } else if (d1->annee == d2->annee && d1->mois == d2->mois && d1->jour == d2->jour) {
        return 0;
    } else {
        return 1;
    }
}
