#include "List.h"
#include <cstddef>
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

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

	if (head) {			//jezeli lista nie jest pusta

		head = p->next;
		if (head) {				//jezeli lista nie jest jednoelementowa
			head->prev = NULL;
		}
		else {					//w przeciwnym przpadku po tej operacji bêdzie pusta
			tail = NULL;
		}
	}

	if (p) {
		delete p;		//jezeli usuwasz, zmniejsz rozmiar
		size--;
	}


}

void List::pushFront(int value)
{
	ElementList* newEl;

	newEl = new ElementList;		//utworz element do wstawienia
	newEl->value = value;
	if (head != NULL) {				//jezeli jest pusta to nowy element 
		newEl->next = head;			//  bedzie poczatkiem i koncem listy
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

	if (tail)					//jezeli lista nie jest pusta
	{
		tail = p->prev;
		if (tail) {				//jezeli lista nie jest jednoelementowa
			tail->next = NULL;
		}
		else {					//w przeciwnym przpadku po tej operacji bêdzie pusta
			head = NULL;
		}
	}

	if (p) {
		delete p;				//jezeli usuwasz, zmniejsz rozmiar
		size--;
	}
}

void List::pushBack(int value)
{
	ElementList* newEl;

	newEl = new ElementList;		//utworz element do wstawienia
	newEl->value = value;
	
	if (tail != NULL) {				//jezeli jest pusta to nowy element
		newEl->prev = tail;			//  bedzie poczatkiem i koncem listy
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
	
 
	if (index >= 0)				//indexy musza byc nieujemne
	{

		if (head == NULL) {		//jezeli list pusta to utworz

			head = new ElementList;
			head->value = 0;
			head->prev = NULL;
			head->next = NULL;
			tail = head;
		}


		ElementList* tmp = head,* insert;
		


		if (index < size) {						//przypadek, kiedy index jest mniejszy
												// ni¿ rozmiar -> nie trzeba rozszerzac
			for (int i = 0; i < index; i++) {	// listy o pozycje z zerem
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
				head = insert;			//kiedy wstawiamy na pierwesza pozycje 
			}
			
			if (insert->next) {
				insert->next->prev = insert;
			}
			else {						//kiedy wstawiamy na ostatnia pozycje
				tail = insert;
			}
			
			

		}
		else {							//przypadek kiedy index jest wiekszy od
										// od rozmiaru list -> trzeba rozszerzyc
			for (int i = 1; i < index; i++) {
				
				if (tmp->next) {
					tmp = tmp->next;
				}
				else {
					insert = new ElementList;		//rozszerzanie listy o pozycje z 0

					insert->value = 0;
					insert->next = NULL;
					insert->prev = tmp;
					tmp->next = insert;
					tmp = insert;
					tail = tmp;
				}
			}

			if (index != 0)					//przypadek, kiedy lista nie wstawiamy na poczatek 
			{								
				insert = new ElementList;
				insert->value = value;
				insert->next = NULL;
				insert->prev = tmp;
				tmp->next = insert;
				tmp = insert;
				tail = tmp;
			}
			else {
				tmp->value = value;			//przypadek, kiedy lista jest pusta 
			}								// i wstawiamy na poczatek -> wpisujemy wartosc
											// do wczesniej utworzonego elementu
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

	while (tmp != NULL) {						//znajdz element do usuniecia
		
		if (tmp->value == value) {
			

			if (tmp->prev != NULL) {			//kiedy element nie jest poczatkiem
				tmp->prev->next = tmp->next;
			}
			else {								//kiedy element jest poczatkiem
				head = tmp->next;
			}

			if (tmp->next != NULL) {			//kiedy element nie jest koncem
				tmp->next->prev = tmp->prev;
			}
			else {								//kiedy element jest koncem
				tail = tmp->prev;
			}

			delete tmp;
			size--;

			return;
		}
		else
		{
			tmp = tmp->next;					//szukaj dalej
		}

	}

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

	while (tmpFront)					//znajdz element
	{
		if (tmpFront->value == val) {
			return true;				//znaleziono
		}
		else
		{
			tmpFront = tmpFront->next;	//szukaj dalej
		}
	}

	return false;						//nie znaleziono
}

void List::createRandom(int sizen)
{
	if (sizen > 0)						//rozmiar musi byc dodatni
	{
		ElementList* tmpEl;
		srand(time(NULL));

		deleteList();					//usun poprzednia liste

		head = new ElementList;			//utworz pierwszy element
		head->value = rand() % 1001;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
		size++;

		for (int i = 0; i < size - 1; i++)		//dodawaj nastepne elementy
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
		deleteList();				//usun poprzednia liste

		head = new ElementList;		//utworz pierwszy element

		inf >> head->value;

		inf >> head->value;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
		size++;

		while (!inf.eof()) {		//dodawaj nastepne elementy

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

void List::test()
{
	ofstream inf;
	inf.open("Lista-dane.txt");

	if (inf.is_open()) {

		srand(time(NULL));
		long long avg = 0;

		int sizeT = 2000;

		inf << "rozmiar;czas dodawania na poczatek[ns];";
		inf << "czas dodawania na koniec[ns];";
		inf << "czas dodawania w losowe miejsce[ns];";
		inf << "czas uswania z poczatku[ns];";
		inf << "czas usuwania z konca[ns];";
		inf << "czas usuwania z losowego miejsca[ns];";
		inf << "czas znajdowania losowego elementu[ns]";
		inf << endl;

		for (int i = 0; i < 20; i++) {

			createRandom(sizeT);
			inf << sizeT << ";";

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				pushFront(rand() % 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				pushBack(rand() % 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				addValue(rand() % size, rand() % 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";


			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				popFront();
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				popBack();
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				deleteValue(rand() % 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				isValueInList(rand() % 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;


			inf << avg << "\n";

			sizeT += 2000;

		}

		inf.close();

	}


}

void List::deleteList()
{
	ElementList* current = head;
	ElementList* next;

	while (current != NULL) {			//usun po oklei wszystkie elementy
		next = current->next;
		delete current;
		current = next;
		size--;
	}

}


