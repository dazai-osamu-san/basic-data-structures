/*#include "iostream"
using namespace std;

int main()
{
    int array[5] = {99, 420, 77, 88, 120};
    int empty[5] = {0}; // create same sized sorted array
    // start iterating through the array 

    for(int i = 0; i < 5; i++){
        int value = array[i];
        int j = 0;
        for(j = 0; j < i; j++){
            if(i == 0){
                empty[0] = value;
            } else if(value > empty[j]){
                array[j] = array[j+1];
            }
        }
        empty[4-j] = value;
    }
    

    for (size_t i = 5; i > 0; i--)
    {
        cout << empty[i] << " ";
    }
    
    return 0;
}*/

#include <iostream>
using namespace std;

int main() {
    int array[5] = {8, 3, 5, 2, 4};
    int n = 5;

    // Insertion sort
    for (int i = 1; i < n; i++) { // Start with the second element
        int current = array[i];  // The element to be inserted
        int j = i - 1;

        // Shift elements that are larger than current to the right8
        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }

        // Insert the current element in its correct position
        array[j + 1] = current;
    }

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

