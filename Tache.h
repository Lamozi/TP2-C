//
// Created by gedeon on 09/11/23.
//

#ifndef TP_FINAL_TACHE_H
#define TP_FINAL_TACHE_H
#include "stdio.h"
#include "Date.h"


typedef struct Th {
    char Nom[50];
    Date *DateTache;
    char Statut[50];
    int NbJours;
}Tache;

void Affichetache(Tache *);
void SaisieTache(Tache *);



#endif //TP_FINAL_TACHE_H
