#pragma once
#include <string>
constexpr auto HEAP_TAB_MAX = 10000;

using namespace std;

struct TrunkHeap {
	TrunkHeap* prev;
	string str;

	TrunkHeap(TrunkHeap* prev, string str) {
		this->prev = prev;
		this->str = str;
	}
};

class Heap
{
public :
	Heap();
	void display();
	void push(int val);
	void pop();
	void deleteValue(int val);
	bool isValueInHeap(int val);
	void createRandom(int size);
	int loadFromFile(string fileName);


private:
	int heapTab[HEAP_TAB_MAX] = { 0 }, size;
	bool heapUp(int index);
	bool heapDown(int index);
	void printTree(int root, TrunkHeap* prev, bool isLeft);
	int getLeft(int par);
	int getRight(int par);
	int getParent(int child);
	void showTrunks(TrunkHeap* p);
};

