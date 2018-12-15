#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_p.cpp"

#define PRIME 13 

struct Map {
	int size; 	// Map бүтцэд хэдэн элемент байгааг заана
	List *table; 	// Төрөл гэдэг үгийг өөрийн тодорхойлсон бүтцээр солино
};

typedef struct Map Map;
typedef struct List List;

void init(Map *mp) {

	mp->size = 0;
	mp->table = (List*)malloc(sizeof(List)*20);

	for (int i = 0; i < 20; i++)
		list_init(&mp->table[i]);

}

int hashing(char s[]) {

	int hash = 0;
	int i = 0;		//lenght of s[]

	while(s[i] != 0)
		i++;		//finding charater's lenght

	for (int j = 0; j < i; j++)
		hash += (int)s[j];	

	return hash % PRIME;
	
}
/*
  Map бүтцэд s түлхүүрийн цаана x утгыг хадгална. Хэрэв s түлхүүр
  аль хэдийн map бүтцэд байвал утгыг нь өөрчлөн x болгоно.
  mp - Map бүтцэн хувьсагчийн хаяг
  s - хашлах үгийг агуулах хүснэгт
  x - хадгалах тоо
 */
void store(Map *mp, char s[], int x) {

	int idx = hashing(s);
	Node *p = mp->table[idx].head;

	while (p != nullptr) {
		if (strcmp(p->word, s) == 0) {
			p->data = x;	
			cout << "replaced previous data" << endl;
			return;
		}
		p = p->next;
	}

	push_back(&mp->table[idx], s, x);

}
/*
  Map бүтцээс s түлхүүрийн цаана байгаа утгын хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
  mp - Map бүтцэн хувьсагчийн хаяг
  s - хашлах үгийг агуулах хүснэгт
 */
int *get(Map *mp, char s[]) {

	int idx = hashing(s);
	Node *p = mp->table[idx].head;

	while (p != nullptr) {
		if (strcmp(p->word, s) == 0) {
			return &p->data;
		}
		p = p->next;
	}

	return nullptr;
	
}
/*
  Map бүтцээс s түлхүүрийг устгах.
  Амжилттай устгавал 1, үгүй бол 0 буцаана.
  mp - Map бүтцэн хувьсагчийн хаяг
  s - хашлах үгийг агуулах хүснэгт
 */
int erase(Map *mp, char s[]) {
	
	int idx = hashing(s);
	int pos = 0;

	Node *p = mp->table[idx].head;

	while (p != nullptr) {
		if (strcmp(p->word, s) == 0) {
			erase(&mp->table[idx], pos);
			return 1;
		}
		else {
			pos++;
			p = p->next;
		}
	}

	return 0;

}

void print(Map *mp) {

	for (int i = 0; i < 20; i++) {
		if (empty(&mp->table[i]) == 0) {
			cout << "List: " << i << endl;
			print(&mp->table[i]);
		}
	}

}

int main() {

	Map mm;
	init(&mm);
	int t, x;
	char s[100];
	while (1) {
		printf("1: store, 2: get, 3: print, 4: delete, 5: exit\n");
		scanf("%d", &t);

		switch (t) {
		case 1: {
			printf("Tulxuur ug: ");
			scanf("%s", s);
			printf("Oruulax utga: ");
			scanf("%d", &x);
			store(&mm, s, x);
			printf("%d utga %d index-d orloo\n", x, hashing(s));
			break;
		}
		case 2: {
			printf("Tulxuur ug: ");
			scanf("%s", s);
			int *p = get(&mm, s);
			if (p == NULL) 
				printf("Utga oldsongui\n");
			else
				printf("%d utga oldloo\n", *p);
			break;
		}
		case 3: {
			print(&mm);
			break;
		}
		case 4: {
			printf("Tulxuur ug: ");
			scanf("%s", s);
			x = erase(&mm, s);
			if (x == 1)
				printf("Amjilttai ustagalaa\n");
			else
				printf("Tulxuur ug oldsongui\n");
			break;
		}
		default:
			exit(0);
		}
	}
	return 0;
}
