#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>
using namespace std;
#include "Graph.h"
#include "Graphlnk.h"

const int MaxVertices = 100;	//图中的最大顶点数目
const int MaxWeight = 10000;	//无穷大的权值

struct VertexInfo{     //图中顶点数据域data类型
	string name;           //路由器名称
	string network;       //路由器连接网络的网络号
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

struct RowColWeight      //边信息类型定义
{
	int row;							    //行下标  ---startNum;   起始路由器编号
	int col;							    //列下标  ---endNum;   终点路由器编号
	int weight;							//路由线路长度            
};

#endif 