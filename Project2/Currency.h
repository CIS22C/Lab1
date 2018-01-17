#include <string>
#include <iostream>

#ifndef CURRENCY_H
#define CURRENCY_H

class Currency {
public:
	string currencyname;  /*name of currency */
	int wholeVal;       /* whole part */
	int fractValue;     /* fractional part */
	string fractionalname; /* name of currency fractional part */
};

#endif