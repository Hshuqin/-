#include <iostream>
#include <stdlib.h>
using namespace std;
class List;
class LinkNode
{
    friend class List;
private:
    int data;
    LinkNode *link;
public:
    LinkNode(LinkNode *ptr = NULL){ link = ptr;}
    LinkNode(const int item,LinkNode *ptr=NULL)
    {
        data=item;
        link=ptr;
    }
};
class List
{
public:List()
    {
        first = new LinkNode;
    }
    List(const int x)
    {
        first = new LinkNode(x);
    }
    void onput()
    {
        LinkNode *current = first->link;
        while(current != NULL)
        {
            cout<<current->data<<endl;
            current=current->link;
        }

    }
     void input(int a)
    {
        LinkNode *newnode;
        int val,i=0;
        while(a!=i){
            cin>>val;
            i++;
            newnode = new LinkNode(val);
            newnode->link=first->link;
            first->link=newnode;
        }
    }

    void Insert(int i,int x)
    {
        LinkNode *p = Locate(i);
        LinkNode *newNode = new LinkNode(x);
        newNode->link = p->link;
        p->link = newNode;

    }
    LinkNode *Locate(int i)
    {
        LinkNode *current = first;
        int k=0;
        while(current !=NULL &&k<i)
        {
            current = current->link;
            k++;
        }
        return current;
    }
    int getData(int i)
    {
        int a;
        LinkNode *current = Locate(i);
        a = current->data;
        return a;
    }
    int Length()
    {
        LinkNode *p = first->link;
        int count=0;
        while(p!=NULL)
        {
            p=p->link;
            count++;
        }
        return count;
    }
    void Sort()
    {
        LinkNode *p,*s;
        int temp;
        p=first->link;
        s=p->link;
        while(p!=NULL)
        {
            s=p->link;
            while(s!=NULL)
            {
                    if(p->data >= s->data)
                    {
                        temp=p->data;
                        p->data=s->data;
                        s->data=temp;
                    }
                    s=s->link;

            }
            p=p->link;
        }

    }
private:
    LinkNode *first;
};
int main()
{
    List list1,list2;
    int a,b,length1,length2,data1,data2,count;
    cin>>a;
    list1.input(a);
    cin>>b;
    list2.input(b);
    length1 = list1.Length();
    length2 = list2.Length();

    for(int t=1;t<=length2;t++)
        {
            count=0;
            data2=list2.getData(t);

            for (int i=1;i<=length1;i++)
            {
                data1=list1.getData(i);

                if(data1==data2)
                {
                    count=1;
                    break;
                }

            }
            if(count==1);
            else
            {
                list1.Insert(length1,data2);

                length1++;
            }
        }
    list1.Sort();
    list1.onput();

    return 0;
}
