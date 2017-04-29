#include "stdlib.h"
#include "iostream"
using namespace std ;
class List; //ǰ�Ӷ���,������Ԫ�޷�����
class LinkNode
{
 friend class  List; //��������Ķ���
 private:
   LinkNode *link;
   char data;
 public:
   LinkNode (LinkNode *ptr = NULL)    {link=ptr;}
   LinkNode(const char & item, LinkNode *ptr = NULL){  data=item;link=ptr;}
   ~LinkNode(){}
};

class List
{//��������Ķ���
private:
    LinkNode *first; //ָ���׽���ָ��
public:
    List ( ) { first = new LinkNode ( );}   // ��ͷ���
    ~List (){MakeEmpty();}         //��������
    void MakeEmpty ( );      //�����ÿ�
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
     first->link = q->link;//����ͷ�����һ����������ժ��
     delete q;        //�ͷ���
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
void List ::output ( )  {//�������������ֵ
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
    while(p1->link!=NULL)  //������������
    {
        p2=B.first->link;
        nub=0;
        cot=0;
        while(p2!=NULL)  //A�е�Ԫ����B��һ��һ���Ƚ�
        {
            if(p1->link->data==p2->data) //���������һ���� nub=1��break
            {
                nub=1;
                break;
            }
            p2=p2->link;   //���û��һ���� �����������һ���ڵ�
        }
        if(nub==1)   //���nub=1  ��B��������A����ͬ�ģ��������C���п��Ƿ�����ͬԪ��
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
        else;   //B����û����û��A����һ��������
        if(cot==1);
        else          //nub��=1 ����cot=0 Aû����B������ͬ��nub=1��cot��=1��û����C������ͬ
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
