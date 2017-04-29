#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int T;
class SeqList
{
public:
    T *data;
    int MaxSize; //˳��������Դ�ŵ�Ԫ�ظ�����
    int last; //˳������һ��Ԫ�ص��±꣬��ʼֵΪ-1��
    SeqList(int sz);
    void Input()//��������Ԫ�صĸ�����Ȼ��˳������Ԫ�ص�ֵ��
    {
        int i;
        cin>>last;
        last--;
        for( i=0;i<=last;i++)
        {
            cin>>data[i];
        }
    }
    void Output()//������Ա������Ԫ�ء�
    {
        cout<<"The elements are:"<<endl;
        int i;
        for(i=0;i<=last;i++)
            cout<<data[i]<<endl;
    }
    void Insert(int x, int i )//�����Ա��е�i��λ�ò���ֵΪx��Ԫ�ء�
    {
        int j;
        for(j=last;j>=i;j--)
        {
            data[j+1]=data[j];
        }
        data[i]=x;
        last++;
    }
    int Remove ( int x )//�����Ա���ɾ����һ��ֵ����x��Ԫ�ء�
    {

        //x=data[i-1];
        for(int j=0;j<=last;j++)
        {
            if(data[j]==x)
            {
                for(int t=j;t<last;t++)
                {
                    data[t]=data[t+1];
                }
                last--;
            }
        }

    }
};
SeqList::SeqList(int sz)
{
    if(sz>0)
    {
        data = new T[sz];
        MaxSize = sz;
        last = -1;
        if(data == NULL)
        {
            cout<<"error!!"<<endl;
            exit(1);
        }
    }

}
int main()
 {
  SeqList myList(100);
  myList.Input();
  myList.Output ();
  int i;
  for( i=0;i<5;i++)
	 myList.Insert(i+10,i);
  myList.Output ();
  for( i=10;i<15;i++)
     myList.Remove(i);
  myList.Output ();
  return 0;
 }
