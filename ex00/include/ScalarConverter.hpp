#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter {
public:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& other) = delete;
	ScalarConverter& operator=(const ScalarConverter& other) = delete;
	~ScalarConverter() = default;

	static void convert(const std::string& literal);

	bool static isQuotedChar(const std::string& input);
	bool static isSingleChar(const std::string& input);

private:
	static void convertToChar(const std::string& literal);
	static void convertToInt(const std::string& literal);
	static void convertToFloat(const std::string& literal);
	static void convertToDouble(const std::string& literal);
};

#endif