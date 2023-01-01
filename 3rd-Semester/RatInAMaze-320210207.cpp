// Yousef Ibrahim Gomaa Mahmoud - 320210207

// Sheet 8 - Question 3
#include <iostream>
#include <vector>

using namespace std;

#define mazesize 4

bool foundPath(vector <vector <int>> &maze, vector <vector <int>> &solution, int posX, int posY)
{
    if (posX == mazesize - 1 && posY == mazesize - 1 && maze[posX][posY] == 1) // Flag goal if reached. (maze[3][3])
    {
        solution[posX][posY] = 1;
        return true;
    }

    // Check if current path is eligible. (Flagged 1)
    // Prevent going outside the boundries.
    if (posX >= 0 && posY >= 0 && posX < mazesize && posY < mazesize && maze[posX][posY] == 1)
    {
        if (solution[posX][posY] == 1) return false;
        // Test visit and mark as visited.
        solution[posX][posY] = 1;
        // Move forward or move downwards
        if (foundPath(maze, solution, posX+1, posY) || foundPath(maze, solution, posX, posY+1)) return true;
        solution[posX][posY] = 0; // Backtrack step if not successful.
        return false;
    }
    return false;
}

int main()
{
    // Maze representation in binary matrix.
    vector <vector <int>> maze = {{1 ,0 ,0 ,0},
                                  {1, 1, 0, 0},
                                  {0, 1, 0, 0},
                                  {1, 1, 1, 1}};
    // Solution matrix filled with zeroes.
    vector <vector <int>> solution = {{0, 0, 0, 0},
                                      {0, 0, 0, 0},
                                      {0, 0, 0, 0},
                                      {0, 0, 0, 0}};
    // Call findPath()
    foundPath(maze,solution,0,0);
    cout<<"######## Question 3 ########\n---------------------------"
    <<"\nThe resultant matrix is:\n\n";
    int i = 0;
    while(i < solution.size())
    {
    cout<<"|";
    for (int obj: solution[i])
    {
        cout<<" "<<obj<<" ";
    }
    cout<<"|\n";
    i++;
    }
}