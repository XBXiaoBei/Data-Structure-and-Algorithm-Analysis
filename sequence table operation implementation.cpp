#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h> 
#include<Windows.h>
#include<time.h>
#include<malloc.h>

typedef struct student
{
	char name[20];
	double score;
}ElemType;

typedef struct
{
	ElemType* data;
	int listsize;
	int length;
}SqList;

int initSqList(SqList* L, int max)
{
	L->data = (ElemType*)malloc(sizeof(ElemType));
	if (L->data == NULL) {
		printf("空间申请失败！\n");
		exit(0);
	}
	L->listsize = max;
	L->length = 0;
	return 1;
}

int insertSqList(SqList* L, int i, ElemType X)
{
	if (i < 1 || i > L->length + 1) {
		printf("插入位置异常\n");
		return 0;
	}
	if (L->length >= L->listsize) {
		printf("容量不够\n");
		return 0;
	}
	for (int K = L->length - 1; K > i - 1; K--) {
		L->data[K + 1] = L->data[K];
	}
	L->data[i - 1] = X;
	L->length++;
	return 1;
}

int deleteSqList(SqList* L, int i, ElemType* Elem_Del)
{
	if (L->length == 0) {
		printf("没有数据，不能删除！\n");
		return 0;
	}
	if (i <= 0 || i > L->length) {
		printf("位置异常，不能删除！\n");
		return 0;
	}
	*Elem_Del = L->data[i - 1];
	for (int K = i; K < L->length; K++) {
		L->data[K - 1] = L->data[K];
	}
	L->length--;
	return 1;
}

int updateSqLlist_pointer(SqList L, int i, ElemType Elem_Update)        //顺序表第一个成员是指向数组的指针变量；
{
	if (L.length == 0) {
		printf("没有数据不能更新！\n");
		return 0;
	}
	if (i < 1 || i > L.length) {
		printf("位置不合理！\n");
		return 0;
	}
	L.data[i - 1] = Elem_Update;
	return 1;
}

int updeteSqList_array(SqList* L, int i, ElemType Elem_Update)        //顺序表类型表中的第一个成员是数组；
{
	if (L->length == 0) {
		printf("没有数据不能更新！\n");
		return 0;
	}
	if (i < 1 || i > L->length) {
		printf("位置不合理！\n");
		return 0;
	}
	L->data[i - 1] = Elem_Update;
	return 1;
}

int locationSqList(SqList L, char* newID)
{
	if (L.length == 0) {
		printf("没有数据！\n");
		return 0;
	}
	for (int i = 0; i < L.length; i++) {
		if (strcmp(L.data[i].name, newID) == 0) {
			return i + 1;
		}
	}
	return 0;
}

int dispSqList(SqList L)
{
	if (L.length == 0) {
		printf("没有数据！\n");
		return 0;
	}
	for (int i = 0; i < L.length; i++) {
		printf("%10s, %7.2f\n", L.data[i].name, L.data[i].score);
	}
	return 1;
}

void creatSqList(SqList* L, int maxsize)
{
	if (initSqList(L, maxsize))
		printf("创建成功!\n");
	else
		printf("创建不成功!\n");
	int site_print = 0;
	ElemType Elem_print;
	char judge;
	do {
		printf("请输入第%d个学生的姓名分数，用空格隔开:", site_print + 1);
		//下面的scanf,getchar用了a, b, c来就收scanf的返回值;
		int a = scanf("%s %lf", Elem_print.name, &Elem_print.score);
		//空读回车，下次正确读入数据；
		int b = getchar();
		insertSqList(L, site_print++, Elem_print);
		printf("继续输入吗？Y/N：");
		int c = scanf("%c", &judge);
	} while (judge == 'Y');
}

int main()
{
	SqList S;
	ElemType Elem;
	char name[20] = "xiaoming";
	creatSqList(&S, 10);//init和insert包含再creat函数里面了；
	deleteSqList(&S, 4, &Elem);
	updateSqLlist_pointer(S, 4, Elem);
	locationSqList(S, name);
	dispSqList(S);
	return 0;
}

