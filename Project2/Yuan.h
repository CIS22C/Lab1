#ifndef YUAN_H
#define YUAN_H

class Yuan : public Currency {
private:
	bool RupeeCreated = false;
public:
	Yuan(int initWhole, int initFractional);
	~Yuan();
	void setUp();
};

#endif