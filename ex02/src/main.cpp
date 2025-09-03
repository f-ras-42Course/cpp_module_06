#include "Base.hpp"

int main() {
	for (size_t i = 0; i < 42; i++)
	{
		Base* test = generate();
		std::cout << "Test " << i + 1 << ": ";
		std::cout << "[";
		identify(test);
		if (test) {
			std::cout << "-";
			identify(*test);
		};
		std::cout << "]\n";
		delete test;
	}

    return 0;
}
