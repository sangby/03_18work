#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

//结点数据类型
typedef int ElemType;

// 两个菜单的长度
int dListMenuLength=8;
int sListMenuLength=8;

//单链表的结点
typedef struct SlNode{
    ElemType data;
    struct SlNode* next;
}SlNode,*Slist;
//双向链表的结点
typedef struct DlNode{
    ElemType data;
    struct DlNode* front;
    struct DlNode* next;
}DlNode,*Dlist;



//这个东西好像不能超过G,h是会跟方向键冲突的?
char MenuText_sList[8][15]={
    "[A] 生成",
    "[B] 插入",
    "[C] 销毁",
    "[D] 删除",
    "[E] 查找",
    "[F] 遍历显示",
    "[G] 其他操作",
    "[Q] 退出"
};

char MenuText_dList[8][15]={
    "[A] 生成",
    "[B] 插入",
    "[C] 销毁",
    "[D] 删除",
    "[E] 查找",
    "[F] 遍历显示",
    "[G] 其他操作",
    "[Q] 退出"
};
//声明
void entry_sList();

//单链表的生成,初始化一整个链表,参数为操作链表,一个数组,数组长度
void sList_create(Slist* L,int data[],int length);
//单链表的插入,使node结点成为p结点的直接后继结点,参数为p节点,q节点
void sList_insert(SlNode *p,SlNode *q);
//单链表的销毁,释放所有链表结点,参数,链表指针的指针
void sList_destroy(Slist* L);
//单链表的删除,删除p结点的下一个结点,删除节点
void sList_delete(Slist *L,ElemType n);
//单链表的查找,查找属性为n的结点,若存在则返回1,否则0,参数操作链表,要查找结点的数据
int sList_find(Slist L,ElemType n);
//单链表的遍历显示,参数头节点
void sList_display(Slist L);

void entry_dList();
//双向链表的生成,跟上面差不多,就是双向了
void dList_create(Dlist* L,ElemType data[],int length);
//双向链表的节点前插入
void dList_insert_beforeList(Dlist *L,DlNode* p,DlNode* q);
//双向链表的销毁
void dList_destroy(Dlist *L);
//双向链表的删除
void dList_delete(Dlist*L,ElemType data);
//双向链表的查找
int dList_find(Dlist L,ElemType n);
//双向链表的遍历显示
void dList_display(Dlist L);

//不全部声明了应该跑不起来
void displaymenu_dList(int hilight);
void displaymenu_sList(int hilight);

//用于检查缓冲区里还有没有东西,以此证明输入是否正常
int detect_illegal_input();


//进阶操作
void slist_Advanced_Operating(Slist *L);
void dlist_Advanced_Operating(Dlist *L);
