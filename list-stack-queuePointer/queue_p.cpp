#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};
struct Queue {
	struct Node *head, *tail;
	int length;
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Queue duuren!",
	"Queue xooson!"
};

void init(struct Queue *p_qq, int n) {
	p_qq->head = p_qq->tail = NULL;
	p_qq->length = 0;
}

/* p-ийн зааж буй Queue хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Queue *p_qq) {
	if (p_qq->head == NULL)
		return 1;
	return 0;
}

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void push_back(struct Queue *p_qq, int x) {

	struct Node *new_node = new Node();
	new_node->data = x;
	
	if (p_qq->head == NULL) {
		new_node->next = NULL;
		p_qq->head = p_qq->tail = new_node;
	}

	else {
		new_node->next = NULL;
		p_qq->tail->next = new_node;
		p_qq->tail = new_node;
	}

	p_qq->length++;

}

/* p-ийн зааж буй Queue-с гарган буцаана */
int pop_front(struct Queue *p_qq) {

	struct Node *temp;
	int result;

	temp = p_qq->head;
	result = temp->data;
	p_qq->head = temp->next;
	p_qq->length--;

	delete temp;

	return result;

}

/* p-ийн зааж буй Queue-н утгуудыг хэвлэнэ */
void print(struct Queue *p_qq) {
	struct Node *temp;
	temp = p_qq->head;

	while(temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}

	free(temp);
}

/* p-ийн зааж буй Queue-н хамгийн эхний элементийн утгыг буцаана.
   Гаргах үйлдэл хийхгүй.
 */
int front(struct Queue *p_qq) {
	return p_qq->head->data;	
}
/* p-ийн зааж буй Queue-н хамгийн сүүлийн элементийн утгыг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int back(struct Queue *p_qq) {
	return p_qq->tail->data;	
}
/* p-ийн зааж буй Queue-д хэдэн элемент байгааг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int size(struct Queue *p_qq) {
	return p_qq->length;
}

void release(struct Queue *p_qq) {
	while (empty(p_qq) == 0)
		pop_front(p_qq);
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
			cout << "Queue-d oruulah utga: " << endl;
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
