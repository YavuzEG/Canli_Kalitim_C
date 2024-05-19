#include "Bitki.h"

Bitki BitkiEkle(int num) {

    Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	this->super = CanliEkle(num);
	this->super->gorunum=&bgorunum;
	this->CanliSil=&BitkiSil;
    

    return this;
}

char* bgorunum( )
{
	
	return "B";
	
}

void BitkiSil(const Bitki this)
{
	if(this==NULL) return;
	this->super->CanliSil(this->super);
	free(this);
}