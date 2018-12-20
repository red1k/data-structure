#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Elm {
	int data;
	struct Elm *left, *right;
}; 

typedef struct Elm Elm;

Elm *root;

Elm *insert(Elm *root, int x) {

	if (root == NULL) {
		Elm *new_elm = new Elm();
		new_elm->data = x;
		new_elm->left = new_elm->right = NULL;
		return new_elm;
	}

	if (root->data >= x)
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);

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

/*
  root-ийн зааж буй хаяг дээр үндэстэй модноос x утгыг гаргана.
  Амжилттай гаргавал 1, үгүй бол 0 буцна.
 */
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

