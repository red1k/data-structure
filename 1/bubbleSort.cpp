#include <iostream>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int array[], int length) {
	for (int i = 0; i < length; i++) 
		cout << array[i] << " -> ";
	cout << endl;
}

void bubbleSort(int array[], int length) {
	for (int i = 0; i < length-1; i++) {
		for (int j = 0; j < length-i-1; j++) {
			if (array[j] > array[j+1]) 
				swap(&array[j], &array[j+1]);
		}
	}
}

int main() {
	
	int array[] = {1, 3, 2, 11, 2, 5};
	int n = sizeof(array)/sizeof(array[0]);

	cout << "Array before sorting: \n";
	print(array, n);
	
	bubbleSort(array, n);

	cout << "Array after sorting: \n";
	print(array, n);

	return 0;
}
