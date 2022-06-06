// Lab 11 - Yousef Ibrahim Gomaa Mahmoud - 320210207

#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int p = arr[start];
    int k = start; // First element for comparison.
    int c = start+1; // Iterator
    while(c <= end){
        if(arr[c] < p) {swap(arr[c], arr[++k]);}
        c++;
        if(arr[end] > p) end--; // Decrements the end as it would take longer time to process the rest.
    }
    swap(arr[start],arr[k]);
    return k; // Returns the sorted array index.
}

void printArray(int arr[], int size)
{
    for (int i = 0; i<size; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end) return;
    int pivotIndex = partition(arr,start,end);
    printArray(arr, end);
    cout << "this is the pivot:" << pivotIndex << endl;
    quickSort(arr, start, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);
}



int main()
{
    int arr[] = {9,3,4,2,1,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size-1);
    cout<<"Sorted array: \n";
    printArray(arr,size);
    return 0;
}