#ifndef GRAPH_H
#define GRAPH_H
#include <string>
using namespace std;

const int maxWeight = INT_MAX;
const int DeafultVertices = 30;			//������󶥵��� =n
template<class T,class E>
//�ߵĶ���
struct Edge
{
	int dest;			//�ߵ���һ������λ��
	E cost;				//���ϵ�Ȩֵ
	int EdgeNum;   //�ߵı��
	string EdgeName;  //�ߵ�����
	Edge<T,E> * link;	//��һ������ָ��
	Edge(){cost = maxWeight;}
	Edge(int num,E weight) : dest(num),cost(weight),link(NULL){}
	bool operator != (Edge<T,E>& R)const
	{
		return (dest != R.dest)?true:false;
	}
}; 
template<class T,class E>
//����Ķ���
struct Vertex
{
	T data;			
	Edge<T,E> *adj;			//�������ͷָ��
};
//ͼ�Ķ���
template<class T,class E>
class Graph 
{
public:
	Graph(int sz = DeafultVertices){};
	~Graph(){}
	bool GraphEmpty()const
	{
		if(numEdges == 0 )
			return true;
		else
		{
			return false;
		}
	}
	bool GraphFull()const
	{
		if(numVertices == maxVertices || numEdges == maxVertices * (maxVertices -1 )/2)
			return true;
		else return false;
	}
	int NumberOfVertices(){ return numVertices;}		    //���ص�ǰ������
	int NunberOfEdges() { return numEdges; }			    //���ص�ǰ����
	virtual T getValue(int i ) = 0;							        //ȡ����i������
	virtual E getWeight(int v1,int v2) = 0;					    //ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	virtual int getFirstNeighbor(int v) = 0;				    //ȡ����v�ĵڸ��ڽӶ���
	virtual int getNextNeighbor(int v,int w ) = 0;			//ȡ�ڽӶ���w����һ���ڽӶ���
	virtual bool insertVertex(const T vertex) = 0;			//����һ������vertex
	virtual bool insertEdge(int v1, int v2,E cost ) = 0;    //�����(v1,v2),ȨΪcost
	virtual bool removeVertex(int v) = 0;					    //ɾȥ����v��������v��صı�
	virtual bool removeEdge(int v1,int v2) = 0;				//ɾȥ��(v1,v2)
	int getVertexPos(T vertex);				//��������vertex��ͼ�е�λ��
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
};
#endif