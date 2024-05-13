#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <functional>

using namespace std;

template<typename K, typename V>
class HashTable
{
private:
    vector<list<pair<K, V>>> table;
    hash<K> hasher;

public:
    explicit HashTable(size_t size = 100) : table(size) {}

    void insert(const K& key, const V& value)
    {
        size_t index = hasher(key) % table.size();
        for (const auto& kvp : table[index])
        {
            if (kvp.first == key)
            {
                cerr << "Key already exists in hash table." << endl;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    bool find(const K& key, V& value) const
    {
        size_t index = hasher(key) % table.size();
        for (const auto& kvp : table[index])
        {
            if (kvp.first == key)
            {
                value = kvp.second;
                return true;
            }
        }
        return false;
    }

    void erase(const K& key)
    {
        size_t index = hasher(key) % table.size();
        auto& bucket = table[index];
        bucket.remove_if([&](const auto& kvp) { return kvp.first == key; });
    }
};

int main()
{
    map<int, string> dictionary;
    HashTable<int, string> myHashTable;
    int ch, key;
    string val;

    do {
        cout << "Menu\n1. Insert\n2. Find\n3. Delete\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter key and value: ";
                cin >> key >> val;
                dictionary[key] = val;
                myHashTable.insert(key, val);
                break;

            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                if (myHashTable.find(key, val))
                {
                    cout << "Key found, value is: " << val << endl;
                }
                else
                {
                    cout << "Key not found." << endl;
                }
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.erase(key);
                myHashTable.erase(key);
                cout << "Key deleted." << endl;
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (ch != 4);

    return 0;
}

