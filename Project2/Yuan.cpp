#include "Currency.h"
#include "Yuan.h"
Yuan::Yuan(int initWhole, int initFractional)
{
	setUp();
}
Yuan::~Yuan()
{

}
void Yuan::setUp()
{
	currencyname = "Yuans";
	fractionalname = "Fens";
	partsPerwhole = 100;
}