#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct KeyValuePair
{
    int key;
    string value;
};


class Dictionary
{
private:
    vector<list<KeyValuePair>> hashTable;
    int size;

    
    int hashFunction(int key)
    {
        return key % size;
    }

public:
    
    Dictionary(int s) : size(s)
    {
        hashTable.resize(size);
    }

    
    void insert(int key, const string& value)
    {
        int index = hashFunction(key);
        hashTable[index].push_back({key, value});
    }

    string find(int key)
    {
        int index = hashFunction(key);
        for (auto& pair : hashTable[index])
        {
            if (pair.key == key)
            {
                return pair.value;
            }
        }
        return "Key not found";
    }

 
    void remove(int key)
    {
        int index = hashFunction(key);
        hashTable[index].remove_if([key](const KeyValuePair& pair)
        {
            return pair.key == key;
        });
    }

 
    void display()
    {
        cout << "Dictionary Contents:" << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << "index: " << i << " : ";
            for (const auto& pair : hashTable[i])
            {
                cout << "(" << pair.key << ", " << pair.value << ")----> ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    Dictionary dict(size);

    int choice;
    do {
        cout << "\nDictionary Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Find" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int key;
                string value;
                cout << "Enter key and value to insert : ";
                cin >> key >> value;
                dict.insert(key, value);
                cout << "Key-Value pair inserted successfully." << endl;
                break;
            }
            
            case 2:
            {
                int key;
                cout << "Enter key to find : ";
                cin >> key;
                string result = dict.find(key);
                cout << "Value: " << result << endl;
                break;
            }
            
            case 3:
            {
                int key;
                cout << "Enter key to delete : ";
                cin >> key;
                dict.remove(key);
                cout << "Key-Value pair deleted successfully." << endl;
                break;
            }
            
            case 4:
            {
                dict.display();
                break;
            }
            
            case 5:
                cout << "Exiting program.....!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please enter a valid option..." << endl;
        }
    } while (choice != 5);

    return 0;
}

