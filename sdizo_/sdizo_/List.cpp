#include "List.h"
#include <cstddef>
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

List::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

void List::popFront()
{
	ElementList* p = head;

	if (head) {

		head = p->next;
		if (head) {
			head->prev = NULL;
		}
		else {
			tail = NULL;
		}
	}

	if (p) {
		delete p;
		size--;
	}


}

void List::pushFront(int value)
{
	ElementList* newEl;

	newEl = new ElementList;
	newEl->value = value;
	if (head != NULL) {
		newEl->next = head;
		head->prev = newEl;
		head = newEl;
	}
	else {
		newEl->next = NULL;
		head = newEl;
		tail = newEl;
	}

	newEl->prev = NULL;
	size++;

}

void List::popBack()
{ 
	ElementList* p = tail;

	if (tail)
	{
		tail = p->prev;
		if (tail) {
			tail->next = NULL;
		}
		else {
			head = NULL;
		}
	}

	if (p) {
		delete p;
		size--;
	}
}

void List::pushBack(int value)
{
	ElementList* newEl;

	newEl = new ElementList;
	newEl->value = value;
	
	if (tail != NULL) {
		newEl->prev = tail;
		tail->next = newEl;
		tail = newEl;
	}
	else {
		newEl->prev = NULL;
		head = newEl;
		tail = newEl;
	}
	newEl->next = NULL;
	size++;
}

void List::addValue(int value, int index)
{
	
 
	if (index >= 0)
	{

		if (head == NULL) {

			head = new ElementList;
			head->value = 0;
			head->prev = NULL;
			head->next = NULL;
			tail = head;
		}


		ElementList* tmp = head,* insert;
		


		if (index < size) {

			for (int i = 0; i < index; i++) {
				tmp = tmp->next;
			}

			insert = new ElementList;

			insert->value = value;
			insert->next = tmp;
			insert->prev = tmp->prev;
			
			if (insert->prev) {
				insert->prev->next = insert;
			}
			else {
				head = insert;
			}
			
			if (insert->next) {
				insert->next->prev = insert;
			}
			else {
				tail = insert;
			}
			
			

		}
		else {

			for (int i = 1; i < index; i++) {
				
				if (tmp->next) {
					tmp = tmp->next;
				}
				else {
					insert = new ElementList;

					insert->value = 0;
					insert->next = NULL;
					insert->prev = tmp;
					tmp->next = insert;
					tmp = insert;
					tail = tmp;
				}
			}

			insert = new ElementList;

			insert->value = value;
			insert->next = NULL;
			insert->prev = tmp;
			tmp->next = insert;
			tmp = insert;
			tail = tmp;

		}

		size++;
	}
	else {
		cout << "\nIndex nie moze byc nieujemny\n\n";
	}

}

void List::deleteValue(int value)
{

	ElementList* tmp = head;

	while (tmp != NULL) {
		
		if (tmp->value == value) {
			

			if (tmp->prev != NULL) {
				tmp->prev->next = tmp->next;
			}
			else {
				head = tmp->next;
			}

			if (tmp->next != NULL) {
				tmp->next->prev = tmp->prev;
			}
			else {
				tail = tmp->prev;
			}

			delete tmp;
			size--;

			return;
		}
		else
		{
			tmp = tmp->next;
		}

	}

	cout << "Wartosci nie ma w liscie\n";

}

void List::display()
{
	cout << "\n\n";
	
	
	

	ElementList* tmp = head;

	while (tmp) {
		cout << tmp->value << " ";
		tmp = tmp->next;
	}

	cout << endl;

	
	
	tmp = tail;

	while (tmp) {
		cout << tmp->value << " ";
		tmp = tmp->prev;
	}
	
	cout << "\n\n";

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

void List::createRandom(int sizen)
{
	if (sizen > 0)
	{
		ElementList* tmpEl;
		srand(time(NULL));

		deleteList();

		head = new ElementList;
		head->value = rand() % 1001;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
		size++;

		for (int i = 0; i < size - 1; i++)
		{
			tmpEl = new ElementList;
			tmpEl->value = rand() % 1001;
			tmpEl->next = NULL;
			tmpEl->prev = tail;
			tail->next = tmpEl;
			tail = tmpEl;
			size++;
		}

	}
	else {
		cout << "\nNie mo¿na utworzyæ listy o podanej dlugosci.\n\n";
	}

}

int List::loadFromFile(string fileName)
{
	ifstream inf;
	inf.open(fileName);

	if (inf.is_open()) {

		ElementList *tmpEl;
		deleteList();

		head = new ElementList;

		inf >> head->value;

		inf >> head->value;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
		size++;

		while (!inf.eof()) {

			tmpEl = new ElementList;
			inf >> tmpEl->value;
			tmpEl->next = NULL;
			tmpEl->prev = tail;
			tail->next = tmpEl;
			tail = tmpEl;
			size++;
		}

	}
	else {
		cout << "Nie udalo sie odczytac pliku.\n\n";
	}

	return 0;
}

void List::deleteList()
{
	ElementList* current = head;
	ElementList* next;

	while (current != NULL) {
		next = current->next;
		delete current;
		current = next;
		size--;
	}

}


