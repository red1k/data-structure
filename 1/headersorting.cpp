#include <iostream>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int array[], int length) {
	for (int i=0; i<length; i++) 
		cout << array[i] << "\t";
	cout << endl;
}

void bubbleSort(int array[], int length) {
	for (int i=0; i<length-1; i++) {
		for (int j=0; j < length-i-1; j++) {
			if (array[j] > array[j+1]) 
				swap(&array[j], &array[j+1]);
		}
	}
}

void selectionSort(int array[], int length) {
	
	int min;
	for (int i=0; i<length-1; i++) {
		min = i;
		for (int j=i+1; j<length; j++) {
			if (array[j] < array[min]) {
				min = j;
				swap(&array[min], &array[i]);
			}
		}
	}
}

void insertionSort(int array[], int length) {

}
