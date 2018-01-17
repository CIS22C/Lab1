#include "Currency.h"
#ifndef RUPEE_H
#define RUPEE_H

class Rupee : public Currency {
private:
	bool RupeeCreated = false;
public:
	Rupee(int initWhole, int initFractional);
	~Rupee();
	void setUp();
};

#endif