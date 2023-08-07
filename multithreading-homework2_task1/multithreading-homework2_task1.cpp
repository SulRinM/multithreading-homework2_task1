#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include "Timer.h"


using namespace std;

atomic<unsigned int> counter = 0;


void client() {
	const int maxCounter = 10;
	while (counter < maxCounter) {
		consol_parameter::SetColor(15, 0);
		cout << (counter.fetch_add(1, memory_order_relaxed) + 1) << " ";
		this_thread::sleep_for(1000ms);
	}
}

void operat() {
	this_thread::sleep_for(chrono::milliseconds(100));
	while (counter > 0) {
		consol_parameter::SetColor(10, 0);
		cout << (counter.fetch_sub(1, memory_order_relaxed) - 1) << " ";
		this_thread::sleep_for(2000ms);
	}
}

int main(int argc, char** argv) {
	thread t1(client);
	thread t2(operat);
	t1.join();
	t2.join();

	return 0;
}