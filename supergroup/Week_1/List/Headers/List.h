#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

//�����������
typedef int ElemType;

// �����˵��ĳ���
int dListMenuLength=8;
int sListMenuLength=8;

//������Ľ��
typedef struct SlNode{
    ElemType data;
    struct SlNode* next;
}SlNode,*Slist;
//˫������Ľ��
typedef struct DlNode{
    ElemType data;
    struct DlNode* front;
    struct DlNode* next;
}DlNode,*Dlist;



//������������ܳ���G,h�ǻ���������ͻ��?
char MenuText_sList[8][15]={
    "[A] ����",
    "[B] ����",
    "[C] ����",
    "[D] ɾ��",
    "[E] ����",
    "[F] ������ʾ",
    "[G] ��������",
    "[Q] �˳�"
};

char MenuText_dList[8][15]={
    "[A] ����",
    "[B] ����",
    "[C] ����",
    "[D] ɾ��",
    "[E] ����",
    "[F] ������ʾ",
    "[G] ��������",
    "[Q] �˳�"
};
//����
void entry_sList();

//�����������,��ʼ��һ��������,����Ϊ��������,һ������,���鳤��
void sList_create(Slist* L,int data[],int length);
//������Ĳ���,ʹnode����Ϊp����ֱ�Ӻ�̽��,����Ϊp�ڵ�,q�ڵ�
void sList_insert(SlNode *p,SlNode *q);
//�����������,�ͷ�����������,����,����ָ���ָ��
void sList_destroy(Slist* L);
//�������ɾ��,ɾ��p������һ�����,ɾ���ڵ�
void sList_delete(Slist *L,ElemType n);
//������Ĳ���,��������Ϊn�Ľ��,�������򷵻�1,����0,������������,Ҫ���ҽ�������
int sList_find(Slist L,ElemType n);
//������ı�����ʾ,����ͷ�ڵ�
void sList_display(Slist L);

void entry_dList();
//˫�����������,��������,����˫����
void dList_create(Dlist* L,ElemType data[],int length);
//˫������Ľڵ�ǰ����
void dList_insert_beforeList(Dlist *L,DlNode* p,DlNode* q);
//˫�����������
void dList_destroy(Dlist *L);
//˫�������ɾ��
void dList_delete(Dlist*L,ElemType data);
//˫������Ĳ���
int dList_find(Dlist L,ElemType n);
//˫������ı�����ʾ
void dList_display(Dlist L);

//��ȫ��������Ӧ���ܲ�����
void displaymenu_dList(int hilight);
void displaymenu_sList(int hilight);

//���ڼ�黺�����ﻹ��û�ж���,�Դ�֤�������Ƿ�����
int detect_illegal_input();


//���ײ���
void slist_Advanced_Operating(Slist *L);
void dlist_Advanced_Operating(Dlist *L);
