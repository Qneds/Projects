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
}

void List::addValue(int value, int index)
{

	if (head == NULL) {
		head = new ElementList;
		head->value = 0;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
	}
	
	ElementList* tmp = head, *tmp_if_null;

	for (int i = 0; i < index ; i++) {
		if (tmp->next != NULL) {
			tmp = tmp->next;
		}
		else {
			tmp_if_null = tmp;
			tmp = new ElementList;
			tmp->value = 0;
			tmp->next = NULL;
			tmp->prev = tmp_if_null;
			tmp_if_null->next = tmp;
			tail = tmp;
		}
	}

	if (tmp->next == NULL) {
		tmp_if_null = tmp;
		tmp = new ElementList;
		tmp->value = value;
		tmp->next = NULL;
		tmp->prev = tmp_if_null;
		tmp_if_null->next = tmp;
		tail = tmp;
	}
	else {
		tmp_if_null = tmp->next;
		tmp = new ElementList;
		tmp->value = value;
		tmp->next = tmp_if_null;
		tmp->prev = tmp_if_null->prev;
		tmp_if_null->prev = tmp;
		tmp->prev->next = tmp;
	}

}

void List::deleteValue(int value)
{

	ElementList* tmp = head;

	if (tmp != NULL) {

		

	}
	else
	{
		cout << "Lista jest pusta.\n\n";
	}

}

void List::display()
{
	cout << "\n\n";
	
	cout << "---------------------" << endl;
	
	cout << "|         |  przod  | ";
	

	ElementList* tmp = head;

	while (tmp) {
		cout << tmp->value << " | ";
		tmp = tmp->next;
	}

	cout << endl;

	cout << "|  LISTA  |---------|" << endl;
	cout << "|         |   tyl   | ";
	
	tmp = tail;

	while (tmp) {
		cout << tmp->value << " | ";
		tmp = tmp->prev;
	}
	cout << "\n---------------------" << endl;
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

void List::createRandom(int size)
{
	ElementList *tmpEl;
	srand(time(NULL));

	deleteList();

	head = new ElementList;
	head->value = rand() % 1001;
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

		while (!inf.eof()) {

			tmpEl = new ElementList;
			inf >> tmpEl->value;
			tmpEl->next = NULL;
			tmpEl->prev = tail;
			tail->next = tmpEl;
			tail = tmpEl;

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
	}

}


