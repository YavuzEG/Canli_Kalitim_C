#include "Canli.h"

Canli CanliEkle(int num) {
    Canli this ;
	this = (Canli)malloc(sizeof(struct CANLI)); 
    this->num = num; 
	this->CanliSil=&CanliSil;
    return this;
}

void CanliSil(const Canli this)
{
	if(this==NULL) return;
	free(this);
}
