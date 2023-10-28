#include "FirstFitService.h"
#include <vector>
#include "BinObj.h"
#include <iostream>
FirstFitService::FirstFitService(std::vector<int> toPack, int binCapacity)
{
	this->toPack = toPack;
	char id = 'A';
	for (int i = 0; i < toPack.size(); i++) {
		BinObj bin = BinObj(binCapacity);
		bin.setBinId(id);
		id++;
		this->bins.push_back(bin); //fill our bin array with the maximum number of potential bins
	}
}

void FirstFitService::fillBins()
{
	for (auto& p : this->toPack) {
		for (auto& b : this->bins) {
			if (b.canPack(p)) {
				b.pack(p);
				break;
			}
		}
	}

	for (auto& b : this->bins) {
		b.printBin();
	}
	std::cout << "\n";
}
