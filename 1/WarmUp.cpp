#include <iostream>

using namespace std;

void print(int a[], int n) {
	for (int i = 0; i < n; i++) 
		cout << a[i] << "->";
	cout << "NULL\n";
}

int max(int a[], int n) {
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)	
			max = a[i];
	}
	return max;
}

int min(int a[], int n) {
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] < min)	
			min = a[i];
	}
	return min;
}

int maxx(int a[], int n, int x) {
	
	int array[n];
	int i = 0, j = 0;
	
	for (i=0, j=0; i < n; i++) {
		if (a[i] > x) { 
			array[j] = a[i];
			j++;	
		}
	}
	
	if (j > 0) 
		return min(array, j);
	return -1;
}

int minx(int a[], int n, int x) {

	int array[n] = {};
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] < x) { 
			array[j] = a[i];
			j++;	
		}
	}

	if (j > 0)
		return max(array, j);
	return -1;

}

int find(int a[], int n, int x) {

	int location;
	for (int i = 0; i < n; i++) {
		if(a[i] == x) {
			location = i+1;
			break;	
		}
	}

	if (location > 0)
		return location;
	return -1;
}

void copy(int a[], int n, int b[]) {
	for (int i = 0; i < n; i++) 
		b[i] = a[i];
}

void append(int a[], int n, int b[], int m) {
	for (int i = 0; i < n; i++) 
		b[i+m] = a[i];
}

void reverse(int a[], int n) {
	int b[n] = {};
	for (int i = 0; i < n; i++) 
		b[i] = a[n-i-1];
	print(b, n);
}
	
int main() {

	int a[]	= {1, 2, 3, 9, 6, 2};
	int b[]	= {2, 1, 3, 7, 8};
	int c[100] = {};
	int d[] = {0, 0, 0};
	
	cout << "a[] array is given below: \n";
	print(a, 6);

	cout << endl;

	cout << "b[] array is given below: \n";
	print(b, 5);

	cout << endl;

	int maximum = max(a, 6);
	int minimum = min(a, 6);

	cout << "Maximum member of A array is: " << maximum << endl;
	cout << "Minimum member of A array is: " << minimum << endl;
	
	cout << endl;

	int max_x = maxx(a, 6, 4);
	int min_x = minx(b, 5, 4);

	cout << "Greater than 4 and smallest of Array A[] is: " << max_x << endl;
	cout << "Smaller than 4 and biggest of Array B[] is: " << min_x << endl;

	cout << endl;

	copy(a, 6, c);
	append(b, 5, d, 3);

	cout << "a[] array copied to c[]: \n";
	print(c, 6);
	cout << endl;

	cout << "b array merged into d array: \n";
	print(d, 8);
	cout << endl;

	cout << "d array is reversed: \n";
	reverse(d, 8);

	return 0;
}
