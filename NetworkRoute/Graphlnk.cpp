#include "Graphlnk.h"


template<class T,class E>
T Graphlnk<T,E>::getValue(int i)					
	{
		if(i>=0 && i< numVertices){
		    return NodeTable[i].data;
		}else{
		    cerr<<"i越界"<<endl;
		}
	}

template<class T,class E>
Graphlnk<T,E>::Graphlnk(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = NULL;
	
	try
	{
		NodeTable = new Vertex<T,E>[maxVertices];
	}
	catch(bad_alloc & memExp)
	{
		cerr<<memExp.what()<<endl;
	}
	for(int i = 0;i<maxVertices;i++)
	{
		NodeTable[i].adj =NULL;
	}
}
template<class T,class E>
Graphlnk<T,E>::~Graphlnk()
{
	for(int i = 0;i<maxVertices;i++)
	{
		Edge<T,E> * p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[] NodeTable;
}

template<class T,class E>
//获取路由器在数组中的位置（序号）
int Graphlnk<T,E>::getVertexPos(const T vertex)
{
	for( int i =0;i<numVertices; i++)
		if(NodeTable[i].data == vertex)
			return i;
	return -1;
}

template<class T,class E>
//获取第一个邻接结点
int Graphlnk<T,E>::getFirstNeighbor(int v)
{
	if(v != -1)
	{
		Edge<T,E> * p = NodeTable[v].adj;
		if( p != NULL) return p->dest;
	}
	return -1;
}


template<class T,class E>
//获取v的除w外的另一个邻接结点
int Graphlnk<T,E>::getNextNeighbor(int v,int w )
{
	if(v != -1)
	{
		Edge<T,E> * p = NodeTable[v].adj;
		while (p!= NULL && p->dest != w)
		{
			p = p->link;
		}
		if( p != NULL && p->link != NULL)
			return p->link->dest;
	}
	return -1;
}

template<class T,class E>
//获得权值
E Graphlnk<T,E>::getWeight(int v1,int v2)
{
	if( v1 != -1 && v2 != -1)
	{
		Edge<T,E> *p = NodeTable[v1].adj;
		while (p!= NULL && p->dest != v2)
		{
			p = p->link;
		}
		if(p != NULL) 
			return p->cost;
		else return maxWeight;
	}
}

template<class T,class E>
//在表尾插入新结点
bool Graphlnk<T,E>::insertVertex(const T vertex)
{
	if(numVertices == maxVertices) return false;
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}
 
template<class T,class E>
//从邻接表中找到被删结点和在这条边上的另一个结点，然后更新数据
bool Graphlnk<T,E>::removeVertex(int v)
{
	if(numVertices == 1|| v<0 || v>=numVertices )return false;
	Edge<T,E> *p,*s,*t;
	int i,k;
	while (NodeTable[v].adj != NULL)   //遍历v的所有邻接边
	{
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;
		t = NULL;
		while(s != NULL && s->dest !=v) //在s的邻接结点的链表中匹配被删节点
		{
			t = s;
			s = s->link;
		}
		if(s != NULL)
		{
			if( t == NULL) NodeTable[k].adj = s->link;   //删掉与被删结点连接的边
			else t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		numEdges--;
	}
	numVertices --;   //接下来处理表尾数据覆盖该结点的一些问题
	NodeTable[v].data = NodeTable[numVertices].data;  //表尾数据覆盖该结点
	p = NodeTable[v].adj = NodeTable[numVertices].adj;   //把表尾数据的链表结点移到该位置
	while (p!= NULL)
	{
		s = NodeTable[p->dest].adj;
		while (s!= NULL){
			if(s ->dest == numVertices){ s->dest = v;break;}
			else s = s->link;
		}
		p = p->link;
	}
	return true;
}

template<class T,class E>
/**插入边
   @v1 -- 起点的序号
   @v2 -- 终点的序号
   @cost -- 路径长度 （权值）
  */
bool Graphlnk<T,E>::insertEdge(int v1, int v2, E cost)     
{
	if(v1 >=0 && v1< numVertices && v2>=0 && v2<numVertices)
	{
		Edge<T,E> *q,*p = NodeTable[v1].adj;
		while (p!=NULL && p->dest != v2)
		{
			p = p->link;
		}
		if(p != NULL ) return false;
		p = new Edge<T,E>;
		q = new Edge<T,E>;
		p->dest = v2;
		p->cost = cost;
		p->link = NodeTable[v1].adj;         //插入到链表头
		NodeTable[v1].adj = p;
		q ->dest = v1;
		q ->cost = cost;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges ++;
		return true;
	}
	return false;
}

template<class T,class E>
//同时在两个结点删掉公共边
bool Graphlnk<T,E>::removeEdge(int v1,int v2)      
{
	if(v1 != -1 &&v2 != -1)
	{
		Edge<T,E> *p = NodeTable[v1].adj, *q = NULL,*s = p;
		while(p!= NULL && p->dest != v2)
		{
			 q = p;
			 p = p->link;
		}
		if(p!= NULL)
		{
			if(p == s)      //被删边是首结点
				NodeTable[v1].adj = p->link;
			else
			{
				 q ->link = p->link;
			}
			delete p;
		}
		else
		{
			return false;
		}
		p = NodeTable[v2].adj;
		q = p;
		s = p;
		while (p->dest !=v1)
		{
			q = p;
			p = p->link;
		}
		if(p == s)
			NodeTable[v2].adj = p->link;
		else
		{
			q->link = p->link;
		}
		delete p;
		return true;
	}
	return false;
}

template<class T,class E>
ostream& operator << (ostream& out,Graphlnk<T,E>& G)
{
	int i,j;
	cout<<"顶点个数为:" << G.NumberOfVertices()<<endl;
	cout<<"边的条数为:" << G.NumberOfEdges()<<endl;	
	cout<<"结点集合为:"<<endl;
	for(i=0;i< G.NumberOfVertices();i++)
		cout<<"     路由器"<<G.getValue(i).name<<"    网络号："<<G.getValue(i).network<<endl;
	cout<<"\n";
	cout<<"路由边集合为:\n";
	for(i=0;i<G.NumberOfVertices();i++)
	{
		for(j=0;j<G.NumberOfVertices();j++)
		{
			if(G.getWeight(i,j)== maxWeight)
				cout<<setw(10)<<"Max";
			else
			cout<<setw(10)<<G.getWeight(i,j);
		}
		cout<<"\n";
	}
	return out;
}


