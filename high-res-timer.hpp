#include <chrono>

#ifndef H_R_TIMER_H
#define H_R_TIMER_H

class h_r_Timer {
	private:
		std::chrono::high_resolution_clock::time_point st, e;
		std::chrono::duration<double> elapsed;

	public:
		h_r_Timer();
		~h_r_Timer();
		void start();
		void stop();
		double time();
};
#endif
