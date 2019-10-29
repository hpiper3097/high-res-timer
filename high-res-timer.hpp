#ifdef __unix__
	#include <time.h>
#elif defined(_WIN32) || defined(WIN32)
	#define OS_Windows
	#include <windows.h>
#endif

class h_r_Timer {
	private:
#ifdef OS_Windows
			LARGE_INTEGER st, e, elapsed, frequency;
#else
			clock_t st, e, elapsed;
#endif

	public:
		h_r_Timer();
		~h_r_Timer();
		void start();
		void stop();
		size_t time();
};
