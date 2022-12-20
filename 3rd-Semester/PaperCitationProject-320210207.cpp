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

vector<string> getClose(vector<vector <string>>& vector1, int userInput)
{
    vector<string> close;
    bool isClose;
    for (int i=1; i<Papers; i++)
    {
        isClose = true;
        for (int j=1; j<vector1[i].size(); j++)
        {
            if (vector1[userInput][j] != vector1[i][j]) 
            {
                isClose = false;
                continue;
            }
        }
        if (isClose) close.push_back(vector1[i][0]);
    }
    return close;
}

// MAIN PROGRAM
int main()
{
    // Papers File.           
    vector<vector <string>> paperFile;
    ifstream File1("nodes.csv"); // Open given File1.
				 // O(n) = n
				 // (n is the number of lines in nodes.csv)
	if (File1.is_open())
    {
        int i=1;
        bool skippedFirst = false;
        string str;
        while(getline(File1,str)) // Select every line and store in str of type String.
        {
            if (!skippedFirst) {skippedFirst = true; continue;} // Skips the first line with the "ID,Name"
            
            vector<string> parts = split(str,',');
            paperFile.push_back({parts[0],parts[1],"0"}); // Paper ID
							  // IDs starts from index 1 and are equivalent to its value.
							  // Paper Name
							  // Amount of times cited column. (To be used later during sorting)
            // T.A. Note: Uncomment this to print paperFile's contents.───────────────┐                                           
            //                                                                        ▼
            // cout<<paperFile[i-1][0]<<" "<<paperFile[i-1][1]<<" "<<paperFile[i-1][2]<<endl;
            i++;
        }
    }
	File1.close();
    
    // Edges File.
    vector<vector <string>> edgesFile;

    ifstream File2("edges.csv"); // Open given File2
				                 // O(n) = 	n
				                 // (n is the number of lines in edges.csv)
	if (File2.is_open())
    {
        bool skippedFirst = false;
        int i,j=1;
        string str;
        while(getline(File2,str)) // Select every line and store in str of type String.
        {
            if (!skippedFirst) {skippedFirst = true; continue;} // Skips the first line with the "ID,CitedID"

            vector<string> parts = split(str,',');
            int paperCitingID = stoi(parts[0]); // IDs start from index 1.
            int citedPaperID = stoi(parts[1]);
            if (edgesFile.empty() || edgesFile[i-1].front() != parts[1]) // If paper hasn't been cited before, push it to the vector. 
            {
                edgesFile.push_back({parts[1]});
                i++; // Increment number of papers in the vector.
                j=1; // Set number of papers that cited given paper to 0.
            }
            edgesFile[i-1].push_back(parts[0]); // Add & Increment number of papers that cited given paper by 1.
            paperFile[citedPaperID][2] = to_string(stoi(paperFile[citedPaperID][2])+1);
            
            // T.A. Note: Uncomment to print edgesFile's contents.────┐                                           
            //                                                        ▼
            // cout<<edgesFile[i-1][0]<<" "<<edgesFile[i-1][j-1]<<endl;
            j++;
        }
    }
	File2.close();
   	
    // Sort Function  
    sort(paperFile.begin(), paperFile.end(), column3Sort); // Initiate sorting..	O(n) = n^2
							   // (n is the  number of iterations in the sort function) 
							   // Total Time Complexity = O(n^2) + n + n = O(n^2)
    int x=1;
    while(true)
    {
        cout<<"########### START ###########\n"
    	<<"Kindly enter which (n)th highest cited paper to return:\n------------------------\n"<<endl;
    	cin>>x;
        if (x>Papers)
	    {
            cout<<"\nKindly enter a value in the given list of papers. (Less than "<<Papers<<")"
            <<"\n########### RESTARTING ###########\n";
            continue;
	    }
	    break;
    }
    // N-th cited paper.
    cout<<"\nThe "<<x<<"st/nd/th highest cited paper is Paper "<<paperFile[x][0]
    <<"\nPaper Name: \""<<paperFile[x][1]<<"\""
    <<"\nNo. of Citations: "<<paperFile[x][2]<<" times.\n";
    
    // BONUS
    int x2 = 1;
    while(true)
    {
        cout<<"\n\n########### BONUS ###########\n"
        <<"Kindly enter which paper id to return closest group of papers to it:\n------------------------\n"<<endl;
        cin>>x2;
        if (x2>Papers)
        {
            cout<<"\nKindly enter a value in the given list of papers. (Less than "<<Papers<<")"
            <<"\n########### RESTARTING ###########\n";
            continue;
        }
    	break;
    }

    vector<string> closePapers = getClose(paperFile,x2);
    cout<<closePapers.size();
    int threshold = closePapers.size();

    for (int i = 1; i<threshold+1; i++)
    {
        cout<<i<<"st/nd/th Closest Paper:\n";
        cout<<"Paper ID: "<<closePapers[threshold]
        <<"\nPaper Name: "<<paperFile[stoi(closePapers[threshold])][1]
        <<"\nNo. of Citations: "<<paperFile[stoi(closePapers[threshold])][2]
        <<"\n------------------------\n";
    }
}