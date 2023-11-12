#include <iostream>
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/logger.h"
#include "IntQueue.h"
#include "QueueItemHandler.h"
#include <iostream>
spdlog::logger* logger;

void handlingService(QueueItemHandler handler) {
    handler.handle();
    char ID = handler.ID;
    int lastProcessed = handler.getLastProcessed();
    std::cout << lastProcessed;
    logger->info("Handler {} has handled item {}", ID, lastProcessed);
}

//void assignmentLoop(int random, QueueItemHandler* handler){
//    while (handler[random].isBusy()) {
//        random = rand() % (3 - 0 + 1) + 0;
//    }
//    if (!handler[random].isBusy()) {
//        handlingService(handler[random]);
//    }
//}

int main()
{
    try
    {
        logger = spdlog::basic_logger_mt("mainLogger", "logs/mainLog.txt").get();
        logger->info("Main logger created.");
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
    int cap = 40;
    IntQueue q(cap);
    for (int i = 0; i < 40; i++) {
        std::cout << "Adding to queue...\n";
        int add = i + 1;
        q.enqueue(add); //fill queue
        logger->info("Added {} to queue.", add);
    }

    QueueItemHandler handlerA(&q, 'A');
    QueueItemHandler handlerB(&q, 'B');
    QueueItemHandler handlerC(&q, 'C');
    QueueItemHandler handlerD(&q, 'D');

    QueueItemHandler handlers[4] = { handlerA, handlerB, handlerC, handlerD };

    while (!q.isEmpty()) {
        std::cout << "Assigning handler to queued item...\n";

        int which = rand() % (3 - 0 + 1) + 0;
        //std::thread t1;
        //std::thread t2;
        //std::thread t3;
        //std::thread t4;

        handlingService(handlers[which]);

        //t1.join();
        //t2.join();
        //t3.join();
        //t4.join();
    }
    return 0;
}
