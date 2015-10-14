#include <stdio.h>
#include <math.h>

void swap(int *theArray, int a, int b) // gucci
{
    int aux;
    aux = theArray[a];
    theArray[a] = theArray[b];
    theArray[b] = aux;
}

// divides an array into two sets
int partition(int *a, int p, int r)
{
	int x = a[r];
	// this is the pivot
	int i = p - 1;


	for (int j = p; j < r; ++j)
	{
		// go thru the partition 
		if (a[j] <= x)
		{
			// if its less than the pivot
			i = i + 1;
			swap(a,i,j);
		}
	}
	swap(a,i+1,r);

	return i + 1;
}


void quicksort(int *a, int p, int r)
{
	if (p < r)
	{
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}
// https://www.youtube.com/watch?v=y_G9BkAm6B8

int main()
{

	int mike[] = {1,1, 14,3,2,16,9,24,10,4,8,7,3,0};

    int size = sizeof(mike)/sizeof(mike[0]);

    quicksort(mike, 0, size - 1);
    // book says start at length, and 1
    // but it's an array, so we start at 0, and the last index, which is the size - 1

    for (int i = 0; i < size; ++i)
    {
    	printf("%d\n", mike[i]);
    }


	return 0;
}