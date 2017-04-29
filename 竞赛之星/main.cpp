#include "stdlib.h"
#include "iostream"
using namespace std ;
class List; //前视定义,否则友元无法定义
class LinkNode
{
 friend class  List; //链表结点类的定义
 private:
   LinkNode *link;
   char data;
 public:
   LinkNode (LinkNode *ptr = NULL)    {link=ptr;}
   LinkNode(const char & item, LinkNode *ptr = NULL){  data=item;link=ptr;}
   ~LinkNode(){}
};

class List
{//单链表类的定义
private:
    LinkNode *first; //指向首结点的指针
public:
    List ( ) { first = new LinkNode ( );}   // 带头结点
    ~List (){MakeEmpty();}         //析构函数
    void MakeEmpty ( );      //链表置空
     LinkNode * getHead() const {return first;}

    void input(char  endTag);
    void output();
	void process(List B,List C);
};
void List:: MakeEmpty ( )
 {
    LinkNode *q;
    while (  first->link != NULL )
	{q = first->link;
     first->link = q->link;//将表头结点后第一个结点从链中摘下
     delete q;        //释放它
    }
};
void List :: input (char endTag){
	LinkNode  *newnode; char val;
	cin>>val;
	while(val!=endTag)
	{
		newnode=new LinkNode (val);
  	    newnode->link=first->link;
		first->link=newnode;
		cin>>val;
	}
}
void List ::output ( )  {//依次输出各结点的值
    LinkNode  *p=first->link;
    while(p!=NULL)    {
      cout<<p->data;
      p=p->link;
      }
}
void List ::process(List B,List C){
    char val;
    int nub=0,cot;
    LinkNode *p1,*p2,*p3,*newnode;
    p1=first;
    while(p1->link!=NULL)  //对链表逐个检查
    {
        p2=B.first->link;
        nub=0;
        cot=0;
        while(p2!=NULL)  //A中的元素与B中一个一个比较
        {
            if(p1->link->data==p2->data) //如果有数据一样则 nub=1，break
            {
                nub=1;
                break;
            }
            p2=p2->link;   //如果没有一样的 则继续访问下一个节点
        }
        if(nub==1)   //如果nub=1  则B表中有与A表相同的，则继续从C表中看是否有相同元素
        {
            p3=C.first->link;
            while(p3!=NULL)
            {
                if(p1->link->data==p3->data)
                {
                    cot=1;
                    break;
                }
                p3=p3->link;
            }
        }
        else;   //B表中没有与没有A表中一样的数据
        if(cot==1);
        else          //nub！=1 所以cot=0 A没有与B表中相同，nub=1，cot！=1或没有与C表中相同
        {
            //p1->link=p1->link->link;
            newnode=p1->link;
            p1->link=newnode->link;
            delete newnode;
        }
        p1=p1->link;
    }

}
int main()
{
	List A,B,C ;
    A.input('0');
	B.input('1');
	C.input('2');
	A.process(B,C);
	A.output();
        cout<<endl;
       return 0;
}
