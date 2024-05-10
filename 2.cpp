#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

class Graph {
   int V;    
   list<int> *head;
   string loc[7] ={"AMARDHAM","hanuman nagar","tapovan","bali mandir","adgaon","auranagabad naka","janta hall"}  ;
public:
   Graph(int V) {    
      this->V = V;
      head = new list<int>[V];
   }
   void addEdge(int v, int w) {
      head[v].push_back(w);
   }
   
    void printGraph() {
      for (int i = 0; i < V; i++) {
         cout << "Adjacency list of vertex " << loc[i] << ": ";
         for (const auto& node : head[i]) {
            cout << loc[node] << " ";
            cout<<"-->";
         }
         cout << endl;
      }
   }
   void DFSUtil(int v, bool visited[]) {
      visited[v] = true;
      cout << loc[v] ;
      if(v!=6)
      {
        cout<< "-->";
      }
      for (list<int>::iterator i = head[v].begin(); i != head[v].end(); i++)
         if (!visited[*i])
            DFSUtil(*i, visited);
   }
   void DFS(int v) {
      bool *visited = new bool[V];
      for (int i = 0; i < V; i++)
         {
                visited[i] = false;
         }    
      DFSUtil(v, visited);
   }
   void BFS(int v) 
   { 
        bool *visited = new bool[V]; 
        for (int i = 0; i < V; i++) 
                visited[i] = false;

 
        queue<int> q;
        visited[v] = true;
        q.push(v);
  
        while (!q.empty()) {
        v = q.front();
        cout << loc[v];
        if(v!=5)
      {
        cout<< "-->";
      }
        q.pop();
     
        for (list<int>::iterator i = head[v].begin(); i != head[v].end(); i++) {
        if (!visited[*i]) {
           visited[*i] = true;
           q.push(*i);
        }
     }
  }

} 
};

int main() {
    Graph g(7);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    
    g.addEdge(1, 3);
    
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    
    
    g.printGraph();


        cout<<endl;
        int choice;
        do{
        cout<<"1.DFS /n 2.BFS /n 3.exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        
        case 1:
                cout<<endl;
                cout << "Depth First Traversal (starting from vertex 0): ";
                cout<<endl;
                g.DFS(0);
                cout<<endl;
                break;
         case 2:
                cout<<endl;
                cout << "breadth First Traversal (starting from vertex 0): ";
                cout<<endl;
                g.BFS(0);
                cout<<endl;
                break;
          case 3:
                cout<<"exiting"<<endl;
                return 0;
        }
    }while(choice!=3);
    
    return 0;
}