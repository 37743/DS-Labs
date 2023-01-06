// Yousef Ibrahim Gomaa Mahmoud - 320210207

// Sheet 9 - Question 1
#include <iostream>
#include <vector>
using namespace std;

// Maximum weight for the KnapSack problem
#define MAXWEIGHT 50
int solveKS(int maxW, vector <int> Weights,vector <int> Values, int n)
{
    if (maxW == 0 || n == 0) return 0; // Returns 0 & exits recursion if number of items to be put is 0
    if (maxW < Weights[n-1]) return solveKS(maxW, Weights, Values, n - 1);
    else{
        int op1 = Values[n - 1] + solveKS(maxW - Weights[n - 1], Weights, Values, n - 1);
        int op2 = solveKS(maxW, Weights, Values, n - 1);
        return op1>op2 ? op1 : op2; // Returns the larger value
    }
}
 
int main()
{
    vector <int> Values = {60,100,120};
    vector <int> Weights = {10,20,30};
    int n = sizeof(Values)/sizeof(Values[0]);
    cout<<"Highest value possible is: "<<solveKS(MAXWEIGHT, Weights, Values, n);
}

//-------------------------------------------------------

// Sheet 9 - Question 2
#include <algorithm>

// // Public struct for Jobs data structure
// struct Job{int start, finish, profit;};
 
// // Sort job jobsay ascendingly by finish time.
// bool sortFinish(Job j1, Job j2){return j1.finish < j2.finish;}
 
// int findLastConflict(Job jobs[], int i)
// {
//     for (int j=i-1; j>=0; j--)
//     {
//         if (jobs[j].finish <= jobs[i-1].start) return j;
//     }
//     return -1;
// }
 
// // Recursive Function
// int RecursiveJobScheduling(Job jobs[], int n)
// {
//     if (n == 1) return jobs[n-1].profit; // Return job's profit if there is just one job
//     int includeProf = jobs[n-1].profit;
//     int i = findLastConflict(jobs, n);
//     if (i != -1) includeProf += RecursiveJobScheduling(jobs, i+1);
//     int excludeProf = RecursiveJobScheduling(jobs, n-1);
//     return includeProf>excludeProf ? includeProf: excludeProf; // Return higher profit of either including the job
//                                                                 // or excluding it.
// }
 
// int maxProfitSubset(Job jobs[], int size)
// {
//     sort(jobs, jobs+size, sortFinish);
//     return RecursiveJobScheduling(jobs, size);
// }
 
// int main()
// {
//     Job jobs[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
//     int size = sizeof(jobs)/sizeof(jobs[0]);
//     cout<<"Maximum profit subset is: "<<maxProfitSubset(jobs, size);
// }

//-------------------------------------------------------

// Sheet 9 - Question 3
// #define n 3
// #define m 3

// int maxGifts(int row, int col, int gifts[][4]) // <- This value must change with m
// {
//     vector<vector<int> > maxAt(n+1,vector<int>(col+1, 0));
//     for(int i=1;i<=row;i++)
//     {
//         for(int j=1;j<=col;j++)
//         {
//             int op1 = maxAt[i][j-1];
//             int op2 = maxAt[i-1][j];
//             maxAt[i][j] = (op1>op2 ? op1: op2)+gifts[i][j];
//         }
//     }
//     return maxAt[row][col];
// }

// int main()
// {
//     // Assume that n = 3, m = 3
//     // Then the gifts matrix should be as follows
//     int GiftsMatrix[n+1][m+1] = {{0,0,0,0},
//                                  {0,4,3,5},
//                                  {0,2,7,1},
//                                  {0,5,6,9}};
//     // Call the maxGifts() function
//     cout<<"Maximum value of Gifts is: "<<maxGifts(3,3,GiftsMatrix)<<"\n";
// }

//-------------------------------------------------------

// Sheet 9 - Question 4
// void longestPalindrome(string str, int size)
// {
//     int maxLength = 1, start = 0;
//     for (int i = 0; i < size; i++) {
//         for (int j = i; j < size; j++) {
//             bool isPalindrome = true;
//             int tempMax = j - i + 1;
//             for (int n = 0; n<tempMax/2; n++)
//             {
//                 // Set to false if current the 2 middle letters aren't identical.
//                 if (str[j - n] != str[i + n]) isPalindrome = false;
//             }
//             // Update new palindrome if its longer.
//             if (isPalindrome && tempMax == maxLength)
//             {
//                 start = i;
//                 maxLength = tempMax;
//             }
//             if (isPalindrome && tempMax > maxLength)
//             {
//                 start = i;
//                 maxLength = tempMax;
//             }
//         }
//     }
 
//     cout << "Longest Palindrome Substring is: ";
//     for (int m = start; m <= start + maxLength-1; ++m) cout << str[m];
// }
 
// int main()
// {
//     string str = "babad";
//     int size = str.length();
//     longestPalindrome(str,size);
// }