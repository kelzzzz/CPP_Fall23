#include "BinObj.h"
#include <iostream>
BinObj::BinObj(int capacity)
{
	this->capacity = capacity;
	this->binId = 'T';
}

void BinObj::pack(int toPack)
{
	this->contents.push_back(toPack);
}

void BinObj::setCapacity(int cap)
{
	this->capacity = cap;
}

int BinObj::getCapacity()
{
	return this->capacity;
}

int BinObj::getContents(int iterator)
{
	if (!iterator > contents.size()) {
		return contents[iterator];
	}
	else {
		throw std::runtime_error("Attempted access to BinObj.contents out of array bounds ");
	}
}

void BinObj::setBinId(char id)
{
	this->binId = id;
}

char BinObj::getBinId()
{
	return this->binId;
}

void BinObj::printBin()
{
	std::cout << "|BIN " << this->binId << " {";
	for (auto const &c : this->contents) {
		std::cout << c << " ";
	}
	std::cout << "}|";
}

void BinObj::clearBin()
{
	this->contents.clear();
}

bool BinObj::isEmpty()
{
	if (this->contents.empty()) {
		return true;
	}
	else {
		return false;
	}
}

bool BinObj::canPack(int toPack)
{
	int totalContents = 0;
	for (auto const& c : this->contents) {
		totalContents += c;
	}
	if (toPack > 0) {
		int nextSize = totalContents + toPack;
		if(nextSize <= capacity) {
			return true;
		}
	}
	return false;
}
