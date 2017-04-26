#include <iostream>

using namespace std;
typedef int E;              //�ߵ�Ȩֵ ����������
typedef char T;          //����ֵ ����������
class Edge {
public://�߽��Ķ���
    int dest;			//�����±�
   	int cost;			//���ϵ�Ȩֵ
   	Edge *link=NULL;		 //��һ������ָ��
   	Edge () {}			//���캯��
};
class Vertex {
public://����Ķ���
    char data;		 //�����ֵ
	Edge  *adj;	 //�������ͷָ��
};
class Graphlnk {
private:
    Vertex  *NodeTable; //����� (���������ͷ���)
    int numVertices;
	int maxVertices;
	int getVertexPos (const char vertx)
	{
        //��������vertex��ͼ�е�λ��
	    for (int i = 0; i < numVertices; i++)
	        if (NodeTable[i].data == vertx ) return i;
 	    return -1;
	}
public:
    Graphlnk (int sz);  //���캯��
   	~Graphlnk(){
	for (int i = 0; i < numVertices; i++ ) {
	    Edge *p = NodeTable[i].adj;
        while (p != NULL) {
          NodeTable[i].adj = p->link;
        delete p;  p = NodeTable[i].adj;
        }
   	}
   	delete [ ]NodeTable;  	};	   //��������
	int getWeight (int v1, int v2);	     //ȡ��(v1,v2)Ȩֵ
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
	//���캯��������һ���յ��ڽӱ�
    maxVertices = sz;
    numVertices = 0;
    NodeTable = new Vertex[maxVertices]; //�������������
    for (int i = 0; i < maxVertices; i++)
       NodeTable[i].adj = NULL;

};
int Graphlnk::getFirstNeighbor (int v) {
//��������λ��Ϊ v �ĵ�һ���ڽӶ����λ��,
//����Ҳ���, ��������-1
    if (v != -1) {//����v����
         Edge *p = NodeTable[v].adj;						//��Ӧ�������һ���߽��
	    if (p != NULL) return p->dest;//����, ���ص�һ���ڽӶ���
   	}
   	return -1;
};
int Graphlnk::getNextNeighbor (int v, int w) {
//��������v���ڽӶ���w����һ���ڽӶ����λ��,
//��û����һ���ڽӶ���, ��������-1
    if (v != -1) {				//����v����
        Edge *p = NodeTable[v].adj;
        while (p != NULL && p->dest != w)
            p = p->link;
	    if (p != NULL && p->link != NULL)
            return p->link->dest; //����next Neighbor
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
    cout <<G.getValue(v) << ' ';      //���ʶ���v
    visited[v] = true;	 	      //�����ʱ��
    int w = G.getFirstNeighbor (v);  //��һ���ڽӶ���
   	while (w != -1) {	                //���ڽӶ���w����
 	    if ( !visited[w] ) DFSS(G, w, visited);
	    w = G.getNextNeighbor (v, w); //��һ���ڽӶ���
    }
};
void DFS(Graphlnk& G, char& v) {
//�Ӷ���v������ͼG����������ȱ�����������
    int i, loc, n = 7;    //�������
    bool *visited = new bool[n];          //������������
   	for (i = 0; i < n; i++) visited [i] = false;
      				      //��������visited��ʼ��
	loc = 0; //ȡ����ʼ�����±�
    DFSS(G, loc, visited); //�Ӷ���v��ʼ�����������
   	delete [] visited;			        //�ͷ�visited
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
