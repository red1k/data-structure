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

		LinkedList() {
            cout << "Linked list object created!\n";
            this->head = NULL;
            this->length = 0;
		}

		~LinkedList() {
			cout << "Linked List deleted" << endl;
		}

		void print();
		void push(int data);
		void append(int data);
		void insert(int data, int index);
		void delete_first();
		void delete_last();
		void deletion(int index);

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
    Node *current = head;

    new_node->data = data;
    new_node->next = NULL;

    if(current == NULL) 
        head = new_node;

    else {
        while(current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
	this->length++;
}

void LinkedList::insert(int data, int index) {

	Node *new_node = new Node();
    Node *temp = head;

	if (index == 1)
		this->push(data);
	
	else if (index == 0) 
		this->append(data);

	else {
    	new_node->data = data;
		for (int i = 1; i < index-1; i++) 		//traverse
			temp = temp->next;			

		new_node->next = temp->next;
		temp->next = new_node;

		this->length++;
	}
}

void LinkedList::delete_first() {

}

void LinkedList::delete_last() {

}

void LinkedList::deletion(int index) {

	Node *temp = new Node();
	Node *prev = new Node();
	temp = head;

	for (int i = 1; i < index; i++) {
		prev = temp;							//re-read again and understand!
		temp = temp->next;	
	}

	prev->next = temp->next;	

	delete temp;
	this->length--;	
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

	list->append(10);
	list->append(20);
	list->append(30);
	list->append(40);

	list->deletion(6);

	list->print();
    cout << "\n";

	cout << "Length of linked list is: " << list->length << "\n";

	delete list;
	
	return 0;

}
