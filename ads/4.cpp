#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        root->left = insert(root->left, value);
    }
    return root;
}
bool search(int value, Node *root)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == value)
    {
        return true;
    }
    else if (root->data > value)
    {
        return search(value, root->left);
    }
    else
    {
        return search(value, root->right);
    }
}

void posttraversal(Node *root)
{
    if (root)
    {
        posttraversal(root->left);
        posttraversal(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = nullptr;
    int choice, value;

    do
    {
        cout << "\n\t\t\t----Menu----\n\n";
        cout << "\t1. Insert new node.\n";
        cout << "\t2. Search for a value.\n";
        cout << "\t3. Tree traversing by using post-order traversal.\n";
        cout << "\t4. Exit.\n";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to search : ";
            cin >> value;
            if (search(value, root))
            {
                cout << value << " is present in the BST.\n";
            }
            else
            {
                cout << value << " is not present in the BST.\n";
            }
            break;

        case 3:
            cout << "Postorder Traversal : ";
            posttraversal(root);
            cout << endl;
            break;

        case 4:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
