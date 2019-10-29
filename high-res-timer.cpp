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
/*#ifdef OS_Windows
	QueryPerformanceCounter(&st);
#else
	st = clock();
#endif*/
	st = std::chrono::high_resolution_clock::now();
}

//set stop variable equal to current time
void h_r_Timer::stop()
{
	/*
#ifdef OS_Windows
	QueryPerformanceCounter(&e);
#else
	e = clock();
#endif*/
	e = std::chrono::high_resolution_clock::now();
}

//returns stop - start
double h_r_Timer::time()
{
	elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(e - st);
	return elapsed.count();
	/*
#ifdef OS_WINDOWS
	return (double)elapsed;
#else
	return 1000*((double)elapsed)/CLOCKS_PER_SEC;
#endif*/
}
