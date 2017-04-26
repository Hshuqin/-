#include <iostream>

using namespace std;
typedef int E;              //边的权值 的数据类型
typedef char T;          //顶点值 的数据类型
class Edge {
public://边结点的定义
    int dest;			//顶点下标
   	int cost;			//边上的权值
   	Edge *link=NULL;		 //下一条边链指针
   	Edge () {}			//构造函数
};
class Vertex {
public://顶点的定义
    char data;		 //顶点的值
	Edge  *adj;	 //边链表的头指针
};
class Graphlnk {
private:
    Vertex  *NodeTable; //顶点表 (各边链表的头结点)
    int numVertices;
	int maxVertices;
	int getVertexPos (const char vertx)
	{
        //给出顶点vertex在图中的位置
	    for (int i = 0; i < numVertices; i++)
	        if (NodeTable[i].data == vertx ) return i;
 	    return -1;
	}
public:
    Graphlnk (int sz);  //构造函数
   	~Graphlnk(){
	for (int i = 0; i < numVertices; i++ ) {
	    Edge *p = NodeTable[i].adj;
        while (p != NULL) {
          NodeTable[i].adj = p->link;
        delete p;  p = NodeTable[i].adj;
        }
   	}
   	delete [ ]NodeTable;  	};	   //析构函数
	int getWeight (int v1, int v2);	     //取边(v1,v2)权值
	bool insertVertex (char vertex,int i);
    bool removeVertex (int v);
    bool insertEdge (int v1, int v2, int cost);
	bool removeEdge (int v1, int v2);
    int getFirstNeighbor (int v);
    int getNextNeighbor (int v, int w);
    /*void DFS(Graphlnk& G, char& v);
    void DFS(Graphlnk& G, int v, bool &visited[]);*/
    char getValue(int v1);
};
Graphlnk::Graphlnk (int sz){
	//构造函数：建立一个空的邻接表
    maxVertices = sz;
    numVertices = 0;
    NodeTable = new Vertex[maxVertices]; //创建顶点表数组
    for (int i = 0; i < maxVertices; i++)
       NodeTable[i].adj = NULL;

};
int Graphlnk::getFirstNeighbor (int v) {
//给出顶点位置为 v 的第一个邻接顶点的位置,
//如果找不到, 则函数返回-1
    if (v != -1) {//顶点v存在
         Edge *p = NodeTable[v].adj;						//对应边链表第一个边结点
	    if (p != NULL) return p->dest;//存在, 返回第一个邻接顶点
   	}
   	return -1;
};
int Graphlnk::getNextNeighbor (int v, int w) {
//给出顶点v的邻接顶点w的下一个邻接顶点的位置,
//若没有下一个邻接顶点, 则函数返回-1
    if (v != -1) {				//顶点v存在
        Edge *p = NodeTable[v].adj;
        while (p != NULL && p->dest != w)
            p = p->link;
	    if (p != NULL && p->link != NULL)
            return p->link->dest; //返回next Neighbor
   	}
   	return -1;
};
bool Graphlnk::insertVertex (char vertex,int i){
	NodeTable[i].data=vertex;
	return 1;
};
bool Graphlnk::insertEdge (int v1,int v2,int cost){
	Edge *temp=new Edge(),*p=new Edge();
	temp->cost=cost;temp->dest=v2;
	while(1){
        if(NodeTable[v1].adj==NULL){
            NodeTable[v1].adj=temp;
            break;
        }
        else{
            p=NodeTable[v1].adj;
            while(p->link!=NULL){
                p=p->link;
            }
            p->link=temp;
            break;
        }
	}
	return 1;
};
void DFSS(Graphlnk& G, int v, bool &visited[]) {
    cout <<G.getValue(v) << ' ';      //访问顶点v
    visited[v] = true;	 	      //作访问标记
    int w = G.getFirstNeighbor (v);  //第一个邻接顶点
   	while (w != -1) {	                //若邻接顶点w存在
 	    if ( !visited[w] ) DFSS(G, w, visited);
	    w = G.getNextNeighbor (v, w); //下一个邻接顶点
    }
};
void DFS(Graphlnk& G, char& v) {
//从顶点v出发对图G进行深度优先遍历的主过程
    int i, loc, n = 7;    //顶点个数
    bool *visited = new bool[n];          //创建辅助数组
   	for (i = 0; i < n; i++) visited [i] = false;
      				      //辅助数组visited初始化
	loc = 0; //取得起始结点的下标
    DFSS(G, loc, visited); //从顶点v开始深度优先搜索
   	delete [] visited;			        //释放visited
};
char Graphlnk::getValue(int v1){
    return NodeTable[v1].data;
};


int main(){
	int num,border,v1,v2,cost;
	int i,j;
	char ver;
	cin>>num;
	Graphlnk Grap(num);
	for(i=0;i<num;i++){
		cin>>ver;
		Grap.insertVertex(ver,i);
	}
	cin>>border;
	for(j=0;j<border;j++){
		cin>>v1>>v2>>cost;
		Grap.insertEdge(v1,v2,cost);
	}

	return 0;
}
