// Yousef Ibrahim Gomaa Mahmoud - 320210207

// Sheet 8 - Question 2
#include <iostream>
#include <vector>

using namespace std;

// Recursive Function
void printPaths(vector<vector <int>> mat, vector<int> &route, int i, int j)
{
    if (mat.size() == 0) return;
    int M = mat.size();
    int N = mat[0].size();
    
    if (i == M-1 && j == N-1)
    {
        cout<<"{";
        for (int k: route)
        {
            cout<<k<<", ";        
        }
        cout<<mat[i][j]<<"}"<<endl;
        return;
    }
    else
        route.push_back(mat[i][j]);

    if (i+1 < M) printPaths(mat, route, i+1, j);
    if (j+1 < N) printPaths(mat, route, i, j+1);
    if (i+1 < M && j+1 < N) printPaths(mat,route,i+1,j+1);

    route.pop_back();
}

void printPaths(vector<vector <int>> const &mat)
{
    vector<int> route;
    printPaths(mat, route, 0, 0);
}

int main()
{
    vector<vector <int>> Matrix =   {{1,2,3},
                                    {4,5,6},
                                    {7,8,9}};
    printPaths(Matrix);
    return 0;
}