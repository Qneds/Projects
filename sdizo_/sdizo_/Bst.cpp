#include "Bst.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

Bst::Bst()
{
	root = NULL;
}

void Bst::display()
{
	cout << "\n\n";
	printTree(root, NULL, false);

}

void Bst::push(int value)
{
	Node* y = NULL;
	Node* x = root;
	Node* newNode = new Node;
	
	newNode->value = value;
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;


	while (x != NULL) {
		y = x;
		if (value < x->value)
			x = x->left;
		else
			x = x->right;
	}

	newNode->parent = y;
	if (y == NULL)
		root = newNode;
	else if (newNode->value < y->value)
		y->left = newNode;
	else
		y->right = newNode;

	
}

void Bst::pop(int value)
{

	Node* nodeToDelete = findNode(value);

	if (nodeToDelete)
	{
		Node* tmp, * x;

		if (nodeToDelete->left == NULL || nodeToDelete->right == NULL)
			tmp = nodeToDelete;
		else
			tmp = successor(nodeToDelete);


		if (tmp->left != NULL)
			x = tmp->left;
		else
			x = tmp->right;

		if (x != NULL)
			x->parent = tmp->parent;

		if (tmp->parent == NULL)
			root = x;
		else {

			if (tmp == tmp->parent->left)
				tmp->parent->left = x;
			else
				tmp->parent->right = x;
		}

		if (tmp != nodeToDelete)
			nodeToDelete->value = tmp->value;

		delete tmp;
						
					
	}
	else
	{
		cout << "\nWartosc nie istnieje w tym drzewie\n\n";
	}
}

bool Bst::isValueInTree(int value)
{
	Node* tmp = findNode(value);

	if (tmp != NULL)
		return true;
	else
		return false;
}

void Bst::createRandom(int size)
{


	if (size > 0)
	{
		srand(time(NULL));
		postorderDeleteNodes(root);

		root = new Node;
		root->value = rand() % 1001;
		root->parent = NULL;
		root->left = NULL;
		root->right = NULL;

		for (int i = 0; i < size - 1; i++) {
			push(rand() % 1001);
		}
	}
	else {
		cout << "\nNie mo¿na utworzyæ drzewa o rozmiarze <= 0.\n\n";
	}


}

int Bst::loadFromFile(string fileName)
{
	ifstream inf;
	inf.open(fileName);

	if (inf.is_open()) {

		Node tmpNode;
		postorderDeleteNodes(root);
		int tmpVal;

		root = new Node;

		inf >> root->value;

		inf >> root->value;
		root->parent = NULL;
		root->left = NULL;
		root->right = NULL;

		while (!inf.eof()) {

			inf >> tmpVal;
			push(tmpVal);

		}

	}
	else {
		cout << "Nie udalo sie odczytac pliku.\n\n";
	}

	return 0;
}

Node* Bst::successor(Node* n)
{
	
	if (n->right != NULL)
		return minKey(n->right);
	Node * tmp = n->parent;
	while (tmp != NULL and tmp->left != n) {
		n = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

Node* Bst::minKey(Node* n)
{
	if (n->left != NULL) {
		return minKey(n->left);
	}
	else {
		return n;
	}
}

Node* Bst::findNode(int val)
{
	Node* x = root;

	while (x != NULL) {
		if (val < x->value)
			x = x->left;
		else if (val > x->value)
			x = x->right;
		else
			return x;
	}

	return x;
}

void Bst::deleteLastNode(Node* n) {

	if (n != root)
	{
		if (n->parent->right == n)
			n->parent->right = NULL;
		else
			n->parent->left = NULL;
	} 
	else {
		root = NULL;
	}

	delete n;

}


void Bst::postorderDeleteNodes(Node* root)
{
	
	if (root == NULL)
		return;

	postorderDeleteNodes(root->left);
	postorderDeleteNodes(root->right);
	deleteLastNode(root);

}

void Bst::showTrunks(TrunkBST* p)
{
	if (p == NULL)
		return;

	showTrunks(p->prev);
	cout << p->str;
}

void Bst::printTree(Node* root, TrunkBST* prev, bool isLeft)
{
	if (root == NULL)
		return;

	string prev_str = "    ";
	TrunkBST* trunk = new TrunkBST(prev, prev_str);

	printTree(root->right, trunk, false);

	if (!prev)
		trunk->str = "---";
	else if (!isLeft) {
		trunk->str = ".---";
		prev_str = "   |";
	}
	else 
	{
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	cout << root->value << endl;

	if (prev)
		prev->str = prev_str;

	trunk->str = "   |";

	printTree(root->left, trunk, true);
}
