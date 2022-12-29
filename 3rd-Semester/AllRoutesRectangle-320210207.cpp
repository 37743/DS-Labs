#include <iostream>
#include <vector>
using namespace std;

// Recursive Function
void printPaths(vector<vector <int>> mat, vector<int> route, int row, int col)
{
    if (mat.size() == 0) return;
    int M = mat[0].size();
    int N = mat.size();
    int i =0 ,int j = 0;
    while (i < mat.size())
    {
        route.push_back(mat[i][j]);

        if (i+1 < M) printPaths(mat, route, i+1, j);
        if (j+1 < N) printPaths(mat, route, i, j+1);
        if (i+1 < M && j+1 < N) printPaths(mat,route,i+1,j+1);
    }
    for (i: route)
    {
        cout<<i<<", ";        
    }
    cout<<mat[i][j]<<endl;

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