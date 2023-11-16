//
// Created by gedeon on 09/11/23.
//

#ifndef TP_FINAL_DATE_H
#define TP_FINAL_DATE_H

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int jour;
    int mois;
    int annee;
}Date;

void  SaisiDate(Date *);
void AfficheDate(Date *);
int ComparerDates(Date*, Date*);






#endif //TP_FINAL_DATE_H
