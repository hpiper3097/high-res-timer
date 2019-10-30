#include "high-res-timer.hpp"

h_r_Timer::h_r_Timer()
{
}

h_r_Timer::~h_r_Timer()
{
}

//set start variable equal to current time
void h_r_Timer::start()
{
	st = std::chrono::high_resolution_clock::now();
}

//set stop variable equal to current time
void h_r_Timer::stop()
{
	e = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(e - st);
}

//returns stop - start
double h_r_Timer::time()
{
	return elapsed.count();
}
