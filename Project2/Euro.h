#include "Currency.h"
#ifndef EURO_H
#define EURO_H

class Euro : public Currency {
private:
	bool EuroCreated = false;
public:
	Euro(int initWhole, int initFractional);
	~Euro();
	void setUp();
};

#endif