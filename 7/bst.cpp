#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Elm {
	int x;
	struct Elm *l, *r;
};

typedef struct Elm Elm;

Elm *root;
/*
  root-ийн зааж буй хаяг дээр үндэстэй модонд x утгыг оруулна.
  Амжилттай оруулбал x-г хадгалсан Elm хаягийг буцаана.
  Үгүй бол NULL буцна.
 */
Elm *insert(Elm *root, int x) {
	
}

/*
  root-ийн зааж буй хаяг дээр үндэстэй модноос x утгыг гаргана.
  Амжилттай гаргавал 1, үгүй бол 0 буцна.
 */
int deletee(Elm *root, int x) {
	
}
/*
  root-ийн зааж буй хаяг дээр үндэстэй модыг inorder-оор хэвлэнэ.
 */
void inorder(Elm *root) {
	
}

/*
  root-ийн зааж буй хаяг дээр үндэстэй модноос x утгыг хайна.
  Олдвол олдсон Elm хаягийг буцаана. Үгүй бол NULL буцаана.
 */
Elm *search(Elm *root, int x) {
	
}
/*
  root-ийн зааж буй хаяг дээр үндэстэй модыг тэр чигээр нь чөлөөлнө.
 */
void release(Elm *root) {
	
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
			p = insert(root, x);
			if (p)
				printf("%d utga %x xaygt orloo\n", x, p);
			else
				printf("Aldaa: oruulj chadsangui\n");
			break;
		case 2:
			printf("Ustgax utga: ");
			scanf("%d", &x);
			if (deletee(root, x))
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
				printf("%x utga %x xayt oldloo\n", p);
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
