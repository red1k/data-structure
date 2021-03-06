#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Хэрэв зурахыг хүсэнгүй бол доорх 1 мөрийг арилга */
#define DRAW_ENABLED

#ifdef DRAW_ENABLED
#include "graphics.h"

#define S_WIDTH              640
#define S_HEIGHT             480
#define BAR_WIDTH            10
#define BAR_SPACE            10
#define FPS                  500
/* дамжуулсан хүснэгтийн утгуудыг зурна */
void zurax(int (*), int, int , int);

/* graphic exluulex function */
void graphic_exluul();

#endif

/* дамжуулсан хүснэгтэд [10...200] хооронд утга дүүргэнэ */
void utga_duurge(int (*), int);

/* Эрэмбэлэх функц */
void insertion_sort(int (*), int);
void selection_sort(int (*), int);
void bubble_sort(int (*), int);

/* Дамжуулсан хүснэгтийг Хэвлэх функц */
void print(int (*), int);

int main() {
	int a[100], n = 20;
#ifdef DRAW_ENABLED
	graphic_exluul();
#endif

	/***************************************************
	 * Insertion sort хийх хэсэг
	 *
	 ***************************************************/
	utga_duurge(a, n);
	print(a, n);
	
	insertion_sort(a, n);
	print(a, n);

	/***************************************************
	 * Selection sort хийх хэсэг
	 *
	 ***************************************************/
	utga_duurge(a, n);
	print(a, n);
	
	selection_sort(a, n);
	print(a, n);

	/***************************************************
	 * Bubble sort хийх хэсэг
	 *
	 ***************************************************/
	utga_duurge(a, n);
	print(a, n);
	
	bubble_sort(a, n);
	print(a, n);

#ifdef DRAW_ENABLED
	closegraph();
#endif

	return 0;
}

#ifdef DRAW_ENABLED
void graphic_exluul() {
	/* graphic эхлүүлэх */
	initwindow(S_WIDTH, S_HEIGHT);

	int errorcode = graphresult();
	if (errorcode != grOk) { /* Алдаа гарлаа */
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(-1);
	}
	setbkcolor(BLACK);
	cleardevice();
}


void zurax(int a[], int n, int sel1, int sel2) {
	int i, col;
	int x = 20;

	/* Дэлгэцийг цэвэрлэе */
	cleardevice();
	setcolor(GREEN);
	outtextxy (10, 10, "Ymar negen tovch darval xaagdana\0");

	if (kbhit()) { /* Гараас товч дарагдсан эсэхийг шалга */
		closegraph();
		exit(0);
	}

	for (i = 0; i < n; i++, x += BAR_WIDTH + BAR_SPACE) { /* дараагийн баганыг зурах */
		col = BLUE;
		if (i == sel1)
			col = RED;
		else if (i == sel2)
			col = GREEN;
		setcolor(col);
		/* дөрвөлжин зурах */
		rectangle(x, S_HEIGHT - a[i], x + BAR_WIDTH, S_HEIGHT);
	}

	/* FPS секунт хүлээ */
	delay(FPS);

}

#endif

void utga_duurge(int a[], int n) {
	srand(time(NULL)); 	/* random тоо үүсгэгчийг одоогийн цагаар эхлүүлэх */
	int i;
	for (i = 0; i < n; i++)
		a[i] = rand() % 200 + 10; /* 1...100 завсарт үүсгэх тул 1-г нэмнэ */
}


void insertion_sort(int a[], int n) {
	/***************************************************
	 * Даалгавар: Энэ хэсэгт өөрийн insertion sort-ийг
	 * хийх кодыг бичнэ.
	 * a     нь эрэмбэлэх хүснэгт
	 * n     нь хүснэгтэд байгаа утгуудын тоо
	 ***************************************************/
}

void selection_sort(int a[], int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

void bubble_sort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1 ; j++) {
			if (a[j] > a[j+1]) 
				swap(&a[j], &a[j+1]);
		}
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
