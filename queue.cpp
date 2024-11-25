#include "iostream"
/* Queues using array */

/* Operations on queues
 * 1. Enqueue
 * 2. Dequeue
 * 3. Display
 * 4. Is Full?
 * 5. Is empty?
 */

/* Queue initialization */

// create the queue
int queue[5] = {0};

// create the front and end of the queue
int front, end;

void init_queue(){
    // both will be set to NULL by default
    front = 0;
    // we'll initialize end to -1 so that we won't have
    // issues dealing with the first enqueue later
    end = -1;
}

/* Check if queue is empty */
unsigned int is_empty(){
    // if the front and end are at same position the queue
    // is empty
    if(front == end){
        return 1;
    } else {
        return 0;
    }
}

/* check if queue is full */
unsigned int is_full(){
    // if the end is at array max len
    // the queue is full
    if(end == 4){
        return 1;
    } else {
        return 0;
    }
}

/* Enqueue */
void enqueue(int data){
    // check if queue is full
    if(is_full()){ std::cout << "Full queue" << std::endl; return;}

    // first increment the end and set value
    end++; queue[end] = data;
}

/* Dequeue */
void dequeue(){
    // check if queue is empty
    if(is_empty()){
        std::cout << "Empty queue" << std::endl;
        return;
    }
    // now we need to dequeue using the front
    // set front = 0
    queue[front] = 0;
    // shift the array
    for(int i = 0; i < 5; i++){
        // for n, i = i+1
        queue[i] = queue[i+1];
    }
    // decrement the end
    end--;
}

/* display operation */
void display(){
    for(int i = 0; i<=end; i++){ // end is also included so <=
        std::cout << queue[i] << ",";
    }
    std::cout << std::endl;
}

int main(){
    init_queue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    std::cout << std::endl;
    dequeue();
    dequeue();
    display();
    return 0;
}
