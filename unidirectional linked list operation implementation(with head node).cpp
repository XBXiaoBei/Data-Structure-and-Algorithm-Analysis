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

typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;

int initLinkList1(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (*L == NULL)
		return 0;
	(*L)->next = NULL;
	return 1;
}

LinkList initLinkList2()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL)
		return NULL;
	L->next = NULL;
	return L;
}

int insertLinkList(LinkList L, int i, ElemType Elem_Insert)
{
	LinkList Link_Insert, Link_Primary = L;
	int site = 0;
	if (i < 1) {
		printf("插入位置越下界，插入失败！\n");
		return 0;
	}
	while (Link_Primary != NULL && site < i - 1) {
		Link_Primary = Link_Primary->next;
		site++;
	}
	if (Link_Primary == NULL) {
		printf("插入位置越上界，插入失败！\n");
		return 0;
	}
	if (!initLinkList1(&Link_Insert))
		return 0;
	Link_Insert->data = Elem_Insert;
	Link_Insert->next = Link_Primary->next;
	Link_Primary->next = Link_Insert;
	return 1;
}

int deleteLinkList(LinkList L, int i, ElemType* Elem_Delete)
{
	LinkList Link_Delete, Link_Primary = L;
	int site = 0;
	if (L->next == NULL) {
		printf("链表为空，删除失败！\n");
		return 0;
	}
	if (i < 1) {
		printf("插入位置越下界，插入失败！\n");
		return 0;
	}
	while (Link_Primary->next != NULL && site < i - 1) {
		Link_Primary = Link_Primary->next;
		site++;
	}
	if (Link_Primary->next == NULL) {
		printf("插入位置越上界，插入失败！\n");
		return 0;
	}
	Link_Delete = Link_Primary->next;
	Link_Primary->next = Link_Delete->next;
	*Elem_Delete = Link_Delete->data;
	return 1;
}

int updateLinkList(LinkList L, int i, ElemType Elem_Update)
{
	LinkList Link_Update;
	int site = 0;
	if (L->next == NULL) {
		printf("链表为空，不能更新！\n");
		return 0;
	}
	if (i < 1) {
		printf("更新位置越下界，不能更新\n");
		return 0;
	}
	Link_Update = L->next;
	site = 1;
	while (Link_Update != NULL && site < i) {
		Link_Update = Link_Update->next;
		site++;
	}
	if (Link_Update == NULL) {
		printf("更新位置超越上界，不能更新！\n");
		return 0;
	}
	Link_Update->data = Elem_Update;
	return 1;
}

LinkList locationLinkList(LinkList L, char* name)
{
	LinkList Link_Location = L->next;
	while (Link_Location) {
		if (strcmp(Link_Location->data.name, name) != 0)
			Link_Location = Link_Location->next;
		else
			return Link_Location;
	}
	return NULL;
}

void dispLinkList(LinkList L)
{
	LinkList Link_to_Display = L->next;
	while (Link_to_Display) {
		printf("%s %7.2f\n", Link_to_Display->data.name, Link_to_Display->data.score);
		Link_to_Display = Link_to_Display->next;
	}
}

void creatLinkList(LinkList* L)
{
	int i = 1;
	ElemType Elem_Creat;
	char judge;
	initLinkList1(L);
	do {
		printf("请输入第%d个学生的姓名和分数，用空格分开:\n", i);
		int a = scanf("%s %lf", Elem_Creat.name, &Elem_Creat.score);
		int c = getchar();
		insertLinkList(*L, i++, Elem_Creat);
		printf("继续输入吗?Y/N:");
		int b = scanf("%c", &judge);
	} while (judge == 'Y');
}

int frontcreatLinkList(LinkList* L)
{
	ElemType Elem_Creat;
	LinkList Link_Creat;
	char judge;
	int n = 0;
	initLinkList1(L);
	do {
		printf("请输入第%d个学生的姓名和分数，用空格分开:\n", ++n);
		int a = scanf("%s %lf", Elem_Creat.name, &Elem_Creat.score);
		int c = getchar();
		if ((Link_Creat = (LinkList)malloc(sizeof(LNode))) == NULL)
			return 0;
		Link_Creat->data = Elem_Creat;
		Link_Creat->next = NULL;
		Link_Creat->next = (*L)->next;
		(*L)->next = Link_Creat;
		printf("继续输入吗?Y/N:");
		int b = scanf("%c", &judge);
	} while (judge == 'Y');
	return 1;
}

int rearcreatLinkList(LinkList* L)
{
	LinkList Link_Creat, Link_Rear;
	ElemType Elem_Creat;
	char judge;
	int n = 0;
	initLinkList1(L);
	Link_Rear = *L;
	do {
		printf("请输入第%d个学生的姓名和分数，用空格分开:\n", ++n);
		int a = scanf("%s %lf", Elem_Creat.name, &Elem_Creat.score);
		int c = getchar();
		if ((Link_Creat = (LinkList)malloc(sizeof(LNode))) == NULL)
			return 0;
		Link_Creat->data = Elem_Creat;
		Link_Creat->next = NULL;
		Link_Rear->next = Link_Creat;
		Link_Rear = Link_Creat;
		printf("继续输入吗?Y/N:");
		int b = scanf("%c", &judge);
	} while (judge == 'Y');
	return 1;
}

void invertLinkList(LinkList L)
{
	LinkList Link_Invert, Link_Invert_Next;
	if (L->next == NULL)
		return;
	Link_Invert = L->next;
	L->next = NULL;
	while (Link_Invert) {
		Link_Invert_Next = Link_Invert->next;
		Link_Invert->next = L->next;
		L->next = Link_Invert;
		Link_Invert = Link_Invert_Next;
	}
}

void clearLinkList(LinkList L)
{
	LinkList Link_Clear;
	while (L->next) {
		Link_Clear = L->next;
		L->next = Link_Clear->next;
		free(Link_Clear);
	}
}

int main()
{
	//Init
	LinkList H;
	if (initLinkList1(&H))
		printf("创建成功！\n");
	else
		printf("创建不成功\n");
	LinkList L = initLinkList2();
	//剩下的与顺序表类似。这里就省略了。
	return 0;
}
