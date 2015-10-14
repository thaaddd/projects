#include <stdio.h>
#include <math.h>

int parent(int i);
int left(int i);
int right(int i);
void maxHeapify(int *a, int i, int size);
void swap(int *theArray, int a, int b);
void buildMaxHeap(int *a, int size);
void heapSort(int *a, int size);

// forward declaration


int main()
{
    int mike[] = {0,4,1,3,2,16,9,10,14,8,7};
    // the sample array
    // this first value is 0 because in heaps
    // the first value must be one in order to work correctly
    
    int size = sizeof(mike)/sizeof(mike[0]);
    // this is the size of the array
    
    
    
    heapSort(mike, size);
    
    for (int l = 1 + 1; l < size +1; l++) {
        printf("%d\n", mike[l]);
    }
    // prints the array
    // printing from 1, becuase it starts at 1
    
}

void buildMaxHeap(int *a, int size) // this is good
{
    for (int i = floor(size/2); i >= 1; i--)
    {
        maxHeapify(a, i, size);
    }
    // this loop starts at the middle of the array and then goes up to the root
    // calling max heapify each time, that basically builds a heap from the
    // bottom up, ensuring that each subtree is a heap
}

void heapSort(int *a, int size)
{
    buildMaxHeap(a, size);
    
    for (int i = size; i >= 2; i--)
    {
        swap(a, 1, i);
        size--;
        maxHeapify(a, 1, size);
    }
    
    
}

void maxHeapify(int *a, int i, int size)
{
    int l = left(i);
    int r = right(i);
    // returns the left and right child of the node
    
    int largest;
    
    if (l <= size && a[l] > a[i])
    {
        largest = l;
    }
    else
        largest = i;
    //
    
    if (r <= size && a[r] > a[largest])
    {
        largest = r;

    }
    //
    
    if (largest != i) {
        swap(a, i, largest);
        maxHeapify(a, largest, size);

    }
    //
}

int parent(int i) // gucci
{
    return floor(i/2);
}

int left(int i) // gucci
{
    return 2*i;
}

int right(int i) // gucci
{
    return 2*i + 1;
}

void swap(int *theArray, int a, int b) // gucci
{
    int aux;
    aux = theArray[a];
    theArray[a] = theArray[b];
    theArray[b] = aux;
}
