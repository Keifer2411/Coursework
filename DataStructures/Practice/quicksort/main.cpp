//quicksort 
//choose pivot -> partition about pivot -> recursively sort both parts
#include <iostream>
#include <algorithm>

using namespace std;

int partition (int arr[], int low, int high) //goal is to have all smaller numbers to the left of the pivot
{
    int pivot = high;
    int i = low -1;
    int j = low;
    for (;j<high; j++) //for loop until j reaches position before povot
    {
        if (arr[j] <= arr[pivot]) //if less than pivot
        {
            i++; //increment i
            swap(arr[i], arr[j]); //swap i and j
        }
    }
    i++;
    swap (arr[i], arr[pivot]); //swap pivot with element at i + 1
    return i; //position of pivot
}

void quicksort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int piv = partition(arr, low, high);
    quicksort(arr, low, piv-1);
    quicksort(arr, piv+1, high);
}


int main()
{
    int arr[] = {4, 6, 2, 7, 9, 2, 5, 2};
    int len = 8;
    quicksort(arr, 0, 7);
    for (int i =0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}
