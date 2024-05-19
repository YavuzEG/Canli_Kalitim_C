#include "Sinek.h"

Sinek SinekEkle(int num) {
    Sinek this ;
	this= (Sinek)malloc(sizeof(struct SINEK));
	this->super= BocekEkle(num);
	this->super->super->gorunum=&sgorunum;
	this->CanliSil=&SinekSil; 
    

    return this;
}

char* sgorunum()
{
	return "S";
}

void SinekSil(const Sinek this)
{
	if(this==NULL) return;
	this->super->super->CanliSil(this->super->super);
	free(this);
}