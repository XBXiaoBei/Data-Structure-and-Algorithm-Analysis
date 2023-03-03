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

typedef struct dnode
{
	ElemType data;
	struct dnode* next;
	struct dnode* pre;
}DNode, * DLinkList;

int initDLinkList(DLinkList* L)
{
	*L = (DLinkList)malloc(sizeof(DNode));
	if (*L == NULL)
		return 0;
	(*L)->pre = (*L);
	(*L)->next = *L;
	return 1;
}

int insertDLinkList(DLinkList L, int i, ElemType Elem_Insert)
{
	DLinkList DLink_Insert, DLink_Primary = L;
	int site = 0;
	if (i < 1) {
		printf("����λ��Խ�½磬����ʧ�ܣ�\n");
		return 0;
	}
	while (DLink_Primary->next != L && site < i - 1) {
		DLink_Primary = DLink_Primary->next;
		site++;
	}
	if (DLink_Primary->next == L && site < i - 1) {
		printf("����λ��Խ�Ͻ磬����ʧ�ܣ�\n");
		return 0;
	}
	if (!initDLinkList(&DLink_Insert))
		return 0;
	DLink_Insert->data = Elem_Insert;
	DLink_Insert->next = DLink_Primary->next;
	DLink_Insert->pre = DLink_Primary;
	DLink_Primary->next->pre = DLink_Insert;
	DLink_Primary->next = DLink_Insert;
	return 1;
}

int deleteDLinkList(DLinkList L, int i, ElemType* Elem_Delete)
{
	DLinkList DLink_Delete, DLink_Primary = L;
	int site = 0;
	if (L->next == L) {
		printf("����Ϊ�գ�ɾ��ʧ�ܣ�\n");
		return 0;
	}
	if (i < 1) {
		printf("ɾ��λ��Խ�½磬����ʧ�ܣ�\n");
		return 0;
	}
	while (DLink_Primary->next != L && site < i - 1) {
		DLink_Primary = DLink_Primary->next;
		site++;
	}
	if (DLink_Primary->next == L) {
		printf("ɾ��λ��Խ�Ͻ磬����ʧ�ܣ�\n");
		return 0;
	}
	DLink_Delete = DLink_Primary->next;
	DLink_Primary->next = DLink_Delete->next;
	DLink_Primary->next->pre = DLink_Primary;
	*Elem_Delete = DLink_Delete->data;
	free(DLink_Delete);
	return 1;
}

void dispDLinkList(DLinkList L, int i)
{
	if (L->next == L) {
		printf("����û�����ݣ�\n");
		return;
	}
	DLinkList DLink_Disp = L;
	if (i == 1) {
		DLink_Disp = DLink_Disp->next;
		while (DLink_Disp != L) {
			printf("%s, %f\n", DLink_Disp->data.name, DLink_Disp->data.score);
			DLink_Disp->next = DLink_Disp;
		}
	}
	if (i == 2) {
		DLink_Disp = DLink_Disp->pre;
		while (DLink_Disp != L) {
			DLink_Disp = DLink_Disp->pre;
			printf("%s, %f\n", DLink_Disp->data.name, DLink_Disp->data.score);
			DLink_Disp->pre = DLink_Disp;
		}
	}
}

//����Ĳ����뵥���������ƣ��ٴβ�������׸����

int main()
{
	//Init
	DLinkList H;
	if (initDLinkList(&H))
		printf("�����ɹ���\n");
	else
		printf("�������ɹ�\n");
	//ʣ�µ���˳������ơ������ʡ���ˡ�
	return 0;
}