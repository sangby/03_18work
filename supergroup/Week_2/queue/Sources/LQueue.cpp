#include "../Headers/LQueue.h"

int is_int = 1;
void setType()
{

    printf("\n\n===================\n");
    printf("===>选择泛型<===\n");
    printf("1.int\n");
    printf("2.char\n");
    printf("暂时只有这么多(。_。)\n");
    printf("===================\n");
    char input[100];
    int choice = 1;
    while (1)
    {
        printf("请输入:");
        fgets(input, 100, stdin);
        // 取出换行符
        input[strcspn(input, "\n")] = 0;
        // 输入检查
        if (strlen(input) == 1)
        {
            if (input[0] <= '2' && input[0] >= '1')
            {
                choice = input[0] - '0';
                break;
            }
            else
            {
                printf("输入错误\n");
            }
        }
        else
        {
            printf("输入错误\n");
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
    // 承接数据
    void *e;
    printf("开始之前先告诉我泛型是什么");
    setType();
    
    // 初始化
    system("cls");
    LQueue *Q = NULL;

    while (1)
    {

        // 简单一个菜单
        printf("\n=======================\n");
        printf("==>队列操作<==\n\n");
        printf("0.设置泛型\n");
        printf("1.初始化队列\n");
        printf("2.销毁队列\n");
        printf("3.查看队列是否为空\n");
        printf("4.查看队头元素\n");
        printf("5.确定队列长度\n");
        printf("6.入队\n");
        printf("7.出队\n");
        printf("8.清空队列\n");
        printf("9.遍历输出\n");
        printf("10.退出\n\n");

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
                if (input[0] <= '9' && input[0] >= '0')
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
            else if (strlen(input) == 2)
            {
                if (input[0] == '1' && input[1] == '0')
                {
                    choice = 10;
                    system("cls");
                    break;
                }
                printf("错误的\n");
            }
            else if (strlen(input) == 0)
            {
                printf("你咋光按回车呢\n");
            }
            else
            {
                printf("住手啊!输入的太多了\n");
            }
        }

        switch (choice)
        {
        case 0:
            setType();
            break;
        case 1:
            if(InitLQueue(&Q)){
                printf("队列初始化成功\n");
            }
            break;

        case 2:
            if(DestoryLQueue(&Q)){
                printf("队列销毁成功\n");
            }
            break;

        case 3:
            if (IsEmptyLQueue(Q))
            {
                printf("队列为空\n");
            }
            else
            {
                printf("队列不为空\n");
            }
            break;

        case 4:
            if (GetHeadLQueue(Q, &e))
            {
                if (is_int == 1)
                {
                    printf("队头元素为%d\n", *(int *)e);
                }
                else if (is_int == 0)
                {
                    printf("队头元素为%c\n", *(char *)e);
                }
            }

            break;

        case 5:
            int length;
            if (LengthLQueue(Q, &length))
            {
                printf("队列长度为%d\n", length);
            }
            break;

        case 6:
            if (is_int == 1)
            {
                if (Q == NULL)
                {
                printf("队列未初始化\n");
                break;
                }
                int* data = (int*)malloc(len*sizeof(int));
                // 输入检查
                
                while (1)
                {
                    a:
                    printf("请输入入队元素:");
                    fgets(input, 100, stdin);
                    // 取出换行符
                    input[strcspn(input, "\n")] = 0;
                    // 输入检查
                    for (int i = 0; i < strlen(input); i++)
                    {
                        if (input[i] <= '9' && input[i] >= '0')
                        {
                        }
                        else
                        {
                            printf("输入错误\n");
                            goto a;
                        }

                    }
                    
                    *data = atoi(input);
                    // printf("你输入的是%d\n", *data);
                    break;
                }
                EnLQueue(Q, data);
                }else{
                    char data;
                    while (1)
                    {
                        
                        printf("请输入入队元素:");
                        fgets(input, 100, stdin);
                        // 取出换行符
                        input[strcspn(input, "\n")] = 0;
                        // 输入检查
                        if (strlen(input) == 1)
                        {
                            //我好像没办法判断他是什么
                            data = input[0];
                            break;
                        }
                        else
                        {
                            printf("暂时只能输入一个捏\n");                           
                        }
                    }
                    EnLQueue(Q, &data);
                }
            
            break;

        case 7:
            if(DeLQueue(Q)){
                printf("出队成功\n");
            }
            break;

        case 8:
        //为啥原来头文件里返回void????
            if(ClearLQueue(Q)){
                printf("清空成功\n");
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
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status InitLQueue(LQueue **Q)
{
    if (*Q != NULL)
    {
        printf("队列已经初始化过了\n");
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status DestoryLQueue(LQueue **Q)
{
    if (*Q == NULL)
    {
        printf("队列未初始化\n");
        return FALSE;
    }
    ClearLQueue(*Q);
    free(*Q);
    *Q = NULL;
    return TRUE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if (Q == NULL)
    {
        printf("队列未初始化\n");
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
// 这里原本是*e,我觉得这样子没用啊,这值也带不出来
Status GetHeadLQueue(LQueue *Q, void **e)
{
    if (Q == NULL)
    {
        printf("队列未初始化\n");
        return FALSE;
    }
    if (Q->length == 0)
    {
        printf("队列为空\n");
        return FALSE;
    }
    *e = Q->front->data;
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE  //???是不是有人改过,怎么写着返回int,这里写返回status
 *  @notice      : None
 */
Status LengthLQueue(LQueue *Q, int *length)
{
    if (Q == NULL)
    {
        printf("队列未初始化\n");
        return FALSE;
    }
    *length = Q->length;
    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if (Q == NULL)
    {
        printf("队列未初始化\n");
        return FALSE;
    }
    //打印数据
    printf("你输入的是%d\n", *(int*)data);
    // 如果是空队列
    if (Q->length == 0)
    {
        // 放在队头队尾同一个
        Q->front = (Node *)malloc(sizeof(Node));
        // Q->front->data = malloc(len);
        //要复制而不是赋值
        if(is_int == 1){
            //创造新地址
            int* copy_data = (int*)malloc(len*sizeof(int));
            *copy_data = *(int*)data;
            //在里面承接在粗去
            data = copy_data;
            
        }else{
            char* copy_data = (char*)malloc(len*sizeof(char));
            *copy_data = *(char*)data;
            //在里面承接在粗去
            data = copy_data;
            
        }
        Q->front->data = data;
        // printf("看看你的值");
        // LPrint(Q->front->data);
        Q->front->next = NULL;
        Q->rear = Q->front;
        Q->length++;
        return TRUE;
    }
    // 如果不是空队列
    else
    {
        // 构造新建点
        Node *p = (Node *)malloc(sizeof(Node));
        // p->data = malloc(len);
        //要复制而不是赋值
        if(is_int == 1){
            //创造新地址
            int* copy_data = (int*)malloc(len*sizeof(int));
            *copy_data = *(int*)data;
            //在里面承接在粗去
            data = copy_data;
            
        }else{
            char* copy_data = (char*)malloc(len*sizeof(char));
            *copy_data = *(char*)data;
            //在里面承接在粗去
            data = copy_data;
            
        }
        p->data = data;
        p->next = NULL;
        // 先连接在迁移
        Q->rear->next = p;
        Q->rear = p;
        Q->length++;
        return TRUE;
    }
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    // 是否初始化
    if (Q == NULL)
    {
        printf("队列未初始化\n");
        return FALSE;
    }
    // 是否为空
    if (Q->length == 0)
    {
        printf("队列为空\n");
        return FALSE;
    }
    // 不为空
    else
    {
        Node *p = Q->front;
        Q->front = Q->front->next;
        // 出队不给数据的吗,这么简单
        //这里为什么异常
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue *Q)
{
    // 是否初始化
    if (Q == NULL)
    {
        printf("队列未初始化\n");
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    // 是否初始化
    if (Q == NULL)
    {
        printf("队列未初始化\n");
        return FALSE;
    }
    // 是否为空
    if (Q->length == 0)
    {
        printf("队列为空\n");
        return FALSE;
    }
    // 不为空
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
 *    @description : 操作函数
 *    @param         q 指针q

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
