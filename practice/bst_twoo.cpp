#include "iostream"
using namespace std;
// structure
typedef struct node {
    int data;
    node* left;
    node* right;
} node;

// insert
node* insert(int data, node *lroot){
    if(lroot == nullptr){
        node *new_node = new node();
        new_node->data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    } else if(data < lroot->data){
        lroot->left = insert(data, lroot->left);
    } else {
        lroot->right = insert(data, lroot->right);
    }
    return lroot;
}

// preorder
void preorder(node* lroot){
    // root left right
    if(lroot!=nullptr){
        cout << lroot->data << " ";
        preorder(lroot->left);
        preorder(lroot->right);
    }
}
// inorder
void inorder(node* lroot){
    // root left right
    if(lroot!=nullptr){
        preorder(lroot->left);
        cout << lroot->data << " ";
        preorder(lroot->right);
    }
}
// postorder


int main()
{
    node *root = nullptr;
    root = insert(10,root);
    root = insert(20,root);
    root = insert(3,root);
    root = insert(23,root);
    preorder(root);
    return 0;
}
