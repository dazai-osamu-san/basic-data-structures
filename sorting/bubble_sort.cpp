#include "iostream"
using namespace std;

int main()
{
    int array[6] = {1,8,7,99,98,88};

    // bubble sort
    for(int i = 0; i < 6; i++){ // go through the entire array
        for(int j = 0; j < i; j++){
            if(array[j] > array[j+1]){
                //swap
                int temp;
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    
    for(int x = 0; x<6;x++){
        cout << array[x] << " ";
    }
    return 0;
}
