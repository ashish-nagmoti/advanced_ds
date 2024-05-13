#include <bits/stdc++.h>
using namespace std;
struct Node
{
    string val;
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int key, string val) : key(key), val(val), left(nullptr), right(nullptr), height(1){};
};

int height(Node *N)
{
    if (N == nullptr)
    {
        return 0;
    }
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *rightrotate(Node *y)
{
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
Node *leftrotate(Node *y)
{
    Node *x = y->right;
    Node *t = x->left;

    x->left = y;
    y->right = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
Node *minNode(Node *node)
{
    Node *current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

int getBalance(Node *n)
{
    if (n == nullptr)
    {
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node *insert(Node *&node, int key, string val)
{
    if (node == nullptr)
    {
        return new Node(key, val);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key, val);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key, val);
    }
    else
    {
        return node;
    }

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }
    if (balance < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " " << root->val << endl;
        inorder(root->right);
    }
}
Node *del(Node *root, int key)
{
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = del(root->left, key);
    else if (key > root->key)
        root->right = del(root->right, key);
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minNode(root->right);
        root->key = temp->key;
        root->val = temp->val;

        root->right = del(root->right, temp->key);
    }
    if (root == nullptr)
        return root;

    // Step 2: Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Step 3: Get the balance factor
    int balance = getBalance(root);

    // Step 4: If the node is unbalanced, then try out the 4 cases
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightrotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftrotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

int main()
{
    int choice;
    Node *root = nullptr;
    do
    {
        cout << "1.insert" << endl
             << "2.inorder" << endl
             << "3.del node" << endl
             << "4.exit" << "Neter a choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            {int k;
            string val;
            cout << "enter a key(int):";
            cin >> k;
            cout << "enter a val";
            cin >> val;
            root = insert(root, k, val);
            break;}
        case 2:
            {inorder(root);
            break;}
        case 3:
            {int key;
            cout << "key you want to del";
            cin >> key;
            root = del(root, key);
            break;}
        case 4:
            cout << "exitintg";
            return 0;
        }
    } while (choice != 4);
}