#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class List;
class LinkNode
{
    friend class List;
private:
    int data,exp;
    LinkNode *link;
public:
    LinkNode(LinkNode *ptr = NULL)
    {
        link = ptr;
    }
    LinkNode(const int item,const int e,LinkNode *ptr=NULL)
    {
        exp=e;
        data=item;
        link=ptr;
    }
};
class List
{
public:
    List()
    {
        first = new LinkNode;
    }
    List(const int x,const int e)
    {
        first = new LinkNode(x,e);
    }
    void onput()
    {
        List list1;
        LinkNode *current = first->link;
        LinkNode *p1,*newnode;
        int a,e,t=0;
        p1=list1.first;
        while(current!=NULL)
        {
            a=current->data;
            e=current->exp;
            newnode = new LinkNode(a,e);
            newnode->link=p1->link;
            p1->link=newnode;
            current=current->link;
        }
        cout<<"C(x)=";
        current=list1.first->link;
        while(current != NULL)
        {
            if(current->data<0)//对负数处理，不用加符号
            {
                t++;
                if(current->data==-1)//系数为-1，只加-符号就行
                    cout<<"-";
                else
                {
                    cout<<current->data;//系数不为-1
                }
                if(current->exp==1)//指数为1
                {
                     cout<<"x";
                }
                else if (current->exp==0){}//指数为0，无x
                else              //指数不为1
                {
                    cout<<"x^";
                    cout<<current->exp;
                }
                current=current->link;
            }
            else if( current->data>0) //系数大于0处理，加个+符号
            {
                t++;
                if(t==1)   //对于第一个系数不加符号
                {
                    if(current->data==1);
                    else
                        cout<<current->data;
                    if(current->exp==1)
                        cout<<"x";
                    else if (current->exp==0);
                    else
                    {

                        cout<<"x^";
                        cout<<current->exp;
                    }
                    current=current->link;
                }
                else      //不是第一个系数
                {
                    cout<<"+";
                    if(current->data==1); //系数为1 不处理，不输出data
                    else
                    cout<<current->data;//系数不为1，输出data
                    if(current->exp==1) //指数为1，只输出X
                    {
                        cout<<"x";
                    }
                    else if (current->exp==0){}
                    else             //指数不为1，输出x^
                    {
                        cout<<"x^";
                        cout<<current->exp;
                    }
                    current=current->link;
                }
            }
            else
            current=current->link;
        }
        cout<<endl;

    }
    void input()
    {
        LinkNode *newnode;
        int val,e,i=0;
        while(1)
        {
            cin>>val;
            if(val==0) break;
            cin>>e;
            i++;
            newnode = new LinkNode(val,e);
            newnode->link=first->link;
            first->link=newnode;
        }
    }

    List Sort(List list1)
    {
         LinkNode *p,*s;
         List list2;
         int temp,e;
         p=list1.first->link;
         while(p!=NULL)
         {
             s=p->link;
             while(s!=NULL)
             {
                     if(p->exp < s->exp)
                     {
                         temp=p->data;
                         p->data=s->data;
                         s->data=temp;
                         e=p->exp;
                         p->exp=s->exp;
                         s->exp=e;
                     }
                     else if(p->exp==s->exp)
                     {
                         if(p->exp==0)
                            break;
                         else
                        {
                             p->data=p->data+s->data;
                             s->data=0;
                             s->exp=0;
                        }
                     }
                     else
                        s=s->link;
             }
             p=p->link;
         }
        return list1;
     }
    List Plus(List list1,List list2)
    {
        LinkNode *p4,*p3,*p1,*newnode,*last;
        int a,e;
        List list3,list4;
        //list1 赋值给 list3
        p1=list1.first->link;
        last=list3.first;
        while(p1!=NULL)
        {
            a=p1->data;
            e=p1->exp;
            newnode = new LinkNode(a,e);
            last->link=newnode;
            last = newnode;
            p1=p1->link;
        }
        last->link=NULL;
        //list2 赋值给 list4
        p1=list2.first->link;
        last=list4.first;
        while(p1!=NULL)
        {
            a=p1->data;
            e=p1->exp;
            newnode = new LinkNode(a,e);
            last->link=newnode;
            last = newnode;
            p1=p1->link;
        }
        last->link=NULL;

        p4=list4.first->link;

        while(p4!=NULL)
        {
            //newnode->data = p1->data;
            p3=list3.first->link;
            if(p4->exp > list3.first->link->exp)
            {
                a=p4->data;
                e=p4->exp;
                newnode = new LinkNode(a,e);
                newnode->link=list3.first->link;
                list3.first->link=newnode;
            }
            else
            {
                while(p3!=NULL)
                {
                    if(p4->exp < p3->exp &&p3->link!=NULL && p4->exp > p3->link->exp) //在两者之间，
                    {
                        a=p4->data;
                        e=p4->exp;
                        newnode = new LinkNode(a,e);
                        newnode->link=p3->link;
                        p3->link=newnode;
                        break;
                    }
                    else if(p4->exp < p3->exp && p3->link==NULL) //小于当前的指数，且下一个为空
                    {
                        a=p4->data;
                        e=p4->exp;
                        newnode = new LinkNode(a,e);
                        newnode->link=p3->link;
                        p3->link=newnode;
                        break;
                    }
                    else if(p4->exp == p3->exp) //等于当前的指数
                    {
                        p3->data=p3->data+p4->data;
                        break;
                    }
                    else
                        p3=p3->link;
                }
            }
            p4=p4->link;
            //cout<<p3->data<<endl;
        }

        return list3;
    }
    List Sub(List list1,List list2)
    {
        LinkNode *p4,*p3,*p1,*newnode,*last;
        int a,e;
        List list3,list4;
        p1=list1.first->link;
        last=list3.first;
        while(p1!=NULL)
        {
            a=p1->data;
            e=p1->exp;
            newnode = new LinkNode(a,e);
            last->link=newnode;
            last = newnode;
            p1=p1->link;
        }
        last->link=NULL;
        p1=list2.first->link;
        last=list4.first;
        while(p1!=NULL)
        {
            a=p1->data;
            e=p1->exp;
            newnode = new LinkNode(a,e);
            last->link=newnode;
            last = newnode;
            p1=p1->link;
        }
        last->link=NULL;

        p4=list4.first->link;

        while(p4!=NULL)
        {
            p3=list3.first->link;
            if(p4->exp > list3.first->link->exp)
            {
                a=p4->data;
                e=p4->exp;
                newnode = new LinkNode(-a,e);
                newnode->link=list3.first->link;
                list3.first->link=newnode;
            }
            else
            {
                while(p3!=NULL)
                {
                    if(p4->exp < p3->exp &&p3->link!=NULL && p4->exp > p3->link->exp) //在两者之间，
                    {
                        a=p4->data;
                        e=p4->exp;
                        newnode = new LinkNode(-a,e);
                        newnode->link=p3->link;
                        p3->link=newnode;
                        break;
                    }
                    else if(p4->exp < p3->exp && p3->link==NULL) //小于当前的指数，且下一个为空
                    {
                        a=p4->data;
                        e=p4->exp;
                        newnode = new LinkNode(-a,e);
                        newnode->link=p3->link;
                        p3->link=newnode;
                        break;
                    }
                    else if(p4->exp == p3->exp) //等于当前的指数
                    {
                        p3->data=p3->data-p4->data;
                        break;
                    }
                    else
                        p3=p3->link;
                }
            }
            p4=p4->link;
            //cout<<p3->data<<endl;
        }

        return list3;
    }
    List mul (List list1,List list2)
    {
        LinkNode *p2,*p3,*p1,*newnode;
        int a,e;
        List list3;
        p1=list1.first->link;
        p3=list3.first;
        while(p1!=NULL)
        {
            p2=list2.first->link;
            while(p2!=NULL)
            {
                a=p1->data*p2->data;
                e=p1->exp+p2->exp;
                newnode = new LinkNode(a,e);
                newnode->link=p3->link;
                p3->link=newnode;
                p2=p2->link;
            }
            p1=p1->link;
        }
        return list3;
    }
    List daoshu(List list1)
    {
        LinkNode *p3,*p1,*newnode,*last;
        int a,e;
        List list3;
        p1=list1.first->link;//list1 赋值给 list3
        last=list3.first;
        while(p1!=NULL)
        {
            a=p1->data;
            e=p1->exp;
            newnode = new LinkNode(a,e);
            last->link=newnode;
            last = newnode;
            p1=p1->link;
        }
        last->link=NULL;
        p3=list3.first->link;
        while(p3!=NULL)
        {
            p3->data=p3->data*p3->exp;
            p3->exp=p3->exp-1;
            p3=p3->link;
        }
        return list3;
    }
    float Qiuzhi(float x)
    {
        List list1;
        LinkNode *newnode,*last,*current = first->link;
        int a,e;
        last=list1.first;
        while(current!=NULL)
        {
            a=current->data;
            e=current->exp;
            newnode = new LinkNode(a,e);
            last->link=newnode;
            last = newnode;
            current=current->link;
        }
        last->link=NULL;
        current=list1.first->link;
        float sum=0.0,temp;
        while(current!=NULL)
        {
            temp=1.0;
            while(current->exp!=0)
            {
                temp=temp*x;
                current->exp=current->exp-1;
            }
            sum=sum+current->data*temp;
            current=current->link;
        }
        return sum;
    }
    void makeEmpty()
    {
        LinkNode *q;
        while (first->link!=NULL)
        {
            q=first->link;
            first->link=q->link;
            delete q;
        }
    }
private:
    LinkNode *first;
};
int main()
{
    List list1,list2,list3,list4,list5,list6;
    char a;
    float b;
    cin>>a;
    if(a=='C')
    {
        list1.input();
        list2.input();
    }
    else
        return 0;
    cin>>a;
    while (a!='X')
    {
        if(a=='P')
        {
            list3=list3.Plus(list1,list2);
            list3.onput();
            cin>>a;
        }
        else if(a=='S')
        {
            list4=list4.Sub(list1,list2);
            list4.onput();
            cin>>a;
        }
        else if(a=='M')
        {
            list5=list5.mul(list1,list2);
            list5.Sort(list5);
            list5.onput();
            cin>>a;
        }
        else if (a=='D')
        {
            list6=list6.daoshu(list1);
            list6.onput();
            cin>>a;
        }
        else if (a=='V')
        {
            cin>>b;
            b=list1.Qiuzhi(b);
            printf("%.2f",b);
            cout<<endl;
            cin>>a;
        }
        else if(a=='C')
        {
            list1.makeEmpty();
            list2.makeEmpty();
            list3.makeEmpty();
            list4.makeEmpty();
            list5.makeEmpty();
            list6.makeEmpty();
        }
    }
    return 0;
}
