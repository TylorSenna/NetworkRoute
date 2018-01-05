#include "Graphlnk.h"
#include <limits.h>
#include "Route.h"

const int maxValue = INT_MAX;

template<class T, class E>
//���path�����д洢��ͼG�Ӷ���v������������·���;���
void printPath(Graph<T, E>& G, int v, E dist[], int path[])
{
	cout << "�Ӷ���(·����)" << G.getValue(v).name << "������������(·����)�����·��Ϊ��" << endl;
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
				d[k++] = j;    //��·��������Ŵ�ŵ�d��
				j = path[j];
			}
			cout << "����(·����)" << G.getValue(i).name << "�����·��Ϊ��" << G.getValue(v).name << " ";
			while (k>0)
			{
				cout << G.getValue(d[--k]).name << " "; //��d�ж�ȡ���·������
			}
			cout << "���·������Ϊ��" << dist[i] <<endl;
		}
	}
	delete[] d;
}

template<class T, class E>
/**
    @G -- ·��ͼ
	@v -- ָ����·����
	@dist -- routeDistance
	@path -- ��Ž��ľ���·��
	�ýӿ�ʵ����·����v����·���������·��
	*/
void ShortestPath(Graph<T, E>& G, int v, E dist[], int path[])
{//Graph��һ����Ȩ����ͼ�����㷨����һ�����飬dist[j],0<=j<n;�ǵ�ǰ�󵽵ĴӶ���v������j�����·�����ȣ�ͬʱ������path����󵽵����·��
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
		for (j = 0; j<n; j++)            //��ѡ����С��·��
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;          //uΪ��ǰ��С·�����յ�
		for (k = 0; k<n; k++)            //�޸�
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
