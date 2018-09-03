#include <stdio.h>
#include <iostream>
#include <limits.h>

#define MAX 1000

using namespace std;

class Stack {
	int top;
	public:
		int a[MAX];					//Maximum size of Stack
		Stack() {
			top = -1;
		}
		int pop();
		bool push(int x);
		bool isEmpty();
		void show();
};

bool Stack::push(int x) {
	if (top >= (MAX-1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		return true;
	}
}

int Stack::pop() {
	if(top < 0) {
		cout << "Stack underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}

bool Stack::isEmpty() {
	return (top < 0);
}

/*										need to rewrite show function
void Stack::show() {
	if (isEmpty()) {
		cout << "Stack underflow \n";
	}
	for (int i = 0; i < MAX; i++)
		cout << a[i];
}
*/


int main() {
	Stack s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

//	s.show();
	cout << s.pop() << "\nPoped from stack\n";
//	s.show();

	return 0;

}
