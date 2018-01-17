#include "Currency.h"
#include "Yen.h"
Yen::Yen(int initWhole, int initFractional)
{
	setUp();
}
Yen::~Yen()
{

}
void Yen::setUp()
{
	currencyname = "Yens";
	fractionalname = "Sens";
	partsPerwhole = 100;
}