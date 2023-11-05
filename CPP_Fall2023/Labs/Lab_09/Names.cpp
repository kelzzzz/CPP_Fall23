#include "Names.h"
#include <fstream>
#include <map>
#include <string>
#include <iostream>
Names::Names(const std::string filepath)
{
    this->filepath = filepath;
    std::map<std::string, std::string> init;
    this->mapOfNames = init;
    std::ifstream file(this->filepath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string s = line;
            std::string delimiter = " ";
            std::string key = s.substr(0, s.find(delimiter));
            std::string value = s.substr(s.find(delimiter)+1, s.length()-1);
            this->mapOfNames.insert(std::pair<std::string, std::string>(key, value));
        }
        file.close();
    }
}

std::string Names::search(std::string key)
{
    if (keyExists(key)) {
        return this->mapOfNames.at(key);
    }
    else {
        return "Name not found.";
    }
}

void Names::printMap()
{
    for (auto it = this->mapOfNames.cbegin(); it != this->mapOfNames.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
}

void Names::remove(std::string key)
{
    this->mapOfNames.erase(key);
}

int Names::size()
{
    return this->mapOfNames.size();
}
void Names::update(std::string key, std::string first) {
    this->mapOfNames.insert_or_assign(key, first);
}
bool Names::keyExists(std::string key)
{
    if (this->mapOfNames.find(key) != this->mapOfNames.end()) {
        return true;
    }
    else {
        return false;
    }
}
