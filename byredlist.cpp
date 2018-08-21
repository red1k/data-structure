#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node *next;
};


class LinkedList {
	public:
		int length;
		Node *head;
		Node *tail;

		LinkedList() {
            cout << "Linked list object created!\n";
            this->head = NULL;
            this->tail = NULL;
            this->length = 0;
		}

		~LinkedList() {
			cout << "Linked List deleted" << endl;
		}

		void print();
		void push(int data);
		void append(int data);

		/*
		void insert(int data);
		*/

};

void LinkedList::push(int data) { 
	Node *new_node = new Node();

    new_node->data = data;
    new_node->next = head;
    head = new_node;

	this->length++;
}

void LinkedList::append(int data) { 

	Node *new_node = new Node();

    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
        tail = new_node;
    }

	this->length++;
}

void LinkedList::print() {
	Node *temp = new Node();
	temp = head;

	while(temp!=NULL) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
}


int main() {

	LinkedList *list = new LinkedList();

	list->push(4);
	list->push(3);
	list->push(2);
	list->push(1);

	list->print();
    cout << "\n";

	cout << "Length of linked list is: " << list->length << "\n";

	delete list;
	
	return 0;

}
