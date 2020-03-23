#pragma once
#include <string>
constexpr auto HEAP_TAB_MAX = 10000;

using namespace std;

class Heap
{
public :
	Heap();
	void display();
	void push(int val);
	void pop();
	bool isValueInHeap(int val);
	void createRandom(int size);
	int loadFromFile(string fileName);

private:
	int heapTab[HEAP_TAB_MAX] = { 0 }, size;
	bool heapUp(int index);
	bool heapDown(int index);
	void print2DUtil(int root, int space);
	int getLeft(int par);
	int getRight(int par);
	int getParent(int child);
};

