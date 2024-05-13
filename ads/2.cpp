#include<bits/stdc++.h>
using namespace std;
const int ite = 100;
class gtr{
	public:
	int V ,limit=0;
	string loc[ite] = {""};
	list<int> *head;
	gtr(int V){
		this->V = V;
		head = new list<int>[V];
	}
	
	void addEdge(string v , string w)
	{
		int vi = getnum(v);
		int wi = getnum(w);
		head[vi].push_back(wi);
	}

	void printGraph(){
		for(int i=0;i<V;i++)
		{
			cout<<loc[i]<<"-->";
			for(auto node:head[i]){
				cout<<loc[node]<<"-->";
			}
			cout<<endl;
		}
	}
	void dfsutil(int m, bool visited[]){
	visited[m] = true;
	cout<<loc[m]<<"-->";
	
	for(auto node:head[m])
	{
		if(!visited[node])
		{ dfsutil(node,visited);
	}
	}
	}
	void DFS(int m){
	bool *visited  = new bool[V];
	for(int i=0;i<V;i++)
{
	visited[i]=false;
}
	dfsutil(m,visited);
	}

 	void BFS(int m)
	{
		bool *visited  = new bool[V];
		for(int i=0;i<V;i++)
		{
			visited[i]=false;
		}
		queue<int> q;
		visited[m]=true;
		q.push(m);
		while(!q.empty())
		{
		m=q.front();
		cout<<loc[m]<<"->";
		q.pop();
		for(auto i :head[m])
		{
			if(!visited[i])
			{
				visited[i]=true;
				q.push(i);
			}
		}	
		}
	}
	int getnum(string city)
	{	
		for(int i=0;i<limit;i++)
		{
			if(city == loc[i])
			{return i;}
		}
		loc[limit] = city;
		return limit++;	
	}
};
int main(){
	cout<<"How many Places you wan to include:";
	int n,choice;
	cin>>n;
	gtr g(n);
	do{
	cout<<"1.Add route"<<endl<<"2.print graph"<<endl<<"3.DFS"<<endl<<"4.BFS"<<endl<<"5.exit"<<endl<<"Enter a choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				string source ,dest;
                cout << "Enter source: ";
    cin >> source;
    cout << "Enter destination: ";
    cin >> dest;
				g.addEdge(source,dest);
				break;
			}
		case 2:
			{
				g.printGraph();
				break;
			}
		case 3:
			{
				g.DFS(0);
				break;
			}
		case 4:
			{
				g.BFS(0);
				break;
			}
		case 5:
			{
				cout<<"exiting....."<<endl;
				return 0; 
			}
		
	}
}while(choice!=5);
return 0;	
}