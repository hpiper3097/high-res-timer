/*#ifdef __unix__
	#include <time.h>
#elif defined(_WIN32) || defined(WIN32)
	#define OS_Windows
	#include <windows.h>
#endif
*/
#include <chrono>

class h_r_Timer {
	private:
		/*
#ifdef OS_Windows
			LARGE_INTEGER st, e, elapsed, frequency;
#else
			clock_t st, e, elapsed;
#endif
*/
		std::chrono::high_resolution_clock::time_point st, e;
		std::chrono::duration<double> elapsed;

	public:
		h_r_Timer();
		~h_r_Timer();
		void start();
		void stop();
		double time();
};
