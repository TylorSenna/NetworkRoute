#include <iostream>
#include <string>
using namespace std;
#include "Route.h"


template<class T,class E>
/**构造路由图
   @G -- 要构造的图的邻接表
   @V -- 结点信息数组
   @n -- 顶点个数
   @E -- 边信息
   @e -- 边个数
  */
void CreatGraph(Graphlnk<T,E> &G, VertexInfo V[], int n, RowColWeight E[],int e)
{
	//在图G中插入n个顶点
	for(int i = 0; i < n; i++) 
		G.insertVertex(V[i]);

	//在图G中插入e条边
	for(int k = 0; k < e; k++) 
		G.insertEdge(E[k].row, E[k].col, E[k].weight);
}

template<class T,class E>
//增加路由器结点
void AddVertex(Graphlnk<T,E> &G, VertexInfo V){        
	//在图G中插入一个顶点
	bool result = G.insertVertex(V);
	if(result){
		cout<<"增加路由器结点"<<V.name<<"成功"<<endl;
	}else{
	    cout<<"增加路由器结点"<<V.name<<"失败"<<endl;
	}
}

template<class T,class E>
//增加路由线路
void AddRoute(Graphlnk<T,E> &G, VertexInfo s, VertexInfo e, int distance){        
	//在图G中插入一条边
	int startNum = G.getVertexPos(s);
	int endNum = G.getVertexPos(e);
	bool result = G.insertEdge(startNum,endNum,distance);   
	if(result){
		cout<<"增加路由线路（"<<s.name<<","<<e.name<<","<<distance<<")成功"<<endl;
	}else{
		cout<<"增加路由线路（"<<s.name<<","<<e.name<<","<<distance<<")失败"<<endl;
	}
}

template<class T,class E>
//删除路由器结点
void DelVertex(Graphlnk<T,E> &G, VertexInfo del){        
	int delNum = G.getVertexPos(del);
	bool result = G.removeVertex(delNum);     
	if(result){
		cout<<"删除路由器结点"<<del.name<<"成功"<<endl;
	}else{
		cout<<"删除路由器结点"<<del.name<<"失败"<<endl;
	}
}

template<class T,class E>
//删除路由线路
void DelRoute(Graphlnk<T,E> &G, VertexInfo s, VertexInfo e){   
	int startNum = G.getVertexPos(s);
	int endNum = G.getVertexPos(e);
	bool result = G.removeEdge(startNum, endNum); 
	if(result){
		cout<<"删除路由线路（"<<s.name<<","<<e.name<<")成功"<<endl;
	}else{
	    cout<<"删除路由线路（"<<s.name<<","<<e.name<<")失败"<<endl;
	}
}