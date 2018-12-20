#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Heap {
	int len;  // Нийт багтаамж
	int size; // Одоогийн хэмжээ
	int *dat; // Өгөгдөл хадгалах хүснэгтийг заах хаяг
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Heap duuren!",
	"Heap xooson!",
};

void init(struct Heap *p, int n) {
	p->len = n;
	p->size = 0;
	p->dat = (int *) malloc(sizeof(int) * n);
}

void release(struct Heap *p) {
	free(p->dat);
	p->dat = NULL;
}

int parent(int i) {
	return (i-1)/2;
}

int left(int i) {
	return 2*i+1;
}

int right(int i) {
	return 2*i+2;
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print(struct Heap *p) {
	for (int i = 0; i < p->size; i++)
		cout << "Heap-> " << p->dat[i] << endl;
}
void heapin(struct Heap *p, int x) {

	p->dat[p->size] = x;
	p->size++;
	int temp = p->size-1;

	while(temp != 0 && p->dat[temp] < p->dat[parent(temp)]) {
		swap(&p->dat[parent(temp)], &p->dat[temp]);
		temp = parent(temp);
	}

}

/* p-ийн зааж буй Heap-с үндэс дээр байгаа утгыг гаргана. */
int heapout(struct Heap *p) {

	if (p->size == 0)
		error = 2;

	else {
		int result = p->dat[0];
		int i = 0;

		p->dat[0] = p->dat[p->size-1];
		p->size--;

		while (p->size > 0 && p->size > left(i)) {
			if (p->dat[i] > p->dat[left(i)]) {
				if (right(i) > p->size) {
					swap(p->dat[i], p->dat[left(i)]);
					i = left(i);
				}
				else if (p->dat[left(i)] > p->dat[right(i)]) {
					swap(p->dat[i], p->dat[right(i)]);
					i = right(i);
				}
				else {
					swap(p->dat[i], p->dat[left(i)]);
					i = left(i);
				}
			}
			else if (p->dat[i] < p->dat[left(i)]) {
				if (right(i) > p->size)
					return 0;
				else if (p->dat[i] > p->dat[right(i)]) {
					swap(p->dat[i], p->dat[right(i)]);
					i = right(i);
				}
				i = right(i);
			}

		}
		return result;
	}
}

int main() {

	struct Heap tr;
	init(&tr, 10);
	int t, x;

	while (1) {
		printf("1: heapin, 2: heapout, 3: print\n");
		scanf("%d", &t);
		error = 0;

		switch (t) {
		case 1:
			printf("Oruulax utga: ");
			scanf("%d", &x);
			heapin(&tr, x);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga orloo\n", x);
			break;

		case 2:
			x = heapout(&tr);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga garlaa\n", x);
			break;

		case 3:
			print(&tr);
		break;

		default:
			exit(0);
		}
	}

	release(&tr);

	return 0;
}
