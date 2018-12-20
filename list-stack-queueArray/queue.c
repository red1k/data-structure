#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int len;
	int *dat;
	int size;
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Queue duuren!",
	"Queue xooson!"
};

void init(struct Queue *p, int n) {
	p->len = n;
	p->size = 0;
	p->dat = (int *) malloc(sizeof(int) * n);
}

void release(struct Queue *p) {
	free(p->dat);
	p->dat = NULL;
}

int empty(struct Queue *p) {
	if (p->size == 0)
		return 1;
	return 0;
}

void push_back(struct Queue *p, int x) {
	if (p->size >= p->len)
		error = 1;
	p->dat[p->size++] = x;
}

int pop_front(struct Queue *p) {
	if(p->size == 0)
		error = 2;
	else {
		struct Queue temp;
		init(&temp, p->size);
		int result = p->dat[0];

		for (int i = 0; i <= p->size; i++)
			temp.dat[i] = p->dat[i];

		for (int i = 0; i <= p->size; i++)
			p->dat[i] = temp.dat[i+1];

		p->size--;
		return result;
	}
}

void print(struct Queue *p) {
	if(p->size == 0)
		error = 2;
	else {
		for (int i = 0; i < p->size; i++)
			printf("Queue -> %d\n", p->dat[i]);
	}
}

int front(struct Queue *p) {
	if (p->size == 0)
		error = 2;
	return p->dat[0];
}

int back(struct Queue *p) {
	if (p->size == 0)
		error = 2;
	return p->dat[p->size-1];
}

int size(struct Queue *p) {
	if (p->size == 0)
		error = 2;
	return p->size;
}


int main() {

	struct Queue st;
	init(&st, 10);
	int t, x;

	while (1) {
		printf("1: push_back, 2: pop_front, 3: print, 4: empty, 5: front,"
		       "6: back, 7: size, 8: exit\n");
		scanf("%d", &t);
		error = 0;

		switch (t) {
		case 1:
			printf("Suuld oruulah utga: ");
			scanf("%d", &x);
			push_back(&st, x);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga orloo\n", x);
			break;
		case 2:
			x = pop_front(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga garlaa\n", x);
			break;
		case 3:
			print(&st);
			break;
		case 4:
			if (empty(&st))
				printf("Queue xooson\n");
			else
				printf("Queue xooson bish\n");
			break;
		case 5:
			x = front(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin exend bna\n", x);
			break;
		case 6:
			x = back(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin suuld bna\n", x);
			break;
		case 7:
			x = size(&st);
			printf("Queue-d %d shirxeg element bna\n", x);
			break;
		default:
			exit(0);
		}
	}

	release(&st);

	return 0;
}
