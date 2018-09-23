/* 
	root - modnii oroi, parent node baihgui 
	children - downside 								NODE THAT HAS PARENT NODE
	parent - upside										NODE THAT HAS CHILD NODE	
	sibling - zeregtsee node uud, neg parenttai 		NODE THAT HAS HAVE SAME PARENT 
	leaves - child node baihgui node, tugsgul node		NODE THAT DOES NOT HAVE A CHILD 
	grand-parent										PARENT OF PARENT
*/

//what is the difference between list and tree if there is no rigth or left nodes?

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

/* p-ийн зааж буй Tree-ийн өндрийг буцаана */
int height(struct Tree *p) {
	/* Энд өндрийг олох үйлдлийг хийнэ */
}

/* p-ийн зааж буй Tree-д x утгыг оруулна */
void insert(struct Tree *p, int x) {
	/* Энд оруулах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно */
void leaves(struct Tree *p, int idx) {
	/* Энд навчуудыг үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д idx зангилаанаас доошхи бүх үр садыг хэвлэнэ  */
void descendants(struct Tree *p, int idx) {
	/* Энд үр садыг олох үйлдлийг хийнэ үү */
}


/* p-ийн зааж буй Tree-д idx зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ */
void ancestors(struct Tree *p, int idx) {
	/* Энд өвөг эцгийг олох үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д idx зангилааны ах, дүүгийн зангилааны дугаарыг буцаана
   (Нэг эцэгтэй зангилаа). Байхгүй бол -1-г буцаана
 */
int sibling(struct Tree *p, int idx) {
	/* Энд ах, дүүг олох үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д x утгатай зангилааны хүүхдүүдийн утгыг хэвлэ.
 */
void children(struct Tree *p, int x) {
	/* Энд хүүхдүүдийн утгыг хэвлэх үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ */
void preorder(struct Tree *p, int idx) {
	/* Энд pre-order-оор хэвлэх үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ */
void inorder(struct Tree *p, int idx) {
	/* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ */
void postorder(struct Tree *p, int idx) {
	/* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
   Tree-д өөрчлөлт оруулахгүй.
 */
int size(struct Tree *p) {
	
}


/* p-ийн зааж буй Tree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
   x тоо олдохгүй бол -1-г буцаана.
 */
int level(struct Tree *p, int x) {
	
}

int main() {
	/* Tree үүсгэн, эхлүүлэх */
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
			printf("Modnii undur: ", height(&tr));
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
