#pragma once
#include <string>

using namespace std;

class Heap
{
public :
	Heap();
	void display();
	bool isValueInHeap(int val);
	void createRandom(int size);
	int loadFromFile(string fileName);

private:
	int heapTab[1000] = { 0 }, size;
	bool heapUp(int index);
	bool heapDown(int index);
	void print2DUtil(int root, int space);
	int getLeft(int par);
	int getRight(int par);
	int getParent(int child);
};

