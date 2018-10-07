#include <stdio.h>
#include <stdlib.h>

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

//	parent = (p->size-1)/2

/* p-ийн зааж буй Heap-д x утгыг оруулна */
void heapin(struct Heap *p, int x) {
	p->dat[p->size++] = x;
	while(p->dat[(p->size-1)/2])
}

/* p-ийн зааж буй Heap-с үндэс дээр байгаа утгыг гаргана. */
int heapout(struct Heap *p) {
}

int main() {
	/* Heap үүсгэн, эхлүүлэх */
	struct Heap tr;
	init(&tr, 10);
	int t, x, pos, idx;

	while (1) {
		printf("1: heapin, 2: heapout, 3: exit");
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
		default:
			exit(0);
		}
	}
	/* Heap-ийн эзэмшсэн нөөцийг чөлөөлөх */
	release(&tr);
	return 0;
}
