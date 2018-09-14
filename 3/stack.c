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
/* p-ийн зааж буй Stack хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Stack *p) {
	if (p->size == 0) 
		return 1;
	return 0;
}

/* p-ийн зааж буй Stack-д x утгыг хийнэ */
 void push(struct Stack *p, int x) { 
	p->size++;
	p->dat[p->size] = x;
 } 

/* p-ийн зааж буй Stack-с гарган буцаана */
int pop(struct Stack *p) {
	
	int result;

	if(p->size == 0)
		error = 2;
	else {
		result = p->dat[p->size];
		p->size--;
	}	
	
	return result;
}

/* p-ийн зааж буй Stack-н утгуудыг хэвлэнэ */
void print(struct Stack *p) {
	for (int i = p->size-1; i >= 0; i--) 
		printf("Stack -- > %d\n",p->dat[p->size-i]);
}


int main()
{
	/* Stack үүсгэн, эхлүүлэх */
	struct Stack st;
	init(&st, 10);
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
	/* Stack-ийн эзэмшсэн нөөцийг чөлөөлөх */
	release(&st);
	return 0;
}
