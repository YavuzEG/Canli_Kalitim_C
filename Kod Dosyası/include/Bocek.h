#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK
{
	Canli super;
	void (*CanliSil)(struct BOCEK*);

};

typedef struct BOCEK* Bocek;

Bocek BocekEkle(int);
char* bogorunum();

void BocekSil(const Bocek);


#endif
