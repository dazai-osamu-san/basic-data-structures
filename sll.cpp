/*
singly linked lists

we have a node that is linked together in
one direction

operations:
1. insert
2. delete
3. traverse

*/

// Include the basics
#include "iostream"

/*
define the structure for one node
*/

typedef struct node {
    int data;   // data
    node* next; // pointer to next node
} node;

/* Initialize the linked list
 * we'll manually initialize the linked list by connecting
 * the pointers together.
*/

// define nodes
node one,two,three,four,five; // start with a intial size of 5
node *head;
node *tail;
void init_list(){

    head = &one; // define the head node

    // define data for each
    one.data =   10;
    two.data =   20;
    three.data = 30;
    four.data =  40;
    five.data =  50;

    // connect the lists
    one.next =   &two;
    two.next =   &three;
    three.next = &four;
    four.next =  &five;
    five.next =  NULL;

    tail = &five;
}

/* Display the list
 * just go through the entire list and print the value
*/
void display(){
    // we'll have a temporary pointer that will go 
    // through the entire list
    node *temp = head;
    // keep going until we reach the last where pointer is null
    while(temp != NULL){
        // print the value
        std::cout << temp->data << " ";
        // next node
        temp = temp->next;
    }
}

/*
* Insertion operation
* Three variants:
* insert at end
* insert at start/head
* insert at index n
*/

// starting with insert at end
void insert_at_end(int data){
    // use maintained tail
    // mistake made here: tried to go to the last node but
    // you accidently end up dereferencing a null pointer.
    // instead maintain size or maintain tail

    node *temp = tail;
    
    // create new node
    node *new_node = new node();

    // update last node's pointer to point to new node
    temp->next = new_node;

    // update new node's pointer to null
    new_node->next = NULL;
    
    // update new node's data to data
    new_node->data = data;
}

// insert at start
void insert_at_start(int data){
    // we'll first create a new node
    node *new_node = new node();

    // update new node with head address
    new_node->next = head;
    new_node->data = data;

    // update head address
    head = new_node;
}

// insert at index n
void insert(int index, int data){
    // traverse to the index-1 by pointer jumping
    node *temp = head;
    for(int i = 0; i < index-1; i++){ temp = temp->next; }

    // create a new node
    node *new_node = new node();

    // update new node's address with previous node's
    new_node->next = temp->next;
    new_node->data = data;
    
    // update previous node's address with new node
    temp->next = new_node;
}


/* Deletion from list
 * There are again 3 variants
 * deletion from head
 * deletion from end
 * deletion of n'th index
 */

// Deletion from head
void delete_from_head(){
    // update the head pointer to point to head's next pointer
    head = head->next;
}

// Deletion from end
// this is the bit tricker one
// we either maintain the size of the linked list
// or calculate the size in the function and then do it.
// for this example we'll calculate the size here as it 
// doesn't really matter here
void deletion_from_end(){
    // calculate list size
    int size = 0;
    node *temp = head;
    while(temp != NULL){ temp = temp->next; size++; }
  
    // traverse to list_size-1
    node *trav_point = head;
    for (size_t i = 0; i < size-2; i++)
    {
        trav_point = trav_point->next;
    }
    
    // set list_size-1 to NULL
    trav_point->next = NULL;
    
    // delete tail's data
    delete temp;
    
    // update tail
    tail = trav_point;
}

//delete from n'th index
void delete_from_n(int index){
    // go to n-1 index
    node *temp = head;
    for(int i = 0; i < index-1; i++){ temp = temp->next; }

    // update n-1 with pointer to next's pointer
    temp->next = temp->next->next;
}

// main function
int main(){
    // initialize the list
    init_list();
    
    // display the list
    display();
    std::cout << std::endl;
    
    // add elements at end
    insert_at_end(778);
    display();
    std::cout << std::endl;

    // add elements at start
    insert_at_start(88);
    display();
    std::cout << std::endl;
    
    // add element at index n
    insert(3, 57);
    display();
    std::cout << std::endl;

    // delete from start
    delete_from_head();
    display();
    std::cout << std::endl;
    
    // delete from end
    deletion_from_end();
    display();
    std::cout << std::endl;

    // delete from n
    delete_from_n(3);
    display();
    std::cout << std::endl;

}