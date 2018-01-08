#include <iomanip>
#include <fstream>
using namespace std;
#include "Route.cpp"
#include "GraphApp.cpp"
#include "Graphlnk.cpp"

int main()
{  cout<<"��ɭ"<<endl; 
	int n = 0,e = 0;
	fstream fin1("data.txt");
	fstream fin2("table.txt");
	fin1>>n;
	VertexInfo * v = new VertexInfo[n];                    //������Ϣ
	for(int i = 0; i<n; i++){
		fin1>>v[i].name;
		fin1>>v[i].network;
	}
	fin2>>e;
	RowColWeight * rcw1 = new RowColWeight[e];         //����Ϣ
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

	Graphlnk<VertexInfo,int>  g2;//�ڽӱ�ͼ
	CreatGraph(g2, v, n, rcw1, e);	//����ͼ		

	n = g2.NumberOfVertices();
	e = g2.NumberOfEdges();
	cout<<g2;						//���ͼ
	ShortestPath(g2,0,distance,path);//������·��·��
	
	int a, i, j, num;
	VertexInfo start, end, add, del;
	bool quit = false;
	while (!quit)
	{
		cout << "·��������" << endl;
		cout << "1 ������б���Ϣ" << endl;
		cout << "2 �������·����Ϣ" << endl;
		cout << "3 ���ָ��·����������·���������·�ɾ���" << endl;
		cout << "4 ����ָ����" << endl;
		cout << "5 ����·���� " << endl;
		cout << "6 ɾ��ָ��·�ɣ��ߣ� " << endl;
		cout << "7 ɾ��ָ��·���� " << endl;
		cout<<"0��ȫ�˳�"<<endl;
		cout<<"���������ѡ���ܣ�"<<endl;
		cin >> a;
		switch (a)
		{
		case 0:quit = true; break;
		case 1:cout<<"��㼯��Ϊ:"<<endl;
			printVertices(g2);
			break;
		case 2: cout << g2;break;
		case 3:cout << "��ѡ��·�������������·��" << endl;
			cout << "·����ѡֵ��ΧΪ1��" <<g2.NumberOfVertices()<< endl;
			cin >> start.name;
			num = g2.getVertexPos(start);
			ShortestPath(g2,num,distance,path);//������·��·��
			break;
		case 4:cout << "���������ӵ�·�ɱߵ���㡢�յ㡢���ȣ�" << endl;
			int l;
			cin>>start.name>>end.name>>l;
			AddRoute(g2,start,end,l);
			break;
		case 5:cout << "���������ӵ�·�������ƣ���ţ���·����8 ������8���������" << endl;
			cout<<"���Ӻ����������·����·����������·�������ʲ�����·������ʹ�����·�����ֱ���"<<endl;
			cin>>add.name>>add.network;
			AddVertex(g2,add);
			break;      
		case 6:cout << "��ѡ��ɾ���ı�" << endl;
			cout<<"·�ɱ߼���Ϊ:\n";
			printEdges(g2);
			cout << "������ɾ��������յ�" << endl;
			cin>>start.name>>del.name;
			DelRoute(g2,start,del);
			break;
		case 7:cout << "��ѡ��ɾ����·�������" << endl;
			printVertices(g2);
			cin>>del.name;
			DelVertex(g2,del);
			break;
		default:cout << "��Ч����" << endl;
			break;
		}	
	}
	fin1.close();
	fin2.close();
	fstream fout1("data.txt",ios::out);
	fstream fout2("table.txt",ios::out);
	//�ļ����  ��������Ϣ  ·�ɱ���Ϣ
	fout1<<g2.NumberOfVertices()<<endl;
	for(i=0;i< g2.NumberOfVertices(); i++){
		fout1<<g2.getValue(i).name<<" "<<g2.getValue(i).network<<endl;
	}
	fout2<<g2.NumberOfEdges()<<endl;
	for(i=0;i<g2.NumberOfVertices();i++)
	{
		for(j=i;j<=g2.NumberOfVertices();j++)
		{
			if(g2.getWeight(i,j)== maxWeight)
				continue;           //û���ڽӱ� ֱ��������һ��ѭ��
			else

				fout2<<i+1<<" "<<j+1<<" "<<g2.getWeight(i,j)<<endl;
		}
	}
	fout1.close();
	fout2.close();
	return 0;
} 