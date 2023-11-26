#pragma once
#include <vector>
#include <string>
enum Status {
    READY, BUSY
};

struct Task {
    double duration = 0;
    std::vector<Task> dependencies;
    std::string name;
    bool dummy = false;

};
