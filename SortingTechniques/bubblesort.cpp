#include <iostream>
using namespace std;

void bubbleSort(int a[], int nElems) {
    int i, j;
    for (i=0; i<nElems+1; i++)
    {
        for (j=i+1; j<nElems; j++)
            if (a[i]>a[j]) swap(a[i],a[j]);
    }
    cout<<"Array is now sorted!"<<endl;
}
void bubbleSortv2(int a[], int nElems) {
    int i, j;
    for (i=0; i<nElems+1; i++)
    {
        bool is_sorted = true;
        for (j=i+1; j<nElems; j++)
            if (a[i]>a[j])
            {
                is_sorted = false;
                swap(a[i],a[j]);
            }
        if (is_sorted == true)
        {
            cout<<"Array is already sorted."<<endl;
            return;
        }
    }
}


void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {11,4,15,1,3,9,8};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);
  bubbleSortv2(arr,size);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}