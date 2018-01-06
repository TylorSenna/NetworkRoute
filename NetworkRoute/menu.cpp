RailwayTraffic.cpp : �������̨Ӧ�ó������ڵ㡣


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
	VertexInfo v[9];                    //������Ϣ
	for(int i = 0; i<n; i  ){
		fin1>>v[i].name;
		fin1>>v[i].network;
	}
	fin2>>e;
	RowColWeight rcw1[16];         //����Ϣ
	for(int i = 0; i<e; i  ){
		fin2>>rcw1[i].row;
		rcw1[i].row--;


		Graphlnk<VertexInfo,int>  g2;//�ڽӱ�ͼ
		CreatGraph(g2, v, n, rcw1, e);	//����ͼ		

		n = g2.NumberOfVertices();
		e = g2.NumberOfEdges();
		cout<<g2;						//���ͼ
		ShortestPath(g2,0,distance,path);//������·��·��

		int a, b, c;
		bool quit = false;
		while (!quit)
		{
			system("cls");
			cout << "·��������" << endl;
			cout << "1 ������б���Ϣ" << endl;
			cout << "2 �������·����Ϣ" << endl;
			cout << "3 ���ָ��·����������·���������·�ɾ���" << endl;
			cout << "4 ����ָ����" << endl;
			cout << "5 ����·���� " << endl;
			cout << "6 ɾ��ָ��·�ɣ��ߣ� " << endl;
			cout << "7 ɾ��ָ��·���� " << endl;
			cout<<"0��ȫ�˳�"<<endl;
			cin >> a;
			switch (a)
			{
			case 0:quit = true; break;
			case 1:cout<<"��㼯��Ϊ:"<<endl;
				for(i=0;i< g2.NumberOfVertices();i  )
					cout<<"     ·����"<<g2.getValue(i).name<<"    ����ţ�"<<G.getValue(i).network<<endl;
				cout<<"\n";
				break;
			case 2: cout << g2;break;
			case 3:cout << "��ѡ��·�������������·��" << endl;
				cout << "·����ѡֵ��ΧΪ1��" <<g2.NumberOfVertices()<< endl;
				VertexInfo s;
				cin >> s.name;
				int a1 = g2.getVertexPos(s);
				ShortestPath(g2,a1,distance,path);//������·��·��
				break;
			case 4:cout << "���������ӵ�·�ɱߵ���㡢�յ㡢���ȣ�" << endl;
				VertexInfo s;
				VertexInfo e;
				int l;
				cin>>s.name>>e.name>>l;
				AddRoute(g2,s,e,l);
				break;
			case 5:cout << "���������ӵ�·�������ƣ���ţ���·����8 ������8���������" << endl;
				VertexInfo add;
				cin>>add.name>>add.network;
				AddVertex(g2,add);
				break;      
			case 6:cout << "��ѡ��ɾ���ı�" << endl;
				cout<<"·�ɱ߼���Ϊ:\n";
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
				cout << "������ɾ��������յ�" << endl;
				VertexInfo s,d;
				cin>>s.name>>d.name;
				DelRoute(g2,s,d);
				break;
			case 7:cout << "��ѡ��ɾ����·�������" << endl;
				for(i=0;i< g2.NumberOfVertices();i  )
					cout<<"     ·����"<<g2.getValue(i).name<<"    ����ţ�"<<G.getValue(i).network<<endl;
				cout<<"\n";
				VertexInfo d;
				cin>>d.name;
				DelVertex(g2,d);
				break;
			default:cout << "��Ч����" << endl;
				break;
			}	
		}

		return 0;
	} 