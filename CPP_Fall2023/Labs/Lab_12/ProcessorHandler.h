#pragma once
#include "Util.h"
#include <set>
class ProcessorHandler
{
public:
	ProcessorHandler(Task dummy);
	Status status = READY;
	void process();
	void assignTask(Task t);
	void updateLastIdleTime(int seconds);
	Task assigned;
	int elapsed_time=0;
	int last_idle_time=0;

private:
	void incrementElapsedTime();
};

