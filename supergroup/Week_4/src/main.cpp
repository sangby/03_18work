/*
 * @Author: Sangby
 * @Date: 2024-04-06 00:49:34
 * @LastEditors: Sangby
 * @LastEditTime: 2024-04-07 16:05:24
 * @FilePath: \forth_week\src\main.cpp
 * @Description: 大组作业
 *
 * Copyright (c) 2024 by $, All Rights Reserved.
 */
#include "../inc/binary_sort_tree.h"

/**
 * @description: 判断传入的字符串是否为纯数字
 * @param {char} *a
 * @return {*}
 */
int is_int(char *a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] < '0' || a[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}
/**
 * @description: 显示节点的值
 * @param {NodePtr} node
 * @return {*}
 */
void show(NodePtr node)
{
    if(node==NULL) return;
    printf("%d\n", node->value);
    
}
int main(){
    //初始化二叉树
    BinarySortTreePtr Bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    BST_init(Bst);
    //二叉树初始值,51782364
    cout<<"二叉树初始值,5372468"<<endl;
    int a[10]={5,3,7,2,4,6,8};
    for(int i=0;i<7;i++){
        BST_insert(Bst,a[i]);
    }
char input[100];
    char choice;
    while (true)
    {
        
        cout << ">>================<<" << endl;
        cout << "  | -1.删除节点   " << endl;
        cout << "  | 0.初始化二叉树   " << endl;
        cout << "  | 1.查找数据 " << endl;
        cout << "  | 2.插入数据   " << endl;
        cout << "  | 3.前序遍历递归   " << endl;
        cout << "  | 4.中序遍历递归   " << endl;
        cout << "  | 5.后序遍历递归   " << endl;
        cout << "  | 6.前序遍历非递归   " << endl;
        cout << "  | 7.中序遍历非递归   " << endl;
        cout << "  | 8.后序遍历非递归   " << endl;
        cout << "  | 9.层序遍历   " << endl;
        cout << "  | 10.退出   " << endl;


        cout << ">>================<<" << endl;
        while (true)
        {
            cout << "请输入选项：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';

            if (strlen(input) == 1)
            {
                if (input[0] >= '0' && input[0] <= '9')
                {
                    system("cls");

                    choice = input[0];
                    break;
                }
                else
                {
                    cout << "请输入正确序数!" << endl;
                }
            }
            else if(strlen(input)==2)
            {
                if(input[0]=='1'&&input[1]=='0'){
                    system("cls");
                    choice='Q';
                    break;
                }
                if(input[0]=='-'&&input[1]=='1'){
                    system("cls");
                    choice='w';
                    break;
                }
            }
        }
        
        switch (choice)
        {
        case 'w':
            //删除节点
           char input[100];
            int data;
            while(true){
            cout << "请输入要删除的数据：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            if(is_int(input))  {
                data = atoi(input);
                break;
            }
            else{
                cout<<"请输入纯数字!"<<endl;
                continue;
            }
        }
            if(BST_delete(Bst,data)){
                cout<<"删除成功"<<endl;
            }
            else{
                cout<<"或许表是空的,删除失败"<<endl;
            }
            break;
        case '0':
        //初始化
            BST_init(Bst);
            cout<< "初始化成功"<<endl;
            break;
        case '1':
            
            while(true){
            cout << "请输入要查找的数据：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            if(is_int(input))  {
                data = atoi(input);
                break;
            }
            else{
                cout<<"请输入纯数字!"<<endl;
                continue;
            }
                }
            if(BST_search(Bst,data)){
                cout<<"找到了"<<endl;
                }
            else{
                cout<<"没找到"<<endl;
            }
            break;
        case '2':
        //插入数据
            
            while(true){
            cout << "请输入要插入的数据：";
            fgets(input, 100, stdin);
            // 取出回车
            input[strlen(input) - 1] = '\0';
            if(is_int(input))  {
                data = atoi(input);
                break;
            }
            else{
                cout<<"请输入纯数字!"<<endl;
                continue;
            }
                }
            if(BST_insert(Bst,data)){
                cout<<"插入成功"<<endl;
            }else{
                cout<<"不要输入已存在的值,插入失败"<<endl;
            }
            break;

        case '3':
        // 前序遍历递归
            BST_preorderR(Bst->root,show);
            break;
        case '4':
            // 中序遍历递归
            BST_inorderR(Bst->root,show);
            break;
        case '5':
              // 后序遍历递归
            BST_postorderR(Bst->root,show);
            break;
            
        case '6':
            //前序遍历非递归
            BST_preorderI(Bst->root,show);
            break;
        case '7':
            //中序遍历非递归
            BST_inorderI(Bst->root,show);
            break;
        case '8':
            //后序遍历非递归
            BST_postorderI(Bst->root,show);
            break;
        case '9':
            //层序遍历
            BST_levelOrder(Bst,show);
            break;
        case 'Q':
            return 0;
            }
        
        }
    }


/**
 * @description: 二叉树的初始化
 * @param {BinarySortTreePtr} Bst
 * @return {*}
 */
Status BST_init(BinarySortTreePtr Bst)
{
    Bst->root = NULL;
    return true;
}

/**
 * @description: 二叉树增加节点
 * @param {BinarySortTreePtr} Bst
 * @param {ElemType} data
 * @return {*}
 */
Status BST_insert(BinarySortTreePtr Bst, ElemType data)
{
   Node* temp = Bst->root;
    // 创建新节点
    NodePtr node = (NodePtr)malloc(sizeof(Node));
    node->value = data;
    // 如果根节点为空，则直接插入
    if (Bst->root == NULL)
    {
        Bst->root = node;
        node->left = NULL;
        node->right = NULL;
        return succeed;
    }
    else
    {
        // 临时节点不为空,事实上我感觉这写true也没问题
        while (temp != NULL)
        {
            // 如果比较节点小于插入数据,往右
            if (temp->value < data)
            {
                // 如果右边刚好为空,直接接入
                if (temp->right == NULL)
                {
                    temp->right = node;
                    node->left = NULL;
                    node->right = NULL;
                    return succeed;
                }

                else
                {
                    temp = temp->right;
                }
            }
            else if(temp->value > data)
            {
                // 同理
                if (temp->left == NULL)
                {
                    temp->left = node;
                    node->left = NULL;
                    node->right = NULL;
                    return succeed;
                }
                else 
                {
                    temp = temp->left;
                }
            }
            //如果值相同则插入失败
            else{
                return false;
            }
        }
    }
}

Status BST_delete(BinarySortTreePtr Bst, ElemType data)
{
    // 先打两个补丁,分出两个类讨论
    if (Bst->root == NULL)
    {
        return false;
    }
    else if (Bst->root->value == data)
    {
        // 如果根节点就是要删除的节点
        // 先判断是否是叶子节点
        if (Bst->root->left == NULL && Bst->root->right == NULL)
        {
            // 直接删除
            Bst->root = NULL;
            return true;
        }
        // 判断是否只有一个子节点
        else if ((Bst->root->left == NULL && Bst->root->right != NULL) || (Bst->root->left != NULL && Bst->root->right == NULL))
        {
            // 左空则右有
            if (Bst->root->left == NULL)
            {
                Bst->root->value = Bst->root->right->value;
                Bst->root->right = NULL;
            }
            else{
                Bst->root->value = Bst->root->left->value;
                Bst->root->left = NULL;
            }
            return true;
            }
            // 判断是否有两个子节点
        else
        {
            // 找直接前驱
            // 左节点没有右结点
            if (Bst->root->left->right == NULL)
            {
                Bst->root->value = Bst->root->left->value;
                Bst->root->left = NULL;
            }
            // 左节点有右结点
            else
            {
                Node *temp1 = Bst->root->left;
                // 找到直接前驱的父节点
                while (temp1->right->right != NULL){
                    temp1 = temp1->right;
                }
                Bst->root->value = temp1->right->value;
                temp1->right = NULL;
            }
            return true;
            }
        }
    
           
    

    // 剩下这种情况如果方法返回空就说明删除的值不存在
    Node *parent_temp = BST_search_return_parent_node(Bst, data);
    Node *temp = NULL;

    // 判断是否这个删除的值在不在
    if (parent_temp == NULL)
    {
        return false;
    }
    else
    {
        // 获取要删除值的结点指针
        if (parent_temp->left->value == data)
            temp = parent_temp->left;
        else if (parent_temp->right->value == data)
            temp = parent_temp->right;
        // 如果要删除的结点是叶子结点
        if (temp->left == NULL && temp->right == NULL)
        {
            // 如果该节点是左结点
            if (data == parent_temp->left->value)
            {
                parent_temp->left = NULL;
            }
            else
            {
                parent_temp->right = NULL;
            }
        }
        // 如果要删除的结点只有一个子节点
        else if ((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL))
        {
            // 左空则右有
            if (temp->left == NULL)
            {
                temp->value = temp->right->value;
                temp->right = NULL;
            }
            else
            {
                temp->value = temp->left->value;
                temp->left = NULL;
            }
        }
        // 如果要删除的结点有左右结点
        else
        {
            // 找直接前驱
            // 左节点没有右结点
            if (temp->left->right == NULL)
            {
                temp->value = temp->left->value;
                temp->left = NULL;
            }
            // 左节点有右结点
            else
            {
                Node *temp1 = temp->left;
                // 找到直接前驱的父节点
                while (temp1->right->right != NULL)
                {
                    temp1 = temp1->right;
                }
                temp->value = temp1->right->value;
                temp1->right = NULL;
            }
        }
    }
}

/**
 * @description: 查找某个值是否存在于二叉树中
 * @return {*}
 */
Status BST_search(BinarySortTreePtr Bst, ElemType data)
{
    Node *temp = Bst->root;
    // 如果根节点为空,直接返回false
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        // 开启循环二分查找
        while (temp != NULL)
        {
            if (temp->value > data)
            {
                temp = temp->left;
            }
            else if (temp->value < data)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        // 如果没找到
        return false;
    }
}

/**
 * @description: 返回某个值的父结点,如果没有根节点或只有根节点或找不到,则返回NULL
 * @param {BinarySortTreePtr} Bst
 * @param {ElemType} data
 * @return {*}
 */
Node *BST_search_return_parent_node(BinarySortTreePtr Bst, ElemType data)
{
    Node *temp1 = Bst->root;
    Node *temp2 = NULL;
    // 如果根节点为空,直接返回false
    if (temp1 == NULL)
    {
        return NULL;
    }
    else
    {
        // 开启循环二分查找
        while (temp1 != NULL)
        {
            if (temp1->value > data)
            {
                temp2 = temp1;
                temp1 = temp1->left;
            }
            else if (temp1->value < data)
            {
                temp2 = temp1;
                temp1 = temp1->right;
            }
            else
            {
                return temp2;
            }
        }
        // 如果没找到
        return NULL;
    }
}

Status BST_preorderR(Node* node, void (*visit)(NodePtr))
{
    Node* temp = node;
    if (temp == NULL)
    {
        return false;
    }
    visit(temp);
    BST_preorderR(temp->left,visit);
    BST_preorderR(temp->right,visit); 
}

Status BST_inorderR(Node* node, void (*visit)(NodePtr))
{
    Node* temp = node;
    if (temp == NULL)
    {
        return false;
    }   
    BST_inorderR(temp->left,visit);
    visit(temp);
    BST_inorderR(temp->right,visit); 
}

Status BST_postorderR(Node* node, void (*visit)(NodePtr)){
    Node* temp = node;
    if (temp == NULL)
    {
        return false;
    }
    BST_postorderR(temp->left,visit);
    BST_postorderR(temp->right,visit); 
    visit(temp);

}

Status BST_preorderI(Node* node, void (*visit)(NodePtr)){
    Node*temp = node;
    if(node==NULL) return false;
    //入栈
    int top = -1;
    Node* stack[100];
    
    
    
    while(temp||top>=0){
        while(temp){
            //将左子树所有节点入栈
            visit(temp);
            stack[++top] = temp;
            temp = temp->left;
        }
        //弹出栈顶元素
        temp = stack[top--];
        //转向右子树
        temp = temp->right;
        
    }
}
Status BST_inorderI(Node* node, void (*visit)(NodePtr)){
    Node* temp = node;
    if(temp == NULL) return false;
    Node* stack[100];
    int top = -1;

    stack[++top]=temp;
    temp = temp->left;
    while(temp||top>=0){
        while(temp){
            //所有左子树入栈
            stack[++top] = temp;
            temp = temp->left;
        }
        //弹出栈顶
        temp = stack[top--];
        visit(temp);
        temp = temp->right;
    }
    return true;
}

Status BST_postorderI(Node* node, void (*visit)(NodePtr)){
    Node* temp = node;
    if(node==NULL) return false;
    int top1 = -1,top2 = -1;
    Node* stack1[100];
    Node* stack2[100];
    
    stack1[++top1] = temp;
    while(top1>=0){
        //弹出栈顶元素压入第二个栈
        temp = stack1[top1--];

        stack2[++top2] = temp;
        //先压左,再压右
        if(temp->left){
            stack1[++top1] = temp->left;
        }
        if(temp->right){
            stack1[++top1] = temp->right;
        }
        
    }
    //此时第二个栈中保存的是后序遍历的顺序,这就是前序遍历的另一种解法,只是把左右孩子
    while(top2>=0){
        visit(stack2[top2--]);
    }
}

Status BST_levelOrder(BinarySortTreePtr Bst, void (*visit)(NodePtr)){
    Node* temp = Bst->root;
    if(temp==NULL) return false;
    Node *queue[100];
    int front = 0,rear = 0;

    queue[rear++] = temp;
    while(front<rear){
        //出队一个节点并访问
        temp = queue[front++];
        visit(temp);
        //如果该节点有左子树,则左子节点入队
        if(temp->left!=NULL){
            queue[rear++] = temp->left;
        }
        //如果该节点有右子树,则右子节点入队
        if(temp->right!=NULL){
            queue[rear++] = temp->right;
        }
    }
}