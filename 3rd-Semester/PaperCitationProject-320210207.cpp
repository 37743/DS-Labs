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
bool column3Sort(vector<string>& vector1, vector<string>& vector2) {return stoi(vector1[2]) > stoi(vector2[2]);}

void sortVector(vector<vector <string>>& vector1) {sort(vector1.begin(), vector1.end(), column3Sort);}

// Split Function using string stream 
vector<string> split(string str, char delim=',') // Default delimiter is ','.
{   
    vector<string> parts;
    stringstream sstr(str); // instance of stream class that operates on strings
    string part;
    while(getline(sstr,part,delim))
    {
        parts.push_back(part); // adds string before and after given delimiter.
    }
    // for (int i = 0; i<parts.size(); i++) std::cout<<parts[i]<<"\\";
    return parts;
}

vector<string> getClose(const vector<string>& target, const vector<vector<string>>& file, int& threshold)
{
    vector<int> similarCount(file.size());
    // std::cout<<"Target's papers cited:\n";
    for (int i = 0; i<file.size(); i++) // Iterate on whole file
    {
        for (string s : file[i]) // For every string in file[i] (current vector in the bigger vector)
        {
            if (find(target.begin(), target.end(), s) != target.end()) // Find paper(s) with the same cited papers as the one given.
            {
                similarCount[i]++; // If found, increment current index by 1 for each similarity.
            }
        }
    }

    int max = 0;
    int maxIndex = 0;
    std::cout<<"\nPapers that share similiarities, have papers in common which amounts to:\n";
    for (int i = 1; i<similarCount.size(); i++)   // For loop that updates max with the index
                                                    // of the most similar paper in the vector.
                                                    // Most similar paper has the highest count of similar strings.
                                                    // (Same cited papers in the vector.)
    {   
        if (similarCount[i] != 0) std::cout<<" ("<<similarCount[i]<<", " << i << ") ";
        if (similarCount[i]>max)
        {
            max = similarCount[i];
            maxIndex = i;
        }
    }
    std::cout<<'\n';
    threshold = max;
    return file[max];
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
            // std::cout<<paperFile[i-1][0]<<" "<<paperFile[i-1][1]<<" "<<paperFile[i-1][2]<<endl;
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
            paperFile[citedPaperID-1][2] = to_string(stoi(paperFile[citedPaperID-1][2])+1);;
            // std::cout << "Paper: " << citedPaperID << ", Count: " <<paperFile[citedPaperID-1][2]  << '\n';
 
            // T.A. Note: Uncomment to print edgesFile's contents.────┐                                           
            //                                                        ▼
            // std::cout<<edgesFile[i-1][0]<<" "<<edgesFile[i-1][j-1]<<endl;
            j++;
        }
    }
	File2.close();
    vector <vector <string>> unsortedPaperFile = paperFile; // For later use during bonus. (could be commented along with bonus)
    // Sort Function  
    sortVector(paperFile);      // Initiate sorting..	O(n) = n*log(n)
							    // (n is the  number of iterations in the sort function) 
							    // Total Time Complexity = n*log(n) + n + n = n*log(n)
        
    int x=1;
    while(true)
    {
        std::cout<<"########### START ###########\n"
    	<<"Kindly enter which (n)th highest cited paper to return:\n------------------------\n"<<endl;
    	cin>>x;
        if (x>Papers)
	    {
            std::cout<<"\nKindly enter a value in the given list of papers. (Less than "<<Papers<<")"
            <<"\n########### RESTARTING ###########\n";
            continue;
	    }
        x--;
	    break;
    }
    // N-th cited paper.
    std::cout<<"\nThe "<<x+1<<"st/nd/th highest cited paper is Paper "<<paperFile[x][0]
    <<"\nPaper Name: \""<<paperFile[x][1]<<"\""
    <<"\nNo. of Citations: "<<paperFile[x][2]<<" times.\n";
    
    
    // BONUS
    int x2 = 1;
    while(true)
    {
        std::cout<<"\n\n########### BONUS ###########\n"
        <<"Kindly enter which paper id to return closest group of papers to it:\n------------------------\n"<<endl;
        cin>>x2;
        if (x2>Papers)
        {
            std::cout<<"\nKindly enter a value in the given list of papers. (Less than "<<Papers<<")"
            <<"\n########### RESTARTING ###########\n";
            continue;
        }
    	break;
    }
    int threshold=0;
    int paper_index=0;
    // for (auto i : edgesFile) {paper_index++; if (stoi(i[0]) == x2){paper_index++; break;}}
    vector<string> closePapers = getClose(edgesFile[x2],edgesFile,threshold);
 //   for (auto i : paperFile)
   //     std::cout << "id: " << i[0] << ", title: " << i[1] << ", count: " << i[2] << '\n';
    std::cout<<"\nThreshold is: "<<threshold;
    std::cout<<"\nClosest Paper:\n";
    std::cout<<"Paper ID: "<<unsortedPaperFile[stoi(closePapers[0])-1][0]
    <<"\nPaper Name: "<<unsortedPaperFile[stoi(closePapers[0])-1][1]
    <<"\nNo. of Times Cited in Other Papers: "<<unsortedPaperFile[stoi(closePapers[0])-1][2]
    <<"\n------------------------\n";
    
}