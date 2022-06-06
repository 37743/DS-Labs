#include <iostream>
using namespace std;

void selectionSort(int a[], int nElems) {
    int out, in, min;
    for (out=0; out<nElems-1; out++)
    {
        int min = out;
        for (in=out+1; in<nElems; in++)
            if (a[in]<a[min]) min = in;
        swap(a[out],a[min]);
    }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {11,4,15,1,3,9,8};
  int size = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, size);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}