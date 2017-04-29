#include <iostream>

using namespace std;

class StackNode
{
public:
    char data;
    StackNode *link;
    StackNode(char a,StackNode *next=NULL):data(a),link(next) {}
    StackNode(StackNode *ptr=NULL)
    {
        link=ptr;
    }
    //~StackNode();
};
class LinkedStack
{
private:
    StackNode *top;
public:
    LinkedStack():top(NULL) {}
    //~LinkedStack(){makeEmpty();}
    void push(char &x)
    {
        top = new StackNode(x,top);
    }
    void input()
    {
        char a;
        cin>>a;
        while(a!='#')
        {
            push(a);
            cin>>a;
        }
    }
    char Pop()
    {
        char x;
        StackNode *p=top;
        //top=top->link;
        x=p->data;
        top=top->link;
        //cout<<x;
        delete p;
        return x;
    }
    char getTop()
    {
        char x;
        x=top->data;
        return x;
    }
    void makeEmpty()
    {
        StackNode *p;
        while(top!=NULL)
        {
            p=top;
            top=top->link;
            delete p;
        }
    }
    void output()
    {
        StackNode *p=top;
        //char a;
        while(p!=NULL)
        {
            cout<<p->data<<endl;
            p=p->link;
        }
    }
    bool IsEmpty()
    {
        return (top==NULL)?true:false;
    }
};
int matching(char a,char b)
{

    if(a=='('&&b==')')return 1;
    else if(a=='['&&b==']')return 1;
    else if(a=='<'&&b=='>')return 1;
    else if(a=='{'&&b=='}')return 1;
    else return 0;
}
int main()
{
    LinkedStack list1,list2;
    char a[20],b,c[10];
    int numb=0,i,temp,d[10],t=0,j=0,k=0;
    cin>>b;
    while(b!='#')
    {
        a[numb]=b;
        cin>>b;
        numb++;
    }
    for (i=0; i<numb; i++)
    {
        //cout<<"dasd";
        if(a[i]=='('||a[i]=='<'||a[i]=='['||a[i]=='{')
        {
            list1.push(a[i]);
            t++;
        }
        else if (a[i]==')'||a[i]=='>'||a[i]==']'||a[i]=='}')
        {
            k++;
            if(list1.IsEmpty())//待会要讨论当栈为空时
            {
                cout<<"The "<<i+1<<" character '"<<a[i]<<"' is wrong."<<endl;
                break;
            }
            else//栈不空
            {
                b=list1.Pop();
                if(matching(b , a[i]))//1 ,chenggong 0 shibaise
                {
                    j++;
                }
                else
                {
                    cout<<"The "<<i+1<<" character '"<<a[i]<<"' is wrong."<<endl;
                    break;
                }
            }
            //cout<<b;

        }
    }
    if(t==j&&t==k)
    {
        cout<<"right"<<endl;
    }
    else if (t>j)
    {
        cout<<"loss of right character ";
        while(t-j)
        {
            if(list1.getTop()=='{')
            {
                b=list1.Pop();
                cout<<'}';
            }
            else if(list1.getTop()=='(')
            {
                b=list1.Pop();
                cout<<')';
            }
            else if(list1.getTop()=='<')
            {
                b=list1.Pop();
                cout<<'>';
            }
            else if(list1.getTop()=='[')
            {
                b=list1.Pop();
                cout<<']';
            }
            t--;
        }
        cout<<'.'<<endl;
    }
    //list1.input();
    list1.output();
    return 0;
}
