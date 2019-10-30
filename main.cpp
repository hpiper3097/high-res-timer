#include "high-res-timer.hpp"
#include <iostream>

int main()
{
	h_r_Timer t = h_r_Timer();

	t.start();
	for(int i = 0; i < 2000; i++)
		for(int j = 0; j < 1000; j++)
			std::cout << i*j << "\n";
	t.stop();
	std::cout << "Printing " << 2000*1000 << " lines takes " << t.time() << " seconds...\n";

	return 0;
}
