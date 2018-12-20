#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class Stack {

	Node *top;
	public:
		Stack() {
			top = NULL;
		}
		void push(int data);
		void pop();
		void show();
};

void Stack::push(int data) {

	Node *ptr = new Node();
	ptr->data = data;

	if (top != NULL) 
		ptr->next = top;
	else
		ptr->next = NULL;

	top = ptr;
}

void Stack::pop() {
	Node *temp = new Node();
	if (top == NULL) 
		cout << "Stack underflow\n";

	temp = top;
	top = top->next;

	cout << "Poped: " << temp->data << endl;
	delete temp;
}

void Stack::show() {
	Node *ptr = top;

	while(ptr != NULL) {
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}
	cout << "NULL\n";
}


int main() {
	Stack s;	

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	s.show();
	s.pop();
	s.show();

	return 0;
}
