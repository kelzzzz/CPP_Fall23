
#include "IntegerQueue.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/logger.h"
#include <iostream>

IntegerQueue::IntegerQueue(int capacity)
{
    try
    {
        this->logger = spdlog::basic_logger_mt("queueLogger", "logs/queueLog.txt").get();
        logger->info("Queue logging created.");
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }

    this->capacity = capacity;
    this->size = 0;
    this->front = 0;
    this->rear = capacity - 1;
    this->array = new int[capacity];
    logger->info("Queue created with a capacity of " + this->capacity);
}

bool IntegerQueue::isEmpty() {
    return (this->size == 0);
}

bool IntegerQueue::isFull() { return(this->size == this->capacity);}


int IntegerQueue::getFront()
{
    if (this->isEmpty()) {
        return -1;
    }
    return this->array[0];
}


int IntegerQueue::getRear()
{
    if (this->isEmpty()) {
        return -1;
    }
    return this->array[this->rear];
}

int IntegerQueue::dequeue()
{
    if (isEmpty()) {
        return -1;
    }
    int get = this->array[this->front];
    this->front = (this->front++) % this->capacity;
    this->size--;
    return get;
}

void IntegerQueue::enqueue(int insert) 
{
    if (isFull())
        return;
    this->rear = (this->rear++)
        % this->capacity;
    this->array[this->rear] = insert;
    this->size++;
}

