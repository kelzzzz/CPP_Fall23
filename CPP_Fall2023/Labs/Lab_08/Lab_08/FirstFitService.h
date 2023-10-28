#pragma once
#include <vector>
#include "BinObj.h"
class FirstFitService
{
public:
	FirstFitService(std::vector<int> toPack, int binCapacity);
	void fillBins();
private:
	std::vector<BinObj> bins;
	std::vector<int> toPack;
};

