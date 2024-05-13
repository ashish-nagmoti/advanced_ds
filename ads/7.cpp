#include<iostream>
using namespace std;

struct node{
    int a;
    node *left;
    node *right;
};

node *create(int item){
    node *ptr = new node;
    ptr -> a = item;
    ptr-> left = ptr->right = NULL;
    return ptr;
}

node* buildTree(int pre[], int in[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd)
        return NULL;

    node* newNode = create(pre[preIndex++]);

    if (inStart == inEnd)
        return newNode;

    int inIndex;
    for (int i = inStart; i <= inEnd; ++i) {
        if (in[i] == newNode->a) {
            inIndex = i;
            break;
        }
    }

    newNode->left = buildTree(pre, in, inStart, inIndex - 1, preIndex);
    newNode->right = buildTree(pre, in, inIndex + 1, inEnd, preIndex);

    return newNode;
}

void printPreorder(node* root) {
    if (root == NULL)
        return;
    cout << root->a << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->a << " ";
    printInorder(root->right);
}

void printPostorder(node* root) {
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->a << " ";
}

int main() {
    int preorder[] = {65, 19, 15, 28, 20, 74, 69, 88, 81, 95};
    int inorder[] = {15, 19, 20, 28, 65, 69, 74, 81, 88, 95};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    int preIndex = 0;

    node* root = buildTree(preorder, inorder, 0, n - 1, preIndex);

    cout << "Preorder traversal of the constructed tree:" << endl;
    printPreorder(root);
    cout << endl;

    cout << "Inorder traversal of the constructed tree:" << endl;
    printInorder(root);
    cout << endl;

    cout << "Postorder traversal of the constructed tree:" << endl;
    printPostorder(root);
    cout << endl;

    return 0;
}

