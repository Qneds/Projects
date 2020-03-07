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

	int loadFromFile(string FileName);

	bool IsValueInTable(int val);

	void addValue(int index, int value);

	void deleteFromTable(int index);

	void display();

	void generateTable(int size);

};

