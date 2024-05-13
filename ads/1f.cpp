#include<bits/stdc++.h>
using namespace std;
const int max_city = 100;

class Flight
{
	public:	
	string city_name[max_city] ;
	int limit = 0;

	int adjMatrix[max_city][max_city]={0};

	struct adjNode{
	 int dest;
	 int cost;
	adjNode *next; 
	};
	
	adjNode *adjlist[max_city] = {nullptr};
	
	void addFlight(string source, string destn, int cost)
	{
		int s = getCity(source);
		int d = getCity(destn);
		adjMatrix[s][d]= cost;
		adjNode *temp = new adjNode{d,cost,adjlist[s]};
		adjlist[s] = temp;
	}
	
	bool isFlight(string source, string dest)
	{
		int s = getCity(source);
		int d = getCity(dest);
		if(adjMatrix[s][d] > 0)
		{
			cout<<"Cities are connected"<<endl;
			return true;
		}
		else
		{
			cout<<"Cities are not connected"<<endl;
			return false;
		}
	}

	void printAdjMatrix(){
		cout<<"Adjacency matrix:"<<endl;
		for(int i=0;i<limit;i++)
		{
			for(int j=0;j<limit;j++){
				cout<<adjMatrix[i][j]<<" ";
			}
		cout<<endl;
		}		
	}
	void printAdjList(){
		cout<<"Adjacency List:"<<endl;
		for(int i=0;i<limit;i++)
		{
			cout<<city_name[i]<<"-->";
			adjNode *current = adjlist[i];
			while(current!=NULL)
			{
				cout<<"("<<city_name[current->dest]<<","<<current->cost<<")";
				current = current ->next;
			}
			cout<<endl;
		}		
	}
	int getCity(string city)
	{
		for(int i=0;i<limit;i++)
		{
			if(city == city_name[i])
			{ return i;}		
		}
		city_name[limit] = city;
		return limit++;
	}
	
};
int main()
{
	Flight f;
	int choice;
	do{	
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"1.Enter a flight"<<endl<<"2.Check if flight exist"<<endl<<"3.print adj matrix"<<endl<<"4.print adj list"<<endl<<"5.exit"<<endl<<"enter a choice:";
	cin>>choice;
	switch(choice)
	{
	 case 1:
		{string source ,dest;
		int cost; 
		cout<<"enter a source:";
		cin>>source;
		cout<<"enter a dest:";
		cin>>dest;
		cout<<"enter a cost:";
		cin>>cost;
		f.addFlight(source,dest,cost);
		break;}
	case 2:
		{string source ,dest;
	
		cout<<"enter a source:";
		cin>>source;
		cout<<"enter a dest:";
		cin>>dest;
		
		f.isFlight(source,dest);
		break;}
	
	case 3:
		{
			f.printAdjMatrix();
			break;
		}
	case 4:
		{
			f.printAdjList();
			break;
		}
	case 5:
		{
			cout<<"Exiting"<<endl;
			return 0;
		}
	}
	
	
	}while(choice!=5);
return 0;
}