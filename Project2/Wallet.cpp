/*
Stephen Lee and Ambrose Hundal
CIS 22C
Winter 2017
Lab 1

Microsoft Visual Studio 2017
Wallet class
Purpose:
Manages currency and the derived currency classes that make up the wallet
Gets number of items
Sees whether it is empty
Adds an object
Removes an occurence of an object if possible
Removes all objects
Test whether or not the object exists
*/

#include "Wallet.h"
#include <iostream>
#include <string>

//Constructor for Wallet class
Wallet::Wallet(const int MAX)
{
	currencyNum = 0; //Number of Currencies in the array
	currencyMax = MAX;
	currencyObjs = new Currency*[currencyMax];
}

//getCurrent Size
//gets number of currency types in Wallet
int Wallet::getSize()
{
	return currencyNum;
}

//isEmpty
//Tests if the wallet is empty
bool Wallet::isEmpty()
{
	bool emptiness = true;
	if (currencyNum > 0)
		emptiness = false;
	return emptiness;
}

//add
//adds a currency type to the wallet
int Wallet::add(std::string wholeName, int whole, int fractional)
{
	int currencyIndex = -1;
	if (currencyNum < currencyMax)
	{
		currencyIndex = currencyNum;
		if (wholeName == "Dollar")
		{
			currencyObjs[currencyIndex] = new Dollar(whole, fractional);
		}
		else if (wholeName == "Euro")
		{
			currencyObjs[currencyIndex] = new Euro(whole, fractional);
		}
		else if (wholeName == "Rupee")
		{
			currencyObjs[currencyIndex] = new Rupee(whole, fractional);
		}
		else if (wholeName == "Yen")
		{
			currencyObjs[currencyIndex] = new Yen(whole, fractional);
		}
		else if (wholeName == "Yuan")
		{
			currencyObjs[currencyIndex] = new Yuan(whole, fractional);
		}
		else
		{
			currencyNum--;
			currencyIndex = -2;
		}
		currencyNum++;
	}
	return currencyIndex;
}

//remove
//removes a currency from the wallet
bool Wallet :: remove(int currencyIndex)
{
	bool executed = false;
	if (exist(currencyIndex))
	{
		for (int i = currencyIndex; i < currencyNum - 1; i++)
		{
			currencyObjs[i] = currencyObjs[i + 1];
		}
		currencyObjs[currencyNum - 1] = NULL;
		currencyNum--;
		executed = true;
	}
	return executed;
}

//addValue
//adds integers to the currency type
bool Wallet::addValue(int currencyIndex, int wholeAdd, int fractionalAdd)
{
	bool executed = false;
	if (exist(currencyIndex))
	{
		currencyObjs[currencyIndex]->addValue(wholeAdd, fractionalAdd);
		executed = true;
	}
	return executed;
}

//removeValue
//addvalue but negative
bool Wallet::removeValue(int currencyIndex, int wholeAdd, int fractionalAdd)
{
	bool executed = false;
	if (exist(currencyIndex))
	{
		currencyObjs[currencyIndex]->addValue(-wholeAdd, -fractionalAdd);
		executed = true;
	}
	return executed;
}

//clear
//removes all currency from wallet
bool Wallet::clear()
{
	for (int i = 0; i < 10; i++)
	{
		currencyObjs = NULL;
	}
	currencyNum = 0;
	return true;
}
bool Wallet::contains(std::string wholeNameFind)
{
	for (int i = 0; i < currencyTypesNum; i++)
	{
		if (currencyObjs[i]->getWholeName() == wholeNameFind)
		{
			return true;
		}
	}
	return false;
}

/* ******************** exist ********************
determines if the currency index exists
*/
bool Wallet::exist(int currencyIndex)
{
	bool executed = false;
	if (currencyIndex >= 0 && currencyIndex < currencyNum)
	{
		executed = true;
	}
	return executed;
}

Currency Wallet::operator[] (const unsigned int i)
{
	return (*currencyObjs)[i];
}