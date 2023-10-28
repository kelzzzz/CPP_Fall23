#include "NextFitService.h"
#include <vector>
#include "BinObj.h"
#include <iostream>

NextFitService::NextFitService(std::vector<int> toPack, int binCapacity)
{
	char id = 'A';
	for (int i = 0; i < toPack.size(); i++) {
		BinObj bin = BinObj(binCapacity);
		bin.setBinId(id);
		id++;
		this->bins.push_back(bin); //fill our bin array with the maximum number of potential bins
	}
	for(int j = toPack.size()-1; j >= 0; j--) {
		this->stackToPack.push(toPack[j]);
	}
}

void NextFitService::fillBins()
{
	for (auto& b : this->bins) {
		while (!stackToPack.empty() && b.canPack(stackToPack.top())) {
			b.pack(stackToPack.top());
			stackToPack.pop();
		}
	}

	for (auto& b : this->bins) {
		b.printBin();
	}
	std::cout << "\n";
}
