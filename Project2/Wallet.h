#include <string>
#include "currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Rupee.h"
#include "Yen.h"
#include "Yuan.h"
#ifndef WALLET_H
#define WALLET_H

class Wallet
{
private:
	Currency **currencyObjs;
	int currencyNum;
	int currencyMax;
public:
	Wallet(const int CURRENCY_MAX);
	int getSize();
	bool isEmpty();
	int add(std::string initWholeName, int initWhole, int initFractional);
	bool remove(int currencyIndex);
	bool addValue(int currencyIndex, int wholeAdd, int fractionalAdd);
	bool removeValue(int currencyIndex, int wholeAdd, int fractionalAdd);
	bool clear();
	bool contains(std::string initWholeName);
	bool exist(int currencyIndex);

	Currency operator[] (const unsigned int i);
};
#endif