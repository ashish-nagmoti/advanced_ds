#include <bits/stdc++.h>
using namespace std;
const int ite = 100;
class topo
{
public:
    string name[ite];
    int limit = 0, V;
    list<int> *head;
    topo(int V)
    {
        this->V = V;
        head = new list<int>[V];
    }
    void adde(string a, string b)
    {
        int ai = getnum(a);
        int bi = getnum(b);
        head[ai].push_back(bi);
    }
    int getnum(string names)
    {
        for (int i = 0; i < limit; i++)
        {
            if (names == name[i])
            {
                return i;
            }
        }
        name[limit] = names;
        return limit++;
    }
    void printlist()
    {
        for (int i = 0; i < V; i++)
        {
            cout << name[i] << "-->";
            for (auto node : head[i])
            {
                cout << name[node] << "-->";
            }
            cout<<endl;
        }
    }
    void toplogicalsort()
    {
        vector<int> indegree(V, 0); // creates vecotor of size  V with all 0
        // first for loop iterate througha all graph and then 2nd for loop iterate theough node connected to node
        for (int u = 0; u < V; u++)
        {
            for (auto v : head[u])
            {
                indegree[v]++;
            }
        }
        queue<int> q;

        for (int u = 0; u < V; u++)
        {
            if (indegree[u] == 0)
            {
                q.push(u);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (auto v : head[u])
            {
                --indegree[v];
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }
};
int main()
{
    int n, choice;
    cout << "Total no. of tasks:";
    cin >> n;
    topo t(n);
    do
    {
        cout << "1.add edge" << endl
             << "2.display list" << endl
             << "3.topological sort" << endl
             << "4.exit" << endl
             << "Enter A choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string a, b;
            cout << "task 1:";
            cin >> a;
            cout << "task 2:";
            cin >> b;
            t.adde(a, b);
            break;
        }
        case 2:
        {
            t.printlist();
            break;
        }
        case 3:
        {
            t.toplogicalsort();
            break;
        }
        case 4:
        {
            cout << "exiting" << endl;
            return 0;
        }
        }
       
    } while (choice != 5);
}