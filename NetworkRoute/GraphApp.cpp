#include "Graphlnk.h"
#include <limits.h>
#include "Route.h"

const int maxValue = INT_MAX;

template<class T, class E>
//输出path数组中存储的图G从顶点v到其余各顶点的路径和距离
void printPath(Graph<T, E>& G, int v, E dist[], int path[])
{
	cout << "从顶点(路由器)" << G.getValue(v).name << "到其他各顶点(路由器)的最短路径为：" << endl;
	int i, j, k, n = G.NumberOfVertices();
	int * d = new int[n];
	for (i = 0; i<n; i++)
	{
		if (i != v)
		{
			j = i;
			k = 0;
			while (j != v)
			{
				d[k++] = j;    //把路径经由序号存放到d中
				j = path[j];
			}
			cout << "顶点(路由器)" << G.getValue(i).name << "的最短路径为：" << G.getValue(v).name << " ";
			while (k>0)
			{
				cout << G.getValue(d[--k]).name << " "; //从d中读取最短路径经由
			}
			cout << "最短路径长度为：" << dist[i] <<endl;
		}
	}
	delete[] d;
}

template<class T, class E>
/**
    @G -- 路由图
	@v -- 指定的路由器
	@dist -- routeDistance
	@path -- 存放结点的经过路径
	该接口实现求路由器v到各路由器的最短路径
	*/
void ShortestPath(Graph<T, E>& G, int v, E dist[], int path[])
{//Graph是一个带权有向图，本算法建立一个数组，dist[j],0<=j<n;是当前求到的从顶点v到顶点j的最短路径长度，同时用数组path存放求到的最短路径
	int n = G.NumberOfVertices();
	bool *S = new bool[n];
	int i, j, k;
	E w, min;
	for (i = 0; i<n; i++)
	{
		dist[i] = G.getWeight(v, i);
		S[i] = false;
		if (i != v && dist[i] <maxValue)
			path[i] = v;
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;
	dist[v] = 0;
	for (i = 0; i<n - 1; i++)
	{
		min = maxValue;
		int u = v;
		for (j = 0; j<n; j++)            //挑选出最小的路径
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;          //u为当前最小路径的终点
		for (k = 0; k<n; k++)            //修改
		{
			w = G.getWeight(u, k);
			if (S[k] == false && w <maxValue && dist[u] + w<dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
	printPath(G, v, dist, path);
}
