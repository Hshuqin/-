#include <iostream>
using namespace std;
int icp(char x){
    if(x==42||x==47)return 1;
    else return 0;
};
class BinaryTree;
class BinTreeNode{                                 //�����Ķ���
friend class BinaryTree;
public:
    BinTreeNode ( ) { leftChild =NULL; rightChild =NULL; }
    BinTreeNode ( char x, BinTreeNode *left = NULL, BinTreeNode *right = NULL ) : data (x),  leftChild (left),  rightChild(right) { }               //���캯��
    ~BinTreeNode ( ) { }                                   //��������
private:
    BinTreeNode *leftChild,  *rightChild;   //������Ů����
    char data;                                              //������
};
class BinaryTree{
public:
    BinaryTree(): root (NULL) { }
	void CreateBinTree(BinTreeNode *&subTree){// xian xu create
        char data;
        cin >> data;
        if (data!='@'){
            subTree = new BinTreeNode(data);
            CreateBinTree(subTree->leftChild);
            CreateBinTree(subTree->rightChild);
            }
        else{
           subTree=NULL;
        }
    }
    void midout(BinTreeNode *subTree){    //zhong xu shuchu
        int r=0,l=0;
        if(subTree->leftChild!=NULL){
            midout(subTree->leftChild);
             cout<<subTree->data;
            if(subTree->data<48&&subTree->data>41)
                if(subTree->rightChild!=NULL)
                    if(subTree->rightChild->data<48&&subTree->rightChild->data>41){
                        if(icp(subTree->data)>icp(subTree->rightChild->data)){
                            cout<<"(";
                            r=1;
                        }
                    }
            if(subTree->rightChild!=NULL){
                midout(subTree->rightChild);
                if(r==1){
                    cout<<")";
                    r=0;
                }
            }
        }
        else{
            cout<<subTree->data;
            if(subTree->data<48&&subTree->data>41)
                if(subTree->rightChild!=NULL)
                    if(subTree->rightChild->data<48&&subTree->rightChild->data>41){
                        if(icp(subTree->data)>icp(subTree->rightChild->data)){
                            cout<<"(";
                            r=1;
                        }
                    }
            if(subTree->rightChild!=NULL){
                midout(subTree->rightChild);
                if(r==1){
                cout<<")";
                r=0;
                }
            }
        }
    }
    int Qiuzhi(BinTreeNode *subTree){
        int result;
        if(subTree!=NULL){
            if(subTree->data==42)
                return result=Qiuzhi(subTree->leftChild)*Qiuzhi(subTree->rightChild);
            else if(subTree->data==43)
                return result=Qiuzhi(subTree->leftChild)+Qiuzhi(subTree->rightChild);
            else if(subTree->data==45)
                return result=Qiuzhi(subTree->leftChild)-Qiuzhi(subTree->rightChild);
            else if(subTree->data==47)
                return result=Qiuzhi(subTree->leftChild)/Qiuzhi(subTree->rightChild);
                else
                    return subTree->data-48;
        }
    }
private:
    BinTreeNode  *root;
};
int main()
{
    BinaryTree tree;
    BinTreeNode *sub;
    tree.CreateBinTree(sub);
    tree.midout(sub);
    cout<<"=";
    cout<<tree.Qiuzhi(sub)<<endl;
    return 0;
}
