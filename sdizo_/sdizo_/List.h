#pragma once
#include <string>

using namespace std;


//element przechowuj¹cy wartoœæ w liœcie
struct ElementList
{
	int value;
	ElementList* next, * prev;
};

class List
{

public:
	List();
	void popFront();						//usun z przodu
	void pushFront(int value);				//dodaj na przod
	void popBack();							//usun z tylu
	void pushBack(int value);				//dodaj na tyl
	void addValue(int value, int index);	//dodaj we wskazane miejsce
	void deleteValue(int value);			//usun podana wartosc
	void display();							//wyswietl liste
	bool isValueInList(int val);			//czy wartosc jest w liscie
	void createRandom(int size);			//wygeneruj liste
	int loadFromFile(string fileName);		//wczytaj liste
	void test();							//funkcja do testow
	
	ElementList* head, *tail;				//zmienne okreslajace poczatek i koniec listy
	int size;								//zmienna okreslajaca rozmiar listy

private:
	void deleteList();						//funkcja do usuwania ca³ej listy

};

