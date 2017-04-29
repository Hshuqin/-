#include <iostream>
#include <stdlib.h>
using namespace std;
const int DefaultSize = 100;
class Trituple
{
public:
    int row,col,value;
    Trituple &operator = (Trituple &x){
        row=x.row;
        col=x.col;
        value=x.value;
    }
};
class SparseMatrix
{
    friend ostream& operator << (ostream& out,SparseMatrix &M);
    friend ostream& operator >> (ostream& in,SparseMatrix &M);
public:
    SparseMatrix(int maxSz = DefaultSize);//构造函数
    SparseMatrix(SparseMatrix &x);//复制构造函数
    ~SparseMatrix(){
        delete []smArray;   //析构函数
    }
    SparseMatrix &operator = (SparseMatrix &x);
    SparseMatrix Transpose();//对当前稀疏矩阵对象执行转置运算
    SparseMatrix Add(SparseMatrix &b);//当前矩阵与矩阵b想加

    int Rows,Cols,Terms;
    Trituple *smArray;
    int maxTerms;
};
SparseMatrix::SparseMatrix(int maxSz):maxTerms(maxSz)
{
    smArray = new Trituple[maxSz];
    Rows=0;
    Cols=0;
    Terms=0;
};
SparseMatrix::SparseMatrix(SparseMatrix &x)
{
    Rows=x.Rows;
    Cols=x.Cols;
    Terms=x.Terms;
    maxTerms = x.maxTerms;
    smArray=new Trituple[maxTerms];
    for (int i; i<Terms; i++)smArray[i]=x.smArray[i];
};
ostream& operator <<(ostream& out,SparseMatrix &M)
{
    //out<<"The transformed matrix  is:"<<endl;
    for(int i=0; i<M.Terms; i++){
            if(M.smArray[i].value!=0){
        out<<M.smArray[i].row<<" "<<M.smArray[i].col<<" "<<M.smArray[i].value<<endl;
            }
    }
    return out;
};
istream& operator >>(istream& in,SparseMatrix &M)
{
    in>>M.Rows>>M.Cols>>M.Terms;
    for(int i=0; i<M.Terms; i++){
        in>>M.smArray[i].row>>M.smArray[i].col>>M.smArray[i].value;
    }
    return in;
};
SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix b(maxTerms);
    b.Rows=Cols;
    b.Cols=Rows;
    b.Terms=Terms;
    if(Terms>0){
        int k,i,CurrentB=0;
        for(k=0; k<Cols; k++)
            for(i=0; i<Terms; i++)
                if(smArray[i].col==k){
                    b.smArray[CurrentB].row=k;
                    b.smArray[CurrentB].col=smArray[i].row;
                    b.smArray[CurrentB].value=smArray[i].value;
                    CurrentB++;
                }
    }
    cout<<"The transformed matrix  is:"<<endl;
    cout<<b;
    return b;
};
SparseMatrix SparseMatrix::Add(SparseMatrix &b)
{
    SparseMatrix result;
    int i=0,j=0,index_a,index_b;
    result.Terms=0;
    while(i<Terms&&j<b.Terms){
        index_a=Cols*smArray[i].row+smArray[i].col;
        index_b=Cols*b.smArray[j].row+b.smArray[j].col;
        if(index_a<index_b){
            result.smArray[result.Terms]=smArray[i];
            i++;
        }
        else if (index_a>index_b){
            result.smArray[result.Terms]=b.smArray[j];
            j++;
        }
        else{
            result.smArray[result.Terms]=smArray[i];
            result.smArray[result.Terms].value=smArray[i].value+b.smArray[j].value;
            i++;
            j++;
        }
        result.Terms++;
    }
    for(; i<Terms; i++){
        result.smArray[result.Terms]=smArray[i];
        result.Terms++;
    }
    for(; j<b.Terms;j++){
        result.smArray[result.Terms]=b.smArray[j];
        result.Terms++;
    }
    cout<<"The added matrix is:"<<endl;
    cout<<result;
    return result;
};
int main()
{
    SparseMatrix a,b,c;
    cin>>a;
    cin>>b;
    a.Transpose();
    a.Add(b);
    return 0;
}
