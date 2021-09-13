//merge sort - divide recursively, conqure - merge
//remember only the divide is recursive, the conqure is not
//space complex because you have to make a bigger array to fit the arrays - O(n) space complexity
#include <iostream>
using namespace std;

//example from https://www.geeksforgeeks.org/merge-sort/ used as guide
void combine(int arr[], int l, int m, int r)
{
    int sizeArr1 = m-l + 1;
    int sizeArr2 = r-m;

    //create the two arrays to merge
    int Arr1[sizeArr1];
    int Arr2[sizeArr2];

    for (int i = 0; i< sizeArr1; i++)
    {
        Arr1[i] = arr[l+i]; //in this example l is 0]
    }
    for (int j = 0; j< sizeArr2; j++)
    {
        Arr2[j] = arr[m+j+1];
    }

    int i=0; //posinArr1
    int j=0; //posinArr2
    int k=l; //posinMerged

    while (i<sizeArr1 && j<sizeArr2) 
    {
        if (Arr1[i] <= Arr2[j]) {
            arr[k] = Arr1[i];
            i++;
        }
        else {
            arr[k] = Arr2[j];
            j++;
        }
        k++;
    }
    while (i < sizeArr1) {
        arr[k] = Arr1[i];
        i++;
        k++;
    }
    while (j < sizeArr2) {
        arr[k] = Arr2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right)
{
    if(left >= right)
    {
        return;
    }

    else{
        int mid= left+(right-left)/2;
        mergesort(arr,left, mid); // left side divide - the combine function does the heavy work as these recursive calls only determine the indicies which will be used in the combine function
        mergesort(arr, mid+1, right); //right side divide
        combine(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {5, 18, 5, 16, 8, 11, 6, 7};
    int len = 8;
    mergesort(arr, 0, len-1);
    for (int i =0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}