#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
	int id_;
	std::string message_;
	double value_;
	
	Data();
	Data(int i, const std::string& n, double v);
};

#endif
