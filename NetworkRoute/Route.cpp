#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "Route.h"


template<class T,class E>
/**����·��ͼ
   @G -- Ҫ�����ͼ���ڽӱ�
   @V -- �����Ϣ����
   @n -- �������
   @E -- ����Ϣ
   @e -- �߸���
  */
void CreatGraph(Graphlnk<T,E> &G, VertexInfo V[], int n, RowColWeight E[],int e)
{
	//��ͼG�в���n������
	for(int i = 0; i < n; i++) 
		G.insertVertex(V[i]);

	//��ͼG�в���e����
	for(int k = 0; k < e; k++) 
		G.insertEdge(E[k].row, E[k].col, E[k].weight);
}

template<class T,class E>
//����·�������
void AddVertex(Graphlnk<T,E> &G, VertexInfo V){        
	//��ͼG�в���һ������
	bool result = G.insertVertex(V);
	if(result){
		cout<<"����·�������"<<V.name<<"�ɹ�"<<endl;
	}else{
	    cout<<"����·�������"<<V.name<<"ʧ��"<<endl;
	}
}

template<class T,class E>
//����·����·
void AddRoute(Graphlnk<T,E> &G, VertexInfo s, VertexInfo e, int distance){        
	//��ͼG�в���һ����
	int startNum = G.getVertexPos(s);
	int endNum = G.getVertexPos(e);
	bool result = G.insertEdge(startNum,endNum,distance);   
	if(result){
		cout<<"����·����·��"<<s.name<<","<<e.name<<","<<distance<<")�ɹ�"<<endl;
	}else{
		cout<<"����·����·��"<<s.name<<","<<e.name<<","<<distance<<")ʧ��"<<endl;
	}
}

template<class T,class E>
//ɾ��·�������
void DelVertex(Graphlnk<T,E> &G, VertexInfo del){        
	int delNum = G.getVertexPos(del);
	bool result = G.removeVertex(delNum);     
	if(result){
		cout<<"ɾ��·�������"<<del.name<<"�ɹ�"<<endl;
	}else{
		cout<<"ɾ��·�������"<<del.name<<"ʧ��"<<endl;
	}
}

template<class T,class E>
//ɾ��·����·
void DelRoute(Graphlnk<T,E> &G, VertexInfo s, VertexInfo e){   
	int startNum = G.getVertexPos(s);
	int endNum = G.getVertexPos(e);
	bool result = G.removeEdge(startNum, endNum); 
	if(result){
		cout<<"ɾ��·����·��"<<s.name<<","<<e.name<<")�ɹ�"<<endl;
	}else{
	    cout<<"ɾ��·����·��"<<s.name<<","<<e.name<<")ʧ��"<<endl;
	}
}

template<class T,class E>
//��ӡ��·�ɱ�
void printEdges(Graphlnk<T,E> &G){
	for(int i=0;i<G.NumberOfVertices();i++)
	{
		for(int j=0;j<G.NumberOfVertices();j++)
		{
			if(G.getWeight(i,j)== maxWeight)
				cout<<setw(10)<<"Max";
			else
				cout<<setw(10)<<G.getWeight(i,j);
		}
		cout<<"\n";
	}
}

template<class T,class E>
//��ӡ��·�������
void printVertices(Graphlnk<T,E> &G){
	for(int i=0;i< G.NumberOfVertices();i++){
		cout<<"     ·����"<<G.getValue(i).name<<"    ����ţ�"<<G.getValue(i).network<<endl;
	}
	cout<<"\n";
}