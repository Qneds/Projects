#include<conio.h>
#include<string>
#include<iostream>
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "Bst.h"
using namespace std;


//przyk³adowa implementacja tablicy ale tylko jest TYLKO szkielet 
//staramy siê unikaæ u¿ywania funkcji we/wy w klasie (opócz metody  display)



void displayMenuTable(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void displayMenuList(string info) {

	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun z przodu" << endl;
	cout << "3.Usun z tylu" << endl;
	cout << "4.Usun liczbe " << endl;
	cout << "5.Dodaj z przodu" << endl;
	cout << "6.Dodaj z tylu" << endl;
	cout << "7.Dodaj liczbe" << endl;
	cout << "8.Znajdz" << endl;
	cout << "9.Utworz losowo" << endl;
	cout << "q.Wyswietl" << endl;
	cout << "w.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";

}

void displayMenuHeap(string info) {

	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun element z korzenia" << endl;
	cout << "3.Usun element o podanej wartosci" << endl;
	cout << "4.Dodaj element" << endl;
	cout << "5.Znajdz" << endl;
	cout << "6.Utworz losowo" << endl;
	cout << "7.Wyswietl" << endl;
	cout << "8.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";

}


void displayMenuBST(string info) {

	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun element" << endl;
	cout << "3.Dodaj element" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

Table myTab; //myTab mo¿e byæ dynamiczna, mo¿e byc zadeklarowana w manu_table 
List myList;
Heap myHeap;
Bst myBST;

void menu_table()
{
	char opt;
	string fileName;
	int index, value;


	do {
		displayMenuTable("--- TABLICA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			myTab.loadFromFile(fileName);
			myTab.display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj index:";
			cin >> index;
			myTab.deleteFromTable(index);
			myTab.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj wartoœæ:";
			cin >> value;

			myTab.addValue(index, value);
			myTab.display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj waertoœæ:";
			cin >> value;
			if (myTab.IsValueInTable(value))
				cout << "poadana wartoœc jest w tablicy";
			else
				cout << "poadanej wartoœci NIE ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj iloœæ elementów tablicy:";
			cin >> value;
			myTab.generateTable(value);
			myTab.display();
			break;

		case '6':  //tutaj wyœwietlanie tablicy
			myTab.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			myTab.test();

			break;
		}

	} while (opt != '0');
}

void menu_list()
{
	char opt;
	string fileName;
	int value, index;


	do {
		displayMenuList("--- LISTA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie listy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			myList.loadFromFile(fileName);
			myList.display();
			break;

		case '2': //tutaj usuwanie pierwszego elementu z listy
			myList.popFront();
			myList.display();
			break;

		case '3': //tutaj usuwanie ostatniego elementu z listy
			myList.popBack();
			myList.display();
			break;

		case '4': //tutaj usuwanie elementu o podanej wartosci
			cout << "podaj wartosc do usuniecia:";
			cin >> value;
			myList.deleteValue(value);
			myList.display();
			break;

		case '5': //tutaj dodawanie elementu na przód listy
			cout << "podaj wartoœæ:";
			cin >> value;
			myList.pushFront(value);
			myList.display();
			break;

		case '6':  //tutaj dodawanie elementu na koniec listy
			cout << "podaj wartoœæ:";
			cin >> value;
			myList.pushBack(value);
			myList.display();
			break;

		case '7': //tutaj dodawanie elementu o podanej wartosci we wskazane miejsce
			cout << "podaj index:";
			cin >> index;
			cout << "\npodaj wartos:";
			cin >> value;
			myList.addValue(value, index);
			myList.display();
			break;

		case '8':  //tutaj znajdowanie elementu w liœcie
			cout << " podaj wartoœæ:";
			cin >> value;
			if (myList.isValueInList(value))
				cout << "poadana wartoœc jest w liscie";
			else
				cout << "poadanej wartoœci NIE ma w liscie";

			myList.display();
			break;

		case '9':  //tutaj losowe generowanie listy
			cout << " podaj rozmiar:";
			cin >> value;
			myList.createRandom(value);
			myList.display();
			break;

		case 'q' : //tutaj wyœwietlanie listy
			myList.display();
			break;

		case 'w': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			break;
		}

	} while (opt != '0');
}

void menu_heap()
{
	char opt;
	string fileName;
	int value;


	do {
		displayMenuHeap("--- STERTA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			myHeap.loadFromFile(fileName);
			myHeap.display();
			break;

		case '2': //tutaj usuwanie korzenia
			myHeap.pop();
			myHeap.display();
			break;
			
		case '3': //usuwanie elementu o podanej wartosci
			cout << " podaj wartoœæ:";
			cin >> value;
			myHeap.deleteValue(value);
			myHeap.display();
			break;

		case '4': //tutaj dodawanie elementu do sterty
			cout << " podaj wartoœæ:";
			cin >> value;
			myHeap.push(value);
			myHeap.display();
			break;

		case '5':  //tutaj znajdowanie elementu w stercie

			cout << " podaj wartoœæ:";
			cin >> value;
			if (myHeap.isValueInHeap(value))
				cout << "poadana wartoœc jest w stercie";
			else
				cout << "poadanej wartoœci NIE ma w stercie";

			myHeap.display();
			break;

		case '6':  //tutaj losowe generowanie sterty

			cout << " podaj rozmiar:";
			cin >> value;

			myHeap.createRandom(value);
			myHeap.display();
			break;

		case '7': //tutaj wyœwietlanie sterty
			myHeap.display();
			break;

		case '8': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			break;
		}

	} while (opt != '0');
}

void menu_BST() {

	char opt;
	string fileName;
	int value;

	do {
		displayMenuBST("---- BST ----");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie drzewa BST z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			myBST.loadFromFile(fileName);
			myBST.display();
			break;

		case '2': //tutaj usuwanie wartosci z drzewa BST
			cout << " podaj wartoœæ:";
			cin >> value;
			myBST.pop(value);
			myBST.display();
			break;

		case '3': //tutaj dodawanie wartosci do drzewa BST
			cout << " podaj wartoœæ:";
			cin >> value;
			myBST.push(value);
			myBST.display();
			break;

		case '4':  //tutaj znajdowanie wartoœci w drzewie BST

			cout << " podaj wartoœæ:";
			cin >> value;
			if (myBST.isValueInTree(value))
				cout << "poadana wartoœc jest w stercie";
			else
				cout << "poadanej wartoœci NIE ma w stercie";

			myBST.display();
			break;

		case '5':  //tutaj losowe generowanie drzewa BST

			cout << " podaj rozmiar:";
			cin >> value;

			myBST.createRandom(value);
			myBST.display();
			break;

		case '6': //tutaj wyœwietlanie drzewa BST
			myBST.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			break;
		}

	} while (opt != '0');

}

int main(int argc, char* argv[])
{

	char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "4.BST" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;
			
		case '4':
			menu_BST();
			break;
		}
		

	} while (option != '0');


	return 0;
}
