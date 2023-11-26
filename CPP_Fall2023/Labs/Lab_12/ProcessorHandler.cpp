#include "ProcessorHandler.h"
#include "Util.h"
#include <iostream>
#include <chrono>
#include <thread>
ProcessorHandler::ProcessorHandler(Task dummy) {
	this->assigned = dummy;
}
void ProcessorHandler::process()
{
	if (this->status == BUSY && !this->assigned.dummy) {
		auto start = std::chrono::high_resolution_clock::now();
		double taskDur = this->assigned.duration;
		auto as_duration = std::chrono::duration_cast<std::chrono::steady_clock::duration>(std::chrono::duration<double>(taskDur));
		std::this_thread::sleep_for(as_duration);
		auto end = std::chrono::high_resolution_clock::now();
		auto runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		updateLastIdleTime(runtime.count());
		incrementElapsedTime();
		this->status = READY;
	}
}

void ProcessorHandler::assignTask(Task t)
{
	this->status = BUSY;
	this->assigned = t;
}

void ProcessorHandler::updateLastIdleTime(int seconds)
{
	this->last_idle_time = seconds;
}

void ProcessorHandler::incrementElapsedTime()
{
	this->elapsed_time += last_idle_time;
}
