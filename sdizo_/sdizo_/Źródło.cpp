#include<conio.h>
#include<string>
#include<iostream>
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "Bst.h"
using namespace std;


//przyk�adowa implementacja tablicy ale tylko jest TYLKO szkielet 
//staramy si� unika� u�ywania funkcji we/wy w klasie (op�cz metody  display)



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

Table myTab; //myTab mo�e by� dynamiczna, mo�e byc zadeklarowana w manu_table 
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
			cout << " Podaj nazw� zbioru:";
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
			cout << " podaj warto��:";
			cin >> value;

			myTab.addValue(index, value);
			myTab.display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj waerto��:";
			cin >> value;
			if (myTab.IsValueInTable(value))
				cout << "poadana warto�c jest w tablicy";
			else
				cout << "poadanej warto�ci NIE ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilo�� element�w tablicy:";
			cin >> value;
			myTab.generateTable(value);
			myTab.display();
			break;

		case '6':  //tutaj wy�wietlanie tablicy
			myTab.display();
			break;

		case '7': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
				  // mo�na sobie tu doda� w�asne case'y
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
			cout << " Podaj nazw� zbioru:";
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

		case '5': //tutaj dodawanie elementu na prz�d listy
			cout << "podaj warto��:";
			cin >> value;
			myList.pushFront(value);
			myList.display();
			break;

		case '6':  //tutaj dodawanie elementu na koniec listy
			cout << "podaj warto��:";
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

		case '8':  //tutaj znajdowanie elementu w li�cie
			cout << " podaj warto��:";
			cin >> value;
			if (myList.isValueInList(value))
				cout << "poadana warto�c jest w liscie";
			else
				cout << "poadanej warto�ci NIE ma w liscie";

			myList.display();
			break;

		case '9':  //tutaj losowe generowanie listy
			cout << " podaj rozmiar:";
			cin >> value;
			myList.createRandom(value);
			myList.display();
			break;

		case 'q' : //tutaj wy�wietlanie listy
			myList.display();
			break;

		case 'w': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
				  // mo�na sobie tu doda� w�asne case'y
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
			cout << " Podaj nazw� zbioru:";
			cin >> fileName;
			myHeap.loadFromFile(fileName);
			myHeap.display();
			break;

		case '2': //tutaj usuwanie korzenia
			myHeap.pop();
			myHeap.display();
			break;
			
		case '3': //usuwanie elementu o podanej wartosci
			cout << " podaj warto��:";
			cin >> value;
			myHeap.deleteValue(value);
			myHeap.display();
			break;

		case '4': //tutaj dodawanie elementu do sterty
			cout << " podaj warto��:";
			cin >> value;
			myHeap.push(value);
			myHeap.display();
			break;

		case '5':  //tutaj znajdowanie elementu w stercie

			cout << " podaj warto��:";
			cin >> value;
			if (myHeap.isValueInHeap(value))
				cout << "poadana warto�c jest w stercie";
			else
				cout << "poadanej warto�ci NIE ma w stercie";

			myHeap.display();
			break;

		case '6':  //tutaj losowe generowanie sterty

			cout << " podaj rozmiar:";
			cin >> value;

			myHeap.createRandom(value);
			myHeap.display();
			break;

		case '7': //tutaj wy�wietlanie sterty
			myHeap.display();
			break;

		case '8': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
				  // mo�na sobie tu doda� w�asne case'y
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
			cout << " Podaj nazw� zbioru:";
			cin >> fileName;
			myBST.loadFromFile(fileName);
			myBST.display();
			break;

		case '2': //tutaj usuwanie wartosci z drzewa BST
			cout << " podaj warto��:";
			cin >> value;
			myBST.pop(value);
			myBST.display();
			break;

		case '3': //tutaj dodawanie wartosci do drzewa BST
			cout << " podaj warto��:";
			cin >> value;
			myBST.push(value);
			myBST.display();
			break;

		case '4':  //tutaj znajdowanie warto�ci w drzewie BST

			cout << " podaj warto��:";
			cin >> value;
			if (myBST.isValueInTree(value))
				cout << "poadana warto�c jest w stercie";
			else
				cout << "poadanej warto�ci NIE ma w stercie";

			myBST.display();
			break;

		case '5':  //tutaj losowe generowanie drzewa BST

			cout << " podaj rozmiar:";
			cin >> value;

			myBST.createRandom(value);
			myBST.display();
			break;

		case '6': //tutaj wy�wietlanie drzewa BST
			myBST.display();
			break;

		case '7': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
				  // mo�na sobie tu doda� w�asne case'y
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
