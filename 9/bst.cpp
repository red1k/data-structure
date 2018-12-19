#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Elm {
	int data;
	int height;
	struct Elm *left, *right;
}; 

typedef struct Elm Elm;

Elm *root;

int height(Elm *root) {

	return root == nullptr ? 0 : root->height;

}

int balance (Elm *root) {

	if (root == nullptr)
		return 0;
	else
		return height(root->left) - height(root->right);

}

Elm *left_rotate(Elm *root) {

	Elm *q = root->right;
	Elm *r = q->left;

	q->left = root;
	root->right = r;

	root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
	q->height = 1 + (height(q->left) > height(q->right) ? height(q->left) : height(q->right));

	return q;

}

Elm *right_rotate(Elm *root) {

	Elm *q = root->left;
	Elm *r = q->right;

	q->right = root;
	root->left = r;

	root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
	q->height = 1 + (height(q->left) > height(q->right) ? height(q->left) : height(q->right));

	return q;

}

Elm *insert(Elm *root, int x) {

	if (root == NULL) {
		Elm *new_elm = new Elm();
		new_elm->data = x;
		new_elm->height = 1;
		new_elm->left = new_elm->right = NULL;
		return new_elm;
	}

	if (root->data >= x)
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);

	root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

	int check = balance(root);

	if (check > 1 && root->left->data > x) {
		return right_rotate(root);
	}

	if (check > 1 && root->left->data < x) {
		root->left = left_rotate(root->left);
		return right_rotate(root);
		//cout << "left-right side is heavy" << endl;
	}
	if (check < -1 && root->right->data < x) {
		return left_rotate(root);
	}
	if (check < -1 && root->right->data > x) {
		root->right = right_rotate(root->right);
		return left_rotate(root);
		//cout << "right-left side is heavy" << endl;
	}

	return root;
}

Elm *search(Elm *root, int data) {

	if (root == NULL || root->data == data)
		return root;

	if (root->data < data) {
		if (root->right == NULL)
			return NULL;
		return search(root->right, data);
	}
	else  {
		if (root->left == NULL)
			return NULL;
		return search(root->left, data);
	}

}

Elm *deletion(Elm *root, int x) {

	Elm *parent;
	Elm *current = root;

	while (current != NULL && current->data != x) {
		parent = current;
		if (x <= current->data)
			current = current->left;
		else
			current = current->right;
	}

	if (current == NULL) return 0;

	else if (current->left == NULL && current->right == NULL) {
		if (current != root) {
			if (parent->right == current)
				parent->right = NULL;
			else
				parent->left = NULL;
		}
		else 
			root = NULL;

		delete current;
	}

	else if (current->left && current->right) {

		Elm *temp = current->right;

		while (temp->left != NULL)
			temp = temp->left;

		current->data = temp->data;

		current->right = deletion(current->right, temp->data);

	}

	else {

		Elm *temp = (current->left) ? current->left : current->right;

		if (current != root) {
			if (current == parent->left)
				parent->left = temp;
			else
				parent->right = temp;
		}

		else
			root = temp;

		delete current;

	}

	return root;
	
}

void inorder(Elm *root) {

	if (root == NULL) return;

	inorder(root->left);
	cout << "root-> " << root->data << endl;
	inorder(root->right);

}

void release(Elm *root) {

	while (root != NULL) {
		release(root->left);
		release(root->right);
		root = nullptr;
		delete root;
	}

}

int main() {
	int t, x, pos, y;
	Elm *p;
	while (1) {
		printf("1: insert, 2: delete, 3: inorder, 4: search, 5: exit\n" );
		scanf("%d", &t);

		switch (t) {
		case 1:
			printf("Oruulax utga: ");
			scanf("%d", &x);
			p = root = insert(root, x);
			if (p)
				printf("%d utga %p xaygt orloo\n", x, p);
			else
				printf("Aldaa: oruulj chadsangui\n");
			break;
		case 2:
			printf("Ustgax utga: ");
			scanf("%d", &x);
			if (deletion(root, x))
				printf("%d utga ustlaa\n", x);
			else
				printf("Aldaa: ustgaj chadsangui\n");
			break;
		case 3:
			inorder(root);
			cout << "Height of the tree is: " << height(root) << endl;
			cout << "Root->data: " << root->data << endl;
			cout << "Root->left->data: " << root->left->data << endl;
			cout << "Root->right->data: " << root->right->data << endl;
			cout << "Height of the left child is: " << height(root->left) << endl;
			cout << "Height of the right child is: " << height(root->right) << endl;
			cout << "Balance of the tree is: " << balance(root) << endl;
			break;
		case 4:
			printf("Xaix utga: ");
			scanf("%d", &x);
			p = search(root, x);
			if (p) 
				printf("%d utga %p xayt oldloo\n", x, p);
			else
				printf("%d utga oldsongui\n", x);
			break;
		default:
			exit(0);
		}
	}
	release(root);
	return 0;
}

//jsfiddle.net/hv2fujds

