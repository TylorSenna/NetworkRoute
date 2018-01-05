#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>
using namespace std;
#include "Graph.h"
#include "Graphlnk.h"

const int MaxVertices = 100;	//ͼ�е���󶥵���Ŀ
const int MaxWeight = 10000;	//������Ȩֵ

struct VertexInfo{     //ͼ�ж���������data����
	string name;           //·��������
	string network;       //·������������������
	void operator = (const VertexInfo & R)
	{
		name = R.name;
		network = R.network;
	}
	bool operator == (const VertexInfo & R)const
	{
		return (name == R.name)?true:false;
	}
};

struct RowColWeight      //����Ϣ���Ͷ���
{
	int row;							    //���±�  ---startNum;   ��ʼ·�������
	int col;							    //���±�  ---endNum;   �յ�·�������
	int weight;							//·����·����            
};

#endif 