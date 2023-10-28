#pragma once
#include <vector>
#include "BinObj.h"
#include <stack>
class NextFitService
{
public:
	NextFitService(std::vector<int> toPack, int binCapacity);
	void fillBins();
private:
	std::vector<BinObj> bins;
	std::stack<int> stackToPack;
};

