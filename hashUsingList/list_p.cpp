#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Node {
	int data;
	char word[20];
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

void list_init(struct List *p_list) {
	p_list->head = NULL;
	p_list->tail = NULL;
	p_list->length = 0;
}

int empty(struct List *p_list) {
	if (p_list->head == NULL)
		return 1;
	return 0;
}

void push_back(struct List *p_list, char s[], int x) {

	struct Node *new_node = new Node();
	new_node->data = x;
	strcpy(new_node->word, s);

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
		new_node->next = NULL;
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

	struct Node *temp;// = new Node();
	struct Node *prev;// = new Node();
	struct Node *new_node = new Node();
	
	temp = p_list->head;
	new_node->data = x;

	for (int i = 0; i < pos-1; i++)
		temp = temp->next;		

	prev = temp->next;
	temp->next = new_node;
	new_node->next = prev;

	p_list->length++;
}


/* p-ийн зааж буй List-н эхлэлээс гарган буцаана */
int pop_front(struct List *p_list) {

	struct Node *temp;
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

	struct Node *temp;
	int result;

	temp = p_list->head;

	if(p_list->head == NULL)
		error = 1;

	else if(p_list->length == 1)
		return pop_front(p_list);

	else {
		for (int i = 0; i < p_list->length-2; i++)
			temp = temp->next;

		result = temp->next->data;
		p_list->tail = temp;

		delete temp->next;

		p_list->tail->next = NULL;
		p_list->length--;

		return result;
	}
}

/* p-ийн зааж буй List-н pos байралаас гарган буцаана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
 */
int erase(struct List *p_list, int pos) {

	struct Node *temp, *next;
	int result;

	if (pos == 0)
		return pop_front(p_list);

	else if (pos == p_list->length)
		return pop_back(p_list);

	else {
		temp = p_list->head;
		for (int i = 0; i < pos-1; i++)
			temp = temp->next;

		result = temp->next->data;
		next = temp->next->next;
		delete temp->next;
		temp->next = next;

		return result;
	}
}

/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void print(struct List *p_list) {

	struct Node *temp;
	temp = p_list->head;

	while(temp != NULL) {
		cout << temp->word << " - " << temp->data << endl;
		temp = temp->next;
	}
	free(temp);
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

	struct Node *temp;
	int position = 0;

	temp = p_list->head;
	
	while(temp != NULL) {
		if (x == temp->data)
			position++;
		temp = temp->next;
	}

	free(temp);

	if (position > 0)
		return position;
	return -1;
}

void release(struct List *p_list) {
	while (empty(p_list) == 0)
		pop_front(p_list);
}
