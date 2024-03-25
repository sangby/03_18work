#include "../headers/LinkStack.h"
// 链栈
int main()
{
    LinkStack s;
    while (1)
    {
        
        // 简单一个菜单
        printf("\n=======================\n");
        printf("==>链栈操作<==\n\n");
        printf("1.初始化栈\n");
        printf("2.判断栈是否为空\n");
        printf("3.得到栈顶元素\n");
        printf("4.清空栈\n");
        printf("5.销毁栈\n");
        printf("6.检测栈长度\n");
        printf("7.入栈\n");
        printf("8.出栈\n");
        printf("9.退出\n\n");
        printf("=======================\n");

        int choice;
        char input[100];

        while (1)
        {
            printf("请输入操作序号:");
            fgets(input, 100, stdin);
            // 取出换行符
            input[strcspn(input, "\n")] = 0;
            // 输入检查
            if (strlen(input) == 1)
            {
                if (input[0] <= '9' && input[0] >= '1')
                {
                    choice = input[0] - '0';
                    system("cls");
                    break;
                }
                else
                {
                    printf("输入编号哥们\n");
                }
            }
            else
            {
                printf("看不出来只需要输入个位数吗orz?\n");
            }
        }

        // printf("choice是:%d\n", choice);
        // printf("%d\n",strlen(input)); strlen返回元素个数

        switch (choice)
        {
        case 1:
            // 初始化栈
            printf("=====初始化栈=====\n");
            initLStack(&s);
            printf("初始化成功\n");
            break;

        case 2:
            // 判断链表是否为空
            printf("=====是否为空=====\n");

            if (isEmptyLStack(&s))
            {
                printf("栈为空\n");
            }
            else
            {
                printf("栈不为空\n");
            }

            break;

        case 3:
            // 得到栈顶元素
            printf("=====得到栈顶元素=====\n");
            if (getTopLStack(&s, &e))
            {
                printf("栈顶元素是:%d\n", e);
            }

            break;

        case 4:
            // 清空栈
            printf("=====清空栈=====\n");
            if(clearLStack(&s)){
            printf("清空栈成功\n");
                
            }
            break;

        case 5:
            // 销毁栈
            printf("=====销毁栈=====\n");
            if(destroyLStack(&s)){
            printf("销毁栈成功\n");
                
            }
            break;

        case 6:
            // 检测栈长度
            printf("=====检测栈长度=====\n");
            LStackLength(&s, &e);
            printf("栈长度是:%d\n", e);
            break;

        case 7:
            // printf("%p %d", s.top, s.count);
            // 入栈
            printf("=====入栈=====\n");
            if(s.is_init != 1){
                printf("栈未初始化\n");
                break;
            }
            
            while (1)
            {
                A:
                printf("请输入入栈整数:");
                fgets(input, 100, stdin);
                // 取出换行符
                input[strcspn(input, "\n")] = 0;
                // 输入检查
                // 先检查是不是纯数字
                
                    for (size_t i = 0; i < strlen(input); i++)
                    {
                        if (i == 0)
                        {// 检查第一个字符是负号或者数字就继续
                            if (input[i] == '-'|| (input[i]>='0'&&input[i]<='9'))
                            {
                                continue;
                            }
                            else
                            {
                                printf("哥,输入整数\n");
                                goto A;
                            }
                        }
                        if (input[i] < '0' || input[i] > '9')
                        {
                            printf("哥,输入整数\n");
                            goto A;
                        }
                    }
                
                // 再检查大小
                if (strlen(input) >= 10 && input[0] == '+')
                {
                    printf("哥,int类型受不了这么大的\n");

                    
                }
                else if(strlen(input) >= 11 && input[0] == '-')
                {
                    printf("哥,int类型受不了这么大的\n");
                    
                }else{
                    break;
                }
            }
            if(pushLStack(&s, atoi(input))){
                printf("入栈成功\n");
            }
            break;

        case 8:
            // 出栈
            printf("=====出栈=====\n");
            if(popLStack(&s, &e)){
                printf("出栈成功\n");
                printf("出栈元素是:%d\n", e);
            }
            break;

        case 9:
            return 0;
            break;

        default:
            break;
        }
    }
}
// 初始化栈
Status initLStack(LinkStack *s)
{
    if (s->is_init != 1)
    {
        s->is_init = 1;
        s->top = NULL;
        s->count = 0;
        return SUCCESS;
    }
    else
    {
        printf("栈已经初始化\n");
        return S_ERROR;
    }
}

// 判断栈是否为空,若为空,则返回1,否则返回0
Status isEmptyLStack(LinkStack *s)
{
    // 吐槽一下为啥常量要设置成SUCCESS
    if (s->is_init != 1)
    {
        printf("栈未初始化\n");
        return S_ERROR;
    }
    else
    {
        // 这里好难圆回去,不圆了
        if (s->count == 0 && s->top == NULL)
        {
            return SUCCESS;
        }
        else
        {
            return S_ERROR;
        }
    }
}

// 得到栈顶元素,将栈顶元素赋值给e
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (s->is_init != 1)
    {
        printf("栈未初始化\n");
        return S_ERROR;
    }
    if (isEmptyLStack(s))
    {
        printf("栈为空\n");
        return S_ERROR;
    }
    else
    {
        *e = s->top->data;
        return SUCCESS;
    }
}

// 清空栈,保留栈结构
Status clearLStack(LinkStack *s)
{
    if (s->is_init != 1){
        printf("栈未初始化\n");
        return S_ERROR;
    }
    LinkStackPtr p = s->top;
    LinkStackPtr q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    s->count = 0;
    return SUCCESS;
}

// 销毁栈,释放栈结构
Status destroyLStack(LinkStack *s)
{
    if (s->is_init != 1){
        printf("栈未初始化\n");
        return S_ERROR;
    }
    clearLStack(s);
    s->top = NULL;
    s->is_init = 0;
    return SUCCESS;
}

// 检测栈长度
Status LStackLength(LinkStack *s, int *length)
{
    if (s->is_init != 1)
    {
        printf("栈未初始化\n");
        return S_ERROR;
    }
    // 一开始没有初始化的时候是什么值呢
    *length = s->count;
    return SUCCESS;
}

// 入栈
Status pushLStack(LinkStack *s, ElemType data)
{
    // 先判断链表是否被初始化,再新建一个节点填入数据,再让新节点压入栈中,最后更新栈顶元素,count++
    if (s->is_init != 1)
    {
        printf("栈未初始化\n");
        return S_ERROR;
    }

    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(LinkStack));
    p->data = data;
//空栈时
if(s->top == NULL){
    s->top = p;
    }else{
        p->next = s->top;
    s->top = p;
    }

    s->count++;
    return SUCCESS;
}

// 出栈
Status popLStack(LinkStack *s, ElemType *data)
{
    if (s->is_init != 1)
    {
        printf("栈未初始化\n");
        return S_ERROR;
    }
    //将栈顶元素赋值给data,然后将栈顶元素删除,最后更新栈顶元素,count--
    if (s->top == NULL){
        printf("栈为空\n");
        return S_ERROR;
    }
    *data = s->top->data;
    LinkStackPtr p = s->top->next;
    free(s->top);
    s->top = p;

    s->count--;
    //如果栈顶元素已经是最后一个元素了,则把栈顶元素置空
    if(s->count==0){
        s->top = NULL;
    }
    return SUCCESS;
}
