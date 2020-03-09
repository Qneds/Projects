#include "Heap.h"
#include <iostream>

int COUNT = 10;

using namespace std;

Heap::Heap()
{
	size = 0;
	
}

void Heap::display()
{
}

bool Heap::isValueInHeap(int val)
{
	return false;
}

void Heap::createRandom(int size)
{
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
	return true;
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
