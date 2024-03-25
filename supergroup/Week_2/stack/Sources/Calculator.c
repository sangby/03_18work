
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
        //独立筛法
        //如果第一个是负号,不用筛下面的
        if(j==0&&input[j]=='-'){           
            continue;
        }
        //如果不是数字
        if(input[j]<'0'||input[j]>'9'){
            //如果是小数点
            if(input[j]==' ') continue;
            if(input[j]=='.'){
                //如果已经出现过小数点,返回0
                if(is_point){                    
                    return 0;
                }
                //如果没出现过小数点,标记出现过小数点
                else{                   
                    is_point = 1;
                    // 放进num里

                    //继续筛
                    continue;
                }
            }
             //如果不是小数点,那肯定就是字母之类的,因为符号在循环持续条件那边判断过了,所以直接返回0
            else{                   
                return 0;
            }
                       
        }
        
    }
    return 1;
    
    
}

int main()
{
    //计数数字与操作符
    int numcnt;
    int opcnt;
    //是否是检测数字的时候
    int is_num;
    //后缀表达式
    //输入
    char input[1000];
    char copy_input[1000];
    
    while(1){
    a:
        printf("请输入算数表达式(不用写等号):\n");
        numcnt = 0;
        opcnt = 0;
        is_num = 1;

        fgets(input, 100, stdin);
        // 先把回车去掉先
        input[strlen(input) - 1] = '\0';
        
        // 复制一份,因为要检查,不能直接用input
        strcpy(copy_input,input);
        
        //先把括号挑出来
        for(int i = 0; i < strlen(copy_input); i++)
        {
            if(copy_input[i]=='('||copy_input[i]==')'){
                copy_input[i] = ' ';
            }

        }
        //开始检查
        for (int i = 0; i < strlen(copy_input); i++)
        {
            //如果是数字
            if(is_num){
            if(!getNum(copy_input,&i)){
                printf("数字有误,请重新输入\n");
                goto a;
            }
            //通过数字检验
            else{         
                numcnt++;       
                is_num = 0;
            }

        }
        
        //它会直接把符号跳过
        //留下来的不是数字且不是最后一个字符串字符
        if((copy_input[i]>'9'||copy_input[i]<'0')&&i!=strlen(copy_input)){
            opcnt++;
            is_num = 1;            
        }
        
    }
            if(opcnt!=numcnt-1){
                printf("符号有误,请重新输入\n");
                goto a;
            }
           
//==========================================================================================
        // 终于开始写程序了?,现在可以用的只有input字符串
            // printf("成功里\n");
            

            //数字是否是一个整体
            int is_entire = 0;
            char postFix[1000];
            //自增指针
            int z = 0;
            // 初始化栈
            initLStack(&s);
            // 开始遍历字符串
            for (int i = 0; i < strlen(input); i++)
            {
                if(input[i]==' '){
                    continue;
                }
                // 如果是数字或者是小数点
                if(input[i]>='0'&&input[i]<='9'||input[i]=='.'){
                    // 把数字放进postFix
                    if(is_entire) {postFix[z++] = ' '; is_entire = 0;}
                    postFix[z++] = input[i];

                }
                //如果是左括号
                else if(input[i]=='('){
                    // 把左括号放进栈
                    is_entire = 1;
                    pushLStack(&s,input[i]);
                }
                //如果是右括号
                else if(input[i]==')'){
                    is_entire = 1;
                    // 把栈顶元素弹出并输出,直到遇到左括号
                    while(s.top->data!='('){
                        popLStack(&s,&postFix[z++]);
                        //还有问题,我需要给每个连续的数字间打一个空格
                    }
                    // 弹出左括号
                    char left;
                    popLStack(&s,&left);
                }
                //如果是运算符
                else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'){
                    // 如果是空栈,直接把运算符压入栈
                    if(s.top==NULL){
                        pushLStack(&s,input[i]);
                        is_entire = 1;

                    }
                    // 如果是非空栈,则需要判断栈顶元素与当前元素的大小

                    else{
                        // 如果是栈顶元素优先级大于当前元素,则直接把栈顶元素弹出并输出,
                        // 再比较新的栈顶运算符,直到该运算符大于栈顶运算符优先级或者达到栈底为止,然后将该运算符压入栈
                        if(getPriority(s.top->data)>getPriority(input[i])){
                            popLStack(&s,&postFix[z++]);
                            is_entire = 1;
                            // 继续比较,规则还改了
                            while(s.count!=0&&getPriority(s.top->data)>=getPriority(input[i])){
                                popLStack(&s,&postFix[z++]);
                            }
                            // 把当前运算符压入栈
                            pushLStack(&s,input[i]);
                        }
                        // 如果是栈顶元素优先级小于等于当前元素,则直接把当前元素压入栈
                        else{
                            pushLStack(&s,input[i]);
                            is_entire = 1;
                        }
                    }
                }
            }
            // 把栈中剩余的元素弹出并输出
            while(s.top!=NULL){
                popLStack(&s,&postFix[z++]);

            }

            // 输出后缀表达式
            // for(int i = 0; i < z; i++){
            //     printf("%c",postFix[i]);
            // }
            // postFix[z]='\0';
            // printf("后缀表达式为:%s\n",postFix);
            
//=============================================================================================
        // 开始后缀表达式的运算计算
        
            //好麻烦,小数点,多位数都是槛,没时间了就不做多位数的和小数的了,但是之前我又让他们进来了
            //遍历后缀表达式
            for(int i = 0; i<z; i++){
                //空格就跳过了,本来是想要多位数的
                if(postFix[i]==' ')
                    continue;

                // 如果是数字
                if(postFix[i]>='0'&&postFix[i]<='9'){
                    // 把数字放进栈
                    pushLStack(&s,postFix[i]);

                }
                //如果是运算符
                else if(postFix[i]=='+'||postFix[i]=='-'||postFix[i]=='*'||postFix[i]=='/'){
                    // 弹出两个数字,然后计算结果,把结果压入栈
                    // 弹出两个数字
                    char num1,num2;
                    popLStack(&s,&num1);
                    popLStack(&s,&num2);
                    // 计算结果
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
                    // 把结果压入栈
                    pushLStack(&s,result+'0');
                }
                
                    
                
            }
            //最后把栈销毁一下
            destroyLStack(&s);
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
    if (s->is_init != 1)
    {
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
    if (s->is_init != 1)
    {
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
    // 空栈时
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

// 出栈
Status popLStack(LinkStack *s, ElemType *data)
{
    if (s->is_init != 1)
    {
        printf("栈未初始化\n");
        return S_ERROR;
    }
    // 将栈顶元素赋值给data,然后将栈顶元素删除,最后更新栈顶元素,count--
    if (s->top == NULL)
    {
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
