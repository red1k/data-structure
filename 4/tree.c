/* 
	root - modnii oroi, parent node baihgui 
	children - downside 					NODE THAT HAS PARENT NODE
	parent - upside						NODE THAT HAS CHILD NODE	
	sibling - zeregtsee node uud, neg parenttai 		NODE THAT HAS HAVE SAME PARENT 
	leaves - child node baihgui node, tugsgul node		NODE THAT DOES NOT HAVE A CHILD 
	grand-parent						PARENT OF PARENT
*/

#include <stdio.h>
#include <stdlib.h>

struct Tree {
	int len;  // Нийт багтаамж
	int size; // Одоогийн хэмжээ
	int *dat; // Өгөгдөл хадгалах хүснэгтийг заах хаяг
};

int error = 0;

const char error_msg[][50] = {
	"",
	"Mod duuren!",
};

void init(struct Tree *p, int n) {
	p->len = n;
	p->size = 0;
	p->dat = (int *) malloc(sizeof(int) * n);
}

void release(struct Tree *p) {
	free(p->dat);
	p->dat = NULL;
}

/* p-ийн зааж буй Tree-с x тоог хайн олдсон байрлалыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int search(struct Tree *p, int x) {
	for (int i = 0; i < p->size; i++) {
		if (p->dat[i] == x)
			return i;
	}
	return -1;
}

// p-ийн зааж буй Tree-ийн өндрийг буцаана
int height(struct Tree *p) {
	int count = 0;

	for (int i=0; i<p->size; i=2*i+1)
		count++;

	return count;
}

// p-ийн зааж буй Tree-д x утгыг оруулна
void insert(struct Tree *p, int x) {
	if (p->size >= p->len)
		error = 1;
	p->dat[p->size++] = x;
}

// p-ийн зааж буй Tree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно
void leaves(struct Tree *p, int idx) {

	if (idx >= p->size)
		return;

	if (idx*2+1 >= p->size) {
		printf("%d\n",p->dat[idx]);
		return;
	}

	leaves(p, (2 * idx + 1));
	leaves(p, (2 * (idx + 1)));
}


/* p-ийн зааж буй Tree-д idx зангилааны ах, дүүгийн зангилааны дугаарыг буцаана
   (Нэг эцэгтэй зангилаа). Байхгүй бол -1-г буцаана
 */
int sibling(struct Tree *p, int idx) {
	/* Энд ах, дүүг олох үйлдлийг хийнэ үү */
	if (idx % 2 == 0 && idx <= p->size)
		return --idx;
	else if (idx % 2 != 0) {
		idx++;
		if (p->dat[idx] == 0)
			return -1;
		return idx;
	}
}

// p-ийн зааж буй Tree-д x утгатай зангилааны хүүхдүүдийн утгыг хэвлэ
void children(struct Tree *p, int x) {
	int left = x * 2 + 1;
	int right = x * 2 + 2;

	if (p->dat[left] != 0)
		printf("%d", p->dat[left]);
	if (p->dat[right] != 0)
		printf("%d", p->dat[right]);
}

// p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ
void preorder(struct Tree *p, int idx) {

	if (p->size <= idx)
		return;

	printf("%d", p->dat[idx]);		//printing
	preorder(p, 2*idx+1);			//left
	preorder(p, 2*(idx+1));			//right
}

// p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ
void inorder(struct Tree *p, int idx) {

	if (p->size <= idx)
		return;

	inorder(p, 2*idx+1);			//left
	printf("%d", p->dat[idx]);		//printing
	inorder(p, 2*(idx+1));			//right
}

// p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ
void postorder(struct Tree *p, int idx) {

	if (p->size <= idx)
		return;

	postorder(p, 2*idx+1);			//left
	postorder(p, 2*(idx+1));		//right
	printf("%d", p->dat[idx]);		//printing
}

// p-ийн зааж буй Tree-д idx зангилаанаас доошхи бүх үр садыг хэвлэнэ
void descendants(struct Tree *p, int idx) {

	if (2*(idx+1) > p->size)
		printf("No descendants");

	postorder(p, 2*idx+1);
	postorder(p, 2*(idx+1));
}

// p-ийн зааж буй Tree-д idx зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ
void ancestors(struct Tree *p, int idx) {

	if (idx == 1 || idx == 2) {
		printf("%d", p->dat[0]);
		return;
	}
	ancestors(p, (idx-1)/2);
	printf("%d", p->dat[(idx-1)/2]);
}

int size(struct Tree *p) {
	return p->size;
}


/* p-ийн зааж буй Tree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
   x тоо олдохгүй бол -1-г буцаана.
 */
int level(struct Tree *p, int x) {
	return height(p) - 1;
}

int main() {
	struct Tree tr;
	init(&tr, 10);
	int t, x, pos, idx;

	while (1) {
		printf("1: height, 2: insert, 3: leaves, 4: descendants, 5: ancestors,"
		       "6: sibling, 7: children, 8: preorder, 9: inorder, 10: postorder, 11: size, 12: search, 13: level"
		       "14: exit\n");
		scanf("%d", &t);
		error = 0;

		switch (t) {
		case 1:
			printf("Modnii undur: %d\n", height(&tr));
			break;
		case 2:
			printf("Oruulax utga: ");
			scanf("%d", &x);
			insert(&tr, x);
			if (error) 
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga orloo\n", x);
			
			break;
		case 3:
			leaves(&tr, 0);
			break;
		case 4:
			printf("Zangilaanii dugaariig oruul: ");
			scanf("%d", &idx);
			descendants(&tr, idx);
			break;
		case 5:
			printf("Zangilaanii dugaariig oruul: ");
			scanf("%d", &idx);
			ancestors(&tr, idx);
			break;
		case 6:
			printf("Zangilaanii dugaariig oruul: ");
			scanf("%d", &idx);
			printf("ax duugiin bairlal: %d\n", sibling(&tr, idx));
			break;
		case 7:
			printf("Utga oruul: ");
			scanf("%d", &x);
			children(&tr, x);
			break;
		case 8:
			preorder(&tr, 0);
			break;
		case 9:
			inorder(&tr, 0);
			break;
		case 10:
			postorder(&tr, 0);
			break;
		case 11:
			printf("Xemjee: %d\n", size(&tr));
			break;
		case 12:
			printf("Xaix utga oruul: ");
			scanf("%d", &x);
			pos = search(&tr, x); 
			if (pos != -1)
				printf("%d utga %d bairlald oldloo\n", x, pos);
			else
				printf("%d utga oldsongui\n", x);
			break;
		case 13:
			printf("Utga oruul: ");
			scanf("%d", &x);
			printf("%d utgiin tuwshin: %d\n", x, level(&tr, x));
		default:
			exit(0);
		}
	}

	release(&tr);

	return 0;
}
