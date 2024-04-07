/*
 * @Author: Sangby
 * @Date: 2024-04-06 00:49:34
 * @LastEditors: Sangby
 * @LastEditTime: 2024-04-07 16:05:24
 * @FilePath: \forth_week\src\main.cpp
 * @Description: ������ҵ
 *
 * Copyright (c) 2024 by $, All Rights Reserved.
 */
#include "../inc/binary_sort_tree.h"

/**
 * @description: �жϴ�����ַ����Ƿ�Ϊ������
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
 * @description: ��ʾ�ڵ��ֵ
 * @param {NodePtr} node
 * @return {*}
 */
void show(NodePtr node)
{
    if(node==NULL) return;
    printf("%d\n", node->value);
    
}
int main(){
    //��ʼ��������
    BinarySortTreePtr Bst = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    BST_init(Bst);
    //��������ʼֵ,51782364
    cout<<"��������ʼֵ,5372468"<<endl;
    int a[10]={5,3,7,2,4,6,8};
    for(int i=0;i<7;i++){
        BST_insert(Bst,a[i]);
    }
char input[100];
    char choice;
    while (true)
    {
        
        cout << ">>================<<" << endl;
        cout << "  | -1.ɾ���ڵ�   " << endl;
        cout << "  | 0.��ʼ��������   " << endl;
        cout << "  | 1.�������� " << endl;
        cout << "  | 2.��������   " << endl;
        cout << "  | 3.ǰ������ݹ�   " << endl;
        cout << "  | 4.��������ݹ�   " << endl;
        cout << "  | 5.��������ݹ�   " << endl;
        cout << "  | 6.ǰ������ǵݹ�   " << endl;
        cout << "  | 7.��������ǵݹ�   " << endl;
        cout << "  | 8.��������ǵݹ�   " << endl;
        cout << "  | 9.�������   " << endl;
        cout << "  | 10.�˳�   " << endl;


        cout << ">>================<<" << endl;
        while (true)
        {
            cout << "������ѡ�";
            fgets(input, 100, stdin);
            // ȡ���س�
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
                    cout << "��������ȷ����!" << endl;
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
            //ɾ���ڵ�
           char input[100];
            int data;
            while(true){
            cout << "������Ҫɾ�������ݣ�";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            if(is_int(input))  {
                data = atoi(input);
                break;
            }
            else{
                cout<<"�����봿����!"<<endl;
                continue;
            }
        }
            if(BST_delete(Bst,data)){
                cout<<"ɾ���ɹ�"<<endl;
            }
            else{
                cout<<"������ǿյ�,ɾ��ʧ��"<<endl;
            }
            break;
        case '0':
        //��ʼ��
            BST_init(Bst);
            cout<< "��ʼ���ɹ�"<<endl;
            break;
        case '1':
            
            while(true){
            cout << "������Ҫ���ҵ����ݣ�";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            if(is_int(input))  {
                data = atoi(input);
                break;
            }
            else{
                cout<<"�����봿����!"<<endl;
                continue;
            }
                }
            if(BST_search(Bst,data)){
                cout<<"�ҵ���"<<endl;
                }
            else{
                cout<<"û�ҵ�"<<endl;
            }
            break;
        case '2':
        //��������
            
            while(true){
            cout << "������Ҫ��������ݣ�";
            fgets(input, 100, stdin);
            // ȡ���س�
            input[strlen(input) - 1] = '\0';
            if(is_int(input))  {
                data = atoi(input);
                break;
            }
            else{
                cout<<"�����봿����!"<<endl;
                continue;
            }
                }
            if(BST_insert(Bst,data)){
                cout<<"����ɹ�"<<endl;
            }else{
                cout<<"��Ҫ�����Ѵ��ڵ�ֵ,����ʧ��"<<endl;
            }
            break;

        case '3':
        // ǰ������ݹ�
            BST_preorderR(Bst->root,show);
            break;
        case '4':
            // ��������ݹ�
            BST_inorderR(Bst->root,show);
            break;
        case '5':
              // ��������ݹ�
            BST_postorderR(Bst->root,show);
            break;
            
        case '6':
            //ǰ������ǵݹ�
            BST_preorderI(Bst->root,show);
            break;
        case '7':
            //��������ǵݹ�
            BST_inorderI(Bst->root,show);
            break;
        case '8':
            //��������ǵݹ�
            BST_postorderI(Bst->root,show);
            break;
        case '9':
            //�������
            BST_levelOrder(Bst,show);
            break;
        case 'Q':
            return 0;
            }
        
        }
    }


/**
 * @description: �������ĳ�ʼ��
 * @param {BinarySortTreePtr} Bst
 * @return {*}
 */
Status BST_init(BinarySortTreePtr Bst)
{
    Bst->root = NULL;
    return true;
}

/**
 * @description: ���������ӽڵ�
 * @param {BinarySortTreePtr} Bst
 * @param {ElemType} data
 * @return {*}
 */
Status BST_insert(BinarySortTreePtr Bst, ElemType data)
{
   Node* temp = Bst->root;
    // �����½ڵ�
    NodePtr node = (NodePtr)malloc(sizeof(Node));
    node->value = data;
    // ������ڵ�Ϊ�գ���ֱ�Ӳ���
    if (Bst->root == NULL)
    {
        Bst->root = node;
        node->left = NULL;
        node->right = NULL;
        return succeed;
    }
    else
    {
        // ��ʱ�ڵ㲻Ϊ��,��ʵ���Ҹо���дtrueҲû����
        while (temp != NULL)
        {
            // ����ȽϽڵ�С�ڲ�������,����
            if (temp->value < data)
            {
                // ����ұ߸պ�Ϊ��,ֱ�ӽ���
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
                // ͬ��
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
            //���ֵ��ͬ�����ʧ��
            else{
                return false;
            }
        }
    }
}

Status BST_delete(BinarySortTreePtr Bst, ElemType data)
{
    // �ȴ���������,�ֳ�����������
    if (Bst->root == NULL)
    {
        return false;
    }
    else if (Bst->root->value == data)
    {
        // ������ڵ����Ҫɾ���Ľڵ�
        // ���ж��Ƿ���Ҷ�ӽڵ�
        if (Bst->root->left == NULL && Bst->root->right == NULL)
        {
            // ֱ��ɾ��
            Bst->root = NULL;
            return true;
        }
        // �ж��Ƿ�ֻ��һ���ӽڵ�
        else if ((Bst->root->left == NULL && Bst->root->right != NULL) || (Bst->root->left != NULL && Bst->root->right == NULL))
        {
            // ���������
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
            // �ж��Ƿ��������ӽڵ�
        else
        {
            // ��ֱ��ǰ��
            // ��ڵ�û���ҽ��
            if (Bst->root->left->right == NULL)
            {
                Bst->root->value = Bst->root->left->value;
                Bst->root->left = NULL;
            }
            // ��ڵ����ҽ��
            else
            {
                Node *temp1 = Bst->root->left;
                // �ҵ�ֱ��ǰ���ĸ��ڵ�
                while (temp1->right->right != NULL){
                    temp1 = temp1->right;
                }
                Bst->root->value = temp1->right->value;
                temp1->right = NULL;
            }
            return true;
            }
        }
    
           
    

    // ʣ�������������������ؿվ�˵��ɾ����ֵ������
    Node *parent_temp = BST_search_return_parent_node(Bst, data);
    Node *temp = NULL;

    // �ж��Ƿ����ɾ����ֵ�ڲ���
    if (parent_temp == NULL)
    {
        return false;
    }
    else
    {
        // ��ȡҪɾ��ֵ�Ľ��ָ��
        if (parent_temp->left->value == data)
            temp = parent_temp->left;
        else if (parent_temp->right->value == data)
            temp = parent_temp->right;
        // ���Ҫɾ���Ľ����Ҷ�ӽ��
        if (temp->left == NULL && temp->right == NULL)
        {
            // ����ýڵ�������
            if (data == parent_temp->left->value)
            {
                parent_temp->left = NULL;
            }
            else
            {
                parent_temp->right = NULL;
            }
        }
        // ���Ҫɾ���Ľ��ֻ��һ���ӽڵ�
        else if ((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL))
        {
            // ���������
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
        // ���Ҫɾ���Ľ�������ҽ��
        else
        {
            // ��ֱ��ǰ��
            // ��ڵ�û���ҽ��
            if (temp->left->right == NULL)
            {
                temp->value = temp->left->value;
                temp->left = NULL;
            }
            // ��ڵ����ҽ��
            else
            {
                Node *temp1 = temp->left;
                // �ҵ�ֱ��ǰ���ĸ��ڵ�
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
 * @description: ����ĳ��ֵ�Ƿ�����ڶ�������
 * @return {*}
 */
Status BST_search(BinarySortTreePtr Bst, ElemType data)
{
    Node *temp = Bst->root;
    // ������ڵ�Ϊ��,ֱ�ӷ���false
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        // ����ѭ�����ֲ���
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
        // ���û�ҵ�
        return false;
    }
}

/**
 * @description: ����ĳ��ֵ�ĸ����,���û�и��ڵ��ֻ�и��ڵ���Ҳ���,�򷵻�NULL
 * @param {BinarySortTreePtr} Bst
 * @param {ElemType} data
 * @return {*}
 */
Node *BST_search_return_parent_node(BinarySortTreePtr Bst, ElemType data)
{
    Node *temp1 = Bst->root;
    Node *temp2 = NULL;
    // ������ڵ�Ϊ��,ֱ�ӷ���false
    if (temp1 == NULL)
    {
        return NULL;
    }
    else
    {
        // ����ѭ�����ֲ���
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
        // ���û�ҵ�
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
    //��ջ
    int top = -1;
    Node* stack[100];
    
    
    
    while(temp||top>=0){
        while(temp){
            //�����������нڵ���ջ
            visit(temp);
            stack[++top] = temp;
            temp = temp->left;
        }
        //����ջ��Ԫ��
        temp = stack[top--];
        //ת��������
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
            //������������ջ
            stack[++top] = temp;
            temp = temp->left;
        }
        //����ջ��
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
        //����ջ��Ԫ��ѹ��ڶ���ջ
        temp = stack1[top1--];

        stack2[++top2] = temp;
        //��ѹ��,��ѹ��
        if(temp->left){
            stack1[++top1] = temp->left;
        }
        if(temp->right){
            stack1[++top1] = temp->right;
        }
        
    }
    //��ʱ�ڶ���ջ�б�����Ǻ��������˳��,�����ǰ���������һ�ֽⷨ,ֻ�ǰ����Һ���
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
        //����һ���ڵ㲢����
        temp = queue[front++];
        visit(temp);
        //����ýڵ���������,�����ӽڵ����
        if(temp->left!=NULL){
            queue[rear++] = temp->left;
        }
        //����ýڵ���������,�����ӽڵ����
        if(temp->right!=NULL){
            queue[rear++] = temp->right;
        }
    }
}