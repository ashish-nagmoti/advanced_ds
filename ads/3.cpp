#include <iostream>
#include <queue>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
     string land[4]={"A","B","C","D"};

	public :
	
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
   
    void displayList()
    {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << land[i]<< " -> ";
            for (int& node : adj[i])
                cout << land[node]<< " ";
            cout << endl;
        }
    }

    void topologicalSort()
    {
        vector<int> inDegree(V, 0);

        for (int u = 0; u < V; u++)
        {
            for (auto v : adj[u])
            {
                inDegree[v]++;
            }
        }

        queue<int> q;
       
        for (int u = 0; u < V; u++)
        {
            if (inDegree[u] == 0)
            {
                q.push(u);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

         
            for (auto v : adj[u])
            {
                if (--inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    
    g.displayList();

    cout << "Topological Sort : ";
    g.topologicalSort();
    cout<<endl;
    
    return 0;
}
