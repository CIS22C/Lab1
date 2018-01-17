/*
Stephen Lee and Ambrose Hundal
CIS 22C
Winter 2017
Lab 1

Microsoft Visual Studio 2017
main class
Purpose:
Interact with the user with the options to add/remove currency, add/remove money from a currency,
list wallet contents, empty wallet, and exit application.
*/
#include "Wallet.h"
#include <iostream>
#include <sstream>
#include <limits>
#define CURRENCY_MAX 5;

void addCurrency(Wallet *userWallet);
void removeCurrency(Wallet *userWallet);
void addValue(Wallet *userWallet);
void listContents(Wallet *userWallet);
void emptyWallet(Wallet *userWallet);

int main()
{
	int max = CURRENCY_MAX;
	std::cout << max;
	Wallet user(max);
	Wallet *userWallet = &user;
	int menuOption;
	int currentMenu;
	std::cout << "Welcome to your wallet. ";
	bool loopActive = true;
	while (loopActive)
	{
		std::cout << "Please enter the number corresponding to the options below:" << std::endl
			<< "1. Add a new currency" << std::endl
			<< "2. Remove a currency" << std::endl
			<< "3. Add/Remove money to a currency" << std::endl
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
				addCurrency(userWallet);
			}
			else if (menuOption == 2)
			{
				removeCurrency(userWallet);
			}
			else if (menuOption == 3)
			{
				addValue(userWallet);
			}
			else if (menuOption == 4)
			{
				listContents(userWallet);
			}
			else if (menuOption == 5)
			{
				emptyWallet(userWallet);
			}
			else if (menuOption == 6)
			{
				loopActive = false;
			}
		}
	}
}

void addCurrency(Wallet *userWallet)
{
	std::string inputString;
	std::string stringArray[4];
	std::string stringPart;
	int success;
	std::cout << "Please enter the name whole value and fractional value you want to add" << std::endl
		<< "for example Dollars, 3, 25, Cents" << std::endl;
	std::getline(std::cin, inputString);
	int i = 0;
	size_t pos = 0;
	while ((pos = inputString.find(',')) != std::string::npos)
	{
		stringArray[i] = inputString.substr(0, pos);
		inputString.erase(0, pos + 1);
		i++;
		std::cout << "******************************" << std::endl;
	}
	stringArray[2] = inputString;
	if (i != 2)
	{
		std::cout << std::endl << "ERROR, incorrect format" << std::endl;
	}
	else
	{
		std::stringstream wholeStream(stringArray[1]);
		int wholeAdd = 0;
		wholeStream >> wholeAdd;
		std::stringstream fractionalStream(stringArray[2]);
		int fractionalAdd = 0;
		fractionalStream >> fractionalAdd;
		success = userWallet->add(stringArray[0], wholeAdd, fractionalAdd);
		if (success >= 0)
		{
			std::cout << "Add success" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Add failed" << std::endl << std::endl;
		}
	}
	std::cout << std::endl;
}

void removeCurrency(Wallet *userWallet)
{
	int currencyNumber;
	int currencyIndex;
	std::cout << "Please input the number representing the currency" << std::endl;
	int n = userWallet->getSize();
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ". " << &userWallet[1] << std::endl;
	}
	std::cout << std::endl << "currency number: ";
	std::cin >> currencyNumber;
	currencyIndex = currencyNumber - 1;
	try
	{
		if (userWallet->remove(currencyIndex))
		{
			std::cout << "Removal complete" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Removal failed" << std::endl << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl << std::endl;
	}
}

void addValue(Wallet *userWallet)
{

}

void listContents(Wallet *userWallet)
{
	Currency temp;

	std::cout << "Wallet Contents: " << std::endl;
	int n = userWallet->getSize();
	for (int i = 0; i < n; i++)
	{
		temp = (*userWallet)[i];
		std::cout << temp << std::endl;
	}
	std::cout << std::endl;
}

void emptyWallet(Wallet *userWallet)
{
	char confirmChar;
	std::cout << "Are you sure you want to empty your wallet? This is not reversible." << std::endl;
		<< "Y/N: ";
	std::cin >> confirmChar;
	std::cout << std::endl;
	if (confirmChar == 'Y' || confirmChar == 'y')
	{
		if (userWallet->clear())
		{
			std::cout << "Your wallet has been emptied." << std::endl << std::endl;
		}
	}
}