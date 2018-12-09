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

int balance(Elm *root) {
	/*
	if (height(root->left) > height(root->right))
		return height(root->left) - height(root->right);
	return height(root->right) - height(root->left);
	*/
	if (root == nullptr) 
		return 0;
	return height(root->left) - height(root->right);
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

	//root->height++;
	root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

	int check = balance(root);

	if (check > 1 && root->left->data > x) {

		Elm *temp = root;
		Elm *temp_l = root->left;

		root = temp_l;
		root->right = temp;
		root->left = temp_l->left;;

		cout << "left side is heavy" << endl;
		cout << "root: " << root->data << endl;
		cout << "root->right->data is: " << root->right->data << endl;
		cout << "root->left->data is: "<< root->left->data << endl;

		//need to update height as well!

	}
	if (check < -1 && root->right->data < x)
		cout << "right side is heavy" << endl;
	if (check > 1 && root->left->data < x)
		cout << "left-right side" << endl;
	if (check < -1 && root->right->data > x)
		cout << "right-left side" << endl;


	return root;
}

/*
  root-ийн зааж буй хаяг дээр үндэстэй модноос x утгыг хайна.
  Олдвол олдсон Elm хаягийг буцаана. Үгүй бол NULL буцаана.
 */
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
int deletion(Elm *root, int x) {

	Elm *parent = NULL;
	Elm *current = new Elm();
	current = root;

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

		Elm *temp = new Elm();
		temp = current;

		while (temp->left != NULL)
			temp = temp->left;

		current->data = temp->data;

		current->left = nullptr;
		delete temp;

	}

	else {

		Elm *temp = new Elm();

		if (current->left) {
			temp = current->left;
			current->data = temp->data;
			current->left = nullptr;
			delete temp;
		}
		else {
			temp = current->right;
			current->data = temp->data;
			current->right = nullptr;
			delete temp;
		}

	}
	return 1;
	
}
/*
  root-ийн зааж буй хаяг дээр үндэстэй модыг inorder-оор хэвлэнэ.
 */
void inorder(Elm *root) {

	if (root == NULL) return;

	inorder(root->left);
	cout << "root-> " << root->data << endl;
	inorder(root->right);

}

int baslance(Elm *root) {

	/*
	Elm *temp = new Elm();
	temp = root;

	int left_counter = 0;
	int right_counter = 0;

	while (temp != nullptr) {
		temp = temp->left;
		left_counter++;
	}

	while (temp != nullptr) {
		temp = temp->right;
		right_counter++;
	}

	if (left_counter > right_counter) 
	*/
	return 0;

}
/*
  root-ийн зааж буй хаяг дээр үндэстэй модыг тэр чигээр нь чөлөөлнө.
 */
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
		printf("1: insert, 2: delete, 3: inorder, 4: search, 5: exit 6. height\n" );
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
			cout << root->height << endl;
			cout << balance(root) << endl;
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
		case 5: {
			int result = balance(root);
			cout << result << endl;
			break;
			   }
		default:
			exit(0);
		}
	}
	release(root);
	return 0;
}
