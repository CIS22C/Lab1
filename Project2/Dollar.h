#ifndef DOLLAR_H
#define DOLLAR_H

class Dollar : public Currency {
private:
	bool DollarCreated = false;
public:
	Dollar(int initWhole, int initFractional);
	~Dollar();
	void setUp();
};

#endif