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

// Split Function using string stream 
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
    ifstream File1("nodes.csv"); // Open given File1.
				 // O(n) = n
				 // (n is the number of lines in nodes.csv)
	if (File1.is_open())
    {
        int i=0;
        string str;
        while(getline(File1,str)) // Select every line and store in str of type String.
        {
            vector<string> parts = split(str,',');
            paperFile.push_back({parts[0],parts[1],"0"}); // Paper ID
							  // IDs starts from index 1 and are equivalent to its value.
							  // Paper Name
							  // Amount of times cited column. (To be used later during sorting)
            // cout<<paperFile[i][0]<<" "<<paperFile[i][1]<<" "<<paperFile[i][2]<<endl;
            i++;
        }
    }
	File1.close();
    
    // Readying Edges File.
    vector<vector <string>> edgesFile;
    ifstream File2("edges.csv"); // Open given File2
				 // // O(n) = 	n
				 // (n is the number of lines in edges.csv)
	if (File2.is_open())
    {
        int i,j=0;
        string str;
        while(getline(File2,str)) // Select every line and store in str of type String.
        {
            vector<string> parts = split(str,',');
	    int paperCitingID = stoi(parts[0]);
	    int citedPaperID = stoi(parts[1]);
            if (edgesFile[i][0] != parts[1]) // If paper hasn't been cited before, push it to the vector. 
	    {
		edgesFile.push_back({parts[1]});
		i++; // Increment number of papers in the vector.
		j=0; // Set number of papers that cited given papers to 0.
	    }
	    edgesFile[i].push_back({parts[0]}); // Add & Increment number of papers that cited given paper by 1.
            paperFile[citedPaperID][2] = to_string(stoi(paperFile[citedPaperID][2])+1);
	    cout<<edgesFile[i][0]<<edgesFile[i][j]<<endl;
	    j++;
        }
    }
	File2.close();
   	// Sort Function  
    sort(paperFile.begin(), paperFile.end(), column3Sort); // Initiate sorting..	O(n) = n^2
							   // (n is the  number of iterations in the sort function) 
							   // Total Time Complexity = O(n^2) + n + n = O(n^2)
    int x = 3;
    while(true){
    	cout<<"Kindly enter which (n)th highest cited paper to return:\n------------------------\n"<<endl;
    	if (x>Papers)
	{
		cout<<"Kindly enter a value in the given list of papers\n";
		continue;
	}
	break;
    }

    cout<<"The "<<x<<"th highest cited paper is Paper "<<paperFile[x][0]
    <<"\nPaper Name: "<<paperFile[x][1]
    <<"\nNo. of Citations: "<<paperFile[x][2];

    // BONUS		
    int threshold = 3;
    cout<<"\n\nThe closest group recommended to the given paper is:\n";
    for (int i = 0; i<threshold; i++)
    {
	cout<<i<<"st/nd/th Closest Paper:"<<"\n-------------------\n";
	cout<<"Paper ID: "<<paperFile[x+i][0]
	<<"\nPaper Name: "<<paperFile[x+i][1]
	<<"\nNo. of Citations: "<<paperFile[x+i][2]
	<<"\n-------------------\n";
    }
}
