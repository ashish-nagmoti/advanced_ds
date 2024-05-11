#include <iostream>
using namespace std;

struct node
{
    char key;
    string data;
    node *left;
    node *right;
};

node *createNode(char key, string data)
{
    node *ptr = new node;
    ptr->key = key;
    ptr->data = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

node *insert(node *root, char key, string data)
{
    if (root == NULL)
        return createNode(key, data);
    if (key < root->key)
        root->left = insert(root->left, key, data);
    else if (key > root->key)
        root->right = insert(root->right, key, data);
    return root;
}

void display(node *root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << "Key: " << root->key << ", Value: " << root->data << endl;
        display(root->right);
    }
}

node *search(node *root, char key)
{
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    else    
    	return search(root->right, key);
}
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << "\n\t" << root->key << "\t" << root->data;
    inorder(root->right);
}
node *findMin(node *root)
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

node *deleteNode(node *root, char key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
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
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = findMin(root->right);
            root->key = temp->key;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    root = insert(root, 'f', "Fan");
    	   insert(root, 'd', "Dog");
    	   insert(root, 'e', "Elephant");
    	   insert(root, 'a', "Apple");
    	   insert(root, 'c', "Cat");
    	   insert(root, 'h', "Horse");
    	   insert(root, 'g', "Gate");
	
	cout<<endl;
    display(root);
	cout<<endl;
	
	inorder(root);
	cout<<endl;
    char toSearch[] = {'c', 'z'};
    for (int i = 0; i < sizeof(toSearch) / sizeof(toSearch[0]); i++)
    {
        char key = toSearch[i];
        node *result = search(root, key);
        if (result == NULL)
            cout << "Key: " << key << " Not found" << endl;
        else
            cout << "Key: " << key << " Found: " << result->data << endl;
    }
	cout<<endl;
	char keyToDelete = 'c';
    root = deleteNode(root, keyToDelete);
    
    cout << "\nAfter deleting node with key " << keyToDelete << ":" << endl;
    cout << "\n\tKEY\tVALUE" << endl;
    inorder(root);
    cout << endl;

    return 0;
}
