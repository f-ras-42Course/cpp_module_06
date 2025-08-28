#include "ScalarConverter.hpp"
#include <cmath>

void ScalarConverter::convert(const std::string& input) {
	std::string literal;
	if (isQuotedChar(input)) {
		literal = std::to_string(static_cast<int>(input[1]));
	} else if (isSingleChar(input)) {
		literal = std::to_string(static_cast<int>(input[0]));
	} else {
		literal = input;
	}
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}

void ScalarConverter::convertToChar(const std::string& literal) {
	try {
		int value = std::stoi(literal);
		if (value < 0 || value > 255) throw std::out_of_range("char");
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
	} catch (const std::exception& e) {
		std::cout << "char: not a char value, must be between 0 and 255\n";
	}
}

void ScalarConverter::convertToInt(const std::string& literal) {
	try {
		int value = std::stoi(literal);
		std::cout << "int: " << value << "\n";
	} catch (const std::exception& e) {
		std::cout << "int: not a valid integer\n";
	}
}

void ScalarConverter::convertToFloat(const std::string& literal) {
	try {
		float value = std::stof(literal);
		if (std::isnan(value)) std::cout << "float: nanf\n";
		else if (std::isinf(value)) std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << "\n";
		else std::cout << "float: " << value << "f\n";
	} catch (const std::exception& e) {
		std::cout << "float: not a valid float\n";
	}
}

void ScalarConverter::convertToDouble(const std::string& literal) {
	try {
		double value = std::stod(literal);
		if (std::isnan(value)) std::cout << "double: nan\n";
		else if (std::isinf(value)) std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << "\n";
		else std::cout << "double: " << value << "\n";
	} catch (const std::exception& e) {
		std::cout << "double: not a valid double\n";
	}
}

bool ScalarConverter::isQuotedChar(const std::string& input) {
	return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

bool ScalarConverter::isSingleChar(const std::string& input) {
	return input.length() == 1 && !std::isdigit(input[0]);
}