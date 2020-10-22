#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1 
#define FALSE 0
typedef int Status;
typedef int Elemtype;

Status visit(Elemtype c)
{
	printf("%d ", c);
	return OK;
}

typedef struct Node
{
	Elemtype data;
	struct Node* next;
}Node,*LinkList;

Status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (!(*L))
		return ERROR;
	(*L)->next = NULL;
	return OK;
}

Status ListEmpty(LinkList L)
{
	if (L->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

Status ClearList(LinkList* L)
{
	LinkList p, q;
	p = *L;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, Elemtype* e)
{
	int j=1;
	LinkList p;
	p = L;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

int LocateElem(LinkList L, Elemtype e)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e)
			return i;
		p = p->next;
		
	}
	return 0;
}

Status ListInsert(LinkList* L, int i, Elemtype e)
{
	int j=1;
	LinkList p, s;
	p = *L;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
	
}

Status ListDelete(LinkList* L, int i, Elemtype* e)
{
	int j=1;
	LinkList p, q;
	p = *L;
	while (p->next&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) && j > i)
	{
		return ERROR;
	}
	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return OK;
}

Status ListDis(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;
	srand((unsigned int)time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->next = (*L)->next;
		p->data = rand() % 100 + 1;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand((unsigned int)time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int main()
{
	LinkList L;
	Elemtype e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("��ʼ��L��ListLength(L)=%d\n", ListLength(L));
	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ���β���1��5��L.data=");
	ListDis(L);

	printf("ListLength(L)=%d \n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	i = ClearList(&L);
	printf("���L��ListLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);
	printf("��L�ı�β���β���1��10��L.data=");
	ListDis(L);

	printf("ListLength(L)=%d \n", ListLength(L));

	ListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��L.data=");
	ListTraverse(L);
	printf("ListLength(L)=%d \n", ListLength(L));

	GetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}


	k = ListLength(L); /* kΪ�� */
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(&L, j, &e); /* ɾ����j������ */
		if (i == ERROR)
			printf("ɾ����%d������ʧ��\n", j);
		else
			printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
	}
	printf("�������L��Ԫ�أ�");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e); /* ɾ����5������ */
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);

	printf("�������L��Ԫ�أ�");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\n���L��ListLength(L)=%d\n", ListLength(L));
	CreateListHead(&L, 20);
	printf("���崴��L��Ԫ��(ͷ�巨)��");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\nɾ��L��ListLength(L)=%d\n", ListLength(L));
	CreateListTail(&L, 20);
	printf("���崴��L��Ԫ��(β�巨)��");
	ListTraverse(L);
	
	return 0;
}