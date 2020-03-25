#pragma once
#include <string>

using namespace std;

struct ElementList
{
	
	int value;
	ElementList* next, * prev;
};

class List
{

public:
	List();
	void popFront();
	void pushFront(int value);
	void popBack();
	void pushBack(int value);
	void addValue(int value, int index);
	void deleteValue(int value);
	void display();
	bool isValueInList(int val);
	void createRandom(int size);
	int loadFromFile(string fileName);

	ElementList* head, *tail;
	int size;

private:
	void deleteList();

};

