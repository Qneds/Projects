#include "RBTree.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>

using namespace std;

RBTree::RBTree()
{
	root = NULL;
}

void RBTree::display()				//wyswietl drzewo
{
	printTree(root, NULL, false);
}

bool RBTree::push(int value)
{
	RBNode* y = NULL;
	RBNode* x = root;
	

	while (x != NULL) {					//znajdz miejsce, w ktore nalezy wstawic nowy wezel
		y = x;
		if (value == x->value) 
			return false;				//jezeli wezel o danej wartosci juz istnieje to nie dodawaj kolejnego
		else if (value < x->value)
			x = x->left;
		else
			x = x->right;
	}

	RBNode* newNode = new RBNode;

	newNode->value = value;				//utworz nowy wezel
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->isBlack = false;

	newNode->parent = y;		
	if (y == NULL)						//jezeli drzewo puste to ustaw korzen
		root = newNode;
	else if (newNode->value < y->value)		//ustaw rodzica nowemu wezlowi
		y->left = newNode;
	else
		y->right = newNode;

	rbRepairPush(newNode);				//napraw drzewo po operacji dodawania wezla
	return true;

}

bool RBTree::pop(int value)		//usun wezel o podanej wartosci
{
	return pop(findNode(value));
}

bool RBTree::pop(RBNode* node)						//usun podany wezel
{
	RBNode* nodeToDelete = node, * replacingNode;

	if (nodeToDelete) {

		replacingNode = findRepNode(nodeToDelete);

		bool dBlack = (nodeToDelete->isBlack == true && (replacingNode == NULL || replacingNode->isBlack == true));

		if (replacingNode == NULL) {

			if (nodeToDelete == root)
				root = NULL;
			else {

				if (dBlack) {
					rbRepairPop(nodeToDelete);
				}

				if (nodeToDelete->parent->left == nodeToDelete)
					nodeToDelete->parent->left = NULL;
				else
					nodeToDelete->parent->right = NULL;
			}

			delete nodeToDelete;
			return true;
		}
	
		if (nodeToDelete->left == NULL || nodeToDelete->right == NULL) {

			if (nodeToDelete == root) {
				root = replacingNode;
				replacingNode->parent = NULL;
				replacingNode->isBlack = true;
			}
			else {

				replacingNode->parent = nodeToDelete->parent;

				if (nodeToDelete->parent->left == nodeToDelete)
					nodeToDelete->parent->left = replacingNode;
				else
					nodeToDelete->parent->right = replacingNode;

				delete nodeToDelete;

				if (dBlack) {
					rbRepairPop(replacingNode);
				}
				else {
					replacingNode->isBlack = true;
				}
			}
			return true;
		}

		nodeToDelete->value = replacingNode->value;
		pop(replacingNode);

		return true;
	}
	else {
		cout << "Wezel o podanej wartosci nie istnieje\n\n";
		return false;
	}
}

bool RBTree::isValueInTree(int value)			//znajdz podana wartosc
{												
	RBNode* tmp = findNode(value);

	if (tmp != NULL)							//jezeli wartosc istnieje w drzewie zwroc 'true'
		return true;							// w innym przypadku zwroc 'false'						
	else
		return false;	
}

void RBTree::createRandom(int size)				//stworz losowe drzewo
{

	if (size > 0)								//drzewo musi miec dodatnia ilosc wezlow
	{
		srand(time(NULL));
		postorderDeleteNodes(root);				//usun stare drzewo
		int l;
		bool var;
		for (int i = 0; i < size;) {		//losuj wartosc od 0 do 1000 i dodaj ja do drzewa
			l = rand() % 1000001;
			var = push(l);
			if (var)
				i++;
		}
		cout << endl;
	}
	else {
		cout << "\nNie mo¿na utworzyæ drzewa o rozmiarze <= 0.\n\n";
	}

}

int RBTree::loadFromFile(std::string fileName)		//wczytaj drzewo z pliku
{
	ifstream inf;
	inf.open(fileName);

	if (inf.is_open()) {							//plik musi byc prawidlowo otwarty

						
		int tmpVal, size;

		inf >> size;

		if (size > 0)
		{
											

			postorderDeleteNodes(root);					//usun stare drzewo

			for (int i = 0; i < size; i++) {

				inf >> tmpVal;							//wczytuj kolejne wartosci i dodawaj je do drzewa
				push(tmpVal);

			}
		}
		else {
			cout << "Nie da siêutworzyc drzewa o liczbie elementow <= 0\n\n";
		}
	}
	else {
		cout << "Nie udalo sie odczytac pliku.\n\n";
	}

	return 0;
}

void RBTree::test()
{
	ofstream inf;
	inf.open("RB-dane.txt");

	if (inf.is_open()) {

		srand(time(NULL));
		long long avg = 0;

		int sizeT = 2000, tmp = 0;

		bool var;

		inf << "rozmiar;";
		inf << "czas dodawania elementu[ns];";
		inf << "czas uswania elementu[ns];";
		inf << "czas znajdowania losowego elementu[ns]";
		inf << endl;

		for (int i = 0; i < 20; i++) {

			createRandom(sizeT);
			inf << sizeT << ";";

			for (int l = 0; l < 100;) {
				tmp = rand() % 1000001;
				auto t0 = std::chrono::high_resolution_clock::now();
				var = push(tmp);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				if (var)
				{
					avg += duration;
					l++;
				}
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;

			for (int l = 0; l < 100;) {
				tmp = rand() % 1000001;
				auto t0 = std::chrono::high_resolution_clock::now();
				var = pop(tmp);
				auto t1 = std::chrono::high_resolution_clock::now();
				auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
				
				if (var)
				{
					avg += duration;
					l++;
				}
			}
			avg /= 100;
			inf << avg << ";";

			avg = 0;


			for (int l = 0; l < 100; l++) {
				tmp = rand() % 1000001;
				auto t0 = std::chrono::high_resolution_clock::now();
				isValueInTree(tmp);
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

RBNode* RBTree::findNode(int val)		//znajdz wezel o podane wartosci
{
	RBNode* x = root;

	while (x != NULL) {					//dopoki wezel nie jest lisciem podazaj w dol drzewa
		if (val < x->value)				//jezeli wawrtosc jest mniejsza od tej w wezle to docelowy wezel jest w lewym poddrzewie
			x = x->left;
		else if (val > x->value)		//jezeli wawrtosc jest wieksza od tej w wezle to docelowy wezel jest w prawym poddrzewie
			x = x->right;
		else
			return x;					//jezeli wartosc jest w srodku drzewa to ja zwroc
	}

	return x;
}

void RBTree::deleteLastNode(RBNode* node)		//usun lisc z drzewa
{
	if (node != root)							
	{
		if (node->parent->right == node)		//usun doniesienie do wezla z rodzica tego wezla
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
	}
	else {
		root = NULL;							//jezeli jest tylko korzen to usun go
	}

	delete node;
}

void RBTree::postorderDeleteNodes(RBNode* root)		//usun dane poddrzewo
{
	if (root == NULL)								//nie ma co usuwac, zakoncz
		return;

	postorderDeleteNodes(root->left);				//najpierwa usun cale poddrzewo tego wezla
	postorderDeleteNodes(root->right);
	deleteLastNode(root);							//a na koniec wezel
}

void RBTree::rbRepairPush(RBNode* node)
{
	if (node == root) {								//jezeli wezel jest korzeniem, to go pokoloruj
		node->isBlack = true;						// i zakoncz
		return;
	}

	RBNode* parent = node->parent, * grandparent = parent->parent,
		* uncle = RBTree::uncle(node);

	if (parent != NULL && grandparent != NULL && parent->isBlack == false)
	{
		if (grandparent->left == parent) {						//rodzic jest po lewej stronie dziadka

			if (uncle != NULL && uncle->isBlack == false) {		//jesli stryj jest czerwrony
				parent->isBlack = true;						//kolorujemy ojca i stryja na czarno
				uncle->isBlack = true;
				grandparent->isBlack = false;				//kolorujemy dziadka na czerwono
				RBTree::rbRepairPush(grandparent);			//dalej naprawiamy dziadka
			}
			else {									//jesli stryj jest czarny
				if (node == parent->right) {		//wezel jest prawym potomkiem
					RBTree::leftRotate(parent);		// wykonaj najpierw obrot w lewo
					RBNode* tmp = node;				
					node = parent;
					parent = tmp;
				}
				RBTree::rightRotate(grandparent);	//wykonaj obrot w prawo wokol dziadka
				parent->isBlack = true;				//pokoloruj ojca na czarno, a dziadka na czerwono
				grandparent->isBlack = false;
			}
		}
		else {
																//rodzic jest po prawej stronie dziadka
			if (uncle != NULL && uncle->isBlack == false) {	//jesli stryj jest czerwrony
				parent->isBlack = true;							//kolorujemy ojca i stryja na czarno
				uncle->isBlack = true;
				grandparent->isBlack = false;					//kolorujemy dziadka na czerwono
				RBTree::rbRepairPush(grandparent);			//dalej naprawiamy dziadka
			}
			else {											//jesli stryj jest czarny
				if (node == parent->left) {				//wezel jest lewym potomkiem
					RBTree::rightRotate(parent);		// wykonaj najpierw obrot w prawo
					RBNode* tmp = node;
					node = parent;
					parent = tmp;
				}
				RBTree::leftRotate(grandparent);		//wykonaj obrot w lewo wokol dziadka
				parent->isBlack = true;					//pokoloruj ojca na czarno, a dziadka na czerwono
				grandparent->isBlack = false; 
			}

		}
	}
}

void RBTree::leftRotate(RBNode* node)				//rotacj w lewo
{

	if (node == NULL || node->right == NULL) {		//w tych przypadkach nie da sie wykonac rotacji
		return;
	}
	
	RBNode* nParent = node->right, *tmp;

	
	if (node == root)								//jezeli obrot wokol korzenia, ustaw nowy korzen
		root = nParent;

	if (node->parent != NULL)						//jezeli wezel, wokol ktorego wykonwyany jest obrot ma rodzica
	{												// to ustaw temu rodzicowi odniesienie do wezla zastepujacego wezel, wokol
		if (node->parent->left == node) {			// ktorego jest obrot
			node->parent->left = nParent;
		}
		else {
			node->parent->right = nParent;
		}
	}

	nParent->parent = node->parent;					
	node->parent = nParent;
	tmp = nParent->left;				// przenies lewe poddrzewo w prawe miejsce w obracanym wezle
	nParent->left = node;
	node->right = tmp;
	if (tmp != NULL) {
		tmp->parent = node;
	}

}

void RBTree::rightRotate(RBNode* node)					//rotacj w prawo
{

	if (node == NULL || node->left == NULL) {			//w tych przypadkach nie da sie wykonac rotacji
		return;
	}

	RBNode* nParent = node->left, * tmp;


	if (node == root)									//jezeli obrot wokol korzenia, ustaw nowy korzen
		root = nParent;

	if (node->parent != NULL)							//jezeli wezel, wokol ktorego wykonwyany jest obrot ma rodzica
	{													// to ustaw temu rodzicowi odniesienie do wezla zastepujacego wezel, wokol
		if (node->parent->left == node) {				// ktorego jest obrot
			node->parent->left = nParent;	
		}
		else {
			node->parent->right = nParent;
		}
	}

	nParent->parent = node->parent;
	node->parent = nParent;
	tmp = nParent->right;								// przenies prawe poddrzewo w lewe miejsce w obracanym wezle
	nParent->right = node;
	node->left = tmp;
	if (tmp != NULL) {
		tmp->parent = node;
	}
}

RBNode* RBTree::uncle(RBNode* node)			//zwroc stryja danego wezla
{
	if (node->parent == NULL || node->parent->parent == NULL)	//stryj nie ma mozliwosci istnienia
		return NULL;

	if (node->parent->parent->left == node->parent) {			//w zaleznosci od polozenia wezla zwroc odpowiedniego stryja
		return node->parent->parent->right;
	}
	else {
		return node->parent->parent->left;
	}
}

RBNode* RBTree::sibling(RBNode* node)	//zwroc rodzenstwo danego wezla
{
	if (node == NULL || node->parent == NULL)	//rodzenistwo nie ma mozliwosci istnienia
		return NULL;

	if (node->parent->left == node)				//zwroc odpowiedni wezel
		return node->parent->right;
	else
		return node->parent->left;
}

RBNode* RBTree::successor(RBNode* node)		//zwroc nastepnika danego wezla 
{
	if (node->right != NULL)				//jezeli istnieje prawe poddrzewo to zwroc wezel o najmniejszej
		return minKey(node->right);			// wartosci w tym poddrzewie

	RBNode* tmp = node->parent;
	while (tmp != NULL and tmp->left != node) {	//w przeciwnym wypadku idz w gore drzewa tak dlugo az dotrzesz do korzenia
		node = tmp;								// lub przyjdziesz lewa galezia.
		tmp = tmp->parent;
	}
	return tmp;
}

RBNode* RBTree::minKey(RBNode* node)			//znajdz najmniejsza wartosc w danym poddrzewie
{
	if (node->left != NULL) {					//podarzaj lewymi galeziami dopoki nie bedzie mozliwosci podazania dalej lewymi galeziami
		return minKey(node->left);				// i zwroc wezel na ktorym sie zatrzymales
	}
	else {
		return node;							
	}
}

RBNode* RBTree::findRepNode(RBNode* node)		//znajdz wezel, ktorym mozna zastapic podany waezel
{
	if (node->left != NULL && node->right != NULL)	//jezeli wezel ma lewe i prawe poddrzewo t ozwroc nastepnika wezla 
		return successor(node);

	if (node->left != NULL)						//w przeciwnym przypadku zwroc wezel z jedynej istenijacej galezie lub NULL
		return node->left;
	else
		return node->right;
}

void RBTree::rbRepairPop(RBNode* node)
{
	if (node == root)			//jezeli dotarlismy do korzenia to koniec
		return;

	RBNode* sib = sibling(node);
	if (sib == NULL) {				//jezeli nie ma rodzenstwa to przekaz kolor podwojny czarny rodzicowi
		rbRepairPop(node->parent);
		return;
	}
	if (sib->isBlack == true) {		//jesli rodzenstwo jest czarne

		if ((sib->left && sib->left->isBlack == false) || (sib->right && sib->right->isBlack == false)) {
			//rodzenstwo ma przynajmniej jedno czerwone dziecko

			RBNode* oldParent = sib->parent;

			if (sib->parent->right == sib) { //rodzenstwo jest prawym potomkiem

				if (sib->right && sib->right->isBlack == false) { //prawe dziecko rodzenstwa jest czerwone
					
					sib->right->isBlack = sib->isBlack;			
					sib->isBlack = sib->parent->isBlack;
					leftRotate(sib->parent);

				}
				else {							//jezeli prawe dziecko nie jest czerwone to lewe jest
					sib->left->isBlack = sib->parent->isBlack;
					rightRotate(sib);							
					leftRotate(sib->parent->parent);
				}

			}
			else {							//rodzenstwo jest lewym potomkiem

				if (sib->left && sib->left->isBlack == false) {	//lewe dziecko rodzenstwa jest czerwone

					sib->left->isBlack = sib->isBlack;
					sib->isBlack = sib->parent->isBlack;
					rightRotate(sib->parent);

				}
				else
				{								//jezeli lewe dziecko nie jest czerwone to prawe jest

					sib->right->isBlack = sib->parent->isBlack;
					leftRotate(sib);
					rightRotate(sib->parent->parent);

				}

			}

			oldParent->isBlack = true;
			
		}
		else {				//rodzenstwo ma czarne dzieci

			sib->isBlack = false;

			if (sib->parent->isBlack == true) {	
				rbRepairPop(sib->parent);		//jezeli podwojny czarny to przenies go wyzej
			}
			else {
				sib->parent->isBlack = true;	//jezeli czarno czerwony to wezel jest czarny
			}
		}

	}
	else {
		sib->isBlack = true;
		sib->parent->isBlack = false;

		if (sib->parent->right == sib) {
			leftRotate(sib->parent);
		}
		else {
			rightRotate(sib->parent);
		}

		rbRepairPop(node);
	}
}

void RBTree::showTrunks(Trunk* p)
{
	if (p == NULL)
		return;

	showTrunks(p->prev);
	cout << p->str;
}

void RBTree::printTree(RBNode* root, Trunk* prev, bool isLeft)
{
	if (root == NULL)
		return;

	string prev_str = "     ";
	Trunk* trunk = new Trunk(prev, prev_str);

	printTree(root->right, trunk, false);

	if (!prev)
		trunk->str = "---";
	else if (!isLeft) {
		trunk->str = ".---";
		prev_str = "    |";
	}
	else
	{
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);

	if (root->isBlack)
		cout << "[B]";
	else
		cout << "[R]";
	cout << root->value << endl;

	if (prev)
		prev->str = prev_str;

	trunk->str = "    |";

	printTree(root->left, trunk, true);
}
