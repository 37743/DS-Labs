// Yousef Ibrahim Gomaa Mahmoud - 320210207

// Sheet 8 - Question 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findPlatforms(vector <double> arrive, vector <double> depart, int &platforms)
{
    int i = 0;
    int count = 0;
    while( i < arrive.size())
    {
        if (arrive[0] < depart[0]) 
        {
            arrive.erase(arrive.begin());
            platforms = max(platforms,count++);
        }
        if (arrive[0] > depart[0])
        {
            depart.erase(depart.begin());
            platforms = max(platforms,count--);
        }
        i++;
    }
}

int main()
{
    vector <double> trainsArrive = {2.00, 2.10, 3.00, 3.20, 3.50, 5.00};
    vector <double> trainsDepart = {2.30, 3.40, 3.20, 4.30, 4.00, 5.20};
    sort(trainsArrive.begin(), trainsArrive.end());
    sort(trainsDepart.begin(), trainsDepart.end());
    int platforms = 0;
    findPlatforms(trainsArrive, trainsDepart, platforms);
    cout<<"######## Question 2 ########\n---------------------------"
    <<"\nThe minimum platforms needed is "<<platforms<<"\n\n";
}