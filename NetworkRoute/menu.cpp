#include <iomanip>
#include <fstream>
using namespace std;
#include "Route.cpp"
#include "GraphApp.cpp"
#include "Graphlnk.cpp"

int main()
{
	int n = 0,e = 0;
	ifstream fin1("data.txt");
	ifstream fin2("table.txt");
	fin1>>n;
	VertexInfo v[9];                    //顶点信息
	for(int i = 0; i<n; i++){
		fin1>>v[i].name;
		fin1>>v[i].network;
	}
	fin2>>e;
	RowColWeight rcw1[16];         //边信息
	for(int i = 0; i<e; i++){
		fin2>>rcw1[i].row;
		rcw1[i].row--;
		fin2>>rcw1[i].col;
		rcw1[i].col--;
		fin2>>rcw1[i].weight;
	}
	int *distance= new int[n];
	int *path= new int[n];
	for(int i =0; i<n; i++){
		path[i] = -1;
	}

	Graphlnk<VertexInfo,int>  g2;//邻接表图
	CreatGraph(g2, v, n, rcw1, e);	//创建图		

	n = g2.NumberOfVertices();
	e = g2.NumberOfEdges();
	cout<<g2;						//输出图
	ShortestPath(g2,0,distance,path);//输出最短路由路径
	
	int a, b, c, i, j, num;
	VertexInfo start, end, add, del;
	bool quit = false;
	while (!quit)
	{
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
			for(i=0;i< g2.NumberOfVertices();i++)
				cout<<"     路由器"<<g2.getValue(i).name<<"    网络号："<<g2.getValue(i).network<<endl;
			cout<<"\n";
			break;
		case 2: cout << g2;break;
		case 3:cout << "请选择路由器序号输出最短路由" << endl;
			cout << "路由器选值范围为1到" <<g2.NumberOfVertices()<< endl;
			cin >> start.name;
			num = g2.getVertexPos(start);
			ShortestPath(g2,num,distance,path);//输出最短路由路径
			break;
		case 4:cout << "请输入增加的路由边的起点、终点、长度：" << endl;
			int l;
			cin>>start.name>>end.name>>l;
			AddRoute(g2,start,end,l);
			break;
		case 5:cout << "请输入增加的路由器名称（序号，如路由器8 就输入8）、网络号" << endl;
			cout<<"增加后必须先增加路由线路，否则其他路由器访问不到该路由器会使得最短路径出现崩溃"<<endl;
			cin>>add.name>>add.network;
			AddVertex(g2,add);
			break;      
		case 6:cout << "请选择删除的边" << endl;
			cout<<"路由边集合为:\n";
			for(i=0;i<g2.NumberOfVertices();i++)
			{
				for(j=0;j<g2.NumberOfVertices();j++)
				{
					if(g2.getWeight(i,j)== maxWeight)
						cout<<setw(10)<<"Max";
					else
						cout<<setw(10)<<g2.getWeight(i,j);
				}
				cout<<"\n";
			}
			cout << "请输入删除的起点终点" << endl;
			cin>>start.name>>del.name;
			DelRoute(g2,start,del);
			break;
		case 7:cout << "请选择删除的路由器序号" << endl;
			for(i=0;i< g2.NumberOfVertices();i++)
				cout<<"     路由器"<<g2.getValue(i).name<<"    网络号："<<g2.getValue(i).network<<endl;
			cout<<"\n";
			cin>>del.name;
			DelVertex(g2,del);
			break;
		default:cout << "无效操作" << endl;
			break;
		}	
	}
	
	return 0;
} 