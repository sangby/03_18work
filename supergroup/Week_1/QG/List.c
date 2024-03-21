#include"List.h"
int main(){
    //菜单1
    while(1){
        char sel;
        printf("使用说明:不用按回车直接按数字即可进入相应功能\n");
        printf("================\n\n");
        printf("1.单链表\n");
        printf("2.双向链表\n");
        printf("3.退出\n\n");
        printf("================\n");
        printf("请输入你的选择:");

        sel = getch();
        printf("\n");

        switch(sel){
            case '1':
            //进入单链表
            entry_sList();
            break;

            case '2':
            //进入双向链表
            entry_dList();
            break; 

            case '3':
            //退出
            return 0;
            break;

            default:
            printf("输入有误,请重新输入\n");
            break;
        }
    }
    


    
}

//功能菜单->单链表
void displaymenu_sList(int hilight){
    int i;
    //这里拿了一点课设的代码,维护好麻烦,下次不用了
    printf("使用说明:直接键入字母(不区分大小写),或者光标移动到相应位置后回车\n链表数据是int\n\n");
    printf("\n************************************************\n");
    printf("**      平平无奇的第一周作业系统->单链表      **\n");
    printf("************************************************\n");
    printf("************************************************\n");


    for(i = 0; i<sListMenuLength; i++)
    {
        if(i==hilight-1){
            printf("**              <<%-20s>>      **\n",MenuText_sList[i]);
        }
        else 
            printf("**              %-20s          **\n",MenuText_sList[i]);
    }
    printf("************************************************\n");

}

//功能菜单
void displaymenu_dList(int hilight){
    int i;
    printf("使用说明:直接键入字母(不区分大小写),或者光标移动到相应位置后回车\n\n");
    printf("\n************************************************\n");
    printf("**     平平无奇的第一周作业系统->双向链表     **\n");
    printf("************************************************\n");
    printf("************************************************\n");

    
    for(i = 0; i<sListMenuLength; i++)
    {
        if(i==hilight-1){
            printf("**              <<%-20s>>      **\n",MenuText_dList[i]);
        }
        else 
            printf("**              %-20s          **\n",MenuText_dList[i]);
    }
    printf("************************************************\n");

}

//单链表系统入口
void entry_sList(){
//我怀疑switch里不能定义变量,所以全部拿出来
    int n;
    int data[100];
    int p_data;
    int insert_data;
    int delete_data;
    int find_data;

    //日常使用节点
SlNode* p_sNode=NULL;
SlNode* q_sNode=NULL;


//单链表的头结点
SlNode* head_sList=NULL;

    char c=' ';
    int sel = 1;
    displaymenu_sList(sel);
    while(1){
        if(kbhit()){    
        //利用上下方向键操作
            //若检测到方向键上则刷新页面,光标上移
            if(GetAsyncKeyState(VK_UP)){    
                sel = (sel>1)?sel-1:sel;
                system("cls");
                displaymenu_sList(sel);
                
            }
            //若检测到方向键下则刷新页面,光标下移
            if (GetAsyncKeyState(VK_DOWN))
                {
                sel = (sel<sListMenuLength)?sel+1:sel;
                system("cls");
                displaymenu_sList(sel);
                }
                
            //接受键入字母(不用回车),判断后转化为序数,进而进入某操作
            c=getch();
            if(c<='z'&&c>='a') c = c-('a'-'A');
            if(c<='F'&&c>='A'){
                sel = c-'A'+1;
                system("cls");
                displaymenu_sList(sel);
                switch (c)
                {
                case 'A':
                    //生成,记录链表长度,记录数据
                    
                    printf("请输入要生成的链表长度:");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++){
                        printf("请输入第%d个节点的值:",i+1);
                        scanf("%d",&data[i]);
                    }

                    sList_create(&head_sList,data,n);
                    printf("链表创建成功!\n");
                    break;
                case 'B':
                    //插入,要先找到目的节点,创建新节点,再调用方法
                    

                    printf("请输入要插入在哪个节点的后面,输入那个节点的属性值:");
                    scanf("%d",&p_data);
                    //先查有没有这个节点,没有直接跳过,有再去取出来
                    if(sList_find(head_sList,p_data)){
                        p_sNode = head_sList;
                        while(p_sNode != NULL){
                            if(p_sNode->data == p_data){
                                break;
                            }
                            p_sNode = p_sNode->next;
                        }
                    }else{
                        printf("链表中没有这个节点!\n");
                        break;
                    }
                    
                    printf("请输入要插入的节点的值:");
                    scanf("%d",&insert_data);
                    q_sNode = (SlNode*)malloc(sizeof(SlNode));
                    q_sNode->data = insert_data;

                    sList_insert(p_sNode,q_sNode);

                        printf("插入成功!\n");
                    
                    break;
                case 'C':
                    //销毁
                    sList_destroy(&head_sList);
                    printf("销毁成功!\n");
                    break;
                case 'D':
                    //删除
                    printf("请输入要删除的节点属性值:");
                    scanf("%d",&delete_data);
                    //先判断是否存在这个节点
                    if(sList_find(head_sList,delete_data)){
                        
                    }else{
                        printf("没有这个节点\n");
                        break;
                    }
                    sList_delete(&head_sList,delete_data);
                    //每次程序运行完都写一个成功好了
                        printf("删除成功!\n");
                    
                    break;
                case 'E':
                    printf("请输入要查找的节点属性值:");
                    scanf("%d",&find_data);
                    if(sList_find(head_sList,find_data)){
                        printf("节点存在!\n");

                    }else{
                        printf("节点不存在\n");

                    }
                    break;

                    // 查找
                case 'F':
                    // 遍历
                    sList_display(head_sList);
                    break;
                default:
                    break;
                }
                }
            //若检测到回车键则执行光标所在操作
            else if(c=='\r'){   
                if(sel==sListMenuLength) return;
                char c = 'A'+sel-1;

                switch (c)
                {
                case 'A':
                    //生成,记录链表长度,记录数据
                    
                    printf("请输入要生成的链表长度:");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++){
                        printf("请输入第%d个节点的值:",i+1);
                        scanf("%d",&data[i]);
                    }

                    sList_create(&head_sList,data,n);
                    printf("链表创建成功!\n");
                    break;
                case 'B':
                    //插入,要先找到目的节点,创建新节点,再调用方法
                    

                    printf("请输入要插入在哪个节点的后面,输入那个节点的属性值:");
                    scanf("%d",&p_data);
                    //先查有没有这个节点,没有直接跳过,有再去取出来
                    if(sList_find(head_sList,p_data)){
                        p_sNode = head_sList;
                        while(p_sNode != NULL){
                            if(p_sNode->data == p_data){
                                break;
                            }
                            p_sNode = p_sNode->next;
                        }
                    }else{
                        printf("链表中没有这个节点!\n");
                        break;
                    }
                    
                    printf("请输入要插入的节点的值:");
                    scanf("%d",&insert_data);
                    q_sNode = (SlNode*)malloc(sizeof(SlNode));
                    q_sNode->data = insert_data;

                    sList_insert(p_sNode,q_sNode);

                        printf("插入成功!\n");
                    
                    break;
                case 'C':
                    //销毁
                    sList_destroy(&head_sList);
                    printf("销毁成功!\n");
                    break;
                case 'D':
                    //删除
                    printf("请输入要删除的节点属性值:");
                    scanf("%d",&delete_data);
                    //先判断是否存在这个节点
                    if(sList_find(head_sList,delete_data)){
                        
                    }else{
                        printf("没有这个节点\n");
                        break;
                    }
                    sList_delete(&head_sList,delete_data);
                    //每次程序运行完都写一个成功好了
                        printf("删除成功!\n");
                    
                    break;
                case 'E':
                    printf("请输入要查找的节点属性值:");
                    scanf("%d",&find_data);
                    if(sList_find(head_sList,find_data)){
                        printf("节点存在!\n");

                    }else{
                        printf("节点不存在\n");

                    }
                    break;

                    // 查找
                case 'F':
                    // 遍历
                    sList_display(head_sList);
                    break;
                default:
                    break;
                }
            }

            else if (c=='Q'){
                return;
            }
            //延缓光标移动速度
            Sleep(60);
            Sleep(40);
        }
    }
}

// 双向链表系统入口
void entry_dList(){
    int n;
    int data[100];
    int p_data;
    int insert_data;
    int delete_data;
    int find_data;

//日常使用节点

DlNode* q_dNode=NULL;
DlNode* p_dNode=NULL;


//双向链表的头结点
DlNode* head_dList=NULL;

    char c=' ';
    int sel = 1;
    displaymenu_dList(sel);
    while(1){
        if(kbhit()){    
        //利用上下方向键操作
            //若检测到方向键上则刷新页面,光标上移
            if(GetAsyncKeyState(VK_UP)){    
                sel = (sel>1)?sel-1:sel;
                system("cls");
                displaymenu_dList(sel);
                
            }
            //若检测到方向键下则刷新页面,光标下移
            if (GetAsyncKeyState(VK_DOWN))
                {
                sel = (sel<dListMenuLength)?sel+1:sel;
                system("cls");
                displaymenu_dList(sel);
                }
                
            //接受键入字母(不用回车),判断后转化为序数,进而进入某操作
            c=getch();
            if(c<='z'&&c>='a') c = c-('a'-'A');
            if(c<='F'&&c>='A'){
                sel = c-'A'+1;
                system("cls");
                displaymenu_dList(sel);
                switch (c)
                {
                case 'A':
                    //生成
                    printf("请输入要生成的链表长度:");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++){
                        printf("请输入第%d个节点的值:",i+1);
                        scanf("%d",&data[i]);
                    }
                    dList_create(&head_dList,data,n);
                    printf("链表已生成\n");
                    break;
                case 'B':
                    //插入
                    printf("请输入要插入在哪个节点的前面,输入那个节点的属性值:");
                    scanf("%d",&p_data);
                    printf("请输入要插入的节点的值:");
                    scanf("%d",&insert_data);
                    //先找到插入的节点位置,再新建插入节点
                    if(dList_find(head_dList,p_data)){
                        q_dNode = head_dList;
                        while(q_dNode->data!=p_data) q_dNode = q_dNode->next;

                    }else{
                        printf("未找到该节点,插入失败\n");
                    }

                    p_dNode = (DlNode*)malloc(sizeof(DlNode));
                    p_dNode->data = insert_data;
                    dList_insert_beforeList(&head_dList,q_dNode,p_dNode);
                    printf("插入成功\n");
                    break;
                case 'C':
                    //销毁
                    dList_destroy(&head_dList);
                    printf("销毁成功\n");
                    break;
                case 'D':
                //先确定要删除的节点存在再删除
                    printf("请输入要删除的节点属性值:");
                    scanf("%d",&delete_data);
                    if(dList_find(head_dList,delete_data)){
                        dList_delete(&head_dList,delete_data);
                        printf("删除成功\n");
                    }else{
                        printf("未找到该节点,删除失败\n");
                    }
                    // 删除
                    break;
                case 'E':
                    printf("请输入要查找的节点属性值:");
                    scanf("%d",&find_data);
                    if(dList_find(head_dList,find_data)){
                        printf("节点存在\n");
                    }else{
                        printf("查找失败\n");
                    }
                    break;

                    // 查找
                case 'F':
                    // 遍历
                    dList_display(head_dList);
                    break;        
                default:
                    break;
                }
                }
            //若检测到回车键则执行光标所在操作
            else if(c=='\r'){   
                if(sel==dListMenuLength) return;
                char c = 'A'+sel-1;

                switch (c)
                {
                case 'A':
                    //生成
                    printf("请输入要生成的链表长度:");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++){
                        printf("请输入第%d个节点的值:",i+1);
                        scanf("%d",&data[i]);
                    }
                    dList_create(&head_dList,data,n);
                    printf("链表已生成\n");
                    break;
                case 'B':
                    //插入
                    printf("请输入要插入在哪个节点的前面,输入那个节点的属性值:");
                    scanf("%d",&p_data);
                    printf("请输入要插入的节点的值:");
                    scanf("%d",&insert_data);
                    //先找到插入的节点位置,再新建插入节点
                    if(dList_find(head_dList,p_data)){
                        q_dNode = head_dList;
                        while(q_dNode->data!=p_data) q_dNode = q_dNode->next;

                    }else{
                        printf("未找到该节点,插入失败\n");
                    }

                    p_dNode = (DlNode*)malloc(sizeof(DlNode));
                    p_dNode->data = insert_data;
                    dList_insert_beforeList(&head_dList,q_dNode,p_dNode);
                    printf("插入成功\n");
                    break;
                case 'C':
                    //销毁
                    dList_destroy(&head_dList);
                    printf("销毁成功\n");
                    break;
                case 'D':
                //先确定要删除的节点存在再删除
                    printf("请输入要删除的节点属性值:");
                    scanf("%d",&delete_data);
                    if(dList_find(head_dList,delete_data)){
                        dList_delete(&head_dList,delete_data);
                        printf("删除成功\n");
                    }else{
                        printf("未找到该节点,删除失败\n");
                    }
                    // 删除
                    break;
                case 'E':
                    printf("请输入要查找的节点属性值:");
                    scanf("%d",&find_data);
                    if(dList_find(head_dList,find_data)){
                        printf("节点存在\n");
                    }else{
                        printf("查找失败\n");
                    }
                    break;

                    // 查找
                case 'F':
                    // 遍历
                    dList_display(head_dList);
                    break;        
                default:
                    break;
                }
            }

            else if (c=='Q'){
                return;
            }
            //延缓光标移动速度
            Sleep(60);
            Sleep(40);
        }
    }
}

//已经没有报错了,开始写函数
//整个函数的作用在头文件里有写
void sList_create(Slist * L,int data[],int length){
    
    if(*L==NULL&&length>0){
        //完成三指针,一节点局面
        Slist p1 = (Slist)malloc(sizeof(SlNode));
        p1->data = data[0];
        Slist p2 = p1;
        *L = p1;
    for(int i=1;i<length;i++){
        //注意链表最后的next为NULL
        p1 = (Slist)malloc(sizeof(SlNode));
        p1->data = data[i];
        p2->next = p1;
        p2 = p1;
        if(i==length-1) p1->next = NULL;
        
    }
    }else{
        printf("链表已存在或者数组长度过短");
    }
}

void sList_insert(SlNode *p,SlNode *q){
    //先用p1存p->next,再p连q,q连p1
    SlNode *p1 = p->next;
    p->next = q;
    q->next = p1;
}

int sList_find(Slist L,ElemType data){
    //遍历链表,找到data返回1,没找到返回0
    Slist p = L;
    while(p!=NULL){
        if(p->data==data){
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void sList_destroy(Slist * L){
    //遍历链表,把每个节点释放,p遍历,q销毁
    Slist p = *L;
    Slist q = NULL;
    while(p!=NULL){
        q = p->next;
        free(p);
        p = q;
    }
    *L = NULL;
}

void sList_display(Slist L){
    if(L==NULL) printf("链表为空");
    Slist p = L;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//原来是我没写删除函数!!!!
void sList_delete(Slist* L,ElemType data){
    //遍历链表,找到data所在节点,分三种情况,表头,表中,表尾
    Slist p = *L;
    Slist p1;
    //能进入这个函数的一定都是能找到的
    while(p->data!=data) {
        p1 = p;
        p = p->next;
        }
    
    if(p==*L){
        //表头
        *L = (*L)->next;
        free(p);
    }else if (p->next==NULL){
            //表尾
        p1->next = NULL;
        free(p);
    }else{
        //表中
        p1->next = p->next;
        free(p);
    }

}

void dList_create(Dlist* L,ElemType data[],int length){
    //三指针,一节点
    Dlist p1 = (Dlist)malloc(sizeof(DlNode));
    Dlist p2 = p1;
    *L = p1;
    p1->data = data[0];
    p1->front = NULL;
    for(int i=1;i<length;i++){
        p1 = (Dlist)malloc(sizeof(DlNode));
        p1->data = data[i];
        //相比多了这一步
        p1->front = p2;
        p2->next = p1;
        p2 = p1;
        if(i==length-1) p1->next = NULL;
    }
    
}

void dList_display(Dlist L){
    //跟单链表一样
    Dlist p = L;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int dList_find(Dlist L,ElemType data){
    //遍历链表,找到返回1,找不到返回0
    Dlist p = L;
    while(p!=NULL){
        if(p->data==data) return 1;
        p = p->next;
    }
    return 0;
}

void dList_insert_beforeList(Dlist *L,DlNode *p,DlNode *q){
    //插在p节点的前面,三个节点重建联系,分情况,p在表头,不在表头
    if(p==*L){
        //p在表头
        q->next = p;
        q->front = NULL;
        p->front = q;
        *L = q;
    }else{
        //p不在表头
    DlNode *p1 = p->front;
    p->front = q;
    q->next = p;
    q->front = p1;
    p1->next = q;
    }
}
void dList_destroy(Dlist *L){
    //跟单链表一样,获取头结点,遍历链表,全部释放,最后头结点回空
    Dlist p1 = *L;
    while(p1!=NULL){
        Dlist p2 = p1->next;
        free(p1);
        p1 = p2;
    }
    *L = NULL;
}

void dList_delete(Dlist *L,ElemType data){
    //遍历链表,找到data所在节点,分三种情况,表头,表中,表尾
    Dlist p = *L;

    //能进入这个函数的一定都是能找到的
    while(p->data!=data)  p = p->next;
        
    
    if(p==*L){
        //表头
        *L = (*L)->next;
        (*L)->front = NULL;
        free(p);
    }else if (p->next==NULL){
            //表尾
        p->front->next = NULL;
        free(p);
    }else{
        //表中
        p->front->next = p->next;
        p->next->front = p->front;
        free(p);
    }

}