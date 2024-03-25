
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

typedef int ElemType;

//栈节点
typedef struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

//链栈
typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
	int is_init;
}LinkStack;

//自己新建栈,不要在头文件定义了
// 承接数据
ElemType e;

//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈


#endif 
