#include "Currency.h"
#include "Rupee.h"

void Rupee::setUp()
{
	currencyname = "Rupees";
	fractionalname = "Paises";
	partsPerwhole = 100;
}
Rupee::Rupee(int initWhole, int initFractional)
{
	setUp();
}
Rupee::~Rupee()
{

}