#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct CANLI
{	
	int num;
	char* (*gorunum)();
	void(*CanliSil)(struct CANLI*);

};

typedef struct CANLI* Canli;

Canli CanliEkle(int);
void CanliSil(const Canli);


#endif

		
