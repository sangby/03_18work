

typedef double int_ElemType;

//栈节点
typedef struct int_StackNode
{
	int_ElemType data;
	struct int_StackNode *next;
}int_StackNode, *int_LinkStackPtr;

//链栈
typedef  struct  int_LinkStack
{
	int_LinkStackPtr top;
	int	count;
	int is_init;
}int_LinkStack;

//自己新建栈,不要在头文件定义了
// 承接数据
int_ElemType int_e;

//链栈
Status int_initLStack(int_LinkStack *s);//初始化栈
Status int_isEmptyLStack(int_LinkStack *s);//判断栈是否为空
Status int_getTopLStack(int_LinkStack *s,int_ElemType *e);//得到栈顶元素
Status int_clearLStack(int_LinkStack *s);//清空栈
Status int_destroyLStack(int_LinkStack *s);//销毁栈
Status int_LStackLength(int_LinkStack *s,int *length);//检测栈长度
Status int_pushLStack(int_LinkStack *s,int_ElemType data);//入栈
Status int_popLStack(int_LinkStack *s,int_ElemType *data);//出栈


