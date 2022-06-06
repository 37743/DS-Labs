#include <iostream>
using namespace std;

void insertionSort(int a[], int n)
{
    for (int i = 1; i<n; i++)
    {
        int next = a[i];
        int j;

        for (j=i-1; j>=0 && a[j] > next; j--) a[j+1] = a[j];
        a[j+1] = next;
    }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {11,4,15,1,3,9,8};
  int size = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, size);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}