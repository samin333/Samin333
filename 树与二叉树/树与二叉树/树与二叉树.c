#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#if 0
//二叉树
typedef struct
{
	int data;
	struct node* lchild, * rchild;
}node,*bitree;


int main()
{

	bitree root = NULL;//定义一棵空树
	root = (node*)malloc(sizeof(node));//插入根节点
	root->data = 1;
	root->lchild = NULL;
	root->rchild = NULL;

	return 0;
}
#endif

#if 0
//线索二叉树


typedef struct
{
	char data;
	struct node* lchild, * rchild;
	int ltag, rtag; //左右线索标志
}node, * ThreadTree;


//中序线索二叉树的建立（本质：中序遍历二叉树的改造）
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

//树的双亲表示法的存储结构

typedef struct//树的结点定义
{
	int data;
	int parent;//伪指针，表示双亲
}Pnode;

typedef struct
{
	Pnode ndoes[100];//双亲表示
	int n;//结点数量
};


//二叉排序树的查找

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