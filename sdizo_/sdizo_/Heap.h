#pragma once
#include <string>

using namespace std;

class Heap
{
	void display();
	bool isValueInHeap(int val);
	void createRandom(int size);
	int loadFromFile(string fileName);
};

