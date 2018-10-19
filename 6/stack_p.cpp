#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct Stack {
	struct Node *top;
	int length;
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Stack duuren!",
	"Stack xooson!"
};

void init(struct Stack *p_stk, int n) {
	p_stk->top = NULL;
	p_stk->length = 0;
}

/* p-ийн зааж буй Stack хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Stack *p_stk) {
	if (p_stk->top == NULL)
		return 1;
	return 0;
}

/* p-ийн зааж буй Stack-д x утгыг хийнэ */
void push(struct Stack *p_stk, int x) {

	struct Node *new_node = new Node();
	new_node->data = x;

	new_node->next = p_stk->top;
	p_stk->top = new_node;

	p_stk->length++;
}

/* p-ийн зааж буй Stack-с гарган буцаана */
int pop(struct Stack *p_stk) {

	struct Node *temp;
	temp = p_stk->top;
	int result = temp->data;

	if (p_stk->length != 0) {
		p_stk->top = temp->next;
		p_stk->length--;
	}
	else
		error = 2;

	delete temp;
	
	return result;
}

/* p-ийн зааж буй Stack-н утгуудыг хэвлэнэ */
void print(struct Stack *p_stk) {

	struct Node *temp;
	temp = p_stk->top;

	while(temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}

	free(temp);

}

void release(struct Stack *p_stk) {
	while (empty(p_stk))
		pop(p_stk);
}


int main() {

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

	release(&st);

	return 0;
}
