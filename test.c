#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<assert.h>#include<errno.h>

//��̬�ڴ濪�ټ�������ı�����

//1.
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test()
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");//�������
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//����1
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test()
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//����2
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test()
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//2.
//char* GetMemory()
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test()
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//3.
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, 100);
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//4.
//void Test()
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str)
//	{
//		strcpy(str, "world");//�Ƿ������ڴ�
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//��̬�ڴ����������

//int main()
//{
//	//1.��NULLָ������ò���
//	int *p = malloc(40);
//	*p = 10;//malloc���ٿռ�ʧ��-��NULL������
//
//	//2.�Զ�̬�����ڴ��Խ�����
//	int * p = (int *)malloc(40);
//	if (!p)
//	{
//		return 0;
//	}
//	int i = 0;
//	//Խ��
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	//3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//	int a = 10;
//	int *p = &a;
//	free(p);
//	p = NULL;
//
//	//4.ʹ��free�ͷŶ�̬�����ڴ��һ����
//	int * p = (int *)malloc(40);
//	if (!p)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*p++ = i;
//	}
//	//���տռ䣨��ʱp�ѷ����仯��
//	free(p);
//	p = NULL;
//
//	//5.��ͬһ�鶯̬�ڴ�Ķ���ͷ�
//	int * p = (int*)malloc(40);
//	if (!p)
//	{
//		return 0;
//	}
//	//...
//	free(p);
//	//(���������p = NULL;
//	//...
//	free(p);
//
//	//6.��̬�����ڴ������ͷţ��ڴ�й©��
//	while (1)
//	{
//		malloc(1);
//		Sleep(1000);
//
//	}
//	return 0;
//}

//int main()
//{
//	int* p = (int*)malloc(10*sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("����ɹ�\n");
//	}
//	return 0;
//}


//������

//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node,*LinkList;
//void CreateListHead(LinkList *L, int n)
//{
//	LinkList p;
//	int i;
//	srand(time(0));
//	*L = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = rand() % 100 + 1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//}
//void CreateListTail(LinkList* L, int n)
//{
//	LinkList p, r;
//	int i;
//	srand(time(0));
//	*L = (LinkList)malloc(sizeof(Node));
//	r = *L;
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = rand() % 100 + 1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}
//#define MAXSIZE 1000
//typedef struct
//{
//	int data[MAXSIZE];
//	int length;
//}Sqlist;
//
//
//int main()
//{
//
//	return 0;
//}

//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest&&src);
//	void* ret = dest;
//
//	if (dest < src)
//	{
//		//��ǰ���
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		//�Ӻ���ǰ
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	assert(dest&&src);
//	void* ret = dest;
//	while(count--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//int main()
//{
//	
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr+2, arr, 20);
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	char a[] = "I Have a DOg";
//	int sz = sizeof(a) / sizeof(a[0]);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		if (isupper(a[i]))
//		{
//			a[i] = tolower(a[i]);
//		}
//	}
//	printf("%s\n", a);
//	return 0;
//
//}

//strerror

//#include<errno.h>
//int main()
//{
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file success");
//	}
//	return 0;
//}

//strtok

//int main()
//{
//	char arr[] = "192.168.31.121";
//	char* p = ".";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//ϣ������

//void insertsort(int arr[], int gap, int i)
//{
//	int key = arr[i];
//	int j;
//	for (j = i - gap; j >= 0 && key < arr[j]; j -= gap)
//	{
//		arr[j + gap] = arr[j];
//	}
//	arr[j + gap] = key;
//}
//void shellsort(int arr[], int sz)
//{
//	for (int gap = sz / 2; gap > 0; gap /= 2)
//	{
//		for (int i = gap; i < sz; i++)
//		{
//			insertsort(arr, gap, i);
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	shellsort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//��������

//void insertsort(int arr[], int sz)
//{
//	int i = 1;
//	for (i = 1; i < sz; i++)
//	{
//		int key = arr[i];
//
//		int j = i - 1;
//		while ((j>=0)&&(arr[j] > key))
//		{
//			arr[j + 1] = arr[j];
//			j--;
//		}
//		arr[j + 1] = key;
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	insertsort(arr, sz);
//	int i = 0;
//	for(i=0;i<sz;i++)
//	printf("%d ", arr[i]);
//	return 0;
//}

//ѡ������

//void elect_sort(int a[],int sz)
//{
//	int i, j,k;
//	for (i = 0; i < sz - 1; i++)
//	{
//		j = i + 1;
//		k = i;
//		int min = a[i];
//		for (j = i + 1; j < sz; j++)
//		{
//			if (a[j] < min)
//			{
//				min = a[j];
//				k = j;
//			}
//		}
//		if (k!=i)
//		{
//			int tmp = a[i];
//			a[i] = a[k];
//			a[k] = tmp;
//		}
//	}
//}
//int main()
//{
//	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	elect_sort(a, sz);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}

//

//void Swap(char* e1,char*e2,int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *e1;
//		*e1 = *e2;
//		*e2 = tmp;
//		e1++;
//		e2++;
//	}
//}
//void bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void*e2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1)*width))
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
//			}
//		}
//	}
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	return *((int*)e1)-*((int*)e2);
//}
//int main()
//{
//	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz=sizeof(a)/sizeof(a[0]);
//	bubble_sort(a,sz,sizeof(a[0]),cmp_int);
//	return 0;
//}

//int cmp(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//int main()
//{
//	int a[3] = { 0 };
//	int i = 0;
//	for(i=0;i<3;i++)
//		scanf("%d", &a[i]);
//	int sz = sizeof(a) / sizeof(a[0]);
//
//	qsort(a, sz, sizeof(a[0]), cmp);
//	for (i = 0; i < 3; i++)
//		printf("%d ", a[i]);
//}

//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void test1()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int cmp_f(const void* e1, const void* e2)
//{
//	return ((int)(*(float*)e1 - *(float*)e2));
//}
//void test2()
//{
//	float f[] = { 9.0,8.0,7.0,6.0,5.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]),cmp_f);
//	int i = 0;
//	for(i=0;i<sz;i++)
//	{
//		printf("%f ", f[i]);
//	}
//}
//struct student
//{
//	char name[20];
//	int age;
//};
//int cmp_stu_age(const void* e1, const void* e2)
//{
//	return ((struct student*)e1)->age - ((struct student*)e2)->age;
//}
//int cmp_stu_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct student*)e1)->age, ((struct student*)e1)->name);
//}
//void test3()
//{
//	struct student s[3] = { {"zhangsan",20 }, {"lisi",14}, {"wangwu",12 } };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_age);
//	int i = 0; 
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", s[i].age);
//	}
//
//
//}
//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}


//������������ָ�������Ӧ�ã�

//void menu()
//{
//	printf("************************\n");
//	printf("**    1.Add  2.Sub    **\n");
//	printf("**    3.Mul  4.Div    **\n");
//	printf("****     0.exit     ****\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int(*pfarr[5])(int, int) = { 0 ,Add,Sub,Mul,Div};
//	do
//	{
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("������������:>");
//			scanf("%d%d", &x, &y);
//			int ret = pfarr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		  
//		}
//	} while (input);
//}

//�ж��ֽ���

//
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//int main()
//{
//	//����1��С��
//	//����0�����
//	int ret=check_sys();
//	if (ret == 1)
//		printf("С��");
//	else
//		printf("���");
//	return 0;
//}

//����assert

////10��
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(src != NULL);
//	assert(dest != NULL);//����
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "###################";
//	char arr2[] = "bit";
//	
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}

////9��
//#include<assert.h>
//void my_strcpy(char* dest,const char* src)
//{
//	assert(src != NULL);
//	assert(dest != NULL);//����
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[] = "###################";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

////8��
//#include<assert.h>
//void my_strcpy(char* dest, char* src)
//{
//	assert(src != NULL);
//	assert(dest!=NULL);//����
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[] = "###################";
//	char arr2[] = "bit";
//	my_strcpy(arr1,arr2);
//	printf("%s\n", arr1);
//	return 0;
//
//}

//�ṹ��

//struct stu
//{
//	char name[20];
//	short age;
//	char tele[20];
//}s1,s2,s3;//s1��s2��s3������ȫ�ֵĽṹ�����
//typedef struct stu
//{
//	char name[20];
//	short age;
//	char tele[20];
//}Stu;//Stu���Զ�������

//���������������1�ĸ���(�Ż��㷨������

//int count_bit_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", a);
//	int count = count_bit_one(a);
//	printf("%d\n", count);
//	return 0;
//}

//���鵹��

//void Reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Reverse(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

//��λȡ��

//int main()
//{
//	int a = 11;
//	a = a | (1 << 2);
//	printf("%d\n",a);
//	a = a & (~(1 << 2));
//	printf("%d\n", a);
//	/*int a = 0;
//	printf("%d", ~a);
//	return 0;*/
//}

//��Ŀ

//int main()
//{
//	int a = 10;
//	short s = 0;
//	printf("%d\n", sizeof(s = a + 5));
//	printf("%d\n", s);
//	return 0;
//
//}

//����ĳ�����Ķ�������ʽ�е�1�ĸ���

//int main()
//{
//	int num = 0;
//	int count = 0;
//	scanf("%d", &num);
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((num >> i) & 1) == 1)
//			count++;
//	}
//	/*while (num)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//			num = num / 2;
//		}
//	}*/
//	printf("%d\n", count);
//	return 0;
//}

//��������ʱ������������(����������

//int main()
//{
//	//1.�Ӽ���--���ܻ����
//	int a = 3;
//	int b = 5;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	//2.���
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	return 0;
//}

//�����ַ(&arrȡ��������������ĵ�ַ)

//int main()
//{
//	int arr[] = { 1,3,4,5,6,7,8 };
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//	return 0;
//
//}

//ð������

//void bubble_sort(int arr[], int sz)
//{
//	//ȷ��ð�����������
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag=1;//������һ��Ҫ����������Ѿ�����
//		
//		//ÿһ�˵�ð������
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//��ά����Ĵ洢(Ҳ�������ģ��ڶ��н����ڵ�һ�к��棩

//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] =%p\n", i,j,&arr[i][j]);
//		}
//	}
//	return 0;
//}

//��ά����

//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };//�������� 
//	char arr1[4][5];
//	int arr2[][4] = { {1,2,3,4},{5,6,7,8} };
//
//	return 0;
//}

//һά�����ڵ�Ԫ�����ڴ���������ţ�ÿ������Ԫ��ռ���ĸ��ֽڣ���ÿ�����ڵ�ַ���4

//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//	}
//}

//����(sizeof��strlen)

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr1));
//	printf("%d\n", sizeof(arr2));
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//}

//��ŵ������

//int count;
//void move(int n, char from, char to)
//{
//	printf("��%d������%d�����Ӵ�%c����%c\n", count++, n, from, to);
//}
//void Hanio(int n, char start_, char tran_, char end_)
//{
//	if (n == 1)
//	{
//		move(n, start_,end_);
//	}
//	else
//	{
//		Hanio(n - 1, start_, end_, tran_);//��n-1�������Ƶ���������
//		move(n, start_, end_);            //�����µĴ������Ƶ�Ŀ������
//		Hanio(n - 1, tran_, start_, end_);//����ʼ����Ϊ�������������ڹ������ϵ�n-1������
//	}
//}
//
//int main()
//{
//	int n;
//	while ((scanf("%d",&n))==1&&n)
//	{
//		count = 1;
//		Hanio(n,'1','2','3');
//		printf("�ܲ���Ϊ��%d\n", count-1 );
//	}
//	return 0;
//}

//�����ݹ飨�򵥣�

//���n��쳲�������
//int Fib1(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib1(n - 1) + Fib1(n - 2);
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fib1(n);
//	printf("%d\n", ret);
//	return 0;
//}
//������n��쳲�������
//int Fib2(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fib2(n);
//	printf("%d\n", ret);
//	return 0;
//}

//int fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret=fac(n);
//	printf("%d\n", ret);
//	return 0;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int sum = 1;
//	int i;
//	for (i = 2; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str+1);
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "abvc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	print(num);
//}

//��ʽ����

//int main()
//{
//	printf("%d\n", printf("%d", printf("%d", 43)));
//	return 0;
//}

//int main()
//{
//	printf("%d\n", strlen("abc"));
//	return 0;
//}

//��ϰ

//void Add(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("num=%d\n", num);
//	Add(&num);
//	printf("num=%d\n", num); 
//	Add(&num);
//	printf("num=%d\n", num);
//	return 0;
//}

//int binary_search(int arr[], int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid+1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	if (left > right)
//		return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret=binary_search(arr, k,sz);
//	if (ret == -1)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	}
//	return 0;
//}

//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (1 == is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//
//	return 0;
//}

//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n%j == 0)
//			return 0;
//	}
//		return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}

//void Tell( int x)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x%i == 0)
//		{
//			break;
//		}
//		
//	}
//	if (i >sqrt(x))
//	{
//		printf("������\n");
//	}
//	else
//	{
//		printf("��������\n");
//	}
//}
//int main()
//{
//	int a = 24;
//	Tell(a);
//	return 0;
//}

//�Զ��庯��

//void Swap(int* pa, int* pd)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa=*pd;
//	*pd=tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a=%d b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}

//void Swap(int x,int y)
////û�з���ֵ�ĺ���
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y= tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a=%d b=%d\n", a, b);
//	Swap(a, b);
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}

//int get_max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max=get_max(a,b);
//	printf("max=%d\n", max);
//	return 0;
//}

//�ػ�����goto��䣩

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("��ע�⣬��ĵ�����1�����ڹػ���������룺������ �Ϳ�ȡ���ػ�\n������:");
//	scanf("%s", &input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");
//		printf("�õ���֪����\n");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//!!��������Ϸ

//void menu()
//{
//	printf("******************************\n");
//	printf("****	1.play   0.exit   ****\n");
//	printf("******************************\n");
//}
//void game()
//{
//	int guess = 0;
//	//1.���������
//	int ret = 0;
//	ret = rand()%100+1;//����1-100֮��������
//	//2.������
//	while (1)
//	{
//		printf("���:");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else
//			break;
//	}
//	if (guess == ret)
//	{
//		printf("��ϲ�㣡�¶��ˣ�\n");
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));//��ʱ�����������������������
////ʱ���   ��ǰ�������ʱ��-���������ʼʱ�䣨1970.1.1 0��0��0��=xxxxx��
//	do
//	{
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("�������\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//�˷��ھ���

//int main()
//{
//	int i = 0;
//	//ȷ����ӡ9��
//	for (i = 1; i <= 9; i++)
//	{
//		//��ӡһ��
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i*j);
//
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��ʮ�����е����ֵ

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 1;
//	int max = arr[0];//��Ҫint max=0������
//	int sz = sizeof(arr)/ sizeof(arr[0]);
//	for (i = 1; i < sz; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	return 0;
//}

//���� 1/1-1/2+1/3-....-1/100

//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

//�ж�i�Ƿ�Ϊ�������Գ�����

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 199; i+=2)
//	{
//		int j = 0;
//		for (j = 2; j <=sqrt(i); j++)//sqrt-��ƽ������ѧ�⺯��
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j> sqrt(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d\n", count);
//	return 0;
//}

//��������Լ��

//int main()
//{
//	int m = 24;
//	int n = 18;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//	while (m%n != 0)
//	{
//		r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//	return 0;
//}

//�ַ����Ƚ����

//int main()
//{
//	int i = 0;
//	char password[6] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("���������룺");
//		scanf("%s", password);
//		if( strcmp(password, "123456")==0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("��¼ʧ��");
//	}
//	return 0;
//}

//ѭ��

//int main()
//{
//	char arr1[] = "welcome to bit!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		left++;
//		right--;
//	}
//	return 0;
//}

//�������㷨  ���ֲ����㷨

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz-1;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���");
//	}
//	return 0;
//}

//����1��+2��+....+10!

//int main()
//{
//	int ch = 1;
//	int n = 0;
//	int sum = 1;
//	int ret = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		sum = n *sum;
//		ret = ret + sum;
//	}
//	printf("%d\n",ret);
//	return 0;
//
//}

//n�Ľ׳� 

//int main()
//{
//	int ch = 1;
//	int n = 0;
//	int sum = 1;
//	scanf("%d", &n);
//	for (ch = 1; ch <= n; ch++)
//	{
//		sum =  ch * sum;
//	}	
//	printf("%d\n", sum);
//
//	return 0;
//
//}

//dowhile

//

//int main()
//{
//	int i = 0;
//	do
//	{
//		i++;
//		printf("%d ", i);
//	} 
//	while (i < 10);
//	return 0;
//
//}


//ѭ���״�

//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)
//		k++;
//	return 0;
//}

//forѭ��

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//		printf("%d\n", i);
//	return 0;
//}

//ѭ���뻺��������

//int main()
//{
//	int ret = 0;
//	int ch = 0;
//	char password[20] = { 0 };
//	printf("����������:>");
//	scanf("%s", password);
//	while ((ch = getchar()) != '\n')
//	{
//		;//��ջ�����
//	}
//		printf("��ȷ��(Y/N):>");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("����ȷ��\n");
//	}
//
//
//	return 0;
//}

//ѭ����������

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;

//��֧switch

//int main()
//{
//	int day=0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("Monday\n");
//		break;
//	case 2:
//		printf("Tuesday\n");
//		break;
//	case 3:
//		printf("Wenesday\n");
//		break;
//	case 4:
//		printf("Thursday\n");
//		break;
//	case 5:
//		printf("Friday\n");
//		break;
//	default:
//		printf("�������\n");
//		break;
//	}
//	return 0;
//
//}

//ѭ����֧��ϰ

//int main()
//{
//	int a = 0;
//	while (a <=100)
//	{
//		a++;
//		if (a % 2 == 1)
//			printf("%d\n", a);
//	}
//		return 0;
//	
//}

//�ṹ�����

//struct People
//{
//	char name[20];
//	int age;
//	char sex[20];
//};
//int main()
//{
//	struct People p1 = { "֣��",19,"��" };
//	printf("�����ǵ�%s\n", p1.name);
//	printf("������%d��\n", p1.age);
//	printf("�����Ǹ�%s��\n", p1.sex);
//	return 0;
//}

//�ṹ�����

//struct Book
//{
//	char name[20];
//	short price;
//};
//int main()
//{
//	struct Book b1 = { "C���Գ������", 55 };
//	printf("������%s\n", b1.name);
//	printf("�۸�%d\n", b1.price);
//
//	return 0;
//
//}

//��ʶָ��

//int main()
//{
//	int a = 2;
//	int* p = &a;
//	printf("%d\n", sizeof(p));
//	//*p = 13;
//	//printf("%p\n", a);
//	return 0;
//}

//ѭ���뺯��

//void test()
//{
//	int a = 1;
//	a++;
//	printf("%d\n",a);
//}
//
//int main()
//{
//	int i = 0;
//
//	while (i < 5)
//	{
//		test();
//		i++;
//	}
//		
//
//
//
//	return 0;
//
//}

//�����ϴ�ֵ

//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int max=0;
//	max = Max(a, b);
//	printf("%d\n",max);
//
//	return 0;
//
//}

//�ַ�������

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c','\0' };
//	printf("%d\n",strlen(arr1));
//	printf("%d\n",strlen(arr2));
//
//	return 0;
//}


//��ʶѭ�����֧

//int main()
//{
//	int line = 0;
//	printf("�������\n");
//	while (line < 10000)
//	{
//		printf("��һ�д���\n");
//		printf("%d\n", line);
//		line++;
//	}
//	if (line >= 10000)
//	     printf("��offer\n");
//	return 0;
//}