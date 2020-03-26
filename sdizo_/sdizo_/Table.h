#pragma once

#include<conio.h>
#include<string>
#include<iostream>

using namespace std;

class Table
{
	int* tab;
	int cnt; //iloœæ elementów w tablicy
public:

	Table();

	int loadFromFile(string FileName);		//wczytaj liste
	bool IsValueInTable(int val);			//czy tabela zawiera wartosc
	void addValue(int index, int value);	//dodaj we wskazane miejsce
	void deleteFromTable(int index);		//usun wartosc o podanym indexie
	void display();							//wyswietl tabele
	void generateTable(int size);			//wygeneruj liste
	void test();

};

