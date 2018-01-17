#include "Currency.h"
#include "Euro.h"
Euro::Euro(int initWhole, int initFractional)
{
	setUp();
}
Euro::~Euro()
{

}
void Euro::setUp()
{
	currencyname = "Euros";
	fractionalname = "Cents";
	partsPerwhole = 100;
}