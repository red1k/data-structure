#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct List {
	Node *head;
	Node *tail;
	int length;
};

int error = 0;
const char error_msg[][50] = {
	"List xooson!",
};

void init(struct List *p_list, int n) {
	p_list->head = NULL;
	p_list->tail = NULL;
	p_list->length = 0;
}

int empty(struct List *p_list) {
	if (p_list->head == NULL)
		return 1;
	return 0;
}

void push_back(struct List *p_list, int x) {

	struct Node *new_node = new Node();
	new_node->data = x;

	if (p_list->head == NULL) {
		new_node->next = NULL;
		p_list->head = p_list->tail = new_node;
	}

	else {
		new_node->next = NULL;
		p_list->tail->next = new_node;
		p_list->tail = new_node;
	}
	p_list->length++;
}

/* p-ийн зааж буй List-д x утгыг эхэнд  хийнэ */
void push_front(struct List *p_list, int x) {

	struct Node *new_node = new Node();
	new_node->data = x;

	if (p_list->head == NULL) {
		new_node->next = p_list->head;
		p_list->head =  new_node;
		p_list->tail =  new_node;
	}

	else {
		new_node->next = p_list->head;
		p_list->head =  new_node;
	}
	p_list->length++;
}

/* p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
   pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
 */
void insert(struct List *p_list, int x, int pos) {

	struct Node *temp = new Node();
	struct Node *prev = new Node();
	struct Node *new_node = new Node();
	
	temp = p_list->head;
	new_node->data = x;

	for (int i = 0; i < pos-1; i++)
		temp = temp->next;		

	prev->next = temp->next;
	temp->next = new_node;
	new_node->next = prev->next; 

	p_list->length++;
}


/* p-ийн зааж буй List-н эхлэлээс гарган буцаана */
int pop_front(struct List *p_list) {

	struct Node *temp = new Node();
	int result;

	temp = p_list->head;
	result = temp->data;
	p_list->head = temp->next;
	p_list->length--;

	delete temp;

	return result;
}

/* p-ийн зааж буй List-н төгсгөлөөс гарган буцаана */
int pop_back(struct List *p_list) {

	struct Node *temp = new Node(); 
	int result;

	temp = p_list->head;

	for (int i = 0; i < p_list->length-2; i++)
		temp = temp->next;	

	result = temp->next->data;
	temp = p_list->tail;

	free(temp);
	
	return result;

}

/* p-ийн зааж буй List-н pos байралаас гарган буцаана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
 */
int erase(struct List *p_list, int pos) {

	struct Node *temp = new Node();
	struct Node *next = new Node();

	temp = p_list->head;

	for (int i = 0; temp != NULL && i < pos-1; i++)
		temp = temp->next;

	int result = temp->next->data;

	next = temp->next->next;
	delete temp->next;
	temp->next = next;
	return result;
}

/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void print(struct List *p_list) {

	struct Node *temp = new Node();
	temp = p_list->head;

	while(temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}

}

int front(struct List *p_list) {
	if (p_list->head == NULL)
		error = 0;
	return p_list->head->data;	
}

int back(struct List *p_list) {
	if (p_list->head == NULL)
		error = 0;
	return p_list->tail->data;	
}

int size(struct List *p_list) {
	return p_list->length;
}

/* p-ийн зааж буй List-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int search(struct List *p_list, int x) {

	struct Node *temp = new Node();
	int position = 0;

	temp = p_list->head;
	
	while(temp != NULL) {
		if (x == temp->data)
			position++;
		temp = temp->next;
	}

	delete temp;

	if (position > 0)
		return position;
	return -1;
}

void release(struct List *p_list) {
	while (empty(p_list) == 0)
		pop_front(p_list);
}


int main() {

	struct List st;
	init(&st, 10);
	int t, x, pos;

	while (1) {
		printf("1: push_front, 2: push_back, 3: insert, 4: pop_front, 5: pop_back,"
		       "6: erase, 7: front, 8: back, 9: size, 10: empty, 11: search, 12: print,"
		       "13: exit\n");
		scanf("%d", &t);
		error = 0;

		switch (t) {
		case 1:
			printf("Exend oruulax utga: ");
			scanf("%d", &x);
			push_front(&st, x);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga exend orloo\n", x);
			break;
		case 2:
			printf("Suuld oruulax utga: ");
			scanf("%d", &x);
			push_back(&st, x);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga suuld orloo\n", x);

			break;
		case 3:
			printf("Oruulax utga: ");
			scanf("%d", &x);
			printf("Oruulax bairlal: ");
			scanf("%d", &pos);
			insert(&st, x, pos);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga %d-d orloo\n", x, pos);
			
			break;
		case 4:
			x = pop_front(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utgiig exlelees gargalaa\n", x);
			break;
		case 5:
			x = pop_back(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utgiig suulees gargalaa\n", x);
			break;
		case 6:
			printf("gargax bairlal: ");
			scanf("%d", &pos);
			x = erase(&st, pos);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utgiig %d bairlalaas gargalaa\n", x, pos);
			break;
		case 7:
			x = front(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin exend bna\n", x);
			break;
		case 8:
			x = back(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin suuld bna\n", x);
			break;
		case 9:
			x = size(&st);
			printf("List-d %d shirxeg element bna\n", x);
			break;
		case 10:
			if (empty(&st))
				printf("List xooson\n");
			else
				printf("List xooson bish\n");
			break;
		case 11:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = search(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				printf("%d utga %d bairlald oldloo\n", x, pos);
			break;
		case 12:
			print(&st);
			break;
		default:
			exit(0);
		}
	}

	release(&st);

	return 0;
}
