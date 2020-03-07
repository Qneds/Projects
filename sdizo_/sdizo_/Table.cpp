#include "Table.h"
#include <time.h>
#include <fstream>


using namespace std;




Table::Table() {
	tab = new int[1];
	cnt = 0;
}

int Table::loadFromFile(string FileName) {
	
	ifstream in;
	in.open(FileName);

	if (in.good()) {

		int numberLines = 0;

		while (!in.eof()) {
			numberLines++;
		}

		in.close();

		in.open(FileName);

		if (in.good()) {

			tab = new int[numberLines];
			cnt = numberLines;
			int i = 0;
			while (!in.eof()) {
				in >> tab[i];
			}

			in.close();
			return 0;
		}
		else
			return 2;
	}
	else
		return 1;

}

bool Table::IsValueInTable(int val) {

	for (int i = 0; i < cnt; i++) {
		if (*(tab + i) == val)
			return true;
	}
	
	return false;
}

void Table::addValue(int index, int value) {

	int* tempTab;
	int newS = 0;

	if (index <= cnt) {
		newS = cnt + 1;
	} else if(index > cnt) {
		newS = index + 1;
	}

	if (index >= 0) {
		tempTab = new int[newS];
		int oldTabCnt = 0;

		for (int i = 0; i < newS; i++) {

			if (i == index) {
				tempTab[i] = value;
			}
			else if(oldTabCnt < cnt){
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
		cout << "---------------------------" << endl;
		cout << "INDEX POZA ROZMIAREM TABELI" << endl;
		cout << "---------------------------" << endl;
	}

}

void Table::deleteFromTable(int index) {

	if (index < cnt && index >= 0) {
		int newTabCnt = 0, newS = cnt - 1;
		int* tempTab = new int[newS];

		for (int i = 0; i < cnt; i++) {

			if (i != index) {

				*(tempTab + newTabCnt) = *(tab + i);
				newTabCnt++;

			}
		}

		delete tab;
		tab = tempTab;
		cnt = newS;

	}
	else {
		cout << "---------------------------" << endl;
		cout << "INDEX POZA ROZMIAREM TABELI" << endl;
		cout << "---------------------------" << endl;
	}


}

void Table::display() {

	cout << "\n\n";
	cout << "---------------------" << endl;
	cout << "|      TABLICA      |" << endl;
	cout << "---------------------" << endl;
	cout << "|  id  ||  wartosc  |" << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < cnt; i++) {
		cout << "| " << i << " | " << *(tab + i) << " |" << endl;
	}
}

void Table::generateTable(int size) {

	srand(time(NULL));

	if (tab) {
		delete tab;
	}

	tab = new int[size];

	for (int i = 0; i < size; i++) {
		*(tab + i) = rand() % 1000 + 1;
	}

	cnt = size;

}


