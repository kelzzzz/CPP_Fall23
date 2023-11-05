#pragma once
#include <map>
#include <string>

class Names
{
public:
	Names(const std::string filepath);
	std::string search(std::string key);
	void printMap();
	void remove(std::string key);
	int size();
	void update(std::string key, std::string first);
	bool keyExists(std::string key);
private:
	std::map<std::string, std::string> mapOfNames;
	std::string filepath;
};

