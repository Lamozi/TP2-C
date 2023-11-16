//
// Created by gedeon on 09/11/23.
//

#include "Tache.h"
#include "string.h"

void Affichetache(Tache * tache) {
    printf("Nom de la tache: %s\n", tache->Nom);
    printf("Date de la tache: ");
    AfficheDate(tache->DateTache);
    printf("Statut de la tache: %s\n", tache->Statut);
    printf("Nombre de jours de la tache: %d\n", tache->NbJours);
}


void ViderTamponEntree() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void SaisieTache(Tache *tache) {
    // Allouer de la mémoire pour DateTache
    tache->DateTache = (Date*)malloc(sizeof(Date));

    printf("Entrez le nom de la tache: ");
    scanf(" %s", (tache->Nom));
    ViderTamponEntree(); // Ajout pour vider le tampon d'entrée

    printf("Entrez le statut de la tache: ");
    fgets(tache->Statut, 50, stdin);
    tache->Statut[strlen(tache->Statut) - 1] = '\0';  // Supprimer le \n à la fin de la chaine
    //fgets(tache->Statut, sizeof(tache->Statut), stdin);
    ViderTamponEntree(); // Ajout pour vider le tampon d'entrée

    printf("Entrez le nombre de jours de la tache: ");
    scanf("%d", &(tache->NbJours));

    printf("Entrez la date de la tache:\n");
    SaisiDate(tache->DateTache);
}


