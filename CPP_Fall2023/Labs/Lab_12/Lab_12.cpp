#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <thread>
#include <chrono>
#include "Util.h"
#include "ProcessorHandler.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"

std::set<std::string> completed_cache;
std::queue<Task> task_queue;
spdlog::logger* logger;

Task T1, T2, T3, T4, T5, T6, T7, T8, T9, T_DUMMY;

void assignTasks(ProcessorHandler* P);
void runProcessors(ProcessorHandler *P1, ProcessorHandler *P2);
bool canProcess(Task t);
void initializeTasks();

bool operator<(const Task& a, const Task& b)
{
    return a.duration < b.duration;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    try
    {
        logger = spdlog::basic_logger_mt("mainLogger", "logs/mainLog.txt").get();
        logger->info("--------BUILD--------");
        logger->info(" Main logger created.");
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }

    initializeTasks();
    ProcessorHandler P1(T_DUMMY);
    ProcessorHandler P2(T_DUMMY);
    runProcessors(&P1, &P2);
    auto end = std::chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    logger->info("Total elapsed handling time of Processor 1: {}s", P1.elapsed_time * .001);
    logger->info("Total elapsed handling time of Processor 2: {}s", P2.elapsed_time * .001);
    logger->info("Total program elapsed runtime: {}s", runtime.count() * .001);
}

void assignTasks(ProcessorHandler* P) {
    if (P->status != BUSY) {
        P->assignTask(task_queue.front());
        const Task t = task_queue.front();
        completed_cache.insert(t.name);
        task_queue.pop();
    }
}
void runProcessors(ProcessorHandler *P1, ProcessorHandler *P2)
{
    while (!task_queue.empty()) {
        bool P1Processed = false;
        bool P2Processed = false;
        std::string processedT1;
        std::string processedT2;
        if (canProcess(task_queue.front())) {
            processedT1 = task_queue.front().name;
            assignTasks(P1);
            logger->info("Assigned {} to Processor 1.", P1->assigned.name);
            P1Processed = true;
            std::thread P1Thread(&ProcessorHandler::process, P1);
            if (!task_queue.empty() && canProcess(task_queue.front())) {
                processedT2 = task_queue.front().name;
                assignTasks(P2);
                logger->info("Assigned {} to Processor 2.", P2->assigned.name);
                P2Processed = true;
                std::thread P2Thread(&ProcessorHandler::process, P2);
                P2Thread.join();
            }
            P1Thread.join();
        }
        else {
            const Task t = task_queue.front();
            logger->info("{} requirements not yet met. Pushing to the back of the queue and looking for something to assign.", t.name);
            task_queue.push(t);
            task_queue.pop();
        }

        if (P1Processed) {
            logger->info("Processor 1 processed {} in {} seconds.", processedT1, P1->last_idle_time * .001);
        }
        if (P2Processed) {
            logger->info("Processor 2 processed {} in {} seconds.", processedT2, P2->last_idle_time * .001);
        }
    }
}

bool canProcess(Task t)
{
    int count=0;
    int len = t.dependencies.size();
    for (int i = 0; i < len; i++) {
        if (completed_cache.count(t.dependencies.at(i).name)) {
            count++;
        }
    }
    if (count == len) {
        return true;
    }
    else {
        return false;
    }
}

void initializeTasks()
{
    T_DUMMY.dummy = true;

    T1.duration = 2.0;
    T2.duration = 0.5;
    T3.duration = 2.0;
    T4.duration = 1.0;
    T5.duration = 2.0;
    T6.duration = 0.5;
    T7.duration = 0.5;
    T8.duration = 0.5;
    T9.duration = 1.0;

    T1.name = "T1";
    T2.name = "T2";
    T3.name = "T3";
    T4.name = "T4";
    T5.name = "T5";
    T6.name = "T6";
    T7.name = "T7";
    T8.name = "T8";
    T9.name = "T9";
    T_DUMMY.name = "DUMMY";

    T2.dependencies.push_back(T1);

    T6.dependencies.push_back(T2);
    T6.dependencies.push_back(T3);
    T6.dependencies.push_back(T4);

    T7.dependencies.push_back(T2);
    T7.dependencies.push_back(T3);

    T8.dependencies.push_back(T5);
    T8.dependencies.push_back(T2);

    T9.dependencies.push_back(T6);
    T9.dependencies.push_back(T7);
    T9.dependencies.push_back(T8);

    task_queue.push(T1);
    task_queue.push(T3);
    task_queue.push(T4);
    task_queue.push(T5);
    task_queue.push(T6);
    task_queue.push(T7);
    task_queue.push(T8);
    task_queue.push(T2);
    task_queue.push(T9);
}
