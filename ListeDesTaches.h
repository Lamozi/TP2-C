//
// Created by gedeon on 09/11/23.
//

#ifndef TP_FINAL_LISTEDESTACHES_H
#define TP_FINAL_LISTEDESTACHES_H
#include "stdio.h"
#include "stdlib.h"
#include "Date.h"
#include "Tache.h"
#include "string.h"




typedef struct LT {
    Tache * data;
    struct LT * next;
    struct LT * prev;
}ListeTache;

void afficheListe (ListeTache * L);
void ajouterfin(ListeTache ** L, Tache * C);
void libererTache(Tache *tache);
void libererListe(ListeTache *L);
void modifierTache(ListeTache *L, char *nom);
void supprimerTacheJ0(ListeTache **L);
ListeTache *creerListeVide() ;
void afficheListeCroissante(ListeTache *L);
int tailleliste(ListeTache *L);
void trierListe(ListeTache *L);
void passerTacheEncoursTerminee(ListeTache **L) ;
void supprimerTacheTer(ListeTache **L);
int compterTacheEncours(ListeTache *L) ;























#endif //TP_FINAL_LISTEDESTACHES_H
