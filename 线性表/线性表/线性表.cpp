#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
#define InitSize 10


typedef struct
{
	int data[10];
	int length;
}SqList;

////˳���ľ�̬����

//void InitList(SqList &L)
//{
//	L.length = 0;
//}
//
//int main()
//{
//	SqList L;
//	InitList(L);
//
//	return 0;
//}

////˳���Ķ�̬����

//void InitList(SqList& L)
//{
//	L.data = (int*)malloc(sizeof(int) * InitSize);
//	L.length = 0;
//	L.Max_Size = InitSize;
//}
//
//void IncreaseSize(SqList& L, int add)
//{
//	int* ptr = (int*)realloc(L.data, sizeof(int) * (L.Max_Size + add));
//	if (ptr != NULL)
//	{
//		L.data = ptr;
//		L.Max_Size += add;
//	}
//	else
//		return;
//}
//
//int main()
//{
//	SqList L;
//	InitList(L);
//	IncreaseSize(L, 5);
//
//	return 0;
//}

////˳���Ĳ������
//bool ListInsert(SqList& L, int num, int e)
//{
//	if (num<1 || num>L.length + 1)
//		return false;
//	if (L.length == 10)
//		return false;
//	int i = 0;
//	for (i = L.length; i >= num; i--)
//	{
//		L.data[i] = L.data[i - 1];
//	}
//	L.data[num - 1] = e;
//	L.length++;
//	return true;
//}
//
//int main()
//{
//	SqList L;
//	L.length = 0;
//	//int num;
//	//int ele;
//	ListInsert(L, 3, 3);
//
//	return 0;
//}

////˳����ɾ������
//bool ListDel(SqList& L, int num, int& e)
//{
//	if (num<1 || num>L.length || L.length == 0)
//		return false;
//	e = L.data[num - 1];
//	int i = 0;
//	for (i = num; i < L.length; i++)
//	{
//		L.data[i - 1] = L.data[i];
//	}
//	L.length--;
//	return true;
//}
//
//int main()
//{
//	SqList L;
//	L.length = 0;
//	//......����Ԫ��
//	int e = 0;
//	ListDel(L, 3, e);
//
//	return 0;
//}˳����ɾ��

////˳���İ�λ����ֵ����
//
//int FindBySite(SqList L, int s)
//{
//	return L.data[s - 1];
//}
//int FindByValu(SqList L, int e)
//{
//	int i = 0;
//	for (i = 0; i < L.length; i++)
//	{
//		if (L.data[i] == e)
//			return i + 1;
//	}
//}
//
//int main()
//{
//	SqList L;
//	int sit = 0;
//	int e = 0;
//	FindBySite(L, 1);
//	FindByValu(L, 0);
//
//	return 0;
//}


typedef struct node
{
	int data;
	struct node* next;
}node, * LinkList;
////�������ʼ��
//
//void InitList(LinkList* L)
//{
//	*L = (node*)malloc(sizeof(node));//����ͷ���
//	(*L)->next = NULL;//���óɿձ�
//}
//
//int main()
//{
//	LinkList L;//����һ��ָ�������ָ��
//	InitList(&L);
//
//	return 0;
//}

//������Ĳ������
//void InsertNode(LinkList L, int i, int e)
//{
//	if (i < 1)
//		return;
//	node* p = L;//ָ��ͷ���
//	node* s;
//	int j = 0;//��ʾ��ǰp����λ��
//	while (p->next != NULL && j < i - 1)//ѭ���ҵ���i-1�����
//	{ 
//		p = p->next;
//		j++;
//	}
//	if (p == NULL)
//		return;
//	s = (node*)malloc(sizeof(node));
//	s->next = p->next;
//	p->next = s;
//	s->data = e;
//}
//
//int main()
//{
//	LinkList L;
//	InitList(&L);
//	InsertNode(&L, 2, 2);
//
//	return 0;
//}

////�������ɾ������
//int DelNode(LinkList L, int i, int* e)
//{
//	node* p, * q;
//	p = L;
//	int j = 0;
//	while (p != NULL && j < i - 1)
//	{
//		p = p->next;
//		j++;
//	}
//	if (p->next == NULL)
//		return -1;
//
//	q = p->next;//��qָ���i����㣨Ҫɾ���Ľ�㣩
//	*e = q->data;
//	p->next = q->next;
//	free(q);
//	return 0;
//}
//
//int main()
//{
//	LinkList L;
//	InitList(&L);
//	int e = 0;
//	DelNode(L, 2, &e);
//
//	return 0;
//}
//
////������İ�ֵ����λ����,���
//int Length(LinkList L)
//{
//	int i = 0;
//	node* p = L->next;
//	while (p != NULL)
//	{
//		p = p->next;
//		i++;
//	}
//	return i;
//}
//
//node* FindBySit(LinkList L, int i)
//{
//	if (i < 0)
//		return NULL;
//	node* p = L;
//	int j = 0;//��¼��ǰpָ����ǵڼ������
//	while (p != NULL && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	return p;
//}
//
//node* FindByVal(LinkList L, int e)
//{
//	node* p = L->next;
//	while (p!= NULL && p->data != e)
//	{
//		p = p->next;
//		break;
//	}
//	return p;
//}
//
//
//int main()
//{
//	LinkList L;
//	InitList(&L);
//	FindBySit(L, 2);
//	FindByVal(L, 2);
//	Length(L);
//
//	return 0;
//}

////ͷ�巨��β�巨����������
//LinkList CreatFromHead(LinkList& L)
//{
//	int e;
//	node* s;
//	L = (node*)malloc(sizeof(node));
//	L->next = NULL;
//	scanf("%d", &e);
//	while (e != 9999)
//	{
//		s = (node*)malloc(sizeof(node));
//		s->data = e;
//		s->next = L->next;
//		L->next = s;
//		scanf("%d", &e);
//	}
//	return L;
//}
//
//LinkList CreatFromTail(LinkList& L)
//{
//	int e;
//	node* s, * r = L;
//	scanf("%d", &e);
//	while (e != 9999)
//	{
//		s = (node*)malloc(sizeof(node));
//		s->data = e;
//		r->next = s;
//		r = s;
//		scanf("%d", &e);
//	}
//	r->next = NULL;
//	return L;
//}
//
//int main()
//{
//	LinkList L;
//	CreatFromHead(L);
//	CreatFromTail(L);
//
//	return 0;
//}

typedef struct Dnode
{
	int data;
	struct Dnode* next, * prior;
}Dnode, * DoubleList;

////˫����Ķ���ͳ�ʼ��

//void InitDoubleList(DoubleList* L)
//{
//	*L = (Dnode*)malloc(sizeof(Dnode));
//	(*L)->prior = NULL;
//	(*L)->next = NULL;
//}
//
//int main()
//{
//	DoubleList L;
//	InitDoubleList(&L);
//
//	return 0;
//}

////˫�����ǰ�壬��壬ɾ������
//
//int InsertPriNode(DoubleList L, int i, int e)
//{
//	Dnode* p = L;
//	int j = 0;
//	while (p != NULL && i < j)//ѭ���ҵ���i�����
//	{
//		p = p->next;
//		j++;
//	}
//	//��p������ǰ�������Ҳ�����ҵ���i-1�������к�����
//	Dnode* s = (Dnode*)malloc(sizeof(Dnode));
//	s->data = e;
//	s->prior = p->prior;
//	p->prior->next = s;
//	p->prior = s;
//	s->next = p;
//}
//
//int InsertNextNode(DoubleList L, int i, int e)
//{
//	//��ѭ���ҵ���i�����
//	Dnode* p = L;
//	int j = 0;
//	while (p != NULL && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	Dnode* s = (Dnode*)malloc(sizeof(Dnode));
//	s->next = p->next;
//	if (p->next != NULL)
//	{
//		p->next->prior = s;
//	}
//	p->next = s;
//	s->prior = p;
//}
//
//int DeleteDnode(DoubleList L, int i, int* e)
//{
//	//ѭ���ҵ���i�����
//	Dnode* p = L;
//	int j = 0;
//	while (p != NULL && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	*e = p->data;
//	p->prior->next = p->next;
//	if (p->next != NULL)
//	{
//		p->next->prior = p->prior;
//	}
//	free(p);
//}
//
//int main()
//{
//	DoubleList L;
//	int e;
//	InsertPriNode(L, 2, 2);//˫�����ǰ�����
//	InsertNextNode(L, 2, 2);//˫����ĺ�����
//	DeleteDnode(L, 2, &e);//˫�����ɾ������
//	return 0;
//}

////ѭ��������˫����ĳ�ʼ��
//
//void InitCirLinkList(LinkList* L)
//{
//	*L = (node*)malloc(sizeof(node));
//	(*L)->next = *L;
//}
//void InitCirDoubleList(DoubleList* DL)
//{
//	*DL = (Dnode*)malloc(sizeof(Dnode));
//	(*DL)->prior = *DL;
//	(*DL)->next = *DL;
//}
//
//int main()
//{
//	LinkList L;
//	DoubleList DL;
//	InitCirLinkList(&L);
//	InitCirDoubleList(&DL);
//	return 0;
//}

//��̬����ĳ�ʼ��
typedef struct
{
	int data;
	int next;
}SLinkList[10];

struct Node
{
	int data;
	int next;
};
int main()
{
	SLinkList a;
	struct Node b;
	struct Node c[10];
	printf("%d\n", sizeof(b));
	printf("%d\n", sizeof(c));
	printf("%d\n", sizeof(a));

	return 0;
}