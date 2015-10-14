#include <stdio.h>
#include <math.h>

void bubbleSort(int *theArray, int length);
void swap(int *theArray, int a, int b);
// forward declaration


int main()
{
    int mike[] = {5,2,4,7,1,3,2,6,4};
    // the sample array
    
    int size = sizeof(mike)/sizeof(mike[0]);
    // this is the size of the array
    
    bubbleSort(mike, size);
    
    for (int l = 0; l < size; l++) {
        printf("%d\n", mike[l]);
    }
    // prints the array
    
}

void bubbleSort(int *theArray, int length)
{
    for (int i = length - 1; i > 0; i--) {
        // goes through the loop twice, this is the first time,
        // and we're going backwards. it's nessecary to go through n times
        // twice to ensure the entire is sorted
        for (int j = 0; j < i; j++) {
            // frontwards this time
            if (theArray[j] > theArray[j + 1]) {
                // the comparison
                swap(theArray, j, j + 1);
                // swap em
            }
        }
    }
}

void swap(int *theArray, int a, int b)
{
    int aux;
    aux = theArray[a];
    theArray[a] = theArray[b];
    theArray[b] = aux;
}
// the swap

