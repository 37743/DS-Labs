#include <iostream>
using namespace std;


void printArray(int arr[], int size){for(int i=0; i<size; i++) cout<<arr[i]<<" ";}

int getMax(int arr[],int size)
{
    int MAX = arr[0];
    for (int i=1; i<size; i++) if (arr[i]>MAX) MAX = arr[i];
    return MAX;
}

void countSort(int arr[], int size, int exp)
{
    int* tempArr = new int[size];
    int i;
    int* count = new int[10];
    for (int i=0; i<10;i++) count[i] = 0;
    for (i=0; i<size; i++) count[(arr[i]/exp)%10]++;
    for (i=1; i<10; i++) count[i] += count[i-1];
    for (i=size-1;i>=0;i--) {tempArr[count[(arr[i]/exp)%10]-1] = arr[i];
    --count[(arr[i]/exp)%10];}
    for (i=0;i<size;i++) {arr[i] = tempArr[i];}
}

void radixSort(int arr[],int size)
{
    int exp = 1;
    int max = getMax(arr,size);
    for (int exp=1;max/exp>0;exp*=10) {countSort(arr,size,exp);}
}

int main()
{
    int arr[] = {51,26,19,15,80,39,12,73,43,12,34};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,arrSize);
    cout<<"\n-------------------\n";
    radixSort(arr,arrSize);
    printArray(arr,arrSize);
    
}