#include <vector> // Using string vectors instead of string arrays.
#include <fstream> // File stream.
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <chrono> // Library for system clock time calculations.
#include <string> // For string operations

using namespace std;

static int getDigit(int position, const string& value, int radix)
{
    char character = value[9-position];
    return (int)character-48; // Value of character '0' in ASCII is 48.
}

static void countSort(vector<string>& arr,int size, int position, int radix)
{
    vector<string> tempArray(size);
    int* countArray = new int[radix];
    for (int i=0; i<radix; i++) countArray[i]=0;
    for (int i=0; i<size; i++) countArray[getDigit(position, arr[i], radix)]++;
    for (int i=1; i<radix; i++) countArray[i] += countArray[i-1];
    for (int i=size-1; i>=0; i--) tempArray[countArray[getDigit(position,arr[i],radix)]---1] = arr[i];
    for (int i=0; i<size; i++) {arr[i] = tempArray[i];}
}


static void radixSort(vector<string>& arr, int radix, int size) // using radix sort.
{for (int i=0; i<10; i++) countSort(arr, size, i, radix);} // 10 digits = 10 iterations.

 // MAIN PROGRAM
int main()
{
    // Readying File.
    vector<string> wordList; // Using string vectors instead of string arrays.
    ifstream wordFile("4M_random_numbers.csv"); // Opens given file.
    chrono::time_point<chrono::system_clock> start1 = chrono::system_clock::now();
	if (wordFile.is_open())
    {
        string str;
        while(getline(wordFile,str)) wordList.push_back(str);
    }
	wordFile.close();

    chrono::time_point<chrono::system_clock> end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed1 = end1 - start1; // Calculates time elapsed to load. (in seconds)
    cout<<"Time taken to load: "<<elapsed1.count()<<"s";
    int arrSize = wordList.size();
    cout<<"\n-------------------\nSorting...";
    chrono::time_point<chrono::system_clock> start2 = chrono::system_clock::now();
    
    radixSort(wordList,10,arrSize); // Start sorting using Radix Sort technique.
    
    chrono::time_point<chrono::system_clock> end2 = chrono::system_clock::now();
    chrono::duration<double> elapsed2 = end2 - start2; // Calculates time elapsed to sort. (in seconds)
    cout<<"\nTime taken to sort: "<<elapsed2.count()<<"s";
    // Writing after sorting in a new file.
    ofstream outWordFile("4M_random_numbers-Sorted.csv");
    if (outWordFile.is_open())
    {
        for (int i=0; i<arrSize; i++)
        {
            outWordFile.write(wordList[i].c_str(), wordList[i].size());
            outWordFile.put('\n');
        }
    }
    outWordFile.close();
}