#include <stdio.h>
void printAll (int array[], int start, int end);
void printMergeTreeStatus(int array[], int start, int mid, int end, int n);
void mergeSort(int array[], int start, int end, int n);
void merge(int array[], int start, int end, int mid);

int mainArray[6] = {5, 2, 1, 3, 6, 4};
int mainArray1[6] = {3, 6, 4, 5, 2, 1};
int mainArray2[6] = {4, 1, 3, 6, 5, 2};


int main() {
    //	Attempt a Merge Sort Algorithm
    int start = 0;
    int end = 5;
    printAll(mainArray, 0, 5);
    mergeSort(mainArray, start, end, 0);
    printf("\n");
    printAll(mainArray1, 0, 5);
    mergeSort(mainArray1, start, end, 0);
    printf("\n");
    printAll(mainArray2, 0, 5);
    mergeSort(mainArray2, start, end, 0);
}

void mergeSort(int array[], int start, int end, int n)
{
	if (start != end)
    {
    	int mid = (start + end) / 2;
        //	printMergeTreeStatus(array, start, mid, end, n);

        //	Determine Left Sub-Array
        mergeSort(array, start, mid, n+1);
    	//	Determine Left Sub-Array
        mergeSort(array, mid+1, end, n+1);
        //	Merge
        merge(array, start, mid, end);
        //	View main array after merging sub-arrays
        printAll(array, 0, 5);
    }
}

void merge(int array[], int start, int mid, int end)
{
	//	Size of sub-arrays
	int n1 = (mid - start) + 1;
	int n2 = (end - (mid+1)) + 1;
    //	Temporary sub-arrays
    int L[n1];
    int R[n2];
    //	Counter for merging sub-arrays
    int x = 0;
    //	Counter for each sub-array
    int l = 0;
    int r = 0;

    //	Copy data from main array into current sub-arrays
    for (int i = 0; i < n1; i++)
    {
    	L[i] = array[start+i];
    }
    for (int j = 0; j < n2; j++)
    {
    	R[j] = array[(mid+1)+j];
    }

    /*
    printf("Start: %i	|	Mid: %i	|	End: %i\nn1: %i	|	n2: %i\n", start,mid,end,n1,n2);
    printAll(L, 0, n1-1);
    printAll(R, 0, n2-1);
    printf("\n");
    */

    //	Only repeat for the x amount of times (X = size of merged array)
    while (x < (n1+n2))
    {
    	//	In case, right sub-array is finished OR (Element at Left is < element at Right AND left sub-array has not yet finished)
    	if (r >= n2 || (l < n1 && L[l] < R[r]))
        {
        	//	printf("%i is smaller [L]\n", L[l]);
        	array[start+x] = L[l];
            l++;
        }
        //	Will only trigger if either left sub-array has finished OR element at Right is < element at Left
        else
        {
           	//	printf("%i is smaller [R]\n", R[r]);
        	array[start+x] = R[r];
            r++;
        }
        x++;
    }
    //	printf("\n");
}

void printAll(int array[], int start, int end)
{
	for (int i = start; i <= end; i++)
    {
    	printf("%i ", array[i]);
    }
    printf("\n");
}

void printMergeTreeStatus(int array[], int start, int mid, int end, int n)
{
	printf("[%i] Current array: ", n);
   	printAll(array, start, end);
   	printf("Start: %i | Mid: %i | End: %i\n", start, mid, end);
    printf("[%i] Left sub array: ", n);
  	printAll(array, start, mid);
   	printf("[%i] Right sub array: ", n);
   	printAll(array, (mid+1), end);
   	printf("\n\n");
}
