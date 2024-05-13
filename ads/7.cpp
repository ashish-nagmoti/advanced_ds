#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    
    Node(int data) : data(data), left(nullptr), right(nullptr){};
};

Node *buildTree(int pre[], int in[], int instart, int inend, int& preindex)
{
    if (instart > inend)
    {
        return NULL;
    }
    int index;
    Node *newn = new Node(pre[preindex++]);
    if (instart == inend)
    {
        return newn;
    }
    for (int i = instart; i <= inend; i++)
    {
        if (in[i] == newn->data)
        {
            index = i;
            break;
        }
    }
    newn->left = buildTree(pre, in, instart, index - 1, preindex);
    newn->right = buildTree(pre, in, index + 1, inend,  preindex);
    return newn;
}
void printPreorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPostorder(Node *root)
{
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}
int main()
{
    int choice;
    int n;
    cout << "No of elements in order:";
    cin >> n;
    int pre[n], in[n];
    for (int i = 0;i < n; i++)
    {
        cout << "pre:";
        cin >> pre[i];
    }
    for (int i = 0;i < n; i++)
    {
        cout << "in:";
        cin >> in[i];
    }
    int preindex = 0;
    Node *root = buildTree(pre, in, 0, n - 1, preindex);

    do
    {
        cout << "1.preorder" << endl
             << "2.postorder" << endl
             << "3.inorder" << endl
             << "4.exit" << endl
             << "enter a choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            printPreorder(root);
            break;
        case 2:
            printPostorder(root);
            break;
        case 3:
            printInorder(root);
            break;
        case 4:
            cout << "exiting";
            return 0;
        }
    } while (choice != 4);
}