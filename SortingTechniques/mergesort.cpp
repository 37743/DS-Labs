// Lab 11 - Yousef Ibrahim Gomaa Mahmoud - 320210207

#include <iostream>
using namespace std;

void merge(int arr[], int left, int middle, int right)
 {
     int l = left, r = middle+1;
     int arr2C = 0; 
     int n = right - left + 1;
     int* arr2 = new int[n]; // Temporary Array

     while ((l <= middle) && (r <= right))
     {
        if (arr[l] <= arr[r]) arr2[arr2C++] = arr[l++]; // Ascring Sorting
        else arr2[arr2C++] = arr[r++];   
      }
      while (l <= middle) arr2[arr2C++] = arr[l++]; // Fills in with the rest
      while (r <= right) arr2[arr2C++] = arr[r++]; // of the unfinished array.
      for (int i=0; i<n; i++) arr[left+i] = arr2[i]; // Update the initial array with the sorted temporary array.
      delete[] arr2; // Frees memory of temporary array.
 }

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle+1, right);
    merge(arr, left, middle, right);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}