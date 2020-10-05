#include<iostream>
using namespace std;
//节点
class Node{
    public:
        Node* next;
        int value;
};
//链表
class Linklist{
    public:
        Node* head; //单链表头指针
        int size; //单链表节点个数
        void createLinklist();// 创建单链表,输入一串数字序列，以-1作为结尾
        void selectLinklist();// 打印单链表
        int selectNumOfLinklist();//查询单链表的数量
        void deleteLinklist(int n);//删除第n个节点
        //构造方法和析构方法
        Linklist();
        ~Linklist();
};
//初始化
Linklist::Linklist()
{
    head=new Node;
    size=0;
    head->next=NULL;
    head->value=0;
};
//对象消失时调用的析构方法
Linklist::~Linklist()
{
    delete head;
    printf("game over\n");
};
//创建单链表,输入一串字符串，以-1结尾
void Linklist::createLinklist()
{
    int tmp;
    scanf("%d",&tmp);
    Node* p=head;
    while(tmp!=-1)
    {
        Node* q=new Node;
        q->value=tmp;
        p->next=q;
        p=q;
        size++;
        scanf("%d",&tmp);
    }
    p->next=NULL;
    head->value=size;
};
//打印单链表
void Linklist::selectLinklist()
{
    Node* p=head->next;
    while(p)
    {
        printf("%d ",p->value);
        p=p->next;
    }
    printf("\n");
};
//查询单链表的节点数量
int Linklist::selectNumOfLinklist()
{
    return head->value;
};
//删除单链表的第n个节点
void Linklist::deleteLinklist(int n)
{
    if(n>size)
    {
        printf("不存在该节点\n");
        return;
    }
    Node* p=head->next;
    Node* q;
    while(n--)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    head->value--; 
    size--;

};

int main()
{
    Linklist tmp; //创建单链表对象,不加括号，默认是调用默认构造函数
    int choice;//选项
    /*scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        tmp.createLinklist();
        break;
    case 2:
        tmp.selectLinklist();
        break;
    }
    */

   tmp.createLinklist();
   tmp.selectLinklist();
   tmp.deleteLinklist(4);
   tmp.selectLinklist();
}