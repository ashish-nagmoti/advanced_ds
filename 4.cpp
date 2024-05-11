#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}


bool search(Node* root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (value == root->data)
    {
        return true;
    }
    else if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}


void postTraversal(Node* root)
{
    if (root)
    {
        postTraversal(root->left);
        postTraversal(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node* root = nullptr;
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
                if (search(root, value))
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
                postTraversal(root);
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
