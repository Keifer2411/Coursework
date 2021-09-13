//Bucket and Radix sort
//in bucket sort when you are inserting into the bucket you use insertion sort whereas in Radix sort you do the bucket sort multiple times per digit

#include <iostream>
#include <list>
using namespace std;

int max(int arr[], int size)  //get greatest number in array
{
    int _max = -1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > _max)
        {
            _max = arr[i];
        }
    }
    return _max;
}

void digitSort(int arr[], int size, int d) //count sort: https://cppsecrets.com/users/1039649505048495348575464115971151161149746979946105110/C00-Radix-Sort.php
{//sort according to one's digit, 10's digit, and then 100's digit
    int output[size];
    int buckets[10] = {0};
    int i;

    for (i =0; i < size; i++){buckets[(arr[i] / d) % 10]++;}
    for (i = 1; i < 10; i++) {buckets[i] += buckets[i - 1];}
    for (i = size - 1; i >= 0; i--) { 
        output[buckets[(arr[i] / d) % 10] - 1] = arr[i]; 
        buckets[(arr[i] / d) % 10]--; 
    } 
    for(i=0;i<size;i++){arr[i] = output[i];}
}

void RadixSort(int arr[], int size)
{
    int _max = max(arr, size);
    for (int i = 1; _max/i>0; i *=10){digitSort(arr, size, i);}
}

int main()
{
    
    int arr[] = {834, 65, 164, 223, 43, 67, 32, 411, 9, 44, 629, 79};
    int size = 12;

    RadixSort(arr, size);

    for (int i =0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}