#include "Heap.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

int COUNT = 10;

using namespace std;

Heap::Heap()
{
	size = 0;
	
}

void Heap::display()
{
	cout << "\n\n";
	printTree(0, NULL, false);
}

void Heap::push(int val)
{

	if (size >= HEAP_TAB_MAX) {
		cout << "\n\nSterta jest pe³na\n\n";
		return;
	}
	else
	{
		heapTab[size] = val;	//dodaj na koniec i napraw sterte w gore
		heapUp(size);
		size++;
	}

}

void Heap::pop()
{

	heapTab[0] = heapTab[--size];	//wstaw ostania wartosc w miejsce korzenia i napraw 
	heapDown(0);					// sterte w dol

}

void Heap::deleteValue(int val)
{


	for (int i = 0; i < size; i++) {		//przeszukaj tablice zawierajaca sterte aby 
		if (val == heapTab[i]) {			// aby znalezc wartosc do usuniecia
			heapTab[i] = heapTab[--size];	//wstaw ostania wartosc w miejsce wartosci do usuniecia 
			
			if (heapTab[i] > heapTab[getParent(i)]) {
				heapUp(i);
			}
			else if (heapTab[i] < heapTab[getParent(i)]) {
				heapDown(i);
			}		
			return;
		}
			
	}

	cout << "\nWartosci nie ma w stercie.\n\n";
}

bool Heap::isValueInHeap(int val)
{

	for (int i = 0; i < size; i++) {		//przeszukaj tablice zawierajaca sterte aby 
		if (val == heapTab[i])				// znalezc wartosc
			return true;
	}

	return false;
}

void Heap::createRandom(int size)
{

	srand(time(NULL));

	for (int i = 0; i < size; i++) {

		heapTab[i] = rand() % 100001;		//uzupelniaj kolejne miejsca w tablicy 
		heapUp(i);						// i naprawiaj sterte w gore
	}
	Heap::size = size;

}

int Heap::loadFromFile(string fileName)
{
	ifstream inf;
	inf.open(fileName);
	

	if (inf.is_open()) {

		int tmp;
		inf >> size;
		

		for (int i = 0; i < size; i++) {

			inf >> tmp;
			heapTab[i] = tmp;	//dodaj na koniec i napraw sterte w gore
			heapUp(i);
			

		}

	}
	else {
		cout << "Nie udalo sie odczytac pliku.\n\n";
	}

	return 0;
}

void Heap::test()
{
	ofstream inf;
	inf.open("Sterta-dane.txt");

	if (inf.is_open()) {

		srand(time(NULL));
		long long avg = 0;

		int sizeT = 2000, tmp = 0;;

		inf << "rozmiar;";
		inf << "czas dodawania elementu[ns];";
		inf << "czas uswania elementu[ns];";
		inf << "czas znajdowania losowego elementu[ns]";
		inf << endl;

		for (int i = 0; i < 20; i++) {

			createRandom(sizeT);
			inf << sizeT << ";";

			for (int l = 0; l < 100; l++) {
				tmp = rand() % 100001;
				auto t0 = std::chrono::high_resolution_clock::now();
				push(rand() % tmp);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {
				tmp = rand() % 100001;
				auto t0 = std::chrono::high_resolution_clock::now();
				deleteValue(tmp);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;


			for (int l = 0; l < 100; l++) {
				tmp = rand() % 100001;
				auto t0 = std::chrono::high_resolution_clock::now();
				isValueInHeap(tmp);
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

bool Heap::heapUp(int index)
{
	int parId = getParent(index), temp;

	if (heapTab[index] > heapTab[parId]) {

		if (index == 0)
			return true;

		temp = heapTab[index];				//podmien rodzica z potomkiem
		heapTab[index] = heapTab[parId];
		heapTab[parId] = temp;
		heapUp(parId);						//rob to samo dla rodzica tak dlugo, az rodzic
		return true;						// bedzie wiekszy od swoich potomkow
	}
	else
	{
		return true;
	}

}

bool Heap::heapDown(int index)
{
	int higher, left = getLeft(index), right = getRight(index);

	if (heapTab[left] > heapTab[right]) {
		higher = left;
	}
	else {
		higher = right;
	}

	if (heapTab[index] < heapTab[higher]) {			//podmien rodzica z wiekszym potomkiem
		left = heapTab[index];
		heapTab[index] = heapTab[higher];
		heapTab[higher] = left;
		heapDown(higher);							//rob to samo dla potomka tak dlugo, az
		return true;								// rodzic bedzie wiekszy od potomkow
	}
	else {
		return true;
	}

}

int Heap::getLeft(int par)
{
	return 2*par + 1;		//oblicz index lewego potomka
}

int Heap::getRight(int par)	
{
	return 2*par + 2;		//oblicz index prawego potomka
}

int Heap::getParent(int child)
{
	return (child - 1)/2;	//oblicz index rodzica
}


void Heap::showTrunks(TrunkHeap* p)
{
	if (p == NULL)
		return;

	showTrunks(p->prev);
	cout << p->str;
}

void Heap::printTree(int root, TrunkHeap* prev, bool isLeft) {
	if (size <= 0 || root >=size)
		return;

	string prev_str = "    ";
	TrunkHeap* trunk = new TrunkHeap(prev, prev_str);

	printTree(getRight(root), trunk, false);

	if (!prev)
		trunk->str = "---";
	else if (!isLeft) {
		trunk->str = ".---";
		prev_str = "   |";
	}
	else
	{
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	cout << heapTab[root] << endl;

	if (prev)
		prev->str = prev_str;

	trunk->str = "   |";

	printTree(getLeft(root), trunk, true);
}