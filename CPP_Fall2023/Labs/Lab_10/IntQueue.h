#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/logger.h"
#pragma once
class IntQueue
{
public:
	int front, rear, capacity, size;
	int* array;
	spdlog::logger* logger;
	IntQueue(int capacity);
	bool isEmpty();
	bool isFull();
	int getFront();
	int getRear();
	void enqueue(int insert);
	int dequeue();
};
