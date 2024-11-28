#include "iostream"

// use this for the sake of saving typing 
using namespace std;
/* Queues using linked lists */
// almost the exact same as using a normal linked list



/* operations on queues 
 * 1. enqueue
 * 2. dequeue
 * 3. Display
 */

/* node structure */
typedef struct node {
    int data;
    node *next;
} node;

/* Initialize the queue */
node *front;
node *rear;

void init(){
    front = nullptr;
    rear = nullptr;
}

/* check if queue is empty */
unsigned int isEmpty(){
    if(rear == nullptr) return 1;
    else return 0;
}

/* Enqueue operation */
// this is the exact same as add to end
void enqueue(int data){
    // handle the case where it's the first node
    // to be enqueued
    if(front == nullptr){
        // create new node
        node *new_node = new node();
        
        // update new node
        new_node->data = data;
        new_node->next = nullptr;
        
        // update front and rear 
        front = new_node;
        rear = new_node;
    } else {
        node *new_node = new node();
        new_node->data = data;
        rear->next = new_node;
        new_node->next = nullptr;
        rear = new_node;
    }
}

/* Dequeue operation */
// the dequeue operation is the same as
// remove from head
void dequeue(){
    if(isEmpty()){
        cout << "empty queue" << endl;
        rear = nullptr;
        front = nullptr;
        return;
    }
    // create a temporary pointer front
    node *temp = front;
    
    // update front
    front = front->next;
    
    // delete the temporary pointer
    delete temp;
}

/* display operation */
// exactly the same as the display operation in 
// linked lists
void display(){
    node *temp = front;
    while(temp != nullptr){
        cout << " | " << temp->data;  
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    init();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    cout << endl;

    enqueue(99);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}
