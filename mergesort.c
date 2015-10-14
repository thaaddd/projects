#include <stdio.h>
#include <math.h>

void mergeSort(int *theArray, int p, int r);
void merge(int *theArray, int p, int q, int rp);
// forward declaration


int main()
{
    int mike[] = {5,2,4,7,1,3,2,6,42};
    // the sample array
    
    int size = sizeof(mike)/sizeof(mike[0]);
    // this is the size of the array
    
    mergeSort(mike, 0, size - 1);
    // takes the result of mergeSort and puts it in
    
    for (int l = 0; l < size; l++) {
        printf("%d\n", mike[l]);
    }
    // prints the array
    
}

void mergeSort(int *theArray, int p, int r)
{
    if (p < r) {
        int q = floor((p + r) / 2);
        mergeSort(theArray, p, q);
        mergeSort(theArray,q+1,r);
        merge(theArray,p,q,r);
    }
    
   // return theArray;
}

void merge(int *theArray, int p, int q, int rp)
{
    int n1 = q - p + 1;
    int n2 = rp - q;
    // computes the length of n1 and n2

    int l[n1 + 1];
    int r[n2 + 1];
    // declares the arrays l & r, which are one more than n1 & n2, respectfully
    
    for (int i = 1; i <= n1; i++) {
        l[i] = theArray[p + i - 1];
    }
    // copies the subarray of theArray[p..q] into l[1..n1]
    
    for (int j = 1; j <= n2; j++) {
        r[j] = theArray[q + j];
    }
    // copies the subarray of theArray[q + 1..r] into r[1..n2]


    l[n1 + 1] = 9999;
    r[n2 + 1] = 9999;
    // setting the sentinals at infinite,
    // or for our purposes, 9999
    
    int i = 1;
    int j = 1;
    // duh
    
    for (int k = p; k <= rp; k++) {
        if (l[i] <= r[j]) {
            theArray[k] = l[i];
            i = i + 1;
        }
        else
        {
            theArray[k] = r[j];
            j = j + 1;

        }
    }
    // this is the part that actually sorts the array
    // the way merge sort works is, and I'm borrowing this from CLRS,
    // but it's the best way to explain it.
    // think if you have to stacks of sorted playing cards, with the
    // smallest on top of each stack, this compares the top two cards,
    // and puts the smaller into the next slot of the array
    // the reason the sentinal is set for infinite is so that, since
    // one array is obviously going to finish before the other,
    // the array with actual values will be put next in the order
    // and when both l & r run out, the loop is over
    // ensuring that it doesn't come down to infite vs. infinite

}
