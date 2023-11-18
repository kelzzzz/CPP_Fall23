#include <iostream>
#include <string>
#include <fstream>
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"

struct {
    std::string FILENAME = "items.txt";
    std::string NOTFOUND = "Item not found in dataset.\n";
    static const unsigned QUIT = 0;
    static const unsigned SEARCH = 1;
    static const unsigned NOSTATE = -1;
} constants;

spdlog::logger* logger;

void readFileInToArray(std::string filename, int fillarr[]);
std::string binarySearch(int arr[], int target);
void printOptions();

int main()
{
    int selection = constants.NOSTATE;
    int search = constants.NOSTATE;
    int dataset[10];

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

    readFileInToArray(constants.FILENAME, dataset);
    std::cout << "Dataset loaded. Please select an option.\n";

    while (selection != constants.QUIT) {
        printOptions();
        std::cin >> selection;
        switch (selection) {
            case(constants.QUIT):
                std::cout << "See ya later.\n";
                exit(0);
            case(constants.SEARCH):
                std::cout << "Enter an item to search for. \n";
                std::cin >> search;
                std::cout << "Searching for " << search << "\n";
                std::string result = binarySearch(dataset, search);
                std::cout << result;
                break;
            }
    }
}

void readFileInToArray(std::string filename, int fillarr[])
{
    int counter = 0;
    std::ifstream file(filename);
    std::string str;
    while (counter < 10 && std::getline(file, str)) //only accept 10 array items
    {
        int strToInt = stoi(str);
        fillarr[counter] = strToInt;
        counter++;
    }
    file.close();
    logger->info("Retrieved {} items from dataset.", counter);

    std::string loggerArr = "[";
    for (int i = 0; i < 10; i++) {
        loggerArr.append(std::to_string(fillarr[i]));
        if (i != 9) {
            loggerArr.append(", ");
        }
        else {
            loggerArr.append("]");
        }
    }
    logger->info(loggerArr);
    std::sort(fillarr, fillarr + 10);
    logger->info("Sorted array -->");
    std::string sortedLoggerArr = "[";
    for (int i = 0; i < 10; i++) {
        sortedLoggerArr.append(std::to_string(fillarr[i]));
        if (i != 9) {
            sortedLoggerArr.append(", ");
        }
        else {
            sortedLoggerArr.append("]");
        }
    }
    logger->info(sortedLoggerArr);
}

std::string binarySearch(int arr[], int target)
{
    logger->info("Attempting to search for {}", target);
    int benchmark=0;
    int low = 0;
    int high = 10;

    while (low <= high) {
        benchmark++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            std::string message;
            message.append("Found ");
            message.append(std::to_string(target));
            message.append(" at index ");
            message.append(std::to_string(mid));
            message.append("\n");
            logger->info("Target {} was found at index {} after {} loop(s).", target, mid, benchmark);
            return message;
        }
        if (arr[mid] < target) {
            logger->info("Middle lower than {}", target);
            low = mid + 1;
            logger->info("Set lowest to index {}", low);
            logger->info("New middle is index {}", mid);
        }
        else if (arr[mid] > target) {
            logger->info("Middle higher than {}", target);
            high = mid - 1;
            logger->info("Set highest to index {}", high);
            logger->info("New middle is index {}", mid);
        }
    }
    logger->info("Target {} was never found", target);
    return constants.NOTFOUND;
}
void printOptions() {
    std::cout << " 0: Quit\n 1: Run new search \n";
}
