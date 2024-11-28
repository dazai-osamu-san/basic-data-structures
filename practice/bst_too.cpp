#include "iostream"
using namespace std;

typedef struct node {

    int data;
    char alias;
    node *left;
    node *right;

} node;
char alias_cnt = 'A';
node* insert(node* lroot, int data){

    if(lroot==NULL){
        node *new_node = new node();
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->data = data;
        new_node->alias = alias_cnt++;
        return new_node;
    }
    if(data < lroot->data){
        lroot->left = insert(lroot->left, data);
    } else {
        lroot->right = insert(lroot->right, data);
    }
    return lroot;
}

void preorder(node* lroot){
    if(lroot != NULL){
        cout << lroot->data << endl;
        preorder(lroot->left);
        preorder(lroot->right);
    }
}

void search(node* lroot, int key){
    if(lroot != NULL){
        if(key == lroot->data){
            cout << "Found: " << lroot->data << "Alias: " << lroot->alias;
        } else if(key < lroot->data){
            cout<<"Left subtree"<<endl;
            search(lroot->left,key);
        } else {
            cout << "right subtree" << endl;
            search(lroot->right,key);
        }
    }

}

int main(){
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 12);

    preorder(root);
    search(root,6);
    return 0;
}