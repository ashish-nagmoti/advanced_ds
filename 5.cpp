#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* ExpressionTree(const string& prefix) {
    stack<Node*> st;
    for (int i = prefix.size() - 1; i >= 0; --i) {
        char ch = prefix[i];
        if (isalnum(ch)) {
            Node* node = createNode(ch);
            st.push(node);
        } else {
            Node* node = createNode(ch);
            node->left = st.top();
            st.pop();
            node->right = st.top();
            st.pop();
            st.push(node);
        }
    }
    return st.top();
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    cout << "Level-by-Level Traversal of Expression Tree:" << endl;
    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* currentNode = q.front();
            q.pop();

            cout << currentNode->data << " ";

            if (currentNode->left) {
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }
        cout << endl;
    }
}
void postOrderTraversal(Node* root) {
    if (root == nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void swapTreePointer(Node* root) {
    if (root == nullptr)
        return;
    swap(root->left, root->right);
    swapTreePointer(root->left);
    swapTreePointer(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    cout << "Expression Tree Node Deleted: " << root->data << " " << endl;
    delete root;
}

int main() {
    string prefixExpression;
    int choice;
    cout << "Enter the prefix Expression you want: ";
    cin >> prefixExpression;
    Node* root = ExpressionTree(prefixExpression);

    do {
        cout << "Enter Your Choice: \n 1.Create Expression Tree \n 2.Postorder Traversal \n 3.Inorder Traversal \n 4.Swap Tree Pointers \n 5.Delete Tree \n 6.Print Level by Level \n 7.Exit\n ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Expression Tree Successfully Created !" << endl;
                break;
            case 2:
                cout << "Postorder traversal: ";
                postOrderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 4:
                swapTreePointer(root);
                cout << "Tree Pointers Swapped" << endl;
                break;
            case 5:
                deleteTree(root);
                cout << "Expression tree is Deleted successfully" << endl;
                root = nullptr;
                break;
            case 6:
                levelOrderTraversal(root);
                break;
            case 7:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}