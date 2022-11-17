// Yousef Ibrahim Gomaa Mahmoud - 320210207 - Group 4 - Section 10
#include <iostream>
using namespace std;

// "Heap Sort" Implementation in C++

void Heap(int arr[], int Size, int Index)
{
    int MAX = Index;
    int Left = Index*2 + 1; // Left of selected element according to heap tree.
    int Right = Index*2 + 2; // Right of selected element according to heap tree.
    if (Size > Left && arr[Left]>arr[MAX]) MAX = Left;
    if (Size > Right && arr[Right]>arr[MAX]) MAX = Right;
    if (MAX != Index)
    {
        swap(arr[Index], arr[MAX]); // Swap with the updated biggest element.
        Heap(arr, Size, MAX); // Then reheapify.
    }
}
 
void HeapSort(int arr[], int Size)
{
    for (int i = Size/2 - 1; i >= 0; i--) Heap(arr, Size, i);
    for (int i = Size-1; i > 0; i--) {
        swap(arr[0], arr[i]); // Rearrange current element to the end and shift the rest.
        Heap(arr, i, 0); // Continue reheapifying.
    }
}

int main()
{
    int A[] = {5, 13, 2, 25, 7, 17, 20, 8, 4}; // Given array.
    int ASize = sizeof(A)/sizeof(A[0]);
    HeapSort(A, ASize); // Start heapsorting.
    cout<<"{ ";
    for (int i = 0; i < ASize; i++) cout<<A[i]<<" "; // Standard print function for an array.
    cout<<"}\n";

} 