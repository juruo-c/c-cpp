#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000

typedef int Status;
typedef int Elemtype;

Status visit(Elemtype c)
{
	printf("%d ", c);
	return OK;
}

typedef struct
{
	Elemtype data;
	int cur;
}Component,StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

int Malloc_SSL(StaticLinkList space)
{
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

void Free_SSL(StaticLinkList space,int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

int ListLength(StaticLinkList space)
{
	int j = 0;
	int i = space[MAXSIZE - 1].cur;
	while (i)
	{
		i = space[i].cur;
		j++;
	}
	return j;
}

Status ListInsert(StaticLinkList L, int i, Elemtype e)
{
	int j, k, l;
	k = MAXSIZE - 1;
	if (i<1 || i>ListLength(L) + 1)
	{
		return ERROR;
	}
	j = Malloc_SSL(L);
	if (j)
	{
		L[j].data = e;
		for (l = 1; l < i - 1; l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
}

Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i<1 || i>ListLength(L))
	{
		return	ERROR;
	}
	k = MAXSIZE - 1;
	for (j = 1; j < i - 1; j++)
	{
		k = L[k].cur;
	}
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;
}

Status ListDis(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		visit(L[i].data);
		i = L[i].cur;
		j++;
	}
	return j;
	printf("\n");
	return 0;
}