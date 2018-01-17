#include <string>
#include <iostream>

#ifndef CURRENCY_H
#define CURRENCY_H

class Currency {
public:
	std::string currencyname;  /*name of currency */
	int wholeVal;       /* whole part */
	int fractValue;     /* fractional part */
	std::string fractionalname; /* name of currency fractional part */
	int partsPerwhole;
};

#endif