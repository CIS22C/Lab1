#include "Currency.h"
#include "Dollar.h"
Dollar::Dollar(int initWhole, int initFractional)
{
	setUp();
}
Dollar::~Dollar()
{

}
void Dollar::setUp()
{
	currencyname = "Dollars";
	fractionalname = "Cents";
	partsPerwhole = 100;
}