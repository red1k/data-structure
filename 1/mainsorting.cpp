#include <iostream>
#include "headersorting.cpp"

using namespace std;

int main() {

	int array[] = {1, 3, 2, 11, 3, 5};
	int length = sizeof(array)/sizeof(array[0]);

	cout << "Given array: \n";
	print(array, length);

	cout << "Bubble sort: \n";
	bubbleSort(array, length);				//big O = two "for" loop therefore n^2
	print(array, length);

	cout << "Selection sort: \n";
	selectionSort(array, length);			//big O = two "for" loop therefore n^2
	print(array, length);
/*
	cout << "Insertion sort: \n";
	insertionSort(array, length);
	print(array, length);
*/

	return 0;
}
