

typedef double int_ElemType;

//ջ�ڵ�
typedef struct int_StackNode
{
	int_ElemType data;
	struct int_StackNode *next;
}int_StackNode, *int_LinkStackPtr;

//��ջ
typedef  struct  int_LinkStack
{
	int_LinkStackPtr top;
	int	count;
	int is_init;
}int_LinkStack;

//�Լ��½�ջ,��Ҫ��ͷ�ļ�������
// �н�����
int_ElemType int_e;

//��ջ
Status int_initLStack(int_LinkStack *s);//��ʼ��ջ
Status int_isEmptyLStack(int_LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status int_getTopLStack(int_LinkStack *s,int_ElemType *e);//�õ�ջ��Ԫ��
Status int_clearLStack(int_LinkStack *s);//���ջ
Status int_destroyLStack(int_LinkStack *s);//����ջ
Status int_LStackLength(int_LinkStack *s,int *length);//���ջ����
Status int_pushLStack(int_LinkStack *s,int_ElemType data);//��ջ
Status int_popLStack(int_LinkStack *s,int_ElemType *data);//��ջ


