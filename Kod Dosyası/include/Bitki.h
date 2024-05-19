#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
    Canli super;
	void (*CanliSil)(struct BITKI*);
};

typedef struct BITKI* Bitki;

Bitki BitkiEkle(int num);
char* bgorunum();

void BitkiSil(const Bitki);

#endif