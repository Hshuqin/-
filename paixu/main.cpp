#include "assert.h"
#include <iostream>
using namespace std;
void Sort(int a[],int n){
    int i=0,j=0,k=n-1,temp;
    while(j<=k){
        if(a[j]==1){
            if(a[j]==a[i]){i++;j++;}
            else{
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                cout<<i<<"<--->"<<j<<endl;
                i++;j++;
            }
        }
        else if(a[j]==2) j++;
        else if(a[j]==3){
            if(j==k) k--;
            else{
                temp=a[j];
                a[j]=a[k];
                a[k]=temp;
                cout<<j<<"<--->"<<k<<endl;
                k--;
            }
        }
    }
    for(temp=0;temp<n;temp++){
        cout<<a[temp];
    }
    cout<<endl;
};
int main() {
	int n;
	cin >> n;
	int * a= new int[n];
	for (int i=0;i<n;i++)
		cin>>a[i];
	Sort(a,n);
}
