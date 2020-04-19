#pragma once
#include <string>
#include "Trunk.h"

using namespace std;


// struktura reprezentuj¹ca pojedynczy weze³ drzewa
struct RBNode {
	int value;
	RBNode* left, * right, * parent;
	bool isBlack;
};



class RBTree
{
public:
	RBTree();
	void display();							//wyswietl drzewo
	bool push(int value);					//dodaj wartosc do drzewa
	bool pop(int value);					//usun wartosc z drzewa
	bool isValueInTree(int value);			//sprawdz, czy wartosc jest w drzewie
	void createRandom(int size);			//utwurz losowe drzewo
	int loadFromFile(string fileName);		//zaladuj drzewo z pliku
	void test();							//funkcja do testow

private:
	RBNode* root;							//korzen drzewa
	RBNode* findNode(int val);				//znajdz wezel o podanej wartosci
	void deleteLastNode(RBNode* node);		//usun lisc z drzewa
	void postorderDeleteNodes(RBNode* root);//usun dane poddrzewo
	void rbRepairPush(RBNode* Node);		//napraw drzewo po dodaniu wezla
	void leftRotate(RBNode* node);			//obroc poddrzewo w lewo
	void rightRotate(RBNode* node);			//obroc poddrzewo w prawo
	RBNode* uncle(RBNode* node);			//znajdz "stryja" wezla
	RBNode* sibling(RBNode* node);			//znajdz rodzenstwo wezla
	RBNode* successor(RBNode* node);		//znajdz nastepnika wezla
	RBNode* minKey(RBNode* node);			//idz wzdluz lewych odnog drzewa od podanego wezla i zwroc lisc
	RBNode* findRepNode(RBNode* node);		//znajdz wezel, ktorym mozna zastapic podany wezel
	void rbRepairPop(RBNode* node);			//napraw drzewo po usunieciu wezla
	bool pop(RBNode* node);					//usun wartosc z drzewa

	void showTrunks(Trunk* p);								//funkcje pomocnicze do wyswietlania 
	void printTree(RBNode* root, Trunk* prev, bool isLeft);	// drzewa

};

