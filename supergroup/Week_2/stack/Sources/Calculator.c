
#include "../headers/Calculator.h"


int getPriority(char c){
    if(c=='+'||c=='-'||c=='('||c==')'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    
}

int getNum(char *input,int *i){
    int is_point = 0;
    

    for(int j = *i; ((j==0&&(input[j]=='-'))||(input[j]!='+'&&input[j]!='*'&&input[j]!='/'&&input[j]!='-'))&&j<strlen(input); j++,*i=j){
        //����ɸ��
        //�����һ���Ǹ���,����ɸ�����
        if(j==0&&input[j]=='-'){           
            continue;
        }
        //�����������
        if(input[j]<'0'||input[j]>'9'){
            //�����С����
            if(input[j]==' ') continue;
            if(input[j]=='.'){
                //����Ѿ����ֹ�С����,����0
                if(is_point){                    
                    return 0;
                }
                //���û���ֹ�С����,��ǳ��ֹ�С����
                else{                   
                    is_point = 1;
                    // �Ž�num��

                    //����ɸ
                    continue;
                }
            }
             //�������С����,�ǿ϶�������ĸ֮���,��Ϊ������ѭ�����������Ǳ��жϹ���,����ֱ�ӷ���0
            else{                   
                return 0;
            }
                       
        }
        
    }
    return 1;
    
    
}

int main()
{
    //���������������
    int numcnt;
    int opcnt;
    //�Ƿ��Ǽ�����ֵ�ʱ��
    int is_num;
    //��׺���ʽ
    //����
    char input[1000];
    char copy_input[1000];
    
    while(1){
    a:
        printf("�������������ʽ(����д�Ⱥ�):\n");
        numcnt = 0;
        opcnt = 0;
        is_num = 1;

        fgets(input, 100, stdin);
        // �Ȱѻس�ȥ����
        input[strlen(input) - 1] = '\0';
        
        // ����һ��,��ΪҪ���,����ֱ����input
        strcpy(copy_input,input);
        
        //�Ȱ�����������
        for(int i = 0; i < strlen(copy_input); i++)
        {
            if(copy_input[i]=='('||copy_input[i]==')'){
                copy_input[i] = ' ';
            }

        }
        //��ʼ���
        for (int i = 0; i < strlen(copy_input); i++)
        {
            //���������
            if(is_num){
            if(!getNum(copy_input,&i)){
                printf("��������,����������\n");
                goto a;
            }
            //ͨ�����ּ���
            else{         
                numcnt++;       
                is_num = 0;
            }

        }
        
        //����ֱ�Ӱѷ�������
        //�������Ĳ��������Ҳ������һ���ַ����ַ�
        if((copy_input[i]>'9'||copy_input[i]<'0')&&i!=strlen(copy_input)){
            opcnt++;
            is_num = 1;            
        }
        
    }
            if(opcnt!=numcnt-1){
                printf("��������,����������\n");
                goto a;
            }
           
//==========================================================================================
        // ���ڿ�ʼд������?,���ڿ����õ�ֻ��input�ַ���
            // printf("�ɹ���\n");
            

            //�����Ƿ���һ������
            int is_entire = 0;
            char postFix[1000];
            //����ָ��
            int z = 0;
            // ��ʼ��ջ
            initLStack(&s);
            // ��ʼ�����ַ���
            for (int i = 0; i < strlen(input); i++)
            {
                if(input[i]==' '){
                    continue;
                }
                // ��������ֻ�����С����
                if(input[i]>='0'&&input[i]<='9'||input[i]=='.'){
                    // �����ַŽ�postFix
                    if(is_entire) {postFix[z++] = ' '; is_entire = 0;}
                    postFix[z++] = input[i];

                }
                //�����������
                else if(input[i]=='('){
                    // �������ŷŽ�ջ
                    is_entire = 1;
                    pushLStack(&s,input[i]);
                }
                //�����������
                else if(input[i]==')'){
                    is_entire = 1;
                    // ��ջ��Ԫ�ص��������,ֱ������������
                    while(s.top->data!='('){
                        popLStack(&s,&postFix[z++]);
                        //��������,����Ҫ��ÿ�����������ּ��һ���ո�
                    }
                    // ����������
                    char left;
                    popLStack(&s,&left);
                }
                //����������
                else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
                    // ����ǿ�ջ,ֱ�Ӱ������ѹ��ջ
                    if(s.top==NULL){
                        pushLStack(&s,input[i]);
                        is_entire = 1;

                    }
                    // ����Ƿǿ�ջ,����Ҫ�ж�ջ��Ԫ���뵱ǰԪ�صĴ�С

                    else{
                        // �����ջ��Ԫ�����ȼ����ڵ�ǰԪ��,��ֱ�Ӱ�ջ��Ԫ�ص��������,
                        // �ٱȽ��µ�ջ�������,ֱ�������������ջ����������ȼ����ߴﵽջ��Ϊֹ,Ȼ�󽫸������ѹ��ջ
                        if(getPriority(s.top->data)>getPriority(input[i])){
                            popLStack(&s,&postFix[z++]);
                            is_entire = 1;
                            // �����Ƚ�,���򻹸���
                            while(s.count!=0&&getPriority(s.top->data)>=getPriority(input[i])){
                                popLStack(&s,&postFix[z++]);
                            }
                            // �ѵ�ǰ�����ѹ��ջ
                            pushLStack(&s,input[i]);
                        }
                        // �����ջ��Ԫ�����ȼ�С�ڵ��ڵ�ǰԪ��,��ֱ�Ӱѵ�ǰԪ��ѹ��ջ
                        else{
                            pushLStack(&s,input[i]);
                            is_entire = 1;
                        }
                    }
                }
            }
            // ��ջ��ʣ���Ԫ�ص��������
            while(s.top!=NULL){
                popLStack(&s,&postFix[z++]);

            }

            // �����׺���ʽ
            // for(int i = 0; i < z; i++){
            //     printf("%c",postFix[i]);
            // }
            // postFix[z]='\0';
            // printf("��׺���ʽΪ:%s\n",postFix);
            
//=============================================================================================
        // ��ʼ��׺���ʽ���������
        
            //���鷳,С����,��λ�����Ǽ�,ûʱ���˾Ͳ�����λ���ĺ�С������,����֮ǰ���������ǽ�����
            //������׺���ʽ
            for(int i = 0; i<z; i++){
                //�ո��������,��������Ҫ��λ����
                if(postFix[i]==' ')
                    continue;

                // ���������
                if(postFix[i]>='0'&&postFix[i]<='9'){
                    // �����ַŽ�ջ
                    pushLStack(&s,postFix[i]);

                }
                //����������
                else if(postFix[i]=='+'||postFix[i]=='-'||postFix[i]=='*'||postFix[i]=='/'){
                    // ������������,Ȼ�������,�ѽ��ѹ��ջ
                    // ������������
                    char num1,num2;
                    popLStack(&s,&num1);
                    popLStack(&s,&num2);
                    // ������
                    double result;
                    if(postFix[i]=='+'){
                        result = num1+num2-2*'0';
                    }
                    else if(postFix[i]=='-'){
                        result = num2-num1;
                    }
                    else if(postFix[i]=='*'){
                        result = (num1-'0')*(num2-'0');
                    }
                    else if(postFix[i]=='/'){
                        result = (num2-'0')/(num1-'0');
                    }
                    // �ѽ��ѹ��ջ
                    pushLStack(&s,result+'0');
                }
                
                    
                
            }
            //����ջ����һ��
            destroyLStack(&s);
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
    if (s->is_init != 1)
    {
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
    if (s->is_init != 1)
    {
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
    // ��ջʱ
    if (s->top == NULL)
    {
        s->top = p;
    }
    else
    {
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
    // ��ջ��Ԫ�ظ�ֵ��data,Ȼ��ջ��Ԫ��ɾ��,������ջ��Ԫ��,count--
    if (s->top == NULL)
    {
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
