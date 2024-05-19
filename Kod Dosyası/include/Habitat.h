#ifndef HABITAT_H
#define HABITAT_H
#include "Sinek.h"
#include "Bitki.h"
#include "Pire.h"

#define MAX_SATSUT 200


struct HABITAT {
    Canli matris[MAX_SATSUT][MAX_SATSUT];
    int satir;
    int sutun;
} ;

typedef struct HABITAT Habitat;

void VeriAta(Habitat*,const char*);
void VeriYaz(const Habitat*);
void VeriYe(const Habitat*);

void HabSat(const Habitat*,int,int,int,int,int);
void Temizle(Habitat*);
void Kazanan(const Habitat*);


#endif