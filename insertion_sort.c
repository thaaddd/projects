#include<stdio.h>

int * insertionSort(int *theArray, int k);
// forward declaration

int main()
{
    int mike[] = {5,2,4,6,1,3};
    // the sample array
    
    int size = sizeof(mike)/sizeof(mike[0]);
    // this is the size of the array
    
    
    int *sort = insertionSort(mike, size);
    // where the sorted array is stored,
    // used as the array sort[]
}

int * insertionSort(int *theArray, int k)
{
    
    
    for (int j = 1; j < k; j++) {
        // starts a loop at the second value in the array
        // in our case 1, because the first value is at 0
        // and goes for the length of the array
        
        int key = theArray[j];
        // setting key, the number to be compared
        
        int i = j - 1;
        // setting i, where we start the second loop
        
        while (i > -1 && theArray[i] > key) {
            // this loop original gave me some trouble
            // it must check to ensure that i > -1 because
            // i is going to be 0 on the first iteration
            // and the array would skip over this for the first
            // iteration and we would be left with an assorted array
            // with the initial value theArray[0] untouched
            
            theArray[i + 1] = theArray[i];
            // if the value in the array is smaller than the original key
            // (which is how we got into this loop)
            // then the key is inserted into it's place
            
            i -= 1;
            // duh
        }
        theArray[i + 1] = key;
        // and the original value is moved up a spot
        // and the array behind j is sorted

        
        for (int l = 0; l < k; l++) {
            printf("%d\n", theArray[l]);
        }
        printf("\n");
        // this prints the loop at each step
        // not each switch but so it's comparable to
        // CLR 3ed page 18
    }
    
    return theArray;
    // returns the array
    
}
