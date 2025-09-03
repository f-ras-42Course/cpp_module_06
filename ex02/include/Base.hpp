#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>


class Base {
public:
	virtual ~Base() {}
};

// factory / identification functions
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif