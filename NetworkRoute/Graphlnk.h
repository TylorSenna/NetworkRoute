#ifndef GRAPHLNK_H
#define GRAPHLNK_H
#include "Graph.h"
//���ڽӱ����ʽ�����ͼ�Ķ���
template<class T,class E>
class Graphlnk : public Graph<T,E>
{
	friend istream& operator >> (istream& in,Graphlnk<T,E>& G);
public:
	Graphlnk(int sz = DeafultVertices);
	~Graphlnk();
	//ȡλ��Ϊi�Ķ����е�����
	T getValue(int i);
	//���ر�(v1,v2)��Ȩֵ--->·����·����
	E getWeight(int v1,int v2);			
	bool insertVertex(const T vertex);
	bool removeVertex(int v);
	bool insertEdge(int v1, int v2, E cost); 
	bool removeEdge(int v1,int v2);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v,int w );
	int getVertexPos(const T vertex);
	int NumberOfVertices()
	{
		return this->numVertices;
	}
	int NumberOfEdges()
	{
		return this->numEdges;
	}

private:
	Vertex<T,E> * NodeTable;                //�ڽӱ�Ķ�������
};

#endif