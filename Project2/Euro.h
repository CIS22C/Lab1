#ifndef EURO_H
#define EURO_H

class Euro : public Currency {
private:
	bool EuroCreated = false;
public:
	Euro();
	~Euro();
	void setUp();
};

#endif