#include <stdio.h>
#include "ListeDesTaches.h"

typedef struct HANDLE HANDLE;

//

int main() {
    /*Date T;
    SaisiDate(&T);
    AfficheDate(&T);
    Tache TT;
    SaisieTache(&TT);
    Affichetache(&TT);
    Tache T1;
    SaisieTache(&T1);
    Tache T2;
    SaisieTache(&T2);*/
    ListeTache *LT = NULL;
    /*
    ajouterfin( &LT, &T1);
    ajouterfin( &LT, &T2);
    afficheListe(LT);
    //libererListe(LT);*/


    int choix;

    while (1) { // Boucle infinie, l'utilisateur choisit quand quitter le programme
        printf("\n ** M E N U ** \n");
        printf("---------------\n");
        printf("1. Créer une liste de tâches\n");
        printf("2. Modifier une liste de tâches\n");
        printf("3. Ajouter une tâche à une liste\n");
        printf("4. Afficher la liste\n");
        printf("5. Quitter\n");

        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Code pour créer une liste de tâches
                // ...
                break;
            case 2:
                // Code pour modifier une liste de tâches
                // ...
                break;
            case 3:
                // Code pour ajouter une tâche à une liste
                // ...
                break;
            case 4:
                // Code pour afficher la liste
                afficheListe(LT);
                break;
            case 5:
                // Libérer la mémoire et quitter le programme
                libererListe(LT);
                return 0;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    }

    return 0;
}

