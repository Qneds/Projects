#pragma once
#include <string>

using namespace std;

struct Node
{
	int value;
	Node* left, * right, * parent;
};


struct TrunkBST {
	TrunkBST* prev;
	string str;

	TrunkBST(TrunkBST* prev, string str) {
		this->prev = prev;
		this->str = str;
	}
};

class Bst
{
public:

	Bst();
	void display();
	void push(int value);
	void pop(int value);
	bool isValueInTree(int value);
	void createRandom(int size);
	int loadFromFile(string fileName);

private:
	Node* root;
	Node* successor(Node* n);
	Node* minKey(Node* n);
	Node* findNode(int val);
	void deleteLastNode(Node* n);
	void postorderDeleteNodes(Node* root);
	//-------
	void showTrunks(TrunkBST* p);
	void printTree(Node *root, TrunkBST* prev, bool isLeft);
};

