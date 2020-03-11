#include "Heap.h"
#include <iostream>
#include <time.h>

int COUNT = 10;

using namespace std;

Heap::Heap()
{
	size = 0;
	
}

void Heap::display()
{
	print2DUtil(0, 3);
}

void Heap::push(int val)
{

	if (size >= HEAP_TAB_MAX) {
		cout << "\n\nSterta jest pe³na\n\n";
		return;
	}
	else
	{
		heapTab[size] = val;
		heapUp(size);
		size++;
	}

}

void Heap::pop()
{

	heapTab[0] = heapTab[--size];
	heapDown(0);

}

bool Heap::isValueInHeap(int val)
{

	for (int i = 0; i < size; i++) {
		if (val == heapTab[i])
			return true;
	}

	return false;
}

void Heap::createRandom(int size)
{

	srand(time(NULL));

	for (int i = 0; i < size; i++) {

		heapTab[i] = rand() % 1001;
		heapUp(i);
	}
	Heap::size = size;

}

int Heap::loadFromFile(string fileName)
{
	return 0;
}

bool Heap::heapUp(int index)
{
	int parId = getParent(index), temp;

	if (heapTab[index] > heapTab[parId]) {

		if (index == 0)
			return true;

		temp = heapTab[index];
		heapTab[index] = heapTab[parId];
		heapTab[parId] = temp;
		heapUp(parId);
		return true;
	}
	else
	{
		return true;
	}

}

bool Heap::heapDown(int index)
{
	int higher, left = getLeft(index), right = getRight(index);

	if (heapTab[left] > heapTab[right]) {
		higher = left;
	}
	else {
		higher = right;
	}

	if (heapTab[index] < heapTab[higher]) {
		left = heapTab[index];
		heapTab[index] = heapTab[higher];
		heapTab[higher] = left;
		heapDown(higher);
		return true;
	}
	else {
		return true;
	}

}

int Heap::getLeft(int par)
{
	return 2*par + 1;
}

int Heap::getRight(int par)
{
	return 2*par + 2;
}

int Heap::getParent(int child)
{
	return (child - 1)/2;
}

void Heap::print2DUtil(int root, int space)
{

	if (root >= size)
		return;
	
    // Increase distance between levels  
    space += COUNT;

    // Process right child first  
    print2DUtil(getRight(root), space);

    // Print current node after space  
    // count  
	cout << endl;
	for (int i = COUNT; i < space; i++) {
		cout << " ";
	}
    cout << heapTab[root] << "\n";

    // Process left child  
    print2DUtil(getLeft(root), space);
}
