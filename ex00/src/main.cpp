#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <literal>\n";
		std::cout << "Examples:\n";
		std::cout << "  " << argv[0] << " 42\n";
		std::cout << "  " << argv[0] << " 'c'\n";
		std::cout << "  " << argv[0] << " 4.2f\n";
		std::cout << "  " << argv[0] << " nanf\n";
		std::cout << "  " << argv[0] << " +inff\n";
		std::cout << "  " << argv[0] << " -inf\n";
		std::cout << "  " << argv[0] << " 0.0" << std::endl;
		return 1;
	}
	
	ScalarConverter::convert(argv[1]);
	return 0;
}
