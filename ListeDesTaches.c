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

int tailleliste(ListeTache *L) {
    int taille = 0;
    ListeTache *P = L;
    while (P != NULL) {
        taille++;
        P = P->next;
    }
    return taille;
}


// Fonction pour trier la liste par ordre croissant des dates
void trierListe(ListeTache *L) {
    ListeTache *P = L;
    ListeTache *min = P;
    ListeTache *Q = P->next;
    for(int i = 0; i < tailleliste(L); i++) {

        while (Q != NULL) {
            if (comapredateBis(min->data->DateTache, min->next->data->DateTache)) {
                min = Q;
            }
            Q = Q->next;
        }
        Tache *temp = P->data;
        P->data = min->data;
        min->data = temp;
        P = P->next;
    }
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

// Fonction pour créer une liste de tâches vide

ListeTache *creerListeVide() {
    return NULL;
}

//fonction qui supprime les taches terminees
void supprimerTacheTer(ListeTache **L){
    ListeTache * P = *L;
    ListeTache * temp = NULL;
    while (P != NULL) {
        if (strcmp(P->data->Statut, "Terminee") == 0) {
            temp = P;
            P = P->next;
            temp->prev->next = temp->next;
            free(temp);
        } else {
            P = P->next;
}
    }
}

//fonction qui passe les taches qui ont le nombre de jours a 0 a terminee
void passerTacheEncoursTerminee(ListeTache **L) {
    ListeTache *P = *L;
    while (P != NULL) {
        if ((P->data->NbJours == 0) && (strcmp(P->data->Statut, "En cours") == 0)){
            strcpy(P->data->Statut, "Terminee");
        }
        P = P->next;
    }
}

int compterTacheEncours(ListeTache *L) {
    int compteur = 0;
    ListeTache *P = L;
    while (P != NULL) {
        if (strcmp(P->data->Statut, "En cours") == 0) {
            compteur++;
        }
        P = P->next;
    }
    return compteur;
}

//fonction qui renvoie la position de la tache la plus ancienne avec le statut en attente

int positionTachePlusAncienne(ListeTache *L) {
    ListeTache *P = L;
    ListeTache *min = P;
    int position = 0;
    int i = 0;
    while (P != NULL) {
        if (comapredateBis(min->data->DateTache, P->data->DateTache) && (strcmp(P->data->Statut, "En attente") == 0)) {
            min = P;
            position = i;
        }
        P = P->next;
        i++;
    }
    return position;
}





void passerTacheenAttentetoencours(ListeTache **L) {
    ListeTache *P = *L;
    while (P != NULL) {
        if ((compterTacheEncours(*L)<5) ){
            
        }
        P = P->next;
    }
}
