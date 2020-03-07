#include "List.h"
#include <cstddef>
#include <iostream>
#include <time.h>

using namespace std;

List::List()
{
}

void List::popFront()
{
	ElementList* p = head;

	if (head) {

		head = p->next;
		head->prev = NULL;
	}

	if (p) {
		delete p;
	}


}

void List::pushFront(int value)
{
	ElementList* newEl;

	newEl = new ElementList;
	newEl->value = value;
	newEl->next = head;
	newEl->prev = NULL;
	head->prev = newEl;
	head = newEl;

}

void List::popBack()
{ 
	ElementList* p = tail;

	if (tail)
	{
		tail = p->prev;
		tail->next = NULL;
	}

	if (p) {
		delete p;
	}
}

void List::pushBack(int value)
{
	ElementList* newEl;

	newEl = new ElementList;
	newEl->value = value;
	tail->next = newEl;
	newEl->prev = tail;
	newEl->next = NULL;
	tail = newEl;
}

void List::display()
{
	cout << "\n\n";
	cout << "---------------------" << endl;
	cout << "|       LISTA       |" << endl;
	cout << "---------------------" << endl;
	cout << "|   przod   |  tyl  |" << endl;
	cout << "---------------------" << endl;

	ElementList* tmpFront = head, * tmpBack = tail;

	while (tmpFront) {
		cout << "| " << tmpFront->value << " | " << tmpBack->value << " |" << endl;

		tmpFront = tmpFront->next;
		tmpBack = tmpBack->prev;
	}

}

bool List::isValueInList(int val)
{
	ElementList* tmpFront = head;

	while (tmpFront)
	{
		if (tmpFront->value == val) {
			return true;
		}
		else
		{
			tmpFront = tmpFront->next;
		}
	}

	return false;
}

void List::createRandom(int size)
{
	ElementList *tmpEl;
	srand(time(NULL));

	head = new ElementList;
	head->prev = NULL;
	head->next = NULL;
	tail = head;

	for (int i = 0; i < size - 1; i++)
	{
		tmpEl = new ElementList;
		tmpEl->value = rand() % 1001;
		tmpEl->next = NULL;
		tmpEl->prev = tail;
		tail->next = tmpEl;
		tail = tmpEl;
	}


}

int List::loadFromFile(string fileName)
{
	return 0;
}
