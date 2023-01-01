// Yousef Ibrahim Gomaa Mahmoud - 320210207

// Sheet 8 - Question 6
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Same function as Question 4
void calcPerm(string strIn, string strOut, vector <string> &stringV, int &c)
{
    int j = 0;
    if (strIn.length() == 0) {
       stringV.push_back(strOut);
        c++;
        return;
    }

    for (char i: strIn)
    {
        char temp = i; // Store letter temporarily
        // Append the letter to the end and continue the recursion function.
        calcPerm(strIn.substr(0, j)+strIn.substr(j+1), strOut+temp, stringV, c);
        j++;
    }
}

int main()
{
    char Input[] = {'e','x','h','a','u','s','t','e','d'}; // Assuming the letters are not repeated except for the set.
    string Output = "";
    int Count = 0;
    vector <string> stringV = {};
    calcPerm(Input, Output, stringV ,Count);
    cout<<"######## Question 4 ########\n---------------------------"
    <<"\nAll possible passwords/permutations of the character array,"
    <<"\n{'e','x','h','a','u','s','t','e','d'} are in the file: \"ExhaustedPasswords.txt\"\n"
    // Total number of possible passwords/permutations = Count = N*(N-1)! = 9*8! = 362880
    <<"No. of Possible Passwords: "<<Count<<"\n\n";
    ofstream outWordFile("ExhaustedPasswords.txt");
    if (outWordFile.is_open())
    {
        for (int i=0; i<Count; i++)
        {
            outWordFile << stringV[i];
            outWordFile.put('\n');
        }
    }
    outWordFile.close();
}