#include "Pire.h"

Pire PireEkle(int num) {
	Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
	this->super = BocekEkle(num);
	this->super->super->gorunum=&pgorunum;
	this->CanliSil=&PireSil; 
    
    return this;
}

char* pgorunum()
{
	return "P";
}

void PireSil(const Pire this)
{
	if(this==NULL) return;
	this->super->super->CanliSil(this->super->super);
	free(this);
}