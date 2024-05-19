#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK
{
	Bocek super;
	void (*CanliSil)(struct SINEK*);

	
};

typedef struct SINEK* Sinek;

Sinek SinekEkle(int);
char* sgorunum();

void SinekSil(const Sinek);

#endif