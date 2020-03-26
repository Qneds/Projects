#include "Table.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

Table::Table() {
	Table::tab = new int[1];
	Table::cnt = 0;
}


int Table::loadFromFile(string FileName) {

	ifstream inf;
	

	
	inf.open(FileName, ifstream::in);

	if (inf.is_open()) {

		inf >> cnt;

		if (cnt > 0) {

			delete tab;
			tab = new int[cnt];

			int i = 0;
			while (!inf.eof())
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

	for (int i = 0; i < cnt; i++) {		//przeszukuj cala tabele

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

		if (index <= cnt) {		//kiedy index jest mniejszy od rozmiaru ->zadnych dodatkowych krokow
			newS = cnt + 1;
		}
		else {					//kiedy index jest wiekszy od rozmiru ->rozszerz tablice o wartosci z 0
			newS = index + 1;
		}

		tempTab = new  int[newS];

		for (int i = 0; i < newS; i++) {			//przepisz stara tablice do nowej i wstaw nowa wartosc
			if (i == index) {						// w podane miejsce
				tempTab[i] = value;
			}
			else if (oldTabCnt < cnt) {				
				tempTab[i] = tab[oldTabCnt];
				oldTabCnt++;
			}
			else {									//rozszerzanie tablicy o 0
				tempTab[i] = 0;
			}
		}

		cnt = newS;									//usun poprzednia tablice
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

		for (int i = 0; i < cnt; i++) {			//przepisz zawartosc starej tablicy do nowej
			if (index != i) {					// pomijajac wartosc o podanym indexie
				temp[tmpCn] = tab[i];
				tmpCn++;
			}
		}

		delete tab;								//usun stara tablice
		tab = temp;
		cnt = newS;

	}
	else {
		cout << "\n\nWartoœæ spoza zekresu indexow\n\n";
	}

}

void Table::display() {

	cout << "\n\n";
	
	

	for (int i = 0; i < cnt; i++) {
		cout << tab[i] << " ";
	}

	cout << "\n\n";

}

void Table::generateTable(int size) {


	if (size > 0)
	{
		srand(time(NULL));

		delete tab;							//usun stara tablice, stworz nowa o podanym rozmiarze
		cnt = size;							// i wypelnij ja losowymi wartosciami
		tab = new int[cnt];

		for (int i = 0; i < cnt; i++) {
			tab[i] = rand() % 10001;
		}
	}
	else {
		cout << "\nNie mo¿na utworzyæ tablicy o rozmiarze <= 0.\n\n";
	}

}

void Table::test()
{
	
	

	ofstream inf;
	inf.open("Tabela-dane.txt");

	if (inf.is_open()) {

		srand(time(NULL));
		long long avg = 0;

		int sizeT = 2000;

		inf << "rozmiar;czas dodawania na poczatek[ns];";
		inf << "czas dodawania na koniec[ns];";
		inf	<< "czas dodawania w losowe miejsce[ns];";
		inf << "czas uswania z poczatku[ns];";
		inf << "czas usuwania z konca[ns];";
		inf << "czas usuwania z losowego miejsca[ns];";
		inf << "czas znajdowania losowego elementu[ns]";
		inf << endl;

		for (int i = 0; i < 20; i++) {

			generateTable(sizeT);
			inf << sizeT << ";";

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				addValue(0, rand() % 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				addValue(cnt - 1, rand() % 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				addValue(rand()% cnt, rand() % 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";


			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				deleteFromTable(0);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				deleteFromTable(cnt - 1);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				deleteFromTable(rand() % cnt);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100; l++) {

				auto t0 = std::chrono::high_resolution_clock::now();
				IsValueInTable(rand()% 10001);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				avg += duration;
			}
			avg /= 100;


			inf << avg << "\n";

			sizeT += 2000;

		}

		inf.close();

	}
	
}


