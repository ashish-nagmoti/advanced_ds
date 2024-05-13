#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char key;
    string value;
    Node *left;
    Node *right;
    Node(char k, string v) : key(k), value(v), left(nullptr), right(nullptr){};
};
Node *insert(Node *root, char key, string value)
{
    if (root == NULL)
    {
        return new Node(key, value);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key, value);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key, value);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << "\t" << root ->key << "\t" << root->value << endl;
    inorder(root->right);
}
Node *search(Node *root, char key)
{
    if (root == NULL)
    {
        return nullptr;
    }
    if (root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return search(root->left, key);
    }
    else if (key > root->key)
    {
        return search(root->right, key);
    }
}
Node *findMin(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}
Node *del(Node *root, char key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (key < root->key)
    {
        root->left = del(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = del(root->right, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
            temp = nullptr;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
            temp = nullptr;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->value = temp->value;
            root->right = del(root->right, temp->key);
        }
    }
    return root;
}
void printLevelByLevel(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> nodesQueue;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) {
        int temp = nodesQueue.size();
        for (int i = 0; i < temp; i++) {
        Node* currNode = nodesQueue.front();
        nodesQueue.pop();

        cout << "\t" << currNode->key << "\t" << currNode->value ;

        if (currNode->left != nullptr) {
            nodesQueue.push(currNode->left);
        }
        if (currNode->right != nullptr) {
            nodesQueue.push(currNode->right);
        }
        }
        cout<<endl;
    }
}
int main()
{
    int choice;
    Node *root = nullptr;
    do
    {
        cout << "1.Insert value" << endl
             << "2.inorder" << endl
             << "3.search" << endl
             << "4.find min" << endl
             << "5.del key" << endl
             << "6.level" << endl
             << "enter a choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            {char key;
            string value;
            cout << "enter key";
            cin >> key;
            cout << "enter value";
            cin >> value;
            root = insert(root, key, value);
            break;}
        case 2:
            inorder(root);
            break;
        case 3:
        {
            char key;
            cout << "Enter a key to search:";
            cin >> key;
            Node *temp = search(root, key);
            cout << temp->key << " " << temp->value;
            break;}
        case 4:
        {
            Node *temp = findMin(root);
            cout << temp->key << " " << temp->value;
            break;}
        case 5:

            char key;
            cout << "Enter a key to delete:";
            cin >> key;
            root = del(root, key);
            break;
        case 6:
            printLevelByLevel(root);
            break;
        }
    } while (choice != 7);
}