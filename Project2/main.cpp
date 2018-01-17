#include "Wallet.h"
#include <iostream>
#include 
#define CURRENCY_MAX 5;

void addCurrency();
void removeCurrency();
void addValue();
void listContents();
void emptyWallet();

int main()
{
	Wallet userWallet(CURRENCY_MAX);
	Wallet *userWallet;
	int menuOption;
	int currentMenu;
	std::cout << "Welcome to your wallet. ";
	bool loopActive = true;
	while (loopActive)
	{
		std::cout << "Please enter the number corresponding to the options below:" << std::endl
			<< "1. Add a new currency" << std::endl
			<< "2. Remove a currency" << std::endl
			<< "3. Add money to a currency" << std::endl
			<< "4. List wallet contents" << std::endl
			<< "5. Empty wallet" << std::endl
			<< "6. Exit Application" << std::endl << std::endl
			<< "Selection Number: ";
		std::cin >> menuOption;
		std::cout << std::endl;
		if (menuOption < 1 || menuOption > 6)
		{
			std::cout << "Invalid selection. Please try again. " << std::endl;
		}
		else
		{
			if (menuOption == 1)
			{
				addCurrency();
			}
			else if (menuOption == 2)
			{
				removeCurrency();
			}
			else if (menuOption == 3)
			{
				addValue();
			}
			else if (menuOption == 4)
			{
				listContents();
			}
			else if (menuOption == 5)
			{
				emptyWallet();
			}
			else if (menuOption == 6)
			{
				loopActive = false;
			}
		}
	}
}

void addCurrency()
{
	string input;
	string stringarray[4];
	string stringPart
}

void removeCurrency()
{

}

void addValue()
{

}

void listContents()
{

}

void emptyWallet()
{

}