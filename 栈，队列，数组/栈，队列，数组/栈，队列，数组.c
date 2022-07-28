#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 10

#if 0
typedef struct
{
	int data[MaxSize];
	int top;
}SqStack;

typedef struct
{
	int data[MaxSize];
	int top0;
	int top1;
}ShareStack;

//初始化一个栈
void InitStack(SqStack* S)
{
	S->top = -1;
}
//初始化一个共享栈
void InitShareStack(ShareStack* s)
{
	s->top0 = -1;
	s->top1 = MaxSize;
}

//顺序栈进栈操作
int Push(SqStack* S, int e)
{
	if (S->top == MaxSize - 1)//判断栈是否已满
		return 1;
	S->top++;//若未满，修改栈顶指针
	S->data[S->top] = e;//元素e进栈
	return 0;
}

//顺序栈出栈操作
int pop(SqStack* S, int* e)
{
	if (S->top == -1)//判断是否为空栈
		return 1;
	*e = S->data[S->top];//若不是，栈顶元素赋给e
	S->top--;//修改栈顶指针
}

//读取栈顶元素
int GetTop(SqStack* S, int* e)
{
	if (S->top == -1)
		return 1;
	*e = S->data[S->top];
}


int main()
{
	int e = 0;
	SqStack S;
	ShareStack s;
	InitStack(&S);
	Push(&S, 2);
	Pop(&S, &e);
	GetTop(&S, &e);

	return 0;

}
#endif

//共享栈
#if 0
int Push_s0(ShareStack* s, int i,int e)//0号栈压栈
{
	if (s->top0 + 1 == s->top1)
		return 1;
	s->top0++;
	s->data[s->top0] = e;
	return 0;
}

int Push_s1(ShareStack* s, int i, int e)//1号栈压栈
{
	if (s->top0 + 1 == s->top1)
		return 1;
	s->top1--;
	s->data[s->top1] = e;
	return 0;
}

int Pop_s0(ShareStack* s, int i, int* e)//0号栈出栈
{
	if (s->top0 == -1)
		return 1;
	*e = s->data[s->top0];
	s->top0--;
	return 0;
}

int Pop_s1(ShareStack* s, int i, int* e)//1号栈出栈
{
	if (s->top1 == MaxSize)
		return 1;
	*e = s->data[s->top1];
	s->top1++;
	return 0;
}

int main()
{
	ShareStack s;
	int e;
	Push_s0(&s, 2, 2);
	Push_s1(&s, 2, 2);
	Pop_s1(&s, 2, e);
	Pop_s2(&s, 2, e);

	return 0;
}

#endif

//队列

#if 0

//顺序队列
typedef struct//定义一个顺序队列
{
	int data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue* Q)//顺序队列的初始化
{
	Q->front = Q->rear = 0;
}

int EnterQueue(SqQueue* Q, int e)//顺序队列入队操作
{
	if ((Q->rear + 1) % MaxSize == Q->front)//判断队列是否已满
		return 1;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MaxSize;//重新设置队尾指针
	return 0;
}

int DeleteQueue(SqQueue* Q, int* e)//顺序队列出队操作
{
	if (Q->front == Q->rear)//判断队列是否为空
		return 1;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;//重新设置队头指针
	return 0;
}

int main()
{
	SqQueue Q;//声明一个队列
	int e;
	InitQueue(&Q);
	EnterQueue(&Q, e);
	DeleteQueue(&Q, e);


	return 0;
}

#endif

//链队列

typedef struct LinkNode//链队列结点的定义
{
	int data;
	struct LinkNode* next;
}node;

typedef struct//链队列的定义
{
	node* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (node*)malloc(sizeof(node));
	Q->front->next = NULL;
}

int EnterQueue(LinkQueue* Q, int e)//链队列入队操作
{
	node* p = (node*)malloc(sizeof(node));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return 0;
}

int DeQueue(LinkQueue* Q, int* e)
{
	if (Q->front == Q->rear)
		return 1;
	node* p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (p == Q->rear)
		Q->rear = Q->front;
	free(p);
	return 0;

}

int main()
{
	LinkQueue Q;
	int e;
	InitQueue(&Q);
	EnterQueue(&Q, 2);
	DeleQueue(&Q, e);

	return 0;
}
