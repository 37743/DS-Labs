// Yousef Ibrahim Gomaa Mahmoud - 320210207

// Sorting an array of strings using radix sort.
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(string arr[], int n) // Print Func.
{for (int i=0; i<n; i++) cout << arr[i] << "\n";}

static int getDigit(int position, string value, int radix) // Gets value of current letter in decimal.
{
    char character = value[2-position]; // gets position 0 then 1 then 2. (as given strings are 3 letters each)
    return (int)character-65; // 65 is the value of character 'a' in ASCII. 
}

static void countSort(string arr[],int size, int position, int radix) // String count sort.
{
    string* tempArray = new string[size];
    int* countArray = new int[radix];
    for (int i=0; i<radix; i++) countArray[i]=0; // Fill all of the temporary array with zeroes. (in order to prevent errors when incrementing)
    for (int i=0; i<size; i++) countArray[getDigit(position, arr[i], radix)]++;
    for (int i=1; i<radix; i++) countArray[i] += countArray[i-1];
    for (int i=size-1; i>=0; i--) tempArray[countArray[getDigit(position,arr[i],radix)]---1] = arr[i]; // Post-decrements and subtracts index by 1.
    for (int i=0; i<size; i++) {arr[i] = tempArray[i];} // Copy into permanent array.
}


static void wordRadixSort(string arr[], int radix, int size)
{for (int i=0; i<3; i++) countSort(arr, size, i, radix);} // 3 iterations for each letter in the string.

 // MAIN PROGRAM
int main()
{
    string wordArr[] = {"COW", "DOG", "SEA", "RUG", "ROW", "MOB", "BOX", "TAB",
    "BAR", "EAR", "TAR", "DIG", "BIG", "TEA", "NOW", "FOX"}; // Given array.
    int arrSize = sizeof(wordArr)/sizeof(wordArr[0]);
    int radix = 25; // Dependent on alphabet.
    printArray(wordArr,arrSize);
    cout<<"-----------------\n";
    cout << "Sorted array: \n";
    wordRadixSort(wordArr,radix,arrSize); // Initiate sort.
    printArray(wordArr,arrSize);
}
