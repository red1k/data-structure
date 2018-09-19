#include <stdio.h>
#include <stdlib.h>

struct List {
	int len;
	int *dat;
	int size;
};

int error = 0;
const char error_msg[][50] = {
	"",
	"List duuren!",
	"List xooson!",
	"Bairlald oruulax bolomjgui!",
	"Bairlaas gargax bolomjgui!"
};

void init(struct List *p, int n) {
	p->len = n;
	p->size = 0;
	p->dat = (int *) malloc(sizeof(int) * n);
}

void release(struct List *p) {
	free(p->dat);
	p->dat = NULL;
}

int empty(struct List *p) {
	if (p->size == 0)
		return 1;
	return 0;
}
/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void push_back(struct List *p, int x) {
	if (p->size >= p->len)
		error = 1;
	else
		p->dat[p->size++] = x;
}

void push_front(struct List *p, int x) {
	if (p->size >= p->len)
		error = 1;
	else if (p->size == 0) {
		p->dat[0] = x;
		p->size++;
	}
	else {
		struct List temp;
		init(&temp, p->size);

		for (int i = 0; i <= p->size; i++)					//copying List p's data to List temp
			temp.dat[i] = p->dat[i];

		for (int i = 1; i <= p->size; i++)
			p->dat[i] = temp.dat[i-1];

		p->dat[0] = x;
		p->size++;
	}
}

/* p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
   pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
 */
void insert(struct List *p, int x, int pos) {

	if (p->size >= p->len)
		error = 1;
	else if (p->len < pos || p->size < pos) {
		error = 3;
	}
	else {
		struct List temp;
		init(&temp, p->size);

		for (int i = pos; i <= p->size; i++)
			temp.dat[i] = p->dat[i];

		for (int i = pos; i <= p->size; i++)
			p->dat[pos+1] = temp.dat[pos];

		p->size++;
		p->dat[pos] = x;
	}
}

/* p-ийн зааж буй List-н эхлэлээс гарган буцаана */
int pop_front(struct List *p) {

	if (p->size == 0)
		error = 2;
	else {
		struct List temp;
		init(&temp, p->size);
		int result = p->dat[0];

		for (int i = 0; i <= p->size; i++)
			temp.dat[i]	= p->dat[i];

		for (int i = 0; i <= p->size; i++)
			p->dat[i] = temp.dat[i+1];

		p->size--;
		return result;
	}
}

/* p-ийн зааж буй List-н төгсгөлөөс гарган буцаана */
int pop_back(struct List *p) {

	if (p->size == 0)
		error = 2;
	else {
		int result = p->dat[p->size-1];		//need to delete p->size,
		p->size = p->size - 1;			//return 0 all the time, need to fix this!
		return result;
	}

}

/* p-ийн зааж буй List-н pos байралаас гарган буцаана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
 */
int erase(struct List *p, int pos) {

	if (p->size == 0)
		error = 2;
	else if (p->size < pos)
		error = 3;
	else {

		struct List temp;
		init(&temp, p->size);
		int current = p->dat[pos];

		for (int i = pos; i <= p->size; i++)
			temp.dat[i] = p->dat[i];

		for (int i = pos; i <= p->size; i++)
			p->dat[i] = temp.dat[i+1] ;

		p->size--;
		return current;
	}
}

/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void print(struct List *p) {
	if (p->size == 0)
		error = 1;
	else {
		for (int i = 0; i < p->size; i++)
			printf("List -> %d\n", p->dat[i]);
	}
}

int front(struct List *p) {
	if (p->size == 0)
		error = 2;
	return p->dat[0];
}

int back(struct List *p) {
	if (p->size == 0)
		error = 2;
	else
		return p->dat[p->size-1];
}

int size(struct List *p) {
	if (p->size != 0)
		return p->size;
	return 0;
}

int search(struct List *p, int x) {			//need to fix this shit!

	int position = 0;

	for (int i = 0; i <= p->size; i++) {
		if (p->dat[i] == x){
			++position;
			break;
		}
		++position;
	}

	if (position > 0)
		return position;
	return -1;
}

int main() {
	/* List үүсгэн, эхлүүлэх */
	struct List st;
	init(&st, 10);
	int t, x, pos;

	while (1) {
		printf("1: push_front, 2: push_back, 3: insert, 4: pop_front, 5: pop_back,"
		       "6: erase, 7: front, 8: back, 9: size, 10: empty, 11: search, 12: print,"
		       "13: exit\n");
		scanf("%d", &t);
		error = 0;

		switch (t) {
		case 1:
			printf("Exend oruulax utga: ");
			scanf("%d", &x);
			push_front(&st, x);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga exend orloo\n", x);
			break;
		case 2:
			printf("Suuld oruulax utga: ");
			scanf("%d", &x);
			push_back(&st, x);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga suuld orloo\n", x);

			break;
		case 3:
			printf("Oruulax utga: ");
			scanf("%d", &x);
			printf("Oruulax bairlal: ");
			scanf("%d", &pos);
			insert(&st, x, pos);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga %d-d orloo\n", x, pos);
			
			break;
		case 4:
			x = pop_front(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utgiig exlelees gargalaa\n", x);
			break;
		case 5:
			x = pop_back(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utgiig suulees gargalaa\n", x);
			break;
		case 6:
			printf("gargax bairlal: ");
			scanf("%d", &pos);
			x = erase(&st, pos);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utgiig %d bairlalaas gargalaa\n", x, pos);
			break;
		case 7:
			x = front(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin exend bna\n", x);
			break;
		case 8:
			x = back(&st);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin suuld bna\n", x);
			break;
		case 9:
			x = size(&st);
			printf("List-d %d shirxeg element bna\n", x);
			break;
		case 10:
			if (empty(&st))
				printf("List xooson\n");
			else
				printf("List xooson bish\n");
			break;
		case 11:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = search(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				printf("%d utga %d bairlald oldloo\n", x, pos);
			break;
		case 12:
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				print(&st);
			break;
		default:
			exit(0);
		}
	}
	release(&st);
	return 0;
}
