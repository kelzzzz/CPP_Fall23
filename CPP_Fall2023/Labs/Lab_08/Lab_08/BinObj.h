#pragma once
#include <vector>
class BinObj
{
public:
	BinObj(int capacity);
	void pack(int toPack);
	void setCapacity(int cap);
	int getCapacity();
	int getContents(int iterator);
	void setBinId(char id);
	char getBinId();
	void printBin();
	void clearBin();
	bool isEmpty();
	bool canPack(int toPack);
	//void removeFromBin(int remove);
private:
	std::vector<int> contents;
	int capacity;
	char binId;
};

