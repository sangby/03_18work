
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

typedef enum Status 
{
    S_ERROR = 0, 
	SUCCESS = 1,
	EXCEPTION = -1
} Status;

typedef char ElemType;

//ջ�ڵ�
typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

//��ջ
typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
	int is_init;
}LinkStack;

// ��ջ
LinkStack s;
// �н�����
ElemType e;

//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s,ElemType *data);//��ջ


#endif 
