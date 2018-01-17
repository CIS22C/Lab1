#ifndef RUPEE_H
#define RUPEE_H

class Rupee : public Currency {
private:
	bool RupeeCreated = false;
public:
	Rupee();
	~Rupee();
	void setUp();
};

#endif