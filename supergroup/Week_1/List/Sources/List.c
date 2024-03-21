#include"List.h"
int main(){
    //�˵�1
    while(1){
        char sel;
        printf("ʹ��˵��:���ð��س�ֱ�Ӱ����ּ��ɽ�����Ӧ����\n");
        printf("================\n\n");
        printf("1.������\n");
        printf("2.˫������\n");
        printf("3.�˳�\n\n");
        printf("================\n");
        printf("���������ѡ��:");

        sel = getch();
        printf("\n");

        switch(sel){
            case '1':
            //���뵥����
            entry_sList();
            break;

            case '2':
            //����˫������
            entry_dList();
            break; 

            case '3':
            //�˳�
            return 0;
            break;

            default:
            printf("��������,����������\n");
            break;
        }
    }
    


    
}

//���ܲ˵�->������
void displaymenu_sList(int hilight){
    int i;
    //��������һ�����Ĵ���,ά�����鷳,�´β�����
    printf("ʹ��˵��:ֱ�Ӽ�����ĸ(�����ִ�Сд),���߹���ƶ�����Ӧλ�ú�س�\n����������int\n\n");
    printf("\n************************************************\n");
    printf("**      ƽƽ����ĵ�һ����ҵϵͳ->������      **\n");
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

//���ܲ˵�
void displaymenu_dList(int hilight){
    int i;
    printf("ʹ��˵��:ֱ�Ӽ�����ĸ(�����ִ�Сд),���߹���ƶ�����Ӧλ�ú�س�\n\n");
    printf("\n************************************************\n");
    printf("**     ƽƽ����ĵ�һ����ҵϵͳ->˫������     **\n");
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

//������ϵͳ���
void entry_sList(){
//�һ���switch�ﲻ�ܶ������,����ȫ���ó���
    int n;
    int data[100];
    int p_data;
    int insert_data;
    int delete_data;
    int find_data;

    //�ճ�ʹ�ýڵ�
SlNode* p_sNode=NULL;
SlNode* q_sNode=NULL;


//�������ͷ���
SlNode* head_sList=NULL;

    char c=' ';
    int sel = 1;
    displaymenu_sList(sel);
    while(1){
        if(kbhit()){    
        //�������·��������
            //����⵽���������ˢ��ҳ��,�������
            if(GetAsyncKeyState(VK_UP)){    
                sel = (sel>1)?sel-1:sel;
                system("cls");
                displaymenu_sList(sel);
                
            }
            //����⵽���������ˢ��ҳ��,�������
            if (GetAsyncKeyState(VK_DOWN))
                {
                sel = (sel<sListMenuLength)?sel+1:sel;
                system("cls");
                displaymenu_sList(sel);
                }
                
            //���ܼ�����ĸ(���ûس�),�жϺ�ת��Ϊ����,��������ĳ����
            c=getch();
            if(c<='z'&&c>='a') c = c-('a'-'A');
            if(c<='F'&&c>='A'){
                sel = c-'A'+1;
                system("cls");
                displaymenu_sList(sel);
                switch (c)
                {
                case 'A':
                    //����,��¼������,��¼����
                    
                    printf("������Ҫ���ɵ�������:");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++){
                        printf("�������%d���ڵ��ֵ:",i+1);
                        scanf("%d",&data[i]);
                    }

                    sList_create(&head_sList,data,n);
                    printf("�������ɹ�!\n");
                    break;
                case 'B':
                    //����,Ҫ���ҵ�Ŀ�Ľڵ�,�����½ڵ�,�ٵ��÷���
                    

                    printf("������Ҫ�������ĸ��ڵ�ĺ���,�����Ǹ��ڵ������ֵ:");
                    scanf("%d",&p_data);
                    //�Ȳ���û������ڵ�,û��ֱ������,����ȥȡ����
                    if(sList_find(head_sList,p_data)){
                        p_sNode = head_sList;
                        while(p_sNode != NULL){
                            if(p_sNode->data == p_data){
                                break;
                            }
                            p_sNode = p_sNode->next;
                        }
                    }else{
                        printf("������û������ڵ�!\n");
                        break;
                    }
                    
                    printf("������Ҫ����Ľڵ��ֵ:");
                    scanf("%d",&insert_data);
                    q_sNode = (SlNode*)malloc(sizeof(SlNode));
                    q_sNode->data = insert_data;

                    sList_insert(p_sNode,q_sNode);

                        printf("����ɹ�!\n");
                    
                    break;
                case 'C':
                    //����
                    sList_destroy(&head_sList);
                    printf("���ٳɹ�!\n");
                    break;
                case 'D':
                    //ɾ��
                    printf("������Ҫɾ���Ľڵ�����ֵ:");
                    scanf("%d",&delete_data);
                    //���ж��Ƿ��������ڵ�
                    if(sList_find(head_sList,delete_data)){
                        
                    }else{
                        printf("û������ڵ�\n");
                        break;
                    }
                    sList_delete(&head_sList,delete_data);
                    //ÿ�γ��������궼дһ���ɹ�����
                        printf("ɾ���ɹ�!\n");
                    
                    break;
                case 'E':
                    printf("������Ҫ���ҵĽڵ�����ֵ:");
                    scanf("%d",&find_data);
                    if(sList_find(head_sList,find_data)){
                        printf("�ڵ����!\n");

                    }else{
                        printf("�ڵ㲻����\n");

                    }
                    break;

                    // ����
                case 'F':
                    // ����
                    sList_display(head_sList);
                    break;
                default:
                    break;
                }
                }
            //����⵽�س�����ִ�й�����ڲ���
            else if(c=='\r'){   
                if(sel==sListMenuLength) return;
                char c = 'A'+sel-1;

                switch (c)
                {
                case 'A':
                    //����,��¼������,��¼����
                    
                    printf("������Ҫ���ɵ�������:");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++){
                        printf("�������%d���ڵ��ֵ:",i+1);
                        scanf("%d",&data[i]);
                    }

                    sList_create(&head_sList,data,n);
                    printf("�������ɹ�!\n");
                    break;
                case 'B':
                    //����,Ҫ���ҵ�Ŀ�Ľڵ�,�����½ڵ�,�ٵ��÷���
                    

                    printf("������Ҫ�������ĸ��ڵ�ĺ���,�����Ǹ��ڵ������ֵ:");
                    scanf("%d",&p_data);
                    //�Ȳ���û������ڵ�,û��ֱ������,����ȥȡ����
                    if(sList_find(head_sList,p_data)){
                        p_sNode = head_sList;
                        while(p_sNode != NULL){
                            if(p_sNode->data == p_data){
                                break;
                            }
                            p_sNode = p_sNode->next;
                        }
                    }else{
                        printf("������û������ڵ�!\n");
                        break;
                    }
                    
                    printf("������Ҫ����Ľڵ��ֵ:");
                    scanf("%d",&insert_data);
                    q_sNode = (SlNode*)malloc(sizeof(SlNode));
                    q_sNode->data = insert_data;

                    sList_insert(p_sNode,q_sNode);

                        printf("����ɹ�!\n");
                    
                    break;
                case 'C':
                    //����
                    sList_destroy(&head_sList);
                    printf("���ٳɹ�!\n");
                    break;
                case 'D':
                    //ɾ��
                    printf("������Ҫɾ���Ľڵ�����ֵ:");
                    scanf("%d",&delete_data);
                    //���ж��Ƿ��������ڵ�
                    if(sList_find(head_sList,delete_data)){
                        
                    }else{
                        printf("û������ڵ�\n");
                        break;
                    }
                    sList_delete(&head_sList,delete_data);
                    //ÿ�γ��������궼дһ���ɹ�����
                        printf("ɾ���ɹ�!\n");
                    
                    break;
                case 'E':
                    printf("������Ҫ���ҵĽڵ�����ֵ:");
                    scanf("%d",&find_data);
                    if(sList_find(head_sList,find_data)){
                        printf("�ڵ����!\n");

                    }else{
                        printf("�ڵ㲻����\n");

                    }
                    break;

                    // ����
                case 'F':
                    // ����
                    sList_display(head_sList);
                    break;
                default:
                    break;
                }
            }

            else if (c=='Q'){
                return;
            }
            //�ӻ�����ƶ��ٶ�
            Sleep(60);
            Sleep(40);
        }
    }
}

// ˫������ϵͳ���
void entry_dList(){
    int n;
    int data[100];
    int p_data;
    int insert_data;
    int delete_data;
    int find_data;

//�ճ�ʹ�ýڵ�

DlNode* q_dNode=NULL;
DlNode* p_dNode=NULL;


//˫�������ͷ���
DlNode* head_dList=NULL;

    char c=' ';
    int sel = 1;
    displaymenu_dList(sel);
    while(1){
        if(kbhit()){    
        //�������·��������
            //����⵽���������ˢ��ҳ��,�������
            if(GetAsyncKeyState(VK_UP)){    
                sel = (sel>1)?sel-1:sel;
                system("cls");
                displaymenu_dList(sel);
                
            }
            //����⵽���������ˢ��ҳ��,�������
            if (GetAsyncKeyState(VK_DOWN))
                {
                sel = (sel<dListMenuLength)?sel+1:sel;
                system("cls");
                displaymenu_dList(sel);
                }
                
            //���ܼ�����ĸ(���ûس�),�жϺ�ת��Ϊ����,��������ĳ����
            c=getch();
            if(c<='z'&&c>='a') c = c-('a'-'A');
            if(c<='F'&&c>='A'){
                sel = c-'A'+1;
                system("cls");
                displaymenu_dList(sel);
                switch (c)
                {
                case 'A':
                    //����
                    printf("������Ҫ���ɵ�������:");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++){
                        printf("�������%d���ڵ��ֵ:",i+1);
                        scanf("%d",&data[i]);
                    }
                    dList_create(&head_dList,data,n);
                    printf("����������\n");
                    break;
                case 'B':
                    //����
                    printf("������Ҫ�������ĸ��ڵ��ǰ��,�����Ǹ��ڵ������ֵ:");
                    scanf("%d",&p_data);
                    printf("������Ҫ����Ľڵ��ֵ:");
                    scanf("%d",&insert_data);
                    //���ҵ�����Ľڵ�λ��,���½�����ڵ�
                    if(dList_find(head_dList,p_data)){
                        q_dNode = head_dList;
                        while(q_dNode->data!=p_data) q_dNode = q_dNode->next;

                    }else{
                        printf("δ�ҵ��ýڵ�,����ʧ��\n");
                    }

                    p_dNode = (DlNode*)malloc(sizeof(DlNode));
                    p_dNode->data = insert_data;
                    dList_insert_beforeList(&head_dList,q_dNode,p_dNode);
                    printf("����ɹ�\n");
                    break;
                case 'C':
                    //����
                    dList_destroy(&head_dList);
                    printf("���ٳɹ�\n");
                    break;
                case 'D':
                //��ȷ��Ҫɾ���Ľڵ������ɾ��
                    printf("������Ҫɾ���Ľڵ�����ֵ:");
                    scanf("%d",&delete_data);
                    if(dList_find(head_dList,delete_data)){
                        dList_delete(&head_dList,delete_data);
                        printf("ɾ���ɹ�\n");
                    }else{
                        printf("δ�ҵ��ýڵ�,ɾ��ʧ��\n");
                    }
                    // ɾ��
                    break;
                case 'E':
                    printf("������Ҫ���ҵĽڵ�����ֵ:");
                    scanf("%d",&find_data);
                    if(dList_find(head_dList,find_data)){
                        printf("�ڵ����\n");
                    }else{
                        printf("����ʧ��\n");
                    }
                    break;

                    // ����
                case 'F':
                    // ����
                    dList_display(head_dList);
                    break;        
                default:
                    break;
                }
                }
            //����⵽�س�����ִ�й�����ڲ���
            else if(c=='\r'){   
                if(sel==dListMenuLength) return;
                char c = 'A'+sel-1;

                switch (c)
                {
                case 'A':
                    //����
                    printf("������Ҫ���ɵ�������:");
                    scanf("%d",&n);
                    for(int i = 0;i<n;i++){
                        printf("�������%d���ڵ��ֵ:",i+1);
                        scanf("%d",&data[i]);
                    }
                    dList_create(&head_dList,data,n);
                    printf("����������\n");
                    break;
                case 'B':
                    //����
                    printf("������Ҫ�������ĸ��ڵ��ǰ��,�����Ǹ��ڵ������ֵ:");
                    scanf("%d",&p_data);
                    printf("������Ҫ����Ľڵ��ֵ:");
                    scanf("%d",&insert_data);
                    //���ҵ�����Ľڵ�λ��,���½�����ڵ�
                    if(dList_find(head_dList,p_data)){
                        q_dNode = head_dList;
                        while(q_dNode->data!=p_data) q_dNode = q_dNode->next;

                    }else{
                        printf("δ�ҵ��ýڵ�,����ʧ��\n");
                    }

                    p_dNode = (DlNode*)malloc(sizeof(DlNode));
                    p_dNode->data = insert_data;
                    dList_insert_beforeList(&head_dList,q_dNode,p_dNode);
                    printf("����ɹ�\n");
                    break;
                case 'C':
                    //����
                    dList_destroy(&head_dList);
                    printf("���ٳɹ�\n");
                    break;
                case 'D':
                //��ȷ��Ҫɾ���Ľڵ������ɾ��
                    printf("������Ҫɾ���Ľڵ�����ֵ:");
                    scanf("%d",&delete_data);
                    if(dList_find(head_dList,delete_data)){
                        dList_delete(&head_dList,delete_data);
                        printf("ɾ���ɹ�\n");
                    }else{
                        printf("δ�ҵ��ýڵ�,ɾ��ʧ��\n");
                    }
                    // ɾ��
                    break;
                case 'E':
                    printf("������Ҫ���ҵĽڵ�����ֵ:");
                    scanf("%d",&find_data);
                    if(dList_find(head_dList,find_data)){
                        printf("�ڵ����\n");
                    }else{
                        printf("����ʧ��\n");
                    }
                    break;

                    // ����
                case 'F':
                    // ����
                    dList_display(head_dList);
                    break;        
                default:
                    break;
                }
            }

            else if (c=='Q'){
                return;
            }
            //�ӻ�����ƶ��ٶ�
            Sleep(60);
            Sleep(40);
        }
    }
}

//�Ѿ�û�б�����,��ʼд����
//����������������ͷ�ļ�����д
void sList_create(Slist * L,int data[],int length){
    
    if(*L==NULL&&length>0){
        //�����ָ��,һ�ڵ����
        Slist p1 = (Slist)malloc(sizeof(SlNode));
        p1->data = data[0];
        Slist p2 = p1;
        *L = p1;
    for(int i=1;i<length;i++){
        //ע����������nextΪNULL
        p1 = (Slist)malloc(sizeof(SlNode));
        p1->data = data[i];
        p2->next = p1;
        p2 = p1;
        if(i==length-1) p1->next = NULL;
        
    }
    }else{
        printf("�����Ѵ��ڻ������鳤�ȹ���");
    }
}

void sList_insert(SlNode *p,SlNode *q){
    //����p1��p->next,��p��q,q��p1
    SlNode *p1 = p->next;
    p->next = q;
    q->next = p1;
}

int sList_find(Slist L,ElemType data){
    //��������,�ҵ�data����1,û�ҵ�����0
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
    //��������,��ÿ���ڵ��ͷ�,p����,q����
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
    if(L==NULL) printf("����Ϊ��");
    Slist p = L;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//ԭ������ûдɾ������!!!!
void sList_delete(Slist* L,ElemType data){
    //��������,�ҵ�data���ڽڵ�,���������,��ͷ,����,��β
    Slist p = *L;
    Slist p1;
    //�ܽ������������һ���������ҵ���
    while(p->data!=data) {
        p1 = p;
        p = p->next;
        }
    
    if(p==*L){
        //��ͷ
        *L = (*L)->next;
        free(p);
    }else if (p->next==NULL){
            //��β
        p1->next = NULL;
        free(p);
    }else{
        //����
        p1->next = p->next;
        free(p);
    }

}

void dList_create(Dlist* L,ElemType data[],int length){
    //��ָ��,һ�ڵ�
    Dlist p1 = (Dlist)malloc(sizeof(DlNode));
    Dlist p2 = p1;
    *L = p1;
    p1->data = data[0];
    p1->front = NULL;
    for(int i=1;i<length;i++){
        p1 = (Dlist)malloc(sizeof(DlNode));
        p1->data = data[i];
        //��ȶ�����һ��
        p1->front = p2;
        p2->next = p1;
        p2 = p1;
        if(i==length-1) p1->next = NULL;
    }
    
}

void dList_display(Dlist L){
    //��������һ��
    Dlist p = L;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int dList_find(Dlist L,ElemType data){
    //��������,�ҵ�����1,�Ҳ�������0
    Dlist p = L;
    while(p!=NULL){
        if(p->data==data) return 1;
        p = p->next;
    }
    return 0;
}

void dList_insert_beforeList(Dlist *L,DlNode *p,DlNode *q){
    //����p�ڵ��ǰ��,�����ڵ��ؽ���ϵ,�����,p�ڱ�ͷ,���ڱ�ͷ
    if(p==*L){
        //p�ڱ�ͷ
        q->next = p;
        q->front = NULL;
        p->front = q;
        *L = q;
    }else{
        //p���ڱ�ͷ
    DlNode *p1 = p->front;
    p->front = q;
    q->next = p;
    q->front = p1;
    p1->next = q;
    }
}
void dList_destroy(Dlist *L){
    //��������һ��,��ȡͷ���,��������,ȫ���ͷ�,���ͷ���ؿ�
    Dlist p1 = *L;
    while(p1!=NULL){
        Dlist p2 = p1->next;
        free(p1);
        p1 = p2;
    }
    *L = NULL;
}

void dList_delete(Dlist *L,ElemType data){
    //��������,�ҵ�data���ڽڵ�,���������,��ͷ,����,��β
    Dlist p = *L;

    //�ܽ������������һ���������ҵ���
    while(p->data!=data)  p = p->next;
        
    
    if(p==*L){
        //��ͷ
        *L = (*L)->next;
        (*L)->front = NULL;
        free(p);
    }else if (p->next==NULL){
            //��β
        p->front->next = NULL;
        free(p);
    }else{
        //����
        p->front->next = p->next;
        p->next->front = p->front;
        free(p);
    }

}