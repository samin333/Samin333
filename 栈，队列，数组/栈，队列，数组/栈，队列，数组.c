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

//��ʼ��һ��ջ
void InitStack(SqStack* S)
{
	S->top = -1;
}
//��ʼ��һ������ջ
void InitShareStack(ShareStack* s)
{
	s->top0 = -1;
	s->top1 = MaxSize;
}

//˳��ջ��ջ����
int Push(SqStack* S, int e)
{
	if (S->top == MaxSize - 1)//�ж�ջ�Ƿ�����
		return 1;
	S->top++;//��δ�����޸�ջ��ָ��
	S->data[S->top] = e;//Ԫ��e��ջ
	return 0;
}

//˳��ջ��ջ����
int pop(SqStack* S, int* e)
{
	if (S->top == -1)//�ж��Ƿ�Ϊ��ջ
		return 1;
	*e = S->data[S->top];//�����ǣ�ջ��Ԫ�ظ���e
	S->top--;//�޸�ջ��ָ��
}

//��ȡջ��Ԫ��
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

//����ջ
#if 0
int Push_s0(ShareStack* s, int i,int e)//0��ջѹջ
{
	if (s->top0 + 1 == s->top1)
		return 1;
	s->top0++;
	s->data[s->top0] = e;
	return 0;
}

int Push_s1(ShareStack* s, int i, int e)//1��ջѹջ
{
	if (s->top0 + 1 == s->top1)
		return 1;
	s->top1--;
	s->data[s->top1] = e;
	return 0;
}

int Pop_s0(ShareStack* s, int i, int* e)//0��ջ��ջ
{
	if (s->top0 == -1)
		return 1;
	*e = s->data[s->top0];
	s->top0--;
	return 0;
}

int Pop_s1(ShareStack* s, int i, int* e)//1��ջ��ջ
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

//����

#if 0

//˳�����
typedef struct//����һ��˳�����
{
	int data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue* Q)//˳����еĳ�ʼ��
{
	Q->front = Q->rear = 0;
}

int EnterQueue(SqQueue* Q, int e)//˳�������Ӳ���
{
	if ((Q->rear + 1) % MaxSize == Q->front)//�ж϶����Ƿ�����
		return 1;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MaxSize;//�������ö�βָ��
	return 0;
}

int DeleteQueue(SqQueue* Q, int* e)//˳����г��Ӳ���
{
	if (Q->front == Q->rear)//�ж϶����Ƿ�Ϊ��
		return 1;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;//�������ö�ͷָ��
	return 0;
}

int main()
{
	SqQueue Q;//����һ������
	int e;
	InitQueue(&Q);
	EnterQueue(&Q, e);
	DeleteQueue(&Q, e);


	return 0;
}

#endif

//������

typedef struct LinkNode//�����н��Ķ���
{
	int data;
	struct LinkNode* next;
}node;

typedef struct//�����еĶ���
{
	node* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (node*)malloc(sizeof(node));
	Q->front->next = NULL;
}

int EnterQueue(LinkQueue* Q, int e)//��������Ӳ���
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
