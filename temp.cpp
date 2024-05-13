#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

Node *expressionTree(string prefix)
{
    stack<Node*> st;
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char ch = prefix[i];
        if (isalnum(ch))
        {
            Node *temp = new Node(ch);
            st.push(temp);
        }
        else
        {
            Node *temp = new Node(ch);
            temp->left = st.top();
            st.pop();
            temp->right = st.top();
            st.pop();
            st.push(temp);
        }
    }
    return st.top();
}

void level(Node *root)
{
    if (root == nullptr)
    {
        cout<<"empty tree";
        return ;
    }
    queue<Node*> q;
    q.push(root);
    cout << "level" << endl;
    while (!q.empty())
    {
        int level = q.size();

        for (int i = 0; i < level; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}
void postOrderTraversal(Node *root)
{
    if (root == nullptr)
        cout<<"empty tree";
        return ;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void swaptreepointer(Node *root)
{
    if (root == nullptr)
    {
        cout<<"empty tree";
        return ;
    }
    swap(root->left, root->right);
    swaptreepointer(root->left);
    swaptreepointer(root->right);
}
void deletetree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    deletetree(root->left);
    deletetree(root->right);
    cout << "expression to be deleted" << root->data;
    delete root;
    root = nullptr;
}

int main()
{
    string st;
    int choice;
    cout << "Enter the prefix Expression you want: ";
    cin >> st;
    Node *root = expressionTree(st);
    do
    {
        cout << "1.postorder traversal" << endl
             << "2.level by level" << endl
             << "3.swappointer" << endl
             << "4.delete tree" << endl
             << "enter a choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            postOrderTraversal(root);
            break;
        case 2:
            level(root);
            break;
        case 3:
            swaptreepointer(root);
            break;
        case 4:
            deletetree(root);
            break;
        }

    } while (choice != 5);
}