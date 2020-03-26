#pragma once
#include <string>
constexpr auto HEAP_TAB_MAX = 10000;

using namespace std;


//pomocnicza struktura sluzaca do wyswietlania drzewa
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
	void display();						//wyswietl sterte
	void push(int val);					//dodaj wartosc na koniec sterty
	void pop();							//usun korzen i napraw sterte w dol
	void deleteValue(int val);			//usun konkretny wezel i napraw sterte wdol
	bool isValueInHeap(int val);		//czy sterta zawiera wartosc
	void createRandom(int size);		//wygeneruj losowa sterte
	int loadFromFile(string fileName);	//wczytaj sterte w pliku


private:
	int heapTab[HEAP_TAB_MAX] = { 0 }, size;				//alokacja tabeli do przechowynia sterty
	bool heapUp(int index);									//naprawa listy w gore
	bool heapDown(int index);								//naprawa listy w dol
	void printTree(int root, TrunkHeap* prev, bool isLeft);	//funkcja do rysowania drzewa
	int getLeft(int par);									//znajdz lewego potomka
	int getRight(int par);									//znajdz prawego potomka
	int getParent(int child);								//znajdz rodzica
	void showTrunks(TrunkHeap* p);							//funkcja pomocnicza przy rysowaniu drzewa
};

