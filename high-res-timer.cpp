#include "high-res-timer.hpp"

h_r_Timer::h_r_Timer()
{
#ifdef OS_Windows
	QueryPerformanceFrequency(&frequency);
#endif
}

h_r_Timer::~h_r_Timer()
{

}

//set start variable equal to current time
void h_r_Timer::start()
{
#ifdef OS_Windows
	QueryPerformanceCounter(&st);
#else
	st = clock();
#endif
}

//set stop variable equal to current time
void h_r_Timer::stop()
{
#ifdef OS_Windows
	QueryPerformanceCounter(&e);
#else
	e = clock();
#endif
}

//returns stop - start
size_t h_r_Timer::time()
{
	elapsed = e - st;
#ifdef OS_WINDOWS
	return elapsed;
#else
	return ((float)elapsed)/CLOCKS_PER_SEC;
#endif
}
