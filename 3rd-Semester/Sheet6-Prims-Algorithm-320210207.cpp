// Yousef Ibrahim Gomaa Mahmoud - 320210207
// Sheet 6 - Problem 4

#include <iostream>
using namespace std;

#define max 100
// Assuming that this is the graph that we need to solve. (Graph of problem 3)
//             A
//             │
//             │3
//        10   │    6
//   B ─────── C ─────── E
//    │        │        │
//    │        │        │
//   4│        │2       │1
//    │        │        │
//    │        │        │
//    └─────── D ───────┘

// NOTE: Update this value when changing graph size. ──────────────────────┐
// Prim's Algorithm Function.                                              ▼
void primAlgorithm(int nodes, int edges, bool visited[max], int Graph[max][5]){
    for (int edges; nodes-1>edges; edges++)
    {
        int min = INT_MAX;
        int row, col = 0;  
        for (int i=0; i<nodes; i++)
        {
            if (visited[i]) // Check if current node is visited
            {
                for (int j=0; j<nodes; j++)
                {
                    if (!visited[j]&& (Graph[i][j] != 0)) // Skips visited/unconnected nodes
                    {
                        if (Graph[i][j]<min) {min = Graph[i][j]; row = i; col = j;}
                        // Update min if a new minimum edge is found, and save their connected nodes.
                    }
                }
            }
        }
        char Letter1 = (char)row+65; // Getting the current nodes' letter. (65 is 'A' in ASCII)
        char Letter2 = (char)col+65; // Getting the parent's letter. 
        cout<<"|"<<Letter2<<"\t|"<<Letter1<<"\t|"<<Graph[row][col]<<"\t    |"<<endl;
        visited[col] = true; // Set minimum edge length node's visit status to true
                             // to traverse its connected nodes next.
    }
}

// Main Program.
int main()
{
    const int nodes = 5; // Number of nodes in the graph.
    int Graph[nodes][nodes]={{0,0,3,0,0},
                             {0,0,10,4,0},
                             {3,10,0,2,6},
                             {0,4,6,0,1},
                             {0,0,2,1,0}}; 
                            // 5*5 2D Matrix to put in the edge lengths
                            // between each 2 nodes, index value is the current node.
                            // e.g. Graph[0][1] is the edge length between A and B.
    bool visited[nodes]={false};   
    visited[0] = true; // Assuming Starting point is node A, so it is visited first.
    int edges = 0;
    cout<<"\nMinimum Spanning Tree Result:\n ___________________________\n";
    cout<<"|Node\t|Parent\t|Edge Length|"<<endl;
    primAlgorithm(nodes,edges,visited,Graph); // Same answer as the solution of problem 3.
    cout<<" ===========================\n";
}