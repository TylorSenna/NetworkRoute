#include "Graphlnk.h"


template<class T,class E>
T Graphlnk<T,E>::getValue(int i)					
	{
		if(i>=0 && i< numVertices){
		    return NodeTable[i].data;
		}else{
		    cerr<<"iԽ��"<<endl;
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
//��ȡ·�����������е�λ�ã���ţ�
int Graphlnk<T,E>::getVertexPos(const T vertex)
{
	for( int i =0;i<numVertices; i++)
		if(NodeTable[i].data == vertex)
			return i;
	return -1;
}

template<class T,class E>
//��ȡ��һ���ڽӽ��
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
//��ȡv�ĳ�w�����һ���ڽӽ��
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
//���Ȩֵ
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
//�ڱ�β�����½��
bool Graphlnk<T,E>::insertVertex(const T vertex)
{
	if(numVertices == maxVertices) return false;
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}
 
template<class T,class E>
//���ڽӱ����ҵ���ɾ�������������ϵ���һ����㣬Ȼ���������
bool Graphlnk<T,E>::removeVertex(int v)
{
	if(numVertices == 1|| v<0 || v>=numVertices )return false;
	Edge<T,E> *p,*s,*t;
	int i,k;
	while (NodeTable[v].adj != NULL)   //����v�������ڽӱ�
	{
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;
		t = NULL;
		while(s != NULL && s->dest !=v) //��s���ڽӽ���������ƥ�䱻ɾ�ڵ�
		{
			t = s;
			s = s->link;
		}
		if(s != NULL)
		{
			if( t == NULL) NodeTable[k].adj = s->link;   //ɾ���뱻ɾ������ӵı�
			else t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		numEdges--;
	}
	numVertices --;   //�����������β���ݸ��Ǹý���һЩ����
	NodeTable[v].data = NodeTable[numVertices].data;  //��β���ݸ��Ǹý��
	p = NodeTable[v].adj = NodeTable[numVertices].adj;   //�ѱ�β���ݵ��������Ƶ���λ��
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
/**�����
   @v1 -- �������
   @v2 -- �յ�����
   @cost -- ·������ ��Ȩֵ��
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
		p->link = NodeTable[v1].adj;         //���뵽����ͷ
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
//ͬʱ���������ɾ��������
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
			if(p == s)      //��ɾ�����׽��
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
	cout<<"�������Ϊ:" << G.NumberOfVertices()<<endl;
	cout<<"�ߵ�����Ϊ:" << G.NumberOfEdges()<<endl;	
	cout<<"��㼯��Ϊ:"<<endl;
	for(i=0;i< G.NumberOfVertices();i++)
		cout<<"     ·����"<<G.getValue(i).name<<"    ����ţ�"<<G.getValue(i).network<<endl;
	cout<<"\n";
	cout<<"·�ɱ߼���Ϊ:\n";
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


