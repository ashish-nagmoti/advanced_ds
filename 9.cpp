#include <iostream>
#include <list>
#include <vector>
using namespace std;
struct node
{
    int key;
    string val;
    node(int key, string &
                      v) : key(key), val(v) {}
};
struct node1
{
    int key;
    string val;
    node1 *next;
    node1(int key, string &
                       v) : key(key), val(v), next(nullptr) {}
};
class HashTable
{
public:
    vector<node *> table;
    vector<node1 *> table1;
    int ts;
    HashTable(int size) : ts(size)
    {
        table.resize(ts, nullptr);
        table1.resize(ts, nullptr);
    }
    int hash(int key)
    {
        return key % ts;
    }
    void insert(int key, string &
                             val)
    {
        int i = hash(key);
        node *nn = new node(key, val);
        while (table[i] != nullptr)
        {
            i = (i + 1) % ts;
        }
        table[i] = nn;
    }
    string find(int key)
    {
        int i = hash(key);
        while (table[i] != nullptr)
        {
            if (table[i]->key == key)
            {
                return "name:" + table[i]->val;
            }
            i = (i + 1) % ts;
        }
        return "conatct not found ";
    }
    void remove(int key)
    {
        int i = hash(key);
        node *curr = table[i];
        node *prev = nullptr;
        while (table[i] != nullptr)
        {
            if (table[i]->key == key)
            {
                cout << "deleted contact: " << table[i] << endl;
                delete table[i];
                table[i] = nullptr;
            }
            i = (i + 1) % ts;
        }
        cout << "contact not found " << endl;
    }
    void display()
    {
        cout << "Contact List:"
             << endl;
        for (int i = 1; i <=
                        table.size();
             ++i)
        {
            cout << "Contact- "
                 << i << ": ";
            if (table[i] != nullptr)
            {
                cout << "[" << table[i]->key << ":" << table[i]->val
                     << "] ";
            }
            else
            {
                cout << "*";
            }
            cout << endl;
        }
    }
    void insert1(int key, string &
                              val)
    {
        int i = hash(key);
        node1 *nn = new node1(key, val);
        if (!table1[i])
        {
            table1[i] = nn;
        }
        else
        {
            node1 *
                curr = table1[i];
            while (curr->next)
            {
                curr = curr->next;
            }
            curr->next = nn;
        }
    }
    string find1(int key)
    {
        int i = hash(key);
        node1 *curr = table1[i];
        while (curr)
        {
            if (curr->key == key)
            {
                return "value:" + curr->val;
            }
            curr = curr->next;
        }
        return "key not found";
    }
    void remove1(int key)
    {
        int i = hash(key);
        node1 *curr = table1[i];
        node1 *prev = nullptr;
        while (curr)
        {
            if (curr->key == key)
            {
                if (prev)
                {
                    prev->next = curr->next;
                }
                else
                {
                    table1[i] = curr->next;
                }
                delete curr;
                cout << "deleted key: " << key << endl;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "key not found"
             << endl;
    }
    void display1()
    {
        cout << "Hash Table:" << endl;
        for (int i = 1; i <=
                        table1.size();
             i++)
        {
            cout << "index: " << i << ": ";
            node1 *curr =
                table1[i];
            while (curr)
            {
                cout << "[" << curr->key << ":" << curr->val << "]";
                    curr =
                    curr->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    int ts = 10;
    HashTable ht(ts);
    int key, ch = 0;
    string val;
    do
    {
        cout << "Phone book using HashTable\n1.Add Contact\n2.Search Contact\n3.Delete Contact\n4.View Contact\nenter your choice : " <<endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter the phone.no and name " << endl;
                    cin >>
                    key >>
                    val;
            ht.insert(key, val);
            cout << endl;
            ht.insert1(key, val);
            break;
        case 2:
            cout << "Enter contact to search : ";
            cin >>key;
            cout << "Value: " << ht.find(key) << endl;
            cout << "\n\t using seperate chaining "<<endl;
                cout<< "Value: " << ht.find1(key) << endl;
            break;
        case 3:
            cout << "Enter conatct to delete : ";
                                        cin >>key;
            ht.remove(key);
            cout << "\n\t using seperate chaining "<<endl;
                    ht.remove1(key);
            break;
        case 4:
            ht.display();
            cout << "\n";
            cout << "\n\t using seperate chaining "<<endl;
                    ht.display1();
            cout << "\n";
            break;
        }
    } while (ch <= 4);
    return 0;
}