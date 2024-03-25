#include "../Headers/LQueue.h"

int is_int = 1;
void setType()
{

    printf("\n\n===================\n");
    printf("===>ѡ����<===\n");
    printf("1.int\n");
    printf("2.char\n");
    printf("��ʱֻ����ô��(��_��)\n");
    printf("===================\n");
    char input[100];
    int choice = 1;
    while (1)
    {
        printf("������:");
        fgets(input, 100, stdin);
        // ȡ�����з�
        input[strcspn(input, "\n")] = 0;
        // ������
        if (strlen(input) == 1)
        {
            if (input[0] <= '2' && input[0] >= '1')
            {
                choice = input[0] - '0';
                break;
            }
            else
            {
                printf("�������\n");
            }
        }
        else
        {
            printf("�������\n");
        }

        
    }
    switch (choice)
        {
        case 1:
            is_int = 1;
            break;
        case 2:
            is_int = 0;
            break;
        default:
            break;
        }
    printf("%d", is_int);
}

int main()
{
    // �н�����
    void *e;
    printf("��ʼ֮ǰ�ȸ����ҷ�����ʲô");
    setType();
    
    // ��ʼ��
    system("cls");
    LQueue *Q = NULL;

    while (1)
    {

        // ��һ���˵�
        printf("\n=======================\n");
        printf("==>���в���<==\n\n");
        printf("0.���÷���\n");
        printf("1.��ʼ������\n");
        printf("2.���ٶ���\n");
        printf("3.�鿴�����Ƿ�Ϊ��\n");
        printf("4.�鿴��ͷԪ��\n");
        printf("5.ȷ�����г���\n");
        printf("6.���\n");
        printf("7.����\n");
        printf("8.��ն���\n");
        printf("9.�������\n");
        printf("10.�˳�\n\n");

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
                if (input[0] <= '9' && input[0] >= '0')
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
            else if (strlen(input) == 2)
            {
                if (input[0] == '1' && input[1] == '0')
                {
                    choice = 10;
                    system("cls");
                    break;
                }
                printf("�����\n");
            }
            else if (strlen(input) == 0)
            {
                printf("��զ�ⰴ�س���\n");
            }
            else
            {
                printf("ס�ְ�!�����̫����\n");
            }
        }

        switch (choice)
        {
        case 0:
            setType();
            break;
        case 1:
            if(InitLQueue(&Q)){
                printf("���г�ʼ���ɹ�\n");
            }
            break;

        case 2:
            if(DestoryLQueue(&Q)){
                printf("�������ٳɹ�\n");
            }
            break;

        case 3:
            if (IsEmptyLQueue(Q))
            {
                printf("����Ϊ��\n");
            }
            else
            {
                printf("���в�Ϊ��\n");
            }
            break;

        case 4:
            if (GetHeadLQueue(Q, &e))
            {
                if (is_int == 1)
                {
                    printf("��ͷԪ��Ϊ%d\n", *(int *)e);
                }
                else if (is_int == 0)
                {
                    printf("��ͷԪ��Ϊ%c\n", *(char *)e);
                }
            }

            break;

        case 5:
            int length;
            if (LengthLQueue(Q, &length))
            {
                printf("���г���Ϊ%d\n", length);
            }
            break;

        case 6:
            if (is_int == 1)
            {
                if (Q == NULL)
                {
                printf("����δ��ʼ��\n");
                break;
                }
                int* data = (int*)malloc(len*sizeof(int));
                // ������
                
                while (1)
                {
                    a:
                    printf("���������Ԫ��:");
                    fgets(input, 100, stdin);
                    // ȡ�����з�
                    input[strcspn(input, "\n")] = 0;
                    // ������
                    for (int i = 0; i < strlen(input); i++)
                    {
                        if (input[i] <= '9' && input[i] >= '0')
                        {
                        }
                        else
                        {
                            printf("�������\n");
                            goto a;
                        }

                    }
                    
                    *data = atoi(input);
                    // printf("���������%d\n", *data);
                    break;
                }
                EnLQueue(Q, data);
                }else{
                    char data;
                    while (1)
                    {
                        
                        printf("���������Ԫ��:");
                        fgets(input, 100, stdin);
                        // ȡ�����з�
                        input[strcspn(input, "\n")] = 0;
                        // ������
                        if (strlen(input) == 1)
                        {
                            //�Һ���û�취�ж�����ʲô
                            data = input[0];
                            break;
                        }
                        else
                        {
                            printf("��ʱֻ������һ����\n");                           
                        }
                    }
                    EnLQueue(Q, &data);
                }
            
            break;

        case 7:
            if(DeLQueue(Q)){
                printf("���ӳɹ�\n");
            }
            break;

        case 8:
        //Ϊɶԭ��ͷ�ļ��ﷵ��void????
            if(ClearLQueue(Q)){
                printf("��ճɹ�\n");
            }
            
            break;

        case 9:
             TraverseLQueue(Q, LPrint);
            break;
        case 10:
            return 0;
            break;

        default:
            break;
        }
    }
}

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status InitLQueue(LQueue **Q)
{
    if (*Q != NULL)
    {
        printf("�����Ѿ���ʼ������\n");
        return FALSE;
    }
    *Q = (LQueue *)malloc(sizeof(LQueue));
    (*Q)->front = NULL;
    (*Q)->rear = NULL;
    (*Q)->length = 0;
    return TRUE;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status DestoryLQueue(LQueue **Q)
{
    if (*Q == NULL)
    {
        printf("����δ��ʼ��\n");
        return FALSE;
    }
    ClearLQueue(*Q);
    free(*Q);
    *Q = NULL;
    return TRUE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if (Q == NULL)
    {
        printf("����δ��ʼ��\n");
        return FALSE;
    }
    if (Q->length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
// ����ԭ����*e,�Ҿ���������û�ð�,��ֵҲ��������
Status GetHeadLQueue(LQueue *Q, void **e)
{
    if (Q == NULL)
    {
        printf("����δ��ʼ��\n");
        return FALSE;
    }
    if (Q->length == 0)
    {
        printf("����Ϊ��\n");
        return FALSE;
    }
    *e = Q->front->data;
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE  //???�ǲ������˸Ĺ�,��ôд�ŷ���int,����д����status
 *  @notice      : None
 */
Status LengthLQueue(LQueue *Q, int *length)
{
    if (Q == NULL)
    {
        printf("����δ��ʼ��\n");
        return FALSE;
    }
    *length = Q->length;
    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if (Q == NULL)
    {
        printf("����δ��ʼ��\n");
        return FALSE;
    }
    //��ӡ����
    printf("���������%d\n", *(int*)data);
    // ����ǿն���
    if (Q->length == 0)
    {
        // ���ڶ�ͷ��βͬһ��
        Q->front = (Node *)malloc(sizeof(Node));
        // Q->front->data = malloc(len);
        //Ҫ���ƶ����Ǹ�ֵ
        if(is_int == 1){
            //�����µ�ַ
            int* copy_data = (int*)malloc(len*sizeof(int));
            *copy_data = *(int*)data;
            //������н��ڴ�ȥ
            data = copy_data;
            
        }else{
            char* copy_data = (char*)malloc(len*sizeof(char));
            *copy_data = *(char*)data;
            //������н��ڴ�ȥ
            data = copy_data;
            
        }
        Q->front->data = data;
        // printf("�������ֵ");
        // LPrint(Q->front->data);
        Q->front->next = NULL;
        Q->rear = Q->front;
        Q->length++;
        return TRUE;
    }
    // ������ǿն���
    else
    {
        // �����½���
        Node *p = (Node *)malloc(sizeof(Node));
        // p->data = malloc(len);
        //Ҫ���ƶ����Ǹ�ֵ
        if(is_int == 1){
            //�����µ�ַ
            int* copy_data = (int*)malloc(len*sizeof(int));
            *copy_data = *(int*)data;
            //������н��ڴ�ȥ
            data = copy_data;
            
        }else{
            char* copy_data = (char*)malloc(len*sizeof(char));
            *copy_data = *(char*)data;
            //������н��ڴ�ȥ
            data = copy_data;
            
        }
        p->data = data;
        p->next = NULL;
        // ��������Ǩ��
        Q->rear->next = p;
        Q->rear = p;
        Q->length++;
        return TRUE;
    }
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    // �Ƿ��ʼ��
    if (Q == NULL)
    {
        printf("����δ��ʼ��\n");
        return FALSE;
    }
    // �Ƿ�Ϊ��
    if (Q->length == 0)
    {
        printf("����Ϊ��\n");
        return FALSE;
    }
    // ��Ϊ��
    else
    {
        Node *p = Q->front;
        Q->front = Q->front->next;
        // ���Ӳ������ݵ���,��ô��
        //����Ϊʲô�쳣
        // free(p->data);
        // p->data = NULL;
        free(p);
        p = NULL;
        Q->length--;
        return TRUE;
    }
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue *Q)
{
    // �Ƿ��ʼ��
    if (Q == NULL)
    {
        printf("����δ��ʼ��\n");
        return FALSE;
    }

    Node *p = Q->front;
    Node *q = NULL;
    while (p != NULL)
    {
        q = p->next;
        // free(p->data);
        // p->data = NULL;
        free(p);
        p = q;
    }
    p = NULL;
    q = NULL;
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
    return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    // �Ƿ��ʼ��
    if (Q == NULL)
    {
        printf("����δ��ʼ��\n");
        return FALSE;
    }
    // �Ƿ�Ϊ��
    if (Q->length == 0)
    {
        printf("����Ϊ��\n");
        return FALSE;
    }
    // ��Ϊ��
    else
    {
        Node *p = Q->front;
        while (p != NULL)
        {
            foo(p->data);
            p = p->next;
        }
    }
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q)
{
    if (is_int == 1)
    {
        printf("%d ", *(int *)q);
    }

    else if (is_int == 0)
    {
        printf("%c ", *(char *)q);
    }
}
