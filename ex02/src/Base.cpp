
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> d(0, 2);
	int random = d(rng);
	if (random == 0) return new A();
	if (random == 1) return new B();
	return new C();
}

void identify(Base* p) {
	if (!p) {
		std::cout << "Unknown";
		return;
	}
	if (dynamic_cast<A*>(p)) { std::cout << "A"; return; }
	if (dynamic_cast<B*>(p)) { std::cout << "B"; return; }
	if (dynamic_cast<C*>(p)) { std::cout << "C"; return; }
	std::cout << "Unknown";
}

void identify(Base& p) {
	try { (void)dynamic_cast<A&>(p); std::cout << "A"; return; }
	catch (std::exception&) {}
	try { (void)dynamic_cast<B&>(p); std::cout << "B"; return; }
	catch (std::exception&) {}
	try { (void)dynamic_cast<C&>(p); std::cout << "C"; return; }
	catch (std::exception&) {}
	std::cout << "Unknown";
}
