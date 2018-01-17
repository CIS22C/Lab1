#ifndef DOLLAR_H
#define DOLLAR_H

class Dollar : public Currency {
private:
	bool DollarCreated = false;
public:
	Dollar();
	~Dollar();
};

#endif