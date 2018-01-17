#ifndef YUAN_H
#define YUAN_H

class Yuan : public Currency {
private:
	bool RupeeCreated = false;
public:
	Yuan();
	~Yuan();
	void setUp();
};

#endif