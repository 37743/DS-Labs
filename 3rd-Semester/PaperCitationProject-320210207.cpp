// Yousef Ibrahim Gomaa Mahmoud - 320210207

// Papers Citation Project
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

// Pre-define the amount of papers.
#define Papers 82937 

// Value of parameter is 2 as index of column 3 is 2.
bool column3Sort(vector<string>& vector1, vector<string>& vector2) {return vector1[2] > vector2[2];}

vector<string> split(string str, char delim)
{   
    vector<string> parts;
    stringstream sstr(str);
    string part;
    while(getline(sstr,part,delim))
    {
        parts.push_back(part);
    }
    return parts;
}

// MAIN PROGRAM
int main()
{
    // Readying Papers File.           
    vector<vector <string>> paperFile;
    ifstream File1("nodes.csv"); // Open given File1.             O(n) = n        (n is the number of lines in nodes.csv)
	if (File1.is_open())
    {
        int i=0;
        string str;
        while(getline(File1,str)) // Select every line and store in str of type String.
        {
            vector<string> parts = split(str,',');
            paperFile.push_back({parts[0],parts[1],"0"}); // Paper ID
                                                    // Paper Name
                                                    // Amount of times cited column. (To be used later during sorting)
            // cout<<paperFile[i][0]<<" "<<paperFile[i][1]<<" "<<paperFile[i][2]<<endl;
            i++;
        }
    }
	File1.close();
    
    // Readying Edges File.
    vector<vector <string>> edgesFile;
    ifstream File2("edges.csv"); // Open given File1.
	if (File2.is_open())
    {
        int i=0;
        string str;
        while(getline(File2,str)) // Select every line and store in str of type String.
        {
            vector<string> parts = split(str,',');
            if (edgesFile[i][0] != parts[1]) edgesFile.push_back({parts[1]});
            cout<<edgesFile[i][0];
            i++;
        }
    }

    
    sort(paperFile.begin(), paperFile.end(), column3Sort); // Initiate sorting..

    // int x = 0;
    // cout<<"Kindly enter which (n)th highest cited paper to return:\n------------------------\n"<<endl;
    // cin>>x;
    // cout<<"The "<<x<<"th highest cited paper is Paper "<<paperFile[x][0]
    // <<"\n-------------------\nPaper Name: "<<paperFile[x][1]
    // <<"\n-------------------\nNo. of Citations:"<<paperFile[x][2];

    // BONUS
    //
    //
    //
    //
    //
    //
}