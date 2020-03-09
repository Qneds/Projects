#include<conio.h>
#include<string>
#include<iostream>
#include "Table.h"
#include "List.h"
using namespace std;


//przyk³adowa implementacja tablicy ale tylko jest TYLKO szkielet 
//staramy siê unikaæ u¿ywania funkcji we/wy w klasie (opócz metody  display)



void displayMenu(string info)
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
	cout << "4.Dodaj z przodu" << endl;
	cout << "5.Dodaj z tylu" << endl;
	cout << "6.Znajdz" << endl;
	cout << "7.Utworz losowo" << endl;
	cout << "8.Wyswietl" << endl;
	cout << "9.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";

}


Table myTab; //myTab mo¿e byæ dynamiczna, mo¿e byc zadeklarowana w manu_table 
List myList;

void menu_table()
{
	char opt;
	string fileName;
	int index, value;


	do {
		displayMenu("--- TABLICA ---");
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
			break;
		}

	} while (opt != '0');
}

void menu_list()
{
	char opt;
	string fileName;
	int value;


	do {
		displayMenuList("--- LISTA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
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

		case '4': //tutaj dodawanie elementu na przód listy
			cout << " podaj wartoœæ:";
			cin >> value;
			myList.pushFront(value);
			myList.display();
			break;

		case '5':  //tutaj dodawanie elementu na koniec tablicy
			cout << " podaj wartoœæ:";
			cin >> value;
			myList.pushBack(value);
			myList.display();
			break;

		case '6':  //tutaj znajdowanie elementu w liœcie

			cout << " podaj wartoœæ:";
			cin >> value;
			if (myList.isValueInList(value))
				cout << "poadana wartoœc jest w tablicy";
			else
				cout << "poadanej wartoœci NIE ma w tablicy";

			myList.display();
			break;

		case '7':  //tutaj losowe generowanie listy

			cout << " podaj rozmiar:";
			cin >> value;

			myList.createRandom(value);
			myList.display();
			break;

		case '8' : //tutaj wyœwietlanie listy
			myList.display();
			break;

		case '9': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			break;
		}

	} while (opt != '0');
}

void menu_heap()
{
	//analogicznie jak menu_table()
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
		}

	} while (option != '0');


	return 0;
}
