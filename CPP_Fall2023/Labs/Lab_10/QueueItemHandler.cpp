#include "QueueItemHandler.h"
#include "IntQueue.h"

QueueItemHandler::QueueItemHandler(IntQueue* q, char ID)
{
	this->queue = q;
	this->ID = ID;
}

void QueueItemHandler::handle()
{
	this->busy = true;
	int timer;
	timer = rand() % (40 - 10 + 1) + 10;
	std::this_thread::sleep_for(std::chrono::milliseconds(timer));
	this->lastProcessed = this->queue->dequeue();
	this->busy = false;
}

bool QueueItemHandler::isBusy()
{
	return this->busy;
}

int QueueItemHandler::getLastProcessed()
{
	return this->lastProcessed;
}
