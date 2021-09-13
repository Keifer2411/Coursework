//Bubble Sort, Selection Sort, Insertion Sort
#include <iostream>
#include <time.h>

using namespace std;
int main()
{
    clock_t t1, t2; //you can take difference between clock variables to find time it takes from one part of your program to another; 
    t1 = clock();

    int arr[5] = {15,4,3,1,10};
    int arr2[5] = {15,4,3,1,10};
    //Bubble sort
    for (int pass=1; pass<5;pass++)
    {
        for (int i =0; i <5; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]); //use temp variable if you want to this manually
            }
        }
    }

    //selection sort

    for (int i =0; i < 5;i++)
    {
        int min =arr2[i];
        int minIndex = i;
        for (int j = i; j < 5; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr2[i], arr[minIndex]);
    }

    t2 = clock();
    for (int i=0; i <5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
     for (int i=0; i <5; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << (t2-t1)/CLOCKS_PER_SEC << endl;
    return 0;
    
}