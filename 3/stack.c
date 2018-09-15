#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int len;
	int *dat;
	int size;
};

int error = 0;

const char error_msg[][50] = {
	"",
	"Stack duuren!",
	"Stack xooson!"
};

void init(struct Stack *p, int n) {
	p->len = n;
	p->size = 0;
	p->dat = (int *) malloc(sizeof(int) * n);
}

void release(struct Stack *p) {
	free(p->dat);
	p->dat = NULL;
}

int empty(struct Stack *p) {
	if (p->size == 0) 
		return 1;   								// if empty then 1
	return 0;
}

void push(struct Stack *p, int x) {
	if (p->size >= p->len)
		error = 1;
	else {
		p->size++;
		p->dat[p->size] = x;
	}
}

int pop(struct Stack *p) {
	
	int result;

	if (p->size == 0)
		error = 2;
	else {
		result = p->dat[p->size];
		p->size--;
	}	
	
	return result;
}

void print(struct Stack *p) {
	if (p->size == 0) 
		error = 2;
	else {
		for (int i = p->size-1; i >= 0; i--) 
			printf("Stack -- > %d\n",p->dat[p->size-i]);
	}
}
// need to print reversed order!


int main() {

	struct Stack st;
	init(&st, 5);
	int t, x;

	while (1) {
		printf("1: push, 2: pop, 3: print, 4: empty, 5: exit\n");
		scanf("%d", &t);
		error = 0;

		switch (t) {
		case 1:
			scanf("%d", &x);
			push(&st, x);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga orloo\n", x);
			break;

		case 2:
			x = pop(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga garlaa\n", x);
			break;

		case 3:
			if (empty(&st))
				printf("Stack xooson\n");
			else
				print(&st);
			break;

		case 4:
			if (empty(&st))
				printf("Stack xooson\n");
			else
				printf("Stack xooson bish\n");
			break;

		default:
			exit(0);
		}
	}

	release(&st);

	return 0;
}
