#include <iostream>
using namespace std;
int numb=0,cot=0,a[10],t=0;
char q[10];
class BinTreeNode{
public:
    char data;
    BinTreeNode *leftChild,*rightChild;
    BinTreeNode():leftChild(NULL),rightChild(NULL){}
    BinTreeNode(char x,BinTreeNode *l=NULL,BinTreeNode *r=NULL):data(x),leftChild(l),rightChild(r){}
};
class BinaryTree{
public:
    BinaryTree():root(NULL){}
    BinaryTree(BinaryTree &s);
    ~BinaryTree(){destroy(root);}
    int Height(BinTreeNode *subTree){
        if(subTree==NULL) return 0;
        else{
            int i=Height(subTree->leftChild);
            int j=Height(subTree->rightChild);
            return (i<j)?j+1:i+1;
        }
    }
    int yejiedian(BinTreeNode *subTree){
            if(subTree->leftChild==NULL&&subTree->rightChild==NULL) return 1;
            else{
                    int i,j;
                    if(subTree->leftChild!=NULL){
                        i=yejiedian(subTree->leftChild);
                    }
                    else i=0;
                    if(subTree->rightChild!=NULL){
                        j=yejiedian(subTree->rightChild);
                    }
                    else j=0;
                    return i+j;
            }
        }
    int Size(BinTreeNode *subTree){
        if(subTree==NULL) return 0;
        else return 1+Size(subTree->leftChild)+Size(subTree->rightChild);
    }
    void CreateBinTree(BinTreeNode *&subTree){// xian xu create
        char data;
        cin >> data;
        if (data!='#'){
            q[cot]=data;
            cot++;
            subTree = new BinTreeNode(data);
            CreateBinTree(subTree->leftChild);
            CreateBinTree(subTree->rightChild);
        }
        else{
            subTree=NULL;
        }
    }
    void destroy(BinTreeNode *subTree){
        if(subTree!=NULL){
            destroy(subTree->leftChild);
            destroy(subTree->rightChild);
            delete subTree;
        }
    }
    void preout(BinTreeNode *subTree){// qian xu shuchu
        if(subTree!=NULL){
            cout<<subTree->data<<" ";
            preout(subTree->leftChild);
            preout(subTree->rightChild);
        }
    }
    void midout(BinTreeNode *subTree){    //zhong xu shuchu
        if(subTree->leftChild!=NULL){
            midout(subTree->leftChild);
            cout<<subTree->data<<" ";
            if(subTree->rightChild!=NULL)
            midout(subTree->rightChild);
        }
        else{
            cout<<subTree->data<<" ";
            if(subTree->rightChild!=NULL){
                midout(subTree->rightChild);
            }
        }
    }
    void postout(BinTreeNode *subTree){   //hou xu shuchu
        if(subTree->leftChild!=NULL){
            postout(subTree->leftChild);
            if(subTree->rightChild!=NULL)
                postout(subTree->rightChild);
            cout<<subTree->data<<" ";
        }
        else{
            if(subTree->rightChild!=NULL){
                postout(subTree->rightChild);
                cout<<subTree->data<<" ";
            }
            else cout<<subTree->data<<" ";
        }
    }
    int Find(BinTreeNode *subTree,char x){
        int temp=0;
        int y,z;
        if(subTree!=NULL){
            if(subTree->data==x){
                temp=1;
            }
            y=Find(subTree->leftChild,x);
            z=Find(subTree->rightChild,x);
            return temp+y+z;
        }
        else return 0;
    }
    int shendu(BinTreeNode *subTree,char x){
        int y=0,z=0;
        if(subTree!=NULL){
            if(subTree->data==x){
               numb=1;
               return 1;
            }
            if(numb==0)
                y=shendu(subTree->leftChild,x);
            if(numb==0)
                z=shendu(subTree->rightChild,x);
            return numb+y+z;
        }
        else return 0;
    }
private:
    BinTreeNode *root;
    char RefValue;
};
int main()
{
    BinaryTree tree;
    BinTreeNode *ptr;
    char x,y;
    cin>>x;
    while(1){
        if(x=='C'){
            tree.CreateBinTree(ptr);
            cout<<"Created success!"<<endl;
            cin>>x;
        }
        else if(x=='H'){
            cout<<"Height="<<tree.Height(ptr)<<"."<<endl;
            cin>>x;
        }
        else if(x=='L'){
            cout<<"Leaf="<<tree.yejiedian(ptr)<<"."<<endl;
            cin>>x;
        }
        else if(x=='N'){
            cout<<"Nodes="<<tree.Size(ptr)<<"."<<endl;
            cin>>x;
        }
        else if(x=='1'){
            cout<<"Preorder is:";
            tree.preout(ptr);
            cout<<"."<<endl;
            cin>>x;
        }
        else if(x=='2'){
            cout<<"Inorder is:";
            tree.midout(ptr);
            cout<<"."<<endl;
            cin>>x;
        }
        else if(x=='3'){
            cout<<"Postorder is:";
            tree.postout(ptr);
            cout<<"."<<endl;
            cin>>x;
        }
        else if(x=='F'){
            cin>>y;
            cout<<"The count of "<<y<<" is "<<tree.Find(ptr,y)<<"."<<endl;
            cin>>x;
        }
        else if(x=='P'){
                cout<<"The tree is:"<<endl;
            for(int i=0;i<tree.Size(ptr);i++){
                a[i]=tree.shendu(ptr,q[i]);
                numb=0;
                for(int j=1;j<a[i];j++)
                    cout<<"  ";
                cout<<q[i]<<endl;
            }
            break;
        }
        else break;
    }
    return 0;
}
