#include <stdio.h>
#include <stdlib.h>

struct Elm {
	int x;
	struct Elm *next;
};
struct Stack {
	struct Elm *top;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"Stack duuren!",
	"Stack xooson!"
};

void init(struct Stack *p_stk, int n)
{
	p_stk->top = NULL;
}

/* p-ийн зааж буй Stack хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Stack *p_stk)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
}

/* p-ийн зааж буй Stack-д x утгыг хийнэ */
void push(struct Stack *p_stk, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Stack-с гарган буцаана */
int pop(struct Stack *p_stk)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Stack-н утгуудыг хэвлэнэ */
void print(struct Stack *p_stk)
{
	/* Энд хэвлэх үйлдлийг хийнэ үү */
}

void release(struct Stack *p_stk)
{
	while (empty(p_stk))
		pop(p_stk);
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
