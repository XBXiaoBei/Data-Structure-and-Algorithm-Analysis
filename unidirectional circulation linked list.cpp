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
	(*L)->next = *L;
	return 1;
}

LinkList initLinkList2()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL)
		return NULL;
	L->next = L;
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
	while (Link_Primary->next != L && site < i - 1) {
		Link_Primary = Link_Primary->next;
		site++;
	}
	if (Link_Primary->next == L && site < i - 1) {
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
	if (L->next == L) {
		printf("链表为空，删除失败！\n");
		return 0;
	}
	if (i < 1) {
		printf("删除位置越下界，插入失败！\n");
		return 0;
	}
	while (Link_Primary->next != L && site < i - 1) {
		Link_Primary = Link_Primary->next;
		site++;
	}
	if (Link_Primary->next == L) {
		printf("删除位置越上界，插入失败！\n");
		return 0;
	}
	Link_Delete = Link_Primary->next;
	Link_Primary->next = Link_Delete->next;
	*Elem_Delete = Link_Delete->data;
	return 1;
}

//后面的操作与单向链表类似，再次不做过多赘述；

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