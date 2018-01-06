#ifndef GRAPHLNK_H
#define GRAPHLNK_H
#include "Graph.h"
//以邻接表的形式构造的图的定义
template<class T,class E>
class Graphlnk : public Graph<T,E>
{
	friend istream& operator >> (istream& in,Graphlnk<T,E>& G);
public:
	Graphlnk(int sz = DeafultVertices);
	~Graphlnk();
	//取位置为i的顶点中的内容
	T getValue(int i);
	//返回边(v1,v2)的权值--->路由线路长度
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
	Vertex<T,E> * NodeTable;                //邻接表的顶点数组
};

#endif