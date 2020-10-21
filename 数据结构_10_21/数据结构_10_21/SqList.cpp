#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int Elemtype;

Status visit(Elemtype c)
{
	printf("%d ", c);
	return OK;
}

typedef struct SqList
{
	Elemtype data[MAXSIZE];
	int length;
}SqList;

Status ListInit(SqList* L)
{
	L->length = 0;
	return OK;
}

Status ListEmpty(const SqList* L)
{
	if (L->length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList* L)
{
	L->length = 0;
	return OK;
}

int ListLength(const SqList* L)
{
	return L->length;
}

Status GetElem(const SqList* L, int i, Elemtype* e)
{
	if (L->length == 0 || i<1 || i>L->length)
	{
		return ERROR;
	}
	*e = L->data[i - 1];
	return OK;
}

int LocateElem(SqList* L, Elemtype e)
{
	int i;
	if (L->length == 0)
	{
		return 0;
	}
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
			break;
	}
	if (i >=L -> length)
		return 0;
	return i + 1;
}

Status ListInsert(SqList* L, int i, Elemtype e)
{
	int k;
	if (L->length == MAXSIZE)
	{
		return ERROR;
	}
	if (i<1 || i>L->length + 1)
	{
		return ERROR;
	}
	if (i <= L->length)
	{
		for (k = L->length - 1; k >= i - 1; k--)
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList* L, int i, Elemtype* e)
{
	int k = 0;
	if (L->length == 0)
	{
		return ERROR;
	}
	if (i<1 || i>L->length)
	{
		return ERROR;
	}
	*e = L->data[i - 1];
	if (i < L->length)
	{
		for (k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}

Status ListDis(const SqList* L)
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		visit(L->data[i]);
	}
	printf("\n");
	return OK;
}

void unionL(SqList* La,const SqList* Lb)
{
	int La_len, Lb_len,i;
	Elemtype e;
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	for (i = 1; i < Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if(!LocateElem(La,e))
			ListInsert(La, ++La_len, e);
	}
}

int main()
{
	SqList L, Lb;
	Elemtype e;
	Status i;
	int j, k;
	i = ListInit(&L);
	printf("初始化L后:L.length=%d\n", L.length);
	for (j = 1; j <= 5; j++)
	{
		i = ListInsert(&L, 1, j);
	}
	printf("在L的表头依次插入1~5后：L.data=");
	ListDis(&L);

	return 0;
}