#include<conio.h>
#include<string>
#include<iostream>
#include "Table.h"
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


Table myTab; //myTab mo¿e byæ dynamiczna, mo¿e byc zadeklarowana w manu_table 

void menu_table()
{
	char opt;
	string fileName;
	int index, value;

	//if (&myTab != NULL) {
	//	delete &myTab;
	//}


	myTab = Table::Table();


	do {
		displayMenu("--- TABLICA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			cout << "\n" << myTab.loadFromFile(fileName) << endl;
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
			cout << " podaj waertoœæ:";
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
	//analogicznie jak menu_table()
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
