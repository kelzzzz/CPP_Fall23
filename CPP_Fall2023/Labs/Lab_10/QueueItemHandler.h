#pragma once
#include"IntQueue.h"
class QueueItemHandler
{
public:
	QueueItemHandler(IntQueue* q, char ID);
	char ID;
	int lastProcessed;
	IntQueue* queue;
	bool busy = false;
	void handle();
	bool isBusy();
	int getLastProcessed();
};

