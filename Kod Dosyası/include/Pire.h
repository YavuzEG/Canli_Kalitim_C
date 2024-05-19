#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE
{
	Bocek super;
	void (*CanliSil)(struct PIRE*);
};

typedef struct PIRE* Pire;

Pire PireEkle(int);
char* pgorunum();

void PireSil(const Pire);


#endif
