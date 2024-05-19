#include "Bocek.h"

Bocek BocekEkle(int num) {
    
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super = CanliEkle(num);
	this->super->gorunum=&bogorunum;
 	this->CanliSil=&BocekSil;  

    return this;
}

char* bogorunum(const Bocek this)
{
	
	return "C";
}

void BocekSil(const Bocek this)
{
	if(this==NULL) return;
	this->super->CanliSil(this->super);
	free(this);
}