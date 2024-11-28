#include "iostream"
using namespace std;

int main()
{
    int array[5] = {99, 420, 77, 88, 120};

    // Selection sort
    int passes = 0;
    while (passes < 5) {
        int smallest_value_index = passes; // Reset smallest index for this pass

        for (int i = passes + 1; i < 5; i++) {
            // Search for the smallest
            if (array[i] < array[smallest_value_index]) {
                smallest_value_index = i;
            }
        }

        // Swap with the smallest value index
        int temp = array[smallest_value_index];
        array[smallest_value_index] = array[passes];
        array[passes] = temp;

        passes++;
    }

    // Print sorted array
    for (int i = 0; i < 5; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
