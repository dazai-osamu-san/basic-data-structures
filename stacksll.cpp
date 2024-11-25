#include "iostream"
/* Stacks with linked lists */

/* it will have the same operations as that of normal stacks 
 * 1. Push
 * 2. Pope
 * 3. display
 * 4. Peek
 */

// for simplicity's sake we'll just set global namespace
using namespace std;

/* create the node structure */
typedef struct node {
    int data;
    node* next;
} node;

node *base;
node *head;

/* initialize the stack */
void init(){
    // create the base node
    node *minus_one = new node();
    // set the tail and head to the base node
    base = minus_one;
    head = minus_one;
}

/* check if the stack is empty */
unsigned int isEmpty(){
    if(base == head){
        return 1;
    } else {
        return 0;
    }
}

/* Push operation */
// this operacion is to add to head
void push(int data){
    // create a new node
    node *new_node = new node();
    
    // put the data in
    new_node->data = data;

    // update new node to point to previous node
    new_node->next = head;

    // update the head
    head = new_node;
}

/* Pop operation */
// this is exactly the same as the remove from head operation
void pop(){
    // check if stack is empty
    if(isEmpty()){ std::cout << "Stack is Empty" <<std::endl;; return;}
    // create a temp node to point to current head
    node *temp = head;
    
    // update head
    head = head->next;
    
    // delete temp to free memory
    delete temp;
}

/* display operation */
// exactly the same as displaying the SLL
void display(){
    node *temp = head;
    while(temp != base){
        std::cout << "| " << temp->data << " |" << std::endl;
        std::cout << "-----" << std::endl;
        temp = temp->next;    
    }
}

int main(){
    
    init();
    push(10);
    push(20);
    push(30);
    display();
    std::cout << std::endl;
    
    pop();
    push(69);
    push(77);
    push(88);
    push(99);
    display();
    std::cout << std::endl;
    
    for(int i = 0; i < 5; i++){pop();}
    display();
    cout << endl;
    pop();
    display();
    pop();
    
    return 0;

}

