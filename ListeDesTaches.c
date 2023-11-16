//
// Created by gedeon on 09/11/23.
//

#include "ListeDesTaches.h"

void afficheListe (ListeTache * L) {
    ListeTache * P = L;                                     // on crée un pointeur P qui pointe sur la tête de la liste
    if (P == NULL)                                         // si la liste est vide
        printf("Liste vide");
    else {                                                // si la liste n'est pas vide
        while (P != NULL) {                              // on parcourt la liste
            Affichetache(P->data);                      // on affiche la valeur de la case
            printf("------------------------------\n");
            P = P->next;                              // on avance dans la liste
        }
    }
    printf("\n");
}

void ajouterfin(ListeTache ** L, Tache * C) {
    ListeTache * nouveau_maillon = (ListeTache *) malloc(sizeof(ListeTache));
    nouveau_maillon->data = C;
    nouveau_maillon->next = NULL;
    nouveau_maillon->prev = NULL;

    if (*L == NULL) {
        *L = nouveau_maillon;
    } else {
        ListeTache * P = *L;
        while (P->next != NULL) {
            P = P->next;
        }
        P->next = nouveau_maillon;          // on fait pointer la case next de P sur le nouveau maillon
        nouveau_maillon->prev = P;          // on fait pointer la case prev du nouveau maillon sur P
    }
}


// Fonction pour libérer la mémoire allouée pour une tâche
void libererTache(Tache *tache) {
    free(tache->DateTache);
    free(tache);
}

// Fonction pour libérer la mémoire de toute la liste
void libererListe(ListeTache *L) {
    while (L != NULL) {
        ListeTache *temp = L;
        L = L->next;
        libererTache(temp->data);
        free(temp);
    }
}

// Fonction pour modifier une tâche a partir de son nom

void modifierTache(ListeTache *L, char *nom) {
    ListeTache *P = L;
    while (P != NULL) {
        if (strcmp(P->data->Nom, nom) == 0) {
            SaisieTache(P->data);
            return;
        }
        P = P->next;
    }
    printf("Tache non trouvee\n");
}

// Fonction pour supprimer une tâche si son NbJours est 0

void supprimerTacheJ0(ListeTache **L){
    ListeTache *P = *L;
    while (P != NULL) {
        if (P->data->NbJours == 0) {
            ListeTache *temp = P;
            P = P->next;
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *L = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            libererTache(temp->data);
            free(temp);
        } else {
            P = P->next;
        }
    }
}