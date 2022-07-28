#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#if 0
//������
typedef struct
{
	int data;
	struct node* lchild, * rchild;
}node,*bitree;


int main()
{

	bitree root = NULL;//����һ�ÿ���
	root = (node*)malloc(sizeof(node));//������ڵ�
	root->data = 1;
	root->lchild = NULL;
	root->rchild = NULL;

	return 0;
}
#endif

#if 0
//����������


typedef struct
{
	char data;
	struct node* lchild, * rchild;
	int ltag, rtag; //����������־
}node, * ThreadTree;


//���������������Ľ��������ʣ���������������ĸ��죩
node* pre = NULL;

void CreatInThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		InThread(T);
		if (T->rchild == NULL)
			T->rtag = 1;
	}
}

void InThread(ThreadTree T)
{
	InThread(T->lchild);
	visit(T);
	InThread(T->rchild);
}

void visit(node* p)
{
	if (p->lchild == NULL)
	{
		p->lchild = pre;
		p->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = p;
		pre->rtag = 1;
	}
	pre = p;
}

#endif

//����˫�ױ�ʾ���Ĵ洢�ṹ

typedef struct//���Ľ�㶨��
{
	int data;
	int parent;//αָ�룬��ʾ˫��
}Pnode;

typedef struct
{
	Pnode ndoes[100];//˫�ױ�ʾ
	int n;//�������
};


//�����������Ĳ���

typedef struct
{
	char data;
	struct node* lchild, * rchild;
}node, * BSTree;

node* FindNode(BSTree T, int k)
{
	while (T != NULL && k != T->data)
	{
		if (T->data > k)
			T = T->rchild;
		else
			T = T->lchild;
	}
	return T;
}