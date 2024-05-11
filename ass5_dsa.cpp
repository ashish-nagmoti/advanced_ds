#include<iostream>
#include<stack>

using namespace std;

struct node
{
    char data;
    node* left;
    node* right;
    node(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

 node* Tree(const string& prefix)
 {
    stack<node*> s;

    for (int i = prefix.size() - 1; i >= 0; --i)
    {
        char c = prefix[i];

        node* newNode = new node(c);

        if (isOperand(c))
        {
            s.push(newNode);
        }
        else
        {
            newNode->left = s.top();
            s.pop();
            newNode->right = s.top();
            s.pop();
            s.push(newNode);
        }
    }
return s.top();
}

void postTraversal(node* root)
{
    if(root)
    {
        postTraversal(root->left);
        postTraversal(root->right);
        cout << root->data << " ";
    }
}

void deleteExp(node* root)
{
    if(root)
    {
        deleteExp(root->left);
        deleteExp(root->right);
        cout<<"Deleted Node : "<<root->data<<endl;
        delete root;
       
    }
}

void swap(node* root)
{
 if(root == NULL)
 {
   return;
 }
 else
   swap(root->left, root->right);
   swap(root->left, root->right);
   swap(root->left, root->right);
 }
   

int main()
{
    string prefixExpression;
    cout<<"Enter the Prefix expression of the tree : ";
    cin>>prefixExpression;
    node* root = Tree(prefixExpression);
    postTraversal(root);

    int choice;
        cout << "\nMenu:\n";
        cout << "1. Traverse the given tree using postorder traversal.\n";
        cout << "2. Delete the given tree.\n";
        cout << "3. Swap the given tree. \n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Postorder Traversal : ";
                postTraversal(root);
                cout << endl;
                break;
            case 2:
                deleteExp(root);
                cout << "Expression tree deleted.\n";
                break;
            case 3:
                cout<<"the tree is swapped."<<endl;
                swap(root);
                break;
            default:
            cout<<"Invalid Input. Please try again..."<<endl;
        }
    return 0;
}


