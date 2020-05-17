#include "AdvancedRobots.h"

int main() {
	VaxBot vax("Pero");
	SgiBot sgi("Jura");
	T101 t101("Arnold");

	std::cout << vax << std::endl << sgi << std::endl << t101 << std::endl;
}