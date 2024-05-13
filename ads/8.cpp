#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string value;
    int key;
    Node *left;
    Node *right;
    int height; 

    Node(int key, string value) : key(key), value(value), left(nullptr), right(nullptr), height(1) {}
};

int height(Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node* newNode(int key, string value)
{
    Node* node = new Node(key, value);
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; 
    return(node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}


// Helper function to find the node with the minimum key value
Node* minValueNode(Node* node) {
    Node* current = node;

    // loop down to find the leftmost leaf
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node*& node, int key, string value)
{
    //normal insnertionas
    if (node == nullptr)
        return(newNode(key, value));

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else 
        return node;

   //upadting heighat
    node->height = 1 + max(height(node->left), height(node->right));

    
    int balance = getBalance(node);

    

    // Left Left 
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right 
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right 
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left 
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

   
    return node;
}




void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
       cout << root->key << " " << root->value << endl;
        inorder(root->right);
    }
}
Node* deleteNode(Node* root, int key) {
    // Step 1: Perform standard BST delete
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;
        root->value = temp->value;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // Step 2: Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Step 3: Get the balance factor
    int balance = getBalance(root);

    // Step 4: If the node is unbalanced, then try out the 4 cases
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
string find(Node* root, int key) {
    if (root == nullptr)
        return "Key not found";
    if (key < root->key)
        return find(root->left, key);
    else if (key > root->key)
        return find(root->right, key);
    else
        return root->value;
}
void inorderDescending(Node *root) {
    if (root != nullptr) {
        inorderDescending(root->right);
        cout << root->key << " " << root->value << endl;
        inorderDescending(root->left);
    }
}
int main() {
    Node *root = nullptr;
    int choice, key;
    string value;

    while (true) {
        cout << "1. Insert\n2. Find\n3. Delete\n4. Display Ascending\n5. Display Descending\n6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value: ";
                cin >> key >> value;
                root = insert(root, key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                cout << "Value: " << find(root, key) << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            case 4:
                cout << "Ascending order:\n";
                inorder(root);
                break;
            case 5:
                cout << "Descending order:\n";
                inorderDescending(root);
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}

