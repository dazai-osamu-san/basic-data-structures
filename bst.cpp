#include "iostream"
using namespace std;

/* Binary search trees */

typedef struct node {
    int data;
    node *left;
    node *right;
} node; 

node* insert(int data, node *lroot){ 
    if(lroot==nullptr){
        node *new_node = new node();
        new_node->data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    } else if(data < lroot->data){
        // since the data is less it will be the left
        // child, from here if there are even more children
        // we pass the left address the root address to go even
        // deeper
        lroot->left = insert(data, lroot->left); 
    } else {
        lroot->right = insert(data, lroot->right);
    }
    return lroot;
}
// left root right
void display_inorder(node *lroot){
    if(!(lroot == nullptr)) {
        display_inorder(lroot->left);
        cout << lroot->data << endl;
        display_inorder(lroot->right);
    }
}

// root left right
void display_preorder(node *lroot){
    if(!(lroot == nullptr)) {
        cout << lroot->data << endl;
        display_preorder(lroot->left);
        display_preorder(lroot->right);
    }
}
// left right root
void display_postorder(node *lroot){
    if(!(lroot == nullptr)) {
        display_postorder(lroot->left);
        display_postorder(lroot->right);
        cout << lroot->data << endl;
    }
}
int main()
{   
    node* root = nullptr;
    root = insert(10, root);
    root = insert(20, root);
    root = insert(4, root);
    root = insert(7, root);
    display_inorder(root);
    cout << endl;
    display_preorder(root);
    cout << endl;
    display_postorder(root);
    return 0;
}
