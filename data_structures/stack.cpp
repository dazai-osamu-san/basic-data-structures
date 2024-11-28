#include "iostream"
/* Stack Using Array */

/*
 * Operations of stack
 * 1. Push
 * 2. Pop
 * 3. display
 * 4. Peek
*/

/* Stack initialization */
// initialize the stack with all zeros
int my_stack[5+1] = {0};
int stack_pointer;
void init_stack(){
    // set 0th position as -1 to indicate start of the stack
    my_stack[0] = -1;

    // init the stack pointer to 0
    stack_pointer = 0;
}

/* Check if the stack is empty */
unsigned int is_empty(){
    // stack is empty if stack pointer is at 0 (-1 pos)
    if(stack_pointer == 0){
        return 1;
    } else {
        return 0;
    }
}

/* Check if stack is full */
unsigned int is_full(){
    // stack is full if stack pointer is pointing to max value (6)
    if(stack_pointer == 5){
        return 1;
    } else {
        return 0;
    }
}

/* Push operation */
void push(int data){
    // first check if stack is full
    if(!(is_full())){
        // if not
        // increment stack pointer
        stack_pointer++;
        
        // set value
        my_stack[stack_pointer] = data;
    } else {
        // print stack overflow
        std::cout << "stack overflow!" << std::endl;
        return;
    }
}

/* Pop operation */
void pop(){
    // check if stack is empty
    if(is_empty()){
        // if yes show cant pop
        std::cout << "Stack is empty" << std::endl;  
        return;
    } else {
        // if not 
        // set value to 0
        my_stack[stack_pointer] = 0;
     
        // decrement stack pointer
        stack_pointer--;
    }
}

void display(){
    for(int i = 5; i > 0; i--){
        std::cout << " " << my_stack[i] << " " << std::endl;
        std::cout << "----" << std::endl;
    }
}

int main(){
    init_stack();
    push(10);
    push(20);
    push(30);
    display();
    std::cout << std::endl;
    pop();
    display();
    return 0;
}
