#include "iostream"
using namespace std;



int main()
{
    // selection sort
    // find smallest element
    // swap that element
    const int n = 7;
    int a[n] = {99,88,3,420,69,73,211}; 
    int passes = 0;
    int smv;// assume a(0) to be smallest value

    while(passes < n){
        // update smallest value to next one
        smv = passes;
        for(int i = passes+1; i < n; i++){
            // compare current element with next elements and update 
            // the smallest element
            if(a[smv] > a[i]){
                smv = i;
            }
        }
        // swap 
        int temp = a[passes];
        a[passes] = a[smv];
        a[smv] = temp;
        // increment passes
        passes++;
    }

    // print sorted array
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    

    return 0;
}
