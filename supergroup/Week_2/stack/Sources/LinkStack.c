#include "../headers/LinkStack.h"
// ��ջ
int main()
{
    LinkStack s;
    while (1)
    {
        
        // ��һ���˵�
        printf("\n=======================\n");
        printf("==>��ջ����<==\n\n");
        printf("1.��ʼ��ջ\n");
        printf("2.�ж�ջ�Ƿ�Ϊ��\n");
        printf("3.�õ�ջ��Ԫ��\n");
        printf("4.���ջ\n");
        printf("5.����ջ\n");
        printf("6.���ջ����\n");
        printf("7.��ջ\n");
        printf("8.��ջ\n");
        printf("9.�˳�\n\n");
        printf("=======================\n");

        int choice;
        char input[100];

        while (1)
        {
            printf("������������:");
            fgets(input, 100, stdin);
            // ȡ�����з�
            input[strcspn(input, "\n")] = 0;
            // ������
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
                    printf("�����Ÿ���\n");
                }
            }
            else
            {
                printf("��������ֻ��Ҫ�����λ����orz?\n");
            }
        }

        // printf("choice��:%d\n", choice);
        // printf("%d\n",strlen(input)); strlen����Ԫ�ظ���

        switch (choice)
        {
        case 1:
            // ��ʼ��ջ
            printf("=====��ʼ��ջ=====\n");
            initLStack(&s);
            printf("��ʼ���ɹ�\n");
            break;

        case 2:
            // �ж������Ƿ�Ϊ��
            printf("=====�Ƿ�Ϊ��=====\n");

            if (isEmptyLStack(&s))
            {
                printf("ջΪ��\n");
            }
            else
            {
                printf("ջ��Ϊ��\n");
            }

            break;

        case 3:
            // �õ�ջ��Ԫ��
            printf("=====�õ�ջ��Ԫ��=====\n");
            if (getTopLStack(&s, &e))
            {
                printf("ջ��Ԫ����:%d\n", e);
            }

            break;

        case 4:
            // ���ջ
            printf("=====���ջ=====\n");
            if(clearLStack(&s)){
            printf("���ջ�ɹ�\n");
                
            }
            break;

        case 5:
            // ����ջ
            printf("=====����ջ=====\n");
            if(destroyLStack(&s)){
            printf("����ջ�ɹ�\n");
                
            }
            break;

        case 6:
            // ���ջ����
            printf("=====���ջ����=====\n");
            LStackLength(&s, &e);
            printf("ջ������:%d\n", e);
            break;

        case 7:
            // printf("%p %d", s.top, s.count);
            // ��ջ
            printf("=====��ջ=====\n");
            if(s.is_init != 1){
                printf("ջδ��ʼ��\n");
                break;
            }
            
            while (1)
            {
                A:
                printf("��������ջ����:");
                fgets(input, 100, stdin);
                // ȡ�����з�
                input[strcspn(input, "\n")] = 0;
                // ������
                // �ȼ���ǲ��Ǵ�����
                
                    for (size_t i = 0; i < strlen(input); i++)
                    {
                        if (i == 0)
                        {// ����һ���ַ��Ǹ��Ż������־ͼ���
                            if (input[i] == '-'|| (input[i]>='0'&&input[i]<='9'))
                            {
                                continue;
                            }
                            else
                            {
                                printf("��,��������\n");
                                goto A;
                            }
                        }
                        if (input[i] < '0' || input[i] > '9')
                        {
                            printf("��,��������\n");
                            goto A;
                        }
                    }
                
                // �ټ���С
                if (strlen(input) >= 10 && input[0] == '+')
                {
                    printf("��,int�����ܲ�����ô���\n");

                    
                }
                else if(strlen(input) >= 11 && input[0] == '-')
                {
                    printf("��,int�����ܲ�����ô���\n");
                    
                }else{
                    break;
                }
            }
            if(pushLStack(&s, atoi(input))){
                printf("��ջ�ɹ�\n");
            }
            break;

        case 8:
            // ��ջ
            printf("=====��ջ=====\n");
            if(popLStack(&s, &e)){
                printf("��ջ�ɹ�\n");
                printf("��ջԪ����:%d\n", e);
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
// ��ʼ��ջ
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
        printf("ջ�Ѿ���ʼ��\n");
        return S_ERROR;
    }
}

// �ж�ջ�Ƿ�Ϊ��,��Ϊ��,�򷵻�1,���򷵻�0
Status isEmptyLStack(LinkStack *s)
{
    // �²�һ��Ϊɶ����Ҫ���ó�SUCCESS
    if (s->is_init != 1)
    {
        printf("ջδ��ʼ��\n");
        return S_ERROR;
    }
    else
    {
        // �������Բ��ȥ,��Բ��
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

// �õ�ջ��Ԫ��,��ջ��Ԫ�ظ�ֵ��e
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (s->is_init != 1)
    {
        printf("ջδ��ʼ��\n");
        return S_ERROR;
    }
    if (isEmptyLStack(s))
    {
        printf("ջΪ��\n");
        return S_ERROR;
    }
    else
    {
        *e = s->top->data;
        return SUCCESS;
    }
}

// ���ջ,����ջ�ṹ
Status clearLStack(LinkStack *s)
{
    if (s->is_init != 1){
        printf("ջδ��ʼ��\n");
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

// ����ջ,�ͷ�ջ�ṹ
Status destroyLStack(LinkStack *s)
{
    if (s->is_init != 1){
        printf("ջδ��ʼ��\n");
        return S_ERROR;
    }
    clearLStack(s);
    s->top = NULL;
    s->is_init = 0;
    return SUCCESS;
}

// ���ջ����
Status LStackLength(LinkStack *s, int *length)
{
    if (s->is_init != 1)
    {
        printf("ջδ��ʼ��\n");
        return S_ERROR;
    }
    // һ��ʼû�г�ʼ����ʱ����ʲôֵ��
    *length = s->count;
    return SUCCESS;
}

// ��ջ
Status pushLStack(LinkStack *s, ElemType data)
{
    // ���ж������Ƿ񱻳�ʼ��,���½�һ���ڵ���������,�����½ڵ�ѹ��ջ��,������ջ��Ԫ��,count++
    if (s->is_init != 1)
    {
        printf("ջδ��ʼ��\n");
        return S_ERROR;
    }

    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(LinkStack));
    p->data = data;
//��ջʱ
if(s->top == NULL){
    s->top = p;
    }else{
        p->next = s->top;
    s->top = p;
    }

    s->count++;
    return SUCCESS;
}

// ��ջ
Status popLStack(LinkStack *s, ElemType *data)
{
    if (s->is_init != 1)
    {
        printf("ջδ��ʼ��\n");
        return S_ERROR;
    }
    //��ջ��Ԫ�ظ�ֵ��data,Ȼ��ջ��Ԫ��ɾ��,������ջ��Ԫ��,count--
    if (s->top == NULL){
        printf("ջΪ��\n");
        return S_ERROR;
    }
    *data = s->top->data;
    LinkStackPtr p = s->top->next;
    free(s->top);
    s->top = p;

    s->count--;
    //���ջ��Ԫ���Ѿ������һ��Ԫ����,���ջ��Ԫ���ÿ�
    if(s->count==0){
        s->top = NULL;
    }
    return SUCCESS;
}
