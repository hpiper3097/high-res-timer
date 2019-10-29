#include "high-res-timer.hpp"
#include <iostream>

int main()
{
	h_r_Timer t = h_r_Timer();

	t.start();
	std::cout << 234 * 1234 << std::endl;
	t.stop();
	std::cout << t.time() << std::endl;

	return 0;
}
