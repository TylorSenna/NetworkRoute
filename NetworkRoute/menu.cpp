RailwayTraffic.cpp : 定义控制台应用程序的入口点。


#include <iostream>
	using namespace std;
#include "Route.cpp"
#include "GraphApp.cpp"
#include "Graphlnk.cpp"
#include<conio.h>

int main()
{
	int n = 0,e = 0;
	ifstream fin1("data.txt");
	ifstream fin2("table.txt");
	fin1>>n;
	VertexInfo v[9];                    //顶点信息
	for(int i = 0; i<n; i  ){
		fin1>>v[i].name;
		fin1>>v[i].network;
	}
	fin2>>e;
	RowColWeight rcw1[16];         //边信息
	for(int i = 0; i<e; i  ){
		fin2>>rcw1[i].row;
		rcw1[i].row--;


		Graphlnk<VertexInfo,int>  g2;//邻接表图
		CreatGraph(g2, v, n, rcw1, e);	//创建图		

		n = g2.NumberOfVertices();
		e = g2.NumberOfEdges();
		cout<<g2;						//输出图
		ShortestPath(g2,0,distance,path);//输出最短路由路径

		int a, b, c;
		bool quit = false;
		while (!quit)
		{
			system("cls");
			cout << "路由器管理" << endl;
			cout << "1 输出所有边信息" << endl;
			cout << "2 输出所有路由信息" << endl;
			cout << "3 输出指定路由器到其他路由器的最短路由经由" << endl;
			cout << "4 增加指定边" << endl;
			cout << "5 增加路由器 " << endl;
			cout << "6 删除指定路由（边） " << endl;
			cout << "7 删除指定路由器 " << endl;
			cout<<"0安全退出"<<endl;
			cin >> a;
			switch (a)
			{
			case 0:quit = true; break;
			case 1:cout<<"结点集合为:"<<endl;
				for(i=0;i< g2.NumberOfVertices();i  )
					cout<<"     路由器"<<g2.getValue(i).name<<"    网络号："<<G.getValue(i).network<<endl;
				cout<<"\n";
				break;
			case 2: cout << g2;break;
			case 3:cout << "请选择路由器序号输出最短路由" << endl;
				cout << "路由器选值范围为1到" <<g2.NumberOfVertices()<< endl;
				VertexInfo s;
				cin >> s.name;
				int a1 = g2.getVertexPos(s);
				ShortestPath(g2,a1,distance,path);//输出最短路由路径
				break;
			case 4:cout << "请输入增加的路由边的起点、终点、长度：" << endl;
				VertexInfo s;
				VertexInfo e;
				int l;
				cin>>s.name>>e.name>>l;
				AddRoute(g2,s,e,l);
				break;
			case 5:cout << "请输入增加的路由器名称（序号，如路由器8 就输入8）、网络号" << endl;
				VertexInfo add;
				cin>>add.name>>add.network;
				AddVertex(g2,add);
				break;      
			case 6:cout << "请选择删除的边" << endl;
				cout<<"路由边集合为:\n";
				for(i=0;i<G.NumberOfVertices();i  )
				{
					for(j=0;j<G.NumberOfVertices();j  )
					{
						if(G.getWeight(i,j)== maxWeight)
							cout<<setw(10)<<"Max";
						else
							cout<<setw(10)<<G.getWeight(i,j);
					}
					cout<<"\n";
				}
				cout << "请输入删除的起点终点" << endl;
				VertexInfo s,d;
				cin>>s.name>>d.name;
				DelRoute(g2,s,d);
				break;
			case 7:cout << "请选择删除的路由器序号" << endl;
				for(i=0;i< g2.NumberOfVertices();i  )
					cout<<"     路由器"<<g2.getValue(i).name<<"    网络号："<<G.getValue(i).network<<endl;
				cout<<"\n";
				VertexInfo d;
				cin>>d.name;
				DelVertex(g2,d);
				break;
			default:cout << "无效操作" << endl;
				break;
			}	
		}

		return 0;
	} 