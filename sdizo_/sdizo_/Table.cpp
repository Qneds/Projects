#include "Table.h"
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

Table::Table() {
	Table::tab = new int[1];
	Table::cnt = 0;
}

int Table::loadFromFile(string FileName) {

	ifstream inf;
	
	int size = 0;

	
	inf.open(FileName, ifstream::in);

	if (inf.is_open()) {

		inf >> size;

		if (size > 0) {

			delete tab;
			tab = new int[size];

			int i = 0;
			while (inf.eof())
			{
				inf >> tab[i];
				i++;
			}

		}

		inf.close();

	}
	else {
		cout << "B³¹d w odczycie pliku\n\n";
	}

	return 0;
}

bool Table::IsValueInTable(int val) {

	for (int i = 0; i < cnt; i++) {

		if (val == tab[i]) {
			return true;
		}

	}

	return false;
}

void Table::addValue(int index, int value) {

	if (index >= 0) {

		int* tempTab;
		int newS = 0, oldTabCnt = 0;

		if (index <= cnt) {
			newS = cnt + 1;
		}
		else {
			newS = index + 1;
		}

		tempTab = new  int[newS];

		for (int i = 0; i < newS; i++) {
			if (i == index) {
				tempTab[i] = value;
			}
			else if (oldTabCnt < cnt) {
				tempTab[i] = tab[oldTabCnt];
				oldTabCnt++;
			}
			else {
				tempTab[i] = 0;
			}
		}

		cnt = newS;
		delete tab;
		tab = tempTab;

	}
	else {
		cout << "\n\nIndex nie moze byc ujemny\n\n";
	}

}

void Table::deleteFromTable(int index) {

	if (index >= 0 && index < cnt) {

		int newS = cnt - 1, tmpCn = 0;
		int* temp = new int[newS];

		for (int i = 0; i < cnt; i++) {
			if (index != i) {
				temp[tmpCn] = tab[i];
				tmpCn++;
			}
		}

		delete tab;
		tab = temp;
		cnt = newS;

	}
	else {
		cout << "\n\nWartoœæ spoza zekresu indexow\n\n";
	}

}

void Table::display() {

	cout << "\n\n";
	cout << "---------------------" << endl;
	cout << "|       TABELA       |" << endl;
	cout << "---------------------" << endl;
	cout << "|   id   |  wartosc  |" << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < cnt; i++) {
		cout << "| " << i << " | " << tab[i] << " |" << endl;
	}

}

void Table::generateTable(int size) {


	srand(time(NULL));

	delete tab;
	cnt = size;
	tab = new int[cnt];

	for (int i = 0; i < cnt; i++) {
		tab[i] = rand() % 1001;
	}

}


